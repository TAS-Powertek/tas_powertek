#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include <string>

#include "../data/DailyData.h"

namespace tas_powertek::spf21y {

TEST(DailyDataTest, xlsCalculation) {
  // Based on the XLS sheet provided for EventData
  constexpr std::string_view kDailyData(
      "\x0d\x2f\x11\x0c\x04\x07\xe8\x43\x7c\x67\x5f\x43\x77\xb0\x25\x43\x7b\x0e"
      "\x73\x3e\x65\xf2\xac\x43\xd7\x76\xc3\x43\xd9\x98\xe4\x43\xd8\x79\x74\x3e"
      "\x65\xf2\xac\x44\x03\x8a\xaf\x44\x02\x37\x38\x44\x00\x0a\x80\x43\xbc\xd3"
      "\x76\x40\x66\xd5\xa3\x40\x74\x69\xbb\x40\x80\xfe\xea\x40\x74\x69\xbb\x44"
      "\x5e\xe0\xdc\x49\x38\x36\x41\x49\x36\x82\x22\x45\xc8\x28\xf2\x46\x56\x0c"
      "\xd9\x46\xa0\xef\x99\x43\x2b\x61\xc4\x47\x75\x8d\xcd\x47\xa1\x16\x55\x47"
      "\x9f\xa4\xe3\x43\x60\x81\xc7\x43\x9a\x09\xf1\x43\x2c\x92\xb3\x42\xda\xe2"
      "\x7e\x43\x3c\x3f\x9e\x43\x36\x57\x26\x43\x7f\xf4\x03\x43\xbd\x15\x12\x43"
      "\x57\x43\x7f\x42\x48\x11\xc8\x00\x00\x00\x00\x00\x00\x04\x7d\x00\x00\x00"
      "\x00\x00\x00\x2c\x19\x00\x00\x00\x00\x00\x00\x07\x13\x00\x00\x00\x00\x00"
      "\x00\x09\x58\x00\x00\x00\x00\x00\x00\x39\x07\x00\x00\x00\x00\x00\x00\x0a"
      "\x22\x00\x00\x02\x51\x00\x00\x02\x59\x00\x00\x02\x53\x00\x00\x02\x44\x00"
      "\x00\x02\x54\x00\x00\x02\x47\x00\x00\x02\x42\x00\x00\x00\x1f\x00\x00\x00"
      "\x1f\x00\x00\x00\x1f\x00\x00\x00\x1d\x00\x00\x00\x1b\x00\x00\x00\x1b\x00"
      "\x00\x00\x1d\x00\x00\x00\x1c\x00\x00\x00\x1d\x00\x00\x00\x40\x01\x01\x12"
      "\x12",
      271);
  DailyData dailyData = DailyData::fromByteStream(kDailyData);
  EXPECT_EQ(dailyData.time.sec, 13);
  EXPECT_EQ(dailyData.time.min, 47);
  EXPECT_EQ(dailyData.time.hour, 17);
  EXPECT_EQ(dailyData.time.day_of_month, 12);
  EXPECT_EQ(dailyData.time.month, 4);
  EXPECT_EQ(dailyData.time.year, 2024);

  EXPECT_NEAR(*dailyData.maxPhase1ToNeutralVoltage_RMS, 252.40, 0.01);
  EXPECT_NEAR(*dailyData.maxPhase2ToNeutralVoltage_RMS, 247.69, 0.01);
  EXPECT_NEAR(*dailyData.maxPhase3ToNeutralVoltage_RMS, 251.06, 0.01);
  EXPECT_NEAR(*dailyData.maxPhasesToNetralVoltage_THD, 0.22, 0.01);
  EXPECT_NEAR(*dailyData.maxPhase1ToPhase2Voltage_RMS, 430.93, 0.01);
  EXPECT_NEAR(*dailyData.maxPhase2ToPhase3Voltage_RMS, 435.19, 0.01);
  EXPECT_NEAR(*dailyData.maxPhase3ToPhase1Voltage_RMS, 432.95, 0.01);
  EXPECT_NEAR(*dailyData.maxPhaseToPhaseVoltage_THD, 0.22, 0.01);
  EXPECT_NEAR(*dailyData.maxPhase1Current_RMS, 526.17, 0.01);
  EXPECT_NEAR(*dailyData.maxPhase2Current_RMS, 520.86, 0.01);
  EXPECT_NEAR(*dailyData.maxPhase3Current_RMS, 512.16, 0.01);
  EXPECT_NEAR(*dailyData.maxNeutralCurrent_RMS, 377.65, 0.01);
  EXPECT_NEAR(*dailyData.maxPhase1Current_THD, 3.61, 0.01);
  EXPECT_NEAR(*dailyData.maxPhase2Current_THD, 3.82, 0.01);
  EXPECT_NEAR(*dailyData.maxPhase3Current_THD, 4.03, 0.01);
  EXPECT_NEAR(*dailyData.maxNeutralCurrent_THD, 3.82, 0.01);
  EXPECT_NEAR(*dailyData.maxCapacitorCurrent_THD, 891.51, 0.01);
  EXPECT_NEAR(*dailyData.maxDemandOverallVA, 754532.06, 0.01);
  EXPECT_NEAR(*dailyData.maxDemandOverallWatt, 747554.13, 0.01);

  EXPECT_NEAR(*dailyData.capacitorBank_VAR[0], 6405.12, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[1], 13699.21, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[2], 20599.80, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[3], 171.38, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[4], 62861.80, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[5], 82476.66, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[6], 81737.77, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[7], 224.51, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[8], 308.08, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[9], 172.57, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[10], 109.44, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[11], 188.25, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[12], 182.34, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[13], 255.95, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[14], 378.16, 0.01);
  EXPECT_NEAR(*dailyData.capacitorBank_VAR[15], 215.26, 0.01);

  EXPECT_NEAR(*dailyData.maxExternalTempPT100, 50.02, 0.01);
  EXPECT_EQ(*dailyData.overallActiveEnergyGeneration_Negative, 1149);
  EXPECT_EQ(*dailyData.overallActiveEnergyConsumption_Positive, 11289);
  EXPECT_EQ(*dailyData.overallReactiveEnergyImport_Negative, 1811);
  EXPECT_EQ(*dailyData.overallReactiveEnergyExport_Positive, 2392);
  EXPECT_EQ(*dailyData.overallApparentEnergy, 14599);
  EXPECT_EQ(*dailyData.capacitorReactiveFundamentalEnergyExported, 2594);

  EXPECT_EQ(dailyData.capacitorUtilizationCounters[0], 593);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[1], 601);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[2], 595);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[3], 580);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[4], 596);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[5], 583);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[6], 578);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[7], 31);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[8], 31);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[9], 31);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[10], 29);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[11], 27);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[12], 27);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[13], 29);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[14], 28);
  EXPECT_EQ(dailyData.capacitorUtilizationCounters[15], 29);

  EXPECT_EQ(dailyData.numPowerInterruptions, 64);
  EXPECT_EQ(*dailyData.maxPhasesToNetralVoltage_THDPercent, 1);
  EXPECT_EQ(*dailyData.maxPhaseToPhaseVoltage_THDPercent, 1);
  EXPECT_EQ(*dailyData.maxPhaseCurrent_TDDPercent, 18);
  EXPECT_EQ(*dailyData.maxCapacitorPhaseCurrent_TDDPercent, 18);
}
}  // namespace tas_powertek::spf21y
