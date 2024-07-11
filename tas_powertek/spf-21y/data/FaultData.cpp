#include "FaultData.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>

#include <cstring>

namespace tas_powertek::spf21y {

void FaultDataLow::bigEndian() {
  // SPF21Y uses 16 bit words, while bitset uses 8 bit words. To use the same
  // bit numbers, we manually flip each even and odd byte.
  for (size_t i = 0; i < faultBits.size() / 16; i++) {
    uint16_t* word = reinterpret_cast<uint16_t*>(this);
    word += i;
    *word = folly::Endian::swap(*word);
  }
}
/* static */ FaultDataLow FaultDataLow::fromByteStream(std::string_view data) {
  if (sizeof(FaultDataLow) != data.size()) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into FaultDataLow of size {}",
        data.size(), sizeof(FaultDataLow)));
  }

  FaultDataLow result;
  std::memcpy(&result, data.data(), sizeof(FaultDataLow));
  result.bigEndian();
  return result;
}

void FaultData::bigEndian() {
  // SPF21Y uses 16 bit words, while bitset uses 8 bit words. To use the same
  // bit numbers, we manually flip each even and odd byte.
  for (size_t i = 0; i < faultBits.size() / 16; i++) {
    uint16_t* word = reinterpret_cast<uint16_t*>(this);
    word += i;
    *word = folly::Endian::swap(*word);
  }
}
/* static */ FaultData FaultData::fromByteStream(std::string_view data) {
  if (sizeof(FaultData) != data.size()) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into FaultData of size {}",
        data.size(), sizeof(FaultData)));
  }

  FaultData result;
  std::memcpy(&result, data.data(), sizeof(FaultData));
  result.bigEndian();
  return result;
}
}  // namespace tas_powertek::spf21y