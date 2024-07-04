#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include "../detail/CheckSum.h"

namespace tas_powertek::spf21y::detail {

TEST(CheckSumTest, xlsCalculation) {
  CheckSum16 checksum = CheckSum16::compute("\x74\x61\x73\x20\x31\x32\x35");
  EXPECT_EQ(checksum.underlying(), uint16_t(0xFE00));
  EXPECT_TRUE(checksum.verify("\x74\x61\x73\x20\x31\x32\x35"));
}
}  // namespace tas_powertek::spf21y::detail