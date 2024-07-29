#pragma once

#include <folly/Portability.h>

#include <chrono>
#include <cstdint>

namespace tas_powertek::spf21y {

struct TimeData {
  uint8_t sec;
  uint8_t min;
  uint8_t hour;
  uint8_t day_of_month;  // aka "date"
  uint8_t month;
  uint16_t year;

  std::chrono::sys_seconds toTimePoint() const;
  void bigEndian();  // converts from native to big endian (or vice versa)

  static TimeData fromByteStream(std::string_view data);
  static TimeData fromSysTime(std::chrono::sys_seconds sysTime);
} FOLLY_PACK_ATTR;

static_assert(sizeof(TimeData) == 7);
static_assert(std::is_standard_layout_v<TimeData>);
}  // namespace tas_powertek::spf21y