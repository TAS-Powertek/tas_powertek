#include "Record.h"

namespace tas_powertek::spf21y {

namespace {
constexpr char kRequestStart = '\x02';
constexpr char kRequestEnd = '\x03';
constexpr std::string_view kHeaderBodySeparator = "\x0d\x0a";

constexpr size_t kSizeCompanyCode = 4;
constexpr size_t kSizeProductSerialNumber = 16;
constexpr size_t kSizeDataType = 3;
constexpr size_t kSizeProductId = 11;
constexpr size_t kSizeUnitId = 8;
constexpr size_t kSizeDataLength = 4;
constexpr size_t kSizeDataRecordId = 8;
constexpr size_t kSizeClientTransmissionTime = 14;
constexpr size_t kSizeCheckSum = 2;
static_assert(kSizeCheckSum == sizeof(detail::CheckSum16));

constexpr size_t kSizeHeader = kSizeCompanyCode + kSizeProductSerialNumber +
                               kSizeDataType + kSizeProductId + kSizeUnitId +
                               kSizeDataLength + kSizeDataRecordId +
                               kSizeClientTransmissionTime;
constexpr size_t kSizeRequestWithNoData = sizeof(kRequestStart) + kSizeHeader +
                                          kHeaderBodySeparator.size() +
                                          kSizeCheckSum + sizeof(kRequestEnd);

void assertRequestBoundaries(std::string_view raw) {
  if (raw.size() < kSizeRequestWithNoData) {
    throw std::runtime_error(fmt::format(
        "Invalid request size. Minimum size is {}", kSizeRequestWithNoData));
  }
  if (raw[0] != kRequestStart) {
    throw std::runtime_error("Data does not begin with 0x02");
  }
  if (raw[raw.size() - 1] != kRequestEnd) {
    throw std::runtime_error("Data does not end with 0x03");
  }
  if (raw.substr(sizeof(kRequestStart) + kSizeHeader,
                 kHeaderBodySeparator.size()) != kHeaderBodySeparator) {
    throw std::runtime_error(
        "Did not find delimiter sequence between header and data");
  }
}
void verifyChecksum(std::string_view data, detail::CheckSum16 checksum) {
  std::string_view dataForCheckSum =
      data.substr(0, data.size() - sizeof(kRequestEnd) - kSizeCheckSum);
  if (!checksum.verify(dataForCheckSum)) {
    throw std::runtime_error(fmt::format(
        "The request has a checksum of {}, but it could not be validated",
        checksum.underlying()));
  }
}

std::string getCString(std::string_view data) {
  auto nullIter = data.find('\0');
  if (nullIter == std::string_view::npos) {
    return std::string{data};
  } else {
    return std::string{data.substr(0, nullIter)};
  }
}

template <typename T>
  requires std::is_integral_v<T> && std::is_unsigned_v<T>
T parseInteger(std::string_view data) {
  XCHECK(data.size() % 2 == 0);
  XCHECK_EQ(sizeof(T), data.size() / 2);
  T result{};
  for (char c : data) {
    uint8_t byte = static_cast<uint8_t>(c);
    if (byte >= '0' && byte <= '9')
      byte = byte - '0';
    else if (byte >= 'a' && byte <= 'f')
      byte = byte - 'a' + 10;
    else if (byte >= 'A' && byte <= 'F')
      byte = byte - 'A' + 10;
    result = (result << 4) | (byte & 0xF);
  }
  return result;
}

}  // namespace
/* explicit */ Record::Record(std::string_view raw) {
  assertRequestBoundaries(raw);
  std::string_view checkSumStr = raw.substr(
      raw.size() - kSizeCheckSum - sizeof(kRequestEnd), kSizeCheckSum);
  const uint16_t* castedCheckSumStr =
      reinterpret_cast<const uint16_t*>(checkSumStr.data());
  checksum_ = detail::CheckSum16(folly::Endian::big(*castedCheckSumStr));
  verifyChecksum(raw, checksum_);

  size_t offset = sizeof(kRequestStart);
  std::string_view companyCode = raw.substr(offset, kSizeCompanyCode);
  offset += kSizeCompanyCode;
  std::string_view productSerialNumber =
      raw.substr(offset, kSizeProductSerialNumber);
  offset += kSizeProductSerialNumber;
  std::string_view dataType = raw.substr(offset, kSizeDataType);
  offset += kSizeDataType;
  std::string_view productId = raw.substr(offset, kSizeProductId);
  offset += kSizeProductId;
  std::string_view unitId = raw.substr(offset, kSizeUnitId);
  offset += kSizeUnitId;
  std::string_view dataLength = raw.substr(offset, kSizeDataLength);
  offset += kSizeDataLength;
  std::string_view dataRecordId = raw.substr(offset, kSizeDataRecordId);
  offset += kSizeDataRecordId;
  std::string_view clientTransmissionTime =
      raw.substr(offset, kSizeClientTransmissionTime);
  offset += kSizeClientTransmissionTime;
  XCHECK_EQ(offset, kSizeHeader + sizeof(kRequestStart));

  companyCode_ = getCString(companyCode);
  productSerialNumber_ = getCString(productSerialNumber);
  productId_ = getCString(productId);
  unitId_ = getCString(unitId);
  dataRecordId_ =
      std::string{dataRecordId};  // This is effectively just binary data.
  dataLength_ = parseInteger<uint16_t>(dataLength);
  // For unknown reason the "data length" includes the size of the header-data
  // separator and the checksum.
  dataLength_ -= kHeaderBodySeparator.size() + kSizeCheckSum;
  clientTransmissionTime_.sec =
      parseInteger<uint8_t>(clientTransmissionTime.substr(0, 2));
  clientTransmissionTime_.min =
      parseInteger<uint8_t>(clientTransmissionTime.substr(2, 2));
  clientTransmissionTime_.hour =
      parseInteger<uint8_t>(clientTransmissionTime.substr(4, 2));
  clientTransmissionTime_.day_of_month =
      parseInteger<uint8_t>(clientTransmissionTime.substr(6, 2));
  clientTransmissionTime_.month =
      parseInteger<uint8_t>(clientTransmissionTime.substr(8, 2));
  clientTransmissionTime_.year =
      parseInteger<uint16_t>(clientTransmissionTime.substr(10, 4));

  offset += kHeaderBodySeparator.size();
  if (dataLength_ + offset > raw.size()) {
    throw std::runtime_error(
        fmt::format("Invalid data length {} for request of size {}",
                    dataLength_, raw.size()));
  }

  std::string_view data = raw.substr(offset, dataLength_);
  offset += dataLength_;
  if (offset + kSizeCheckSum + sizeof(kRequestEnd) != raw.size()) {
    throw std::runtime_error("Invalid number of bytes after data");
  }

  // Parse the data.
  if (dataType == "FL ") {
    EventData eventData = EventData::fromByteStream(data);
    data_ = std::make_unique<EventData>(std::move(eventData));
  } else if (dataType == "DY ") {
    DailyData dailyData = DailyData::fromByteStream(data);
    data_ = std::make_unique<DailyData>(std::move(dailyData));
  } else if (dataType == "PR1") {
    UserSettingData userSettingData = UserSettingData::fromByteStream(data);
    data_ = std::make_unique<UserSettingData>(std::move(userSettingData));
  } else if (dataType == "IN ") {
    switch (data.size()) {
      case sizeof(IntervalData64):
        data_ = std::make_unique<IntervalData64>(
            IntervalData64::fromByteStream(data));
        break;
      case sizeof(IntervalData128):
        data_ = std::make_unique<IntervalData128>(
            IntervalData128::fromByteStream(data));
        break;
      case sizeof(IntervalData256):
        data_ = std::make_unique<IntervalData256>(
            IntervalData256::fromByteStream(data));
        break;
      case sizeof(IntervalData512):
        data_ = std::make_unique<IntervalData512>(
            IntervalData512::fromByteStream(data));
        break;
      default:
        throw std::runtime_error(
            fmt::format("Invalid interval data of length {}", data.size()));
    }
  } else if (dataType == "RT ") {
    switch (data.size()) {
      case sizeof(RealTimeData64):
        data_ = std::make_unique<RealTimeData64>(
            RealTimeData64::fromByteStream(data));
        break;
      case sizeof(RealTimeData128):
        data_ = std::make_unique<RealTimeData128>(
            RealTimeData128::fromByteStream(data));
        break;
      case sizeof(RealTimeData256):
        data_ = std::make_unique<RealTimeData256>(
            RealTimeData256::fromByteStream(data));
        break;
      case sizeof(RealTimeData512):
        data_ = std::make_unique<RealTimeData512>(
            RealTimeData512::fromByteStream(data));
        break;
      default:
        throw std::runtime_error(
            fmt::format("Invalid real time data of length {}", data.size()));
    }
  } else {
    throw std::runtime_error(fmt::format("Invalid data type '{}'", dataType));
  }
}

DataType Record::dataType() const {
  switch (data_.index()) {
    case 0:
      return DataType::EVENT;
    case 1:
      return DataType::INTERVAL_64;
    case 2:
      return DataType::INTERVAL_128;
    case 3:
      return DataType::INTERVAL_256;
    case 4:
      return DataType::INTERVAL_512;
    case 5:
      return DataType::DAILY;
    case 6:
      return DataType::USER_SETTINGS;
    case 7:
      return DataType::REAL_TIME_64;
    case 8:
      return DataType::REAL_TIME_128;
    case 9:
      return DataType::REAL_TIME_256;
    case 10:
      return DataType::REAL_TIME_512;
  }

  throw std::runtime_error("Unknown data type");
}

size_t Record::dataLengthWithSeparators() const {
  return dataLength_ + kHeaderBodySeparator.size() + kSizeCheckSum;
}
}  // namespace tas_powertek::spf21y