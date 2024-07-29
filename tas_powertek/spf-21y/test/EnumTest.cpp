#include <gtest/gtest.h>

#include "../Enums.h"

namespace tas_powertek::spf21y {

TEST(EnumTest, toString) {
  EXPECT_EQ("Event/Fault", toString(DataType::EVENT));
  EXPECT_EQ("Interval 64", toString(DataType::INTERVAL_64));
  EXPECT_EQ("Interval 128", toString(DataType::INTERVAL_128));
  EXPECT_EQ("Interval 256", toString(DataType::INTERVAL_256));
  EXPECT_EQ("Interval 512", toString(DataType::INTERVAL_512));
  EXPECT_EQ("Daily", toString(DataType::DAILY));
  EXPECT_EQ("User Settings", toString(DataType::USER_SETTINGS));
  EXPECT_EQ("Real Time 64", toString(DataType::REAL_TIME_64));
  EXPECT_EQ("Real Time 128", toString(DataType::REAL_TIME_128));
  EXPECT_EQ("Real Time 256", toString(DataType::REAL_TIME_256));
  EXPECT_EQ("Real Time 512", toString(DataType::REAL_TIME_512));
}
}  // namespace tas_powertek::spf21y