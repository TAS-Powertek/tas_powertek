#include "RealTimeData.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>

#include <cstring>

namespace tas_powertek::spf21y {
/* static */ RealTimeData64 RealTimeData64::fromByteStream(
    std::string_view data) {
  IntervalData64 intervalData = IntervalData64::fromByteStream(data);
  RealTimeData64& casted = reinterpret_cast<RealTimeData64&>(intervalData);
  return casted;
}

/* static */ RealTimeData128 RealTimeData128::fromByteStream(
    std::string_view data) {
  IntervalData128 intervalData = IntervalData128::fromByteStream(data);
  RealTimeData128& casted = reinterpret_cast<RealTimeData128&>(intervalData);
  return casted;
}

/* static */ RealTimeData256 RealTimeData256::fromByteStream(
    std::string_view data) {
  IntervalData256 intervalData = IntervalData256::fromByteStream(data);
  RealTimeData256& casted = reinterpret_cast<RealTimeData256&>(intervalData);
  return casted;
}

/* static */ RealTimeData512 RealTimeData512::fromByteStream(
    std::string_view data) {
  IntervalData512 intervalData = IntervalData512::fromByteStream(data);
  RealTimeData512& casted = reinterpret_cast<RealTimeData512&>(intervalData);
  return casted;
}
}  // namespace tas_powertek::spf21y