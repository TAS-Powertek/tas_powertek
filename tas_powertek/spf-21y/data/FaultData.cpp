#include "FaultData.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>

#include <cstring>

namespace tas_powertek::spf21y {

/* static */ FaultData FaultData::fromByteStream(std::string_view data) {
  if (sizeof(FaultData) != data.size()) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into FaultData of size {}",
        data.size(), sizeof(FaultData)));
  }

  FaultData result;
  std::memcpy(&result, data.data(), sizeof(FaultData));
  // SPF21Y uses 16 bit words, while bitset uses 8 bit words. To use the same
  // bit numbers, we manually flip each even and odd byte.
  for (int i = 0; i < 8; i++) {
    uint16_t* word = reinterpret_cast<uint16_t*>(&result);
    word += i;
    *word = folly::Endian::swap(*word);
  }
  return result;
}
}  // namespace tas_powertek::spf21y