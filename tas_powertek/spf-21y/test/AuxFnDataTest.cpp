#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include <string>

#include "../data/AuxFnData.h"

namespace tas_powertek::spf21y {

TEST(AuxFnDataTest, xlsCalculation) {
  // Based on the XLS sheet provided for EventData
  constexpr std::string_view kInterval512Data("\x00\x00\x12\x00", 4);
  AuxFnData auxData = AuxFnData::fromByteStream(kInterval512Data);
  EXPECT_EQ(auxData.inputVoltage, 0);
  EXPECT_EQ(auxData.gprsSignalStrength, 18);
  EXPECT_FALSE(auxData.output1());
  EXPECT_FALSE(auxData.output2());
  EXPECT_FALSE(auxData.output3());
  EXPECT_FALSE(auxData.input());
}
}  // namespace tas_powertek::spf21y
