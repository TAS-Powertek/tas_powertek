#pragma once

#include <folly/Portability.h>

#include <chrono>
#include <cstdint>

#include "AuxFnData.h"
#include "BankStatusData.h"
#include "FaultData.h"
#include "TimeData.h"

namespace tas_powertek::spf21y {

static_assert(sizeof(float) == 4);
struct IntervalData512 {
  TimeData time;
  float supplyFrequency;
  float phase1ToNeutralVoltage_RMS;
  float phase2ToNeutralVoltage_RMS;
  float phase3ToNeutralVoltage_RMS;
  float phase1ToNeutralVoltage_Fundamental;
  float phase2ToNeutralVoltage_Fundamental;
  float phase3ToNeutralVoltage_Fundamental;
  float phase1ToNeutralVoltage_THD;
  float phase2ToNeutralVoltage_THD;
  float phase3ToNeutralVoltage_THD;
  uint8_t phase1Voltage_NeutralTHDPercent;
  uint8_t phase2Voltage_NeutralTHDPercent;
  uint8_t phase3Voltage_NeutralTHDPercent;
  float phase1ToPhase2Voltage_RMS;
  float phase2ToPhase3Voltage_RMS;
  float phase3ToPhase1Voltage_RMS;
  float phase1ToPhase2Voltage_Fundamental;
  float phase2ToPhase3Voltage_Fundamental;
  float phase3ToPhase1Voltage_Fundamental;
  float phase1ToPhase2Voltage_THD;
  float phase2ToPhase3Voltage_THD;
  float phase3ToPhase1Voltage_THD;
  uint8_t phase1ToPhase2Voltage_THDPercent;
  uint8_t phase2ToPhase3Voltage_THDPercent;
  uint8_t phase3ToPhase1Voltage_THDPercent;
  float phase1Current_RMS;
  float phase2Current_RMS;
  float phase3Current_RMS;
  float neutralCurrent_RMS;
  float neutralCurrent_Fundamental;
  float phase1Current_Fundamental;
  std::array<float, 30> _phase1Current_Harmonics;  // Index 0 == 2nd harmonic.
  float phase2Current_Fundamental;
  std::array<float, 30> _phase2Current_Harmonics;  // Index 0 == 2nd harmonic.
  float phase3Current_Fundamental;
  std::array<float, 30> _phase3Current_Harmonics;  // Index 0 == 2nd harmonic.
  float phase1Current_THD;
  float phase2Current_THD;
  float phase3Current_THD;
  float neutralCurrent_THD;
  float averageCurrent_THD;
  float overall3PhActivePower_Combined;
  float overall3PhReactivePower_Combined;
  float overall3PhApparentPower_Combined;
  float overall3PhActivePower_Fundamental;
  float overall3PhReactivePower_Fundamental;
  float overall3PhApparentPower_Fundamental;
  float overall3PhDistortionPower_IEC_IEEE;
  float overall3PhDistortionPower_CrossDistortion;
  float phase1ActivePower_Combined;
  float phase2ActivePower_Combined;
  float phase3ActivePower_Combined;
  float phase1ReactivePower_Combined;
  float phase2ReactivePower_Combined;
  float phase3ReactivePower_Combined;
  float phase1ApparentPower_Combined;
  float phase2ApparentPower_Combined;
  float phase3ApparentPower_Combined;
  float phase1ActivePower_Fundamental;
  float phase2ActivePower_Fundamental;
  float phase3ActivePower_Fundamental;
  float phase1ReactivePower_Fundamental;
  float phase2ReactivePower_Fundamental;
  float phase3ReactivePower_Fundamental;
  float phase1ApparentPower_Fundamental;
  float phase2ApparentPower_Fundamental;
  float phase3ApparentPower_Fundamental;
  float powerFactor_OverallThreePhase;
  float powerFactor_Fundamental_OverallThreePhase;
  float phase1PowerFactor;
  float phase2PowerFactor;
  float phase3PowerFactor;
  float phase1PowerFactor_Fundamental;
  float phase2PowerFactor_Fundamental;
  float phase3PowerFactor_Fundamental;
  float phase1DistortionPower_IEC_IEEE;
  float phase2DistortionPower_IEC_IEEE;
  float phase3DistortionPower_IEC_IEEE;
  float phase1DistortionPower_CrossDistortion;
  float phase2DistortionPower_CrossDistortion;
  float phase3DistortionPower_CrossDistortion;
  float phase1LoadReactivePower_Fundamental;
  float phase2LoadReactivePower_Fundamental;
  float phase3LoadReactivePower_Fundamental;
  float overallLoadReactivePower_Fundamental;
  uint8_t phase1Current_THDPercent;
  uint8_t phase2Current_THDPercent;
  uint8_t phase3Current_THDPercent;
  uint8_t neutralCurrent_THDPercent;
  uint8_t phase1Current_TDDPercent;
  uint8_t phase2Current_TDDPercent;
  uint8_t phase3Current_TDDPercent;
  uint8_t capacitorPhase1Current_THDPercent;
  uint8_t capacitorPhase2Current_THDPercent;
  uint8_t capacitorPhase3Current_THDPercent;
  float capacitorPhase1Current_RMS;
  float capacitorPhase2Current_RMS;
  float capacitorPhase3Current_RMS;
  float capacitorEarthFaultCurrent_RMS;
  float capacitorPhase1Current_Fundamental;
  float capacitorPhase2Current_Fundamental;
  float capacitorPhase3Current_Fundamental;
  float capacitorPhase1Current_THD;
  float capacitorPhase2Current_THD;
  float capacitorPhase3Current_THD;
  float averageCapacitorCurrent_THD;
  float capacitorPhase1InjectedReactivePower_Fundamental;
  float capacitorPhase2InjectedReactivePower_Fundamental;
  float capacitorPhase3InjectedReactivePower_Fundamental;
  float capacitorOverallInjectedReactivePower_Fundamental;
  BankStatusData bankStatus;
  FaultData faultData;
  AuxFnData auxFnData;

  float phase1Current_Harmonics(size_t harmonic);
  float phase2Current_Harmonics(size_t harmonic);
  float phase3Current_Harmonics(size_t harmonic);
  void bigEndian();
  static IntervalData512 fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;

static_assert(sizeof(IntervalData512) == 775);
static_assert(std::is_standard_layout_v<IntervalData512>);
}  // namespace tas_powertek::spf21y