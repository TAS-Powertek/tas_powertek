#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include "../data/TimeData.h"

namespace tas_powertek::spf21y {

TEST(TimeDataTest, xlsCalculation) {
  // Based on the XLS sheet provided
  constexpr std::string_view Interval512{"\x19\x19\x11\x0c\x04\x07\xe8", 7};
  EXPECT_EQ(TimeData::fromByteStream(Interval512).toTimePoint(),
            std::chrono::sys_seconds(std::chrono::seconds(1712922925)));
  constexpr std::string_view Interval256{"\x35\x00\x12\x0c\x04\x07\xe8", 7};
  EXPECT_EQ(TimeData::fromByteStream(Interval256).toTimePoint(),
            std::chrono::sys_seconds(std::chrono::seconds(1712925053)));
}
}  // namespace tas_powertek::spf21y