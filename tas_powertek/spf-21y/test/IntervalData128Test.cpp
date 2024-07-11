#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include <string>

#include "../data/IntervalData128.h"

namespace tas_powertek::spf21y {

TEST(IntervalData128Test, xlsCalculation) {
  // Based on the XLS sheet provided for EventData
  constexpr std::string_view kInterval128Data(
      "\x0a\x0f\x12\x0c\x04\x07\xe8\x42\x48\x11\xc8\x43\x7b\x81\x6d\x43\x79\x7c"
      "\x0b\x43\x7b\x47\xf0\x43\x7a\x9b\x7a\x3f\xe5\xf2\xac\x43\xd8\xec\x6e\x43"
      "\xd9\x09\x2c\x43\xff\x20\x97\x44\x00\x4e\x65\x43\xfa\x90\xd6\x43\xae\x4a"
      "\xf4\x43\xed\x84\x87\x43\x34\x8d\x37\x43\x81\x6b\x8b\x43\x81\xa1\xdb\x43"
      "\x85\xc4\xfb\x43\x93\x59\x13\x43\x37\x4f\x4c\x43\x38\x5e\xde\x43\x3b\xc3"
      "\xe4\x43\x36\x76\x0b\x43\x35\xd3\x1a\x43\x3e\x4f\xa9\x63\x62\x65\x3f\x6a"
      "\x89\xd5\x3f\x7a\x71\x4e\x48\xba\xc9\xce\x48\xaa\xc5\xb5\x45\xc5\xcc\x6b"
      "\x48\xae\x8f\xd1\x44\x80\x63\x35\x47\xe8\x79\x91\x47\xe7\xa2\x84\x47\xda"
      "\xfa\xb9\x46\x93\xae\x44\x46\x9b\x6d\x91\xc6\xfd\xa8\xba\x48\x07\xfc\x06"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x14\x00",
      174);
  IntervalData128 intervalData =
      IntervalData128::fromByteStream(kInterval128Data);
  EXPECT_EQ(intervalData.time.sec, 10);
  EXPECT_EQ(intervalData.time.min, 15);
  EXPECT_EQ(intervalData.time.hour, 18);
  EXPECT_EQ(intervalData.time.day_of_month, 12);
  EXPECT_EQ(intervalData.time.month, 4);
  EXPECT_EQ(intervalData.time.year, 2024);

  EXPECT_NEAR(*intervalData.supplyFrequency, 50.02, 0.01);
  EXPECT_NEAR(*intervalData.phase1ToNeutralVoltage_RMS, 251.51, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToNeutralVoltage_RMS, 249.49, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToNeutralVoltage_RMS, 251.28, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseToNeutralVoltage_Fundamental, 250.61,
              0.01);
  EXPECT_NEAR(*intervalData.averagePhaseToNeutralVolage_THD, 1.80, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseToPhaseVoltage_RMS, 433.85, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseToPhaseVoltage_Fundamental, 434.07,
              0.01);
  EXPECT_NEAR(*intervalData.phase1Current_RMS, 510.25, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_RMS, 513.22, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_RMS, 501.13, 0.01);
  EXPECT_NEAR(*intervalData.neutralCurrent_RMS, 348.59, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseCurrent_Fundamental, 475.04, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseCurrent_THD, 180.55, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase1Current_RMS, 258.84, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2Current_RMS, 259.26, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3Current_RMS, 267.54, 0.01);
  EXPECT_NEAR(*intervalData.capacitorEarthFaultCurrent_RMS, 294.70, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase1Current_Fundamental, 183.31, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2Current_Fundamental, 184.37, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3Current_Fundamental, 187.77, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase1Current_THD, 182.46, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2Current_THD, 181.82, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3Current_THD, 190.31, 0.01);
  EXPECT_EQ(*intervalData.capacitorPhase1Current_THDPercent, 99);
  EXPECT_EQ(*intervalData.capacitorPhase2Current_THDPercent, 98);
  EXPECT_EQ(*intervalData.capacitorPhase3Current_THDPercent, 101);
  EXPECT_NEAR(*intervalData.powerFactor_OverallThreePhase, 0.916, 0.01);
  EXPECT_NEAR(*intervalData.powerFactor_Fundamental_OverallThreePhase, 0.978,
              0.01);
  EXPECT_NEAR(*intervalData.overall3PhApparentPower_Combined, 382542.44, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhActivePower_Fundamental, 349741.66, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhReactivePower_Fundamental, 6329.55, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhApparentPower_Fundamental, 357502.53,
              0.01);
  EXPECT_NEAR(*intervalData.overall3PhDistortionPower_IEC_IEEE, 1027.10, 0.01);
  EXPECT_NEAR(*intervalData.phase1ActivePower_Fundamental, 119027.13, 0.01);
  EXPECT_NEAR(*intervalData.phase2ActivePower_Fundamental, 118597.03, 0.01);
  EXPECT_NEAR(*intervalData.phase3ActivePower_Fundamental, 112117.45, 0.01);
  EXPECT_NEAR(*intervalData.phase1ReactivePower_Fundamental, 18903.13, 0.01);
  EXPECT_NEAR(*intervalData.phase2ReactivePower_Fundamental, 19894.78, 0.01);
  EXPECT_NEAR(*intervalData.phase3ReactivePower_Fundamental, -32468.36, 0.01);
  EXPECT_NEAR(*intervalData.capacitorOverallInjectedReactivePower_Fundamental,
              139248.09, 0.01);

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
  EXPECT_EQ(intervalData.auxFnData.gprsSignalStrength, 20);
  EXPECT_FALSE(intervalData.auxFnData.output1());
  EXPECT_FALSE(intervalData.auxFnData.output2());
  EXPECT_FALSE(intervalData.auxFnData.output3());
  EXPECT_FALSE(intervalData.auxFnData.input());
}
}  // namespace tas_powertek::spf21y
