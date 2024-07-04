#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include "../Record.h"

namespace tas_powertek::spf21y {

TEST(RecordTest, toString) {
  EXPECT_EQ("Fault/Event", toString(DataType::FAULT));
  EXPECT_EQ("Interval", toString(DataType::INTERVAL));
  EXPECT_EQ("Daily", toString(DataType::DAILY));
  EXPECT_EQ("User Settings", toString(DataType::USER_SETTINGS));
  EXPECT_EQ("Real Time", toString(DataType::REAL_TIME));
}
}  // namespace tas_powertek::spf21y