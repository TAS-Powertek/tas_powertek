#pragma once

#include <folly/Portability.h>

#include <chrono>
#include <cstdint>

namespace tas_powertek::spf21y {

struct AuxFnData {
  uint16_t inputVoltage;
  uint8_t gprsSignalStrength;
  uint8_t statusInt;

  [[nodiscard]] bool output1() const { return statusInt & 0x01; }
  [[nodiscard]] bool output2() const { return statusInt & 0x02; }
  [[nodiscard]] bool output3() const { return statusInt & 0x04; }
  [[nodiscard]] bool input() const { return statusInt & 0x08; }

  void bigEndian();
  static AuxFnData fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;
static_assert(sizeof(AuxFnData) == 4);
static_assert(std::is_standard_layout_v<AuxFnData>);
};  // namespace tas_powertek::spf21y