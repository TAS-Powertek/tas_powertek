#include "Response.h"

namespace tas_powertek::spf21y {

namespace {
/*
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
constexpr size_t kSizeServerTransmissionTime = 14;
constexpr size_t kSizeCheckSum = 2;
static_assert(kSizeCheckSum == sizeof(detail::CheckSum16));

constexpr size_t kSizeHeader = kSizeCompanyCode + kSizeProductSerialNumber +
                             kSizeDataType + kSizeProductId + kSizeUnitId +
                             kSizeDataLength + kSizeDataRecordId +
                             kSizeClientTransmissionTime +
kSizeServerTransmissionTime;
*/
}

std::string Response::serialize() const {
  std::string result;
  result.resize(80);
  // TODO(mogre) fix
  return result;
}
}  // namespace tas_powertek::spf21y