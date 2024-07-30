#include "FaultData.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>

#include <cstring>

namespace tas_powertek::spf21y {
namespace {

uint64_t bigEndianWordwise(uint64_t current) {
  // SPF21Y uses 16 bit words, while bitset uses 8 bit words. To use the same
  // bit numbers, we manually flip each even and odd byte.
  for (size_t i = 0; i < sizeof(current) / 2; i++) {
    uint16_t* word = reinterpret_cast<uint16_t*>(&current);
    word += i;
    *word = folly::Endian::swap(*word);
  }
  return current;
}
}  // namespace

void FaultDataLow::bigEndian() { bits = bigEndianWordwise(bits); }
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

void FaultDataHigh::bigEndian() { bits = bigEndianWordwise(bits); }
/* static */ FaultDataHigh FaultDataHigh::fromByteStream(
    std::string_view data) {
  if (sizeof(FaultDataHigh) != data.size()) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into FaultDataHigh of size {}",
        data.size(), sizeof(FaultDataHigh)));
  }

  FaultDataHigh result;
  std::memcpy(&result, data.data(), sizeof(FaultDataHigh));
  result.bigEndian();
  return result;
}

void FaultData::bigEndian() {
  low.bigEndian();
  high.bigEndian();
}
/* static */ FaultData FaultData::fromByteStream(std::string_view data) {
  FaultData result;
  result.low =
      FaultDataLow::fromByteStream(data.substr(0, sizeof(FaultDataLow)));
  result.high = FaultDataHigh::fromByteStream(
      data.substr(sizeof(FaultDataLow), sizeof(FaultDataHigh)));
  return result;
}
}  // namespace tas_powertek::spf21y