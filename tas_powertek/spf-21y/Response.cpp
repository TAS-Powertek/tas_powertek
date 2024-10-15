#include "Response.h"

#include <fmt/core.h>

namespace tas_powertek::spf21y {

namespace {

constexpr char kResponseStart = '\x02';
constexpr char kResponseEnd = '\x03';
constexpr std::string_view kBody{"\x00\x00\x00\x00", 4};

constexpr size_t kSizeCompanyCode = 4;
constexpr size_t kSizeProductSerialNumber = 16;
constexpr size_t kSizeDataType = 3;
constexpr size_t kSizeProductId = 11;
constexpr size_t kSizeUnitId = 8;
constexpr size_t kSizeDataLength = 4;
constexpr size_t kSizeDataRecordId = 8;
constexpr size_t kSizeClientTransmissionTime = 14;
constexpr size_t kSizeServerTransmissionTime = 14;
constexpr size_t kSizeCheckSum = 2;
static_assert(kSizeCheckSum == sizeof(detail::CheckSum16));

constexpr size_t kSizeHeader =
    kSizeCompanyCode + kSizeProductSerialNumber + kSizeDataType +
    kSizeProductId + kSizeUnitId + kSizeDataLength + kSizeDataRecordId +
    kSizeClientTransmissionTime + kSizeServerTransmissionTime;
constexpr size_t kSizeBody = kBody.size();
constexpr size_t kTotalSize = sizeof(kResponseStart) + kSizeHeader + kSizeBody +
                              kSizeCheckSum + sizeof(kResponseEnd);
static_assert(kTotalSize == 90);

void checkSize(const std::string& out, size_t sizeToAppend) {
  if (out.size() + sizeToAppend > kTotalSize) {
    throw std::runtime_error(
        fmt::format("Cannot append {} characters to response. Response is {} "
                    "bytes, and can be a maximum of {} bytes",
                    sizeToAppend, out.size(), kTotalSize));
  }
}

void append(std::string& out, char c) {
  checkSize(out, sizeof(c));
  out.append(1, c);
}

void append(std::string& out, std::string_view append, size_t size) {
  checkSize(out, size);
  if (append.size() > size) {
    throw std::runtime_error(fmt::format(
        "Cannot append string of size {} to response. Max size to append is {}",
        append.size(), size));
  }
  out.append(append);
  size_t remaining = size - append.size();
  out.append(remaining, '\0');
}

template <typename T>
  requires std::is_integral_v<T> && std::is_unsigned_v<T>
void append(std::string& out, size_t integer) {
  if (integer > std::numeric_limits<T>::max()) {
    throw std::runtime_error(
        fmt::format("Cannot cast integer {} to size {} bytes when crafting "
                    "response. The max value is {}",
                    integer, sizeof(T), std::numeric_limits<T>::max()));
  }
  checkSize(out, sizeof(T) * 2);
  T castedInteger = static_cast<T>(integer);
  T bigEndianInteger = folly::Endian::big(castedInteger);
  std::array<uint8_t, sizeof(T)>& intAsArray =
      reinterpret_cast<std::array<uint8_t, sizeof(T)>&>(bigEndianInteger);

  static constexpr char hex_digits[] = "0123456789ABCDEF";
  for (uint8_t c : intAsArray) {
    out.push_back(hex_digits[c >> 4]);
    out.push_back(hex_digits[c & 15]);
  }
}

void append(std::string& out, DataType dataType) {
  checkSize(out, kSizeDataType);
  switch (dataType) {
    case DataType::EVENT:
      out.append("FL ");
      break;
    case DataType::INTERVAL_64:
    case DataType::INTERVAL_128:
    case DataType::INTERVAL_256:
    case DataType::INTERVAL_512:
      out.append("IN ");
      break;
    case DataType::DAILY:
      out.append("DL ");
      break;
    case DataType::USER_SETTINGS:
      out.append("PR1");
      break;
    case DataType::REAL_TIME_64:
    case DataType::REAL_TIME_128:
    case DataType::REAL_TIME_256:
    case DataType::REAL_TIME_512:
      out.append("RT ");
      break;
    case DataType::UNKNOWN:
    default:
      throw std::runtime_error(fmt::format("Unknown data type {} ({})",
                                           toString(dataType),
                                           static_cast<size_t>(dataType)));
  }
}

void append(std::string& out, const TimeData& timeData) {
  append<uint8_t>(out, timeData.sec);
  append<uint8_t>(out, timeData.min);
  append<uint8_t>(out, timeData.hour);
  append<uint8_t>(out, timeData.day_of_month);
  append<uint8_t>(out, timeData.month);
  append<uint16_t>(out, timeData.year);
}

void append(std::string& out, const detail::CheckSum16& checksum) {
  std::string checkSumStr = checksum.toString();
  for (char c : checkSumStr) {
    append(out, c);
  }
}
}  // namespace

std::string Response::serialize(std::chrono::sys_seconds curTime) const {
  std::string result;
  result.reserve(kTotalSize);
  // std::chrono::sys_seconds curTime =
  // std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now());

  append(result, kResponseStart);
  append(result, record.companyCode(), kSizeCompanyCode);
  append(result, record.productSerialNumber(), kSizeProductSerialNumber);
  append(result, record.dataType());
  append(result, record.productId(), kSizeProductId);
  append(result, record.unitId(), kSizeUnitId);

  static_assert(sizeof(uint16_t) * 2 == kSizeDataLength);
  append<uint16_t>(result, record.dataLengthWithSeparators());
  append(result, record.dataRecordId(), kSizeDataRecordId);
  append(result, record.clientTransmissionTime());
  TimeData serverTransmissionTime = TimeData::fromSysTime(curTime);
  append(result, serverTransmissionTime);
  append(result, kBody, kSizeBody);

  std::string_view checksumableContent = std::string_view{result};
  detail::CheckSum16 checksum =
      detail::CheckSum16::compute(checksumableContent);

  append(result, checksum);
  append(result, kResponseEnd);

  if (result.size() != kTotalSize) {
    throw std::runtime_error(
        fmt::format("Invalid response created. Expecting to create size {}, "
                    "but is of size {}",
                    kTotalSize, result.size()));
  }
  return result;
}
}  // namespace tas_powertek::spf21y
