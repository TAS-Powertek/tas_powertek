#pragma once

#include <folly/Portability.h>

#include <array>
#include <chrono>
#include <cstdint>
#include <string_view>

namespace tas_powertek::spf21y {

struct BankStatusTuple {
  uint8_t first : 4;
  uint8_t second : 4;
} FOLLY_PACK_ATTR;
static_assert(sizeof(BankStatusTuple) == 1);
struct BankStatusData {
  std::array<BankStatusTuple, 8> statusData;

  /**
   * Gets the status of the bank `index`
   * Note: index is 1-based index (in accordance with docs)
   */
  [[nodiscard]] uint8_t status(uint8_t index) const;
  [[nodiscard]] uint8_t operator[](uint8_t index) const {
    return status(index);
  }

  void bigEndian() { /* noop */ }
  static BankStatusData fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;
static_assert(sizeof(BankStatusData) == 8);
static_assert(std::is_standard_layout_v<BankStatusData>);
};  // namespace tas_powertek::spf21y