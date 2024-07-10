#include "BankStatusData.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>
#include <folly/logging/xlog.h>

#include <cstring>

namespace tas_powertek::spf21y {

uint8_t BankStatusData::status(uint8_t index) const {
  if (index == 0 || index > statusData.size() * 2) {
    throw std::logic_error(fmt::format(
        "Cannot access bank status {:d}. The smallest bank is 1 and "
        "the largest is {:d}",
        index, statusData.size() * 2));
  }
  index--;
  const BankStatusTuple& tuple = statusData[index / 2];
  // Bit fields have different behaviors for big vs little endian:
  // http://mjfrazer.org/mjfrazer/bitfields/
  if (folly::kIsLittleEndian != (index % 2 == 0)) {
    return tuple.first;
  }
  return tuple.second;
}

/* static */ BankStatusData BankStatusData::fromByteStream(
    std::string_view data) {
  if (data.size() != sizeof(BankStatusData)) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into BankStatus of size {}",
        data.size(), sizeof(BankStatusData)));
  }

  BankStatusData result;
  std::memcpy(&result, data.data(), sizeof(BankStatusData));
  return result;
}
}  // namespace tas_powertek::spf21y