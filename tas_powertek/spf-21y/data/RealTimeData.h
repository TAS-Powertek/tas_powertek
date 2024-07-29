#pragma once

#include "IntervalData128.h"
#include "IntervalData256.h"
#include "IntervalData512.h"
#include "IntervalData64.h"

namespace tas_powertek::spf21y {

struct RealTimeData64 : public IntervalData64 {
  static RealTimeData64 fromByteStream(std::string_view data);
};
struct RealTimeData128 : public IntervalData128 {
  static RealTimeData128 fromByteStream(std::string_view data);
};
struct RealTimeData256 : public IntervalData256 {
  static RealTimeData256 fromByteStream(std::string_view data);
};
struct RealTimeData512 : public IntervalData512 {
  static RealTimeData512 fromByteStream(std::string_view data);
};

static_assert(sizeof(RealTimeData64) == sizeof(IntervalData64));
static_assert(std::is_standard_layout_v<RealTimeData64>);
static_assert(sizeof(RealTimeData128) == sizeof(IntervalData128));
static_assert(std::is_standard_layout_v<RealTimeData128>);
static_assert(sizeof(RealTimeData256) == sizeof(IntervalData256));
static_assert(std::is_standard_layout_v<RealTimeData256>);
static_assert(sizeof(RealTimeData512) == sizeof(IntervalData512));
static_assert(std::is_standard_layout_v<RealTimeData512>);
/*
RT is "Real Time" data
RT data is sent exactly like IN data by SPF-21Y.

The frame structure is exactly as per IN data setting.

Only differences are.
1.⁠ ⁠Is sent much faster. User setting are 4 rec/min (15 seconds), 2 rec/
min (30 seconds), 1 rec/min (60 seconds) 2.⁠ ⁠There is no acknowledgement
needed from server. 3.⁠ ⁠It's an instantaneous data (not stored in SPF-21Y)
that is sent in interval record frame format. 4.⁠ ⁠In the frame header, IN
is replaced by RT.
*/
}  // namespace tas_powertek::spf21y