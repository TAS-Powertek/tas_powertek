#include "AuxFnData.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>
#include <folly/logging/xlog.h>

#include <cstring>

namespace tas_powertek::spf21y {

void AuxFnData::bigEndian() {
  inputVoltage = folly::Endian::big(inputVoltage);
  gprsSignalStrength = folly::Endian::big(gprsSignalStrength);
}

/* static */ AuxFnData AuxFnData::fromByteStream(std::string_view data) {
  if (data.size() != sizeof(AuxFnData)) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into AuxFnData of size {}",
        data.size(), sizeof(AuxFnData)));
  }

  AuxFnData result;
  std::memcpy(&result, data.data(), sizeof(AuxFnData));
  result.bigEndian();
  return result;
}
}  // namespace tas_powertek::spf21y