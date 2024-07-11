#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include <string>

#include "../data/IntervalData64.h"

namespace tas_powertek::spf21y {

TEST(IntervalData64Test, xlsCalculation) {
  // Based on the XLS sheet provided for EventData
  constexpr std::string_view kInterval64Data(
      "\x30\x35\x0a\x12\x04\x07\xe8\x42\x48\x2c\xb2\x43\x6f\xd4\x1a\x43\x6f\xd4"
      "\x1a\x3f\xc9\x34\x57\x43\xcf\x9a\xb8\x43\xcf\x9a\xb8\x44\x00\x25\xa8\x43"
      "\x4a\x9d\xdf\x48\xa5\x8a\xe7\x45\xac\x4e\x78\x3f\x7f\xbe\x77\x43\xb6\x76"
      "\x0b\x43\xae\xb7\x95\x43\xb6\x5a\xe3\x44\x28\x08\xb1\x43\x91\xc1\xb8\x43"
      "\x8e\xc9\x53\x43\x96\xa2\xf1\x43\x4f\xeb\xb9\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x11\x00",
      95);
  IntervalData64 intervalData = IntervalData64::fromByteStream(kInterval64Data);
  EXPECT_EQ(intervalData.time.sec, 48);
  EXPECT_EQ(intervalData.time.min, 53);
  EXPECT_EQ(intervalData.time.hour, 10);
  EXPECT_EQ(intervalData.time.day_of_month, 18);
  EXPECT_EQ(intervalData.time.month, 4);
  EXPECT_EQ(intervalData.time.year, 2024);

  EXPECT_NEAR(*intervalData.supplyFrequency, 50.04, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseToNeutralVolage_RMS, 239.83, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseToNeutralVoltage_Fundamental, 239.83,
              0.01);
  EXPECT_NEAR(*intervalData.averagePhaseToNeutralVolage_THD, 1.58, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseToPhaseVoltage_RMS, 415.21, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseToPhaseVoltage_Fundamental, 415.21,
              0.01);
  EXPECT_NEAR(*intervalData.averagePhaseCurrent_RMS, 512.59, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseCurrent_THD, 202.62, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhActivePower_Fundamental, 339031.22, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhReactivePower_Fundamental, 5513.81, 0.01);
  EXPECT_NEAR(*intervalData.powerFactor_Fundamental_OverallThreePhase, 0.999,
              0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase1Current_RMS, 364.92, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2Current_RMS, 349.43, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3Current_RMS, 364.71, 0.01);
  EXPECT_NEAR(*intervalData.capacitorEarthFaultCurrent_RMS, 672.14, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase1Current_Fundamental, 291.51, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2Current_Fundamental, 285.57, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3Current_Fundamental, 301.27, 0.01);
  EXPECT_NEAR(*intervalData.capacitorAverageCurrent_THD, 207.92, 0.01);

  EXPECT_FALSE(intervalData.faultData.OVR());
  EXPECT_FALSE(intervalData.faultData.UVR());
  EXPECT_FALSE(intervalData.faultData.OVY());
  EXPECT_FALSE(intervalData.faultData.UVY());
  EXPECT_FALSE(intervalData.faultData.OVB());
  EXPECT_FALSE(intervalData.faultData.UVB());
  EXPECT_FALSE(intervalData.faultData.OCR());
  EXPECT_FALSE(intervalData.faultData.ULR());
  EXPECT_FALSE(intervalData.faultData.OCY());
  EXPECT_FALSE(intervalData.faultData.ULY());
  EXPECT_FALSE(intervalData.faultData.OCB());
  EXPECT_FALSE(intervalData.faultData.ULB());
  EXPECT_FALSE(intervalData.faultData.COR());
  EXPECT_FALSE(intervalData.faultData.CUR());
  EXPECT_FALSE(intervalData.faultData.COY());
  EXPECT_FALSE(intervalData.faultData.CUY());
  EXPECT_FALSE(intervalData.faultData.COB());
  EXPECT_FALSE(intervalData.faultData.CUB());
  EXPECT_FALSE(intervalData.faultData.SOF());
  EXPECT_FALSE(intervalData.faultData.SUF());
  EXPECT_FALSE(intervalData.faultData.MOT());
  EXPECT_FALSE(intervalData.faultData.ChR());
  EXPECT_FALSE(intervalData.faultData.ChY());
  EXPECT_FALSE(intervalData.faultData.ChB());
  EXPECT_FALSE(intervalData.faultData.OBF());
  EXPECT_FALSE(intervalData.faultData.UBA());
  EXPECT_FALSE(intervalData.faultData.OCN());
  EXPECT_FALSE(intervalData.faultData.EOT());
  EXPECT_FALSE(intervalData.faultData.PDN());
  EXPECT_FALSE(intervalData.faultData.PUP());
  EXPECT_FALSE(intervalData.faultData.RTC());
  EXPECT_FALSE(intervalData.faultData.NVF());
  EXPECT_FALSE(intervalData.faultData.ZCF());
  EXPECT_FALSE(intervalData.faultData.ZVF());
  EXPECT_FALSE(intervalData.faultData.MDW());
  EXPECT_FALSE(intervalData.faultData.MDV());
  EXPECT_FALSE(intervalData.faultData.UBV());
  EXPECT_FALSE(intervalData.faultData.UBC());
  EXPECT_FALSE(intervalData.faultData.__na_1_());
  EXPECT_FALSE(intervalData.faultData.CEL());
  EXPECT_FALSE(intervalData.faultData.VHF());
  EXPECT_FALSE(intervalData.faultData.CHF());
  EXPECT_FALSE(intervalData.faultData.PFR());
  EXPECT_FALSE(intervalData.faultData.PFY());
  EXPECT_FALSE(intervalData.faultData.PFB());
  EXPECT_FALSE(intervalData.faultData.AVL());
  EXPECT_FALSE(intervalData.faultData.AVH());
  EXPECT_FALSE(intervalData.faultData.CBF());
  EXPECT_FALSE(intervalData.faultData.SyF());
  EXPECT_FALSE(intervalData.faultData.CTM());
  EXPECT_FALSE(intervalData.faultData.ERU());
  EXPECT_FALSE(intervalData.faultData.EWU());
  EXPECT_FALSE(intervalData.faultData.RM1());
  EXPECT_FALSE(intervalData.faultData.RM2());
  EXPECT_FALSE(intervalData.faultData.DSB());
  EXPECT_FALSE(intervalData.faultData.HLD());
  EXPECT_FALSE(intervalData.faultData.AMG());
  EXPECT_FALSE(intervalData.faultData.WDR());
  EXPECT_FALSE(intervalData.faultData.SyA());
  EXPECT_FALSE(intervalData.faultData.SyP());
  EXPECT_FALSE(intervalData.faultData.ASM());
  EXPECT_FALSE(intervalData.faultData.PEM());
  EXPECT_FALSE(intervalData.faultData._EOF());
  EXPECT_FALSE(intervalData.faultData._4GN());

  EXPECT_EQ(intervalData.auxFnData.inputVoltage, 0);
  EXPECT_EQ(intervalData.auxFnData.gprsSignalStrength, 17);
  EXPECT_FALSE(intervalData.auxFnData.output1());
  EXPECT_FALSE(intervalData.auxFnData.output2());
  EXPECT_FALSE(intervalData.auxFnData.output3());
  EXPECT_FALSE(intervalData.auxFnData.input());
}
}  // namespace tas_powertek::spf21y
