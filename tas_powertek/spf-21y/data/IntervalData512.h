#pragma once

#include <folly/Portability.h>

#include <chrono>
#include <cstdint>

#include "AuxFnData.h"
#include "BankStatusData.h"
#include "FaultData.h"
#include "StrongType.h"
#include "TimeData.h"

namespace tas_powertek::spf21y {

struct IntervalData512 {
  TimeData time;
  hertz supplyFrequency;
  volt phase1ToNeutralVoltage_RMS;
  volt phase2ToNeutralVoltage_RMS;
  volt phase3ToNeutralVoltage_RMS;
  volt phase1ToNeutralVoltage_Fundamental;
  volt phase2ToNeutralVoltage_Fundamental;
  volt phase3ToNeutralVoltage_Fundamental;
  volt phase1ToNeutralVoltage_THD;
  volt phase2ToNeutralVoltage_THD;
  volt phase3ToNeutralVoltage_THD;
  percent phase1ToNeutralVoltage_THDPercent;
  percent phase2ToNeutralVoltage_THDPercent;
  percent phase3ToNeutralVoltage_THDPercent;
  volt phase1ToPhase2Voltage_RMS;
  volt phase2ToPhase3Voltage_RMS;
  volt phase3ToPhase1Voltage_RMS;
  volt phase1ToPhase2Voltage_Fundamental;
  volt phase2ToPhase3Voltage_Fundamental;
  volt phase3ToPhase1Voltage_Fundamental;
  volt phase1ToPhase2Voltage_THD;
  volt phase2ToPhase3Voltage_THD;
  volt phase3ToPhase1Voltage_THD;
  percent phase1ToPhase2Voltage_THDPercent;
  percent phase2ToPhase3Voltage_THDPercent;
  percent phase3ToPhase1Voltage_THDPercent;
  amp phase1Current_RMS;
  amp phase2Current_RMS;
  amp phase3Current_RMS;
  amp neutralCurrent_RMS;
  amp neutralCurrent_Fundamental;
  amp phase1Current_Fundamental;
  std::array<amp, 30> _phase1Current_Harmonics;  // Index 0 == 2nd harmonic.
  amp phase2Current_Fundamental;
  std::array<amp, 30> _phase2Current_Harmonics;  // Index 0 == 2nd harmonic.
  amp phase3Current_Fundamental;
  std::array<amp, 30> _phase3Current_Harmonics;  // Index 0 == 2nd harmonic.
  amp phase1Current_THD;
  amp phase2Current_THD;
  amp phase3Current_THD;
  amp neutralCurrent_THD;
  amp averageCurrent_THD;
  watt overall3PhActivePower_Combined;
  var overall3PhReactivePower_Combined;
  va overall3PhApparentPower_Combined;
  watt overall3PhActivePower_Fundamental;
  var overall3PhReactivePower_Fundamental;
  va overall3PhApparentPower_Fundamental;
  va overall3PhDistortionPower_IEC_IEEE;
  va overall3PhDistortionPower_CrossDistortion;
  watt phase1ActivePower_Combined;
  watt phase2ActivePower_Combined;
  watt phase3ActivePower_Combined;
  var phase1ReactivePower_Combined;
  var phase2ReactivePower_Combined;
  var phase3ReactivePower_Combined;
  va phase1ApparentPower_Combined;
  va phase2ApparentPower_Combined;
  va phase3ApparentPower_Combined;
  watt phase1ActivePower_Fundamental;
  watt phase2ActivePower_Fundamental;
  watt phase3ActivePower_Fundamental;
  var phase1ReactivePower_Fundamental;
  var phase2ReactivePower_Fundamental;
  var phase3ReactivePower_Fundamental;
  va phase1ApparentPower_Fundamental;
  va phase2ApparentPower_Fundamental;
  va phase3ApparentPower_Fundamental;
  pf powerFactor_OverallThreePhase;
  dpf powerFactor_Fundamental_OverallThreePhase;
  pf phase1PowerFactor;
  pf phase2PowerFactor;
  pf phase3PowerFactor;
  dpf phase1PowerFactor_Fundamental;
  dpf phase2PowerFactor_Fundamental;
  dpf phase3PowerFactor_Fundamental;
  va phase1DistortionPower_IEC_IEEE;
  va phase2DistortionPower_IEC_IEEE;
  va phase3DistortionPower_IEC_IEEE;
  va phase1DistortionPower_CrossDistortion;
  va phase2DistortionPower_CrossDistortion;
  va phase3DistortionPower_CrossDistortion;
  var phase1LoadReactivePower_Fundamental;
  var phase2LoadReactivePower_Fundamental;
  var phase3LoadReactivePower_Fundamental;
  var overallLoadReactivePower_Fundamental;
  percent phase1Current_THDPercent;
  percent phase2Current_THDPercent;
  percent phase3Current_THDPercent;
  percent neutralCurrent_THDPercent;
  percent phase1Current_TDDPercent;
  percent phase2Current_TDDPercent;
  percent phase3Current_TDDPercent;
  percent capacitorPhase1Current_THDPercent;
  percent capacitorPhase2Current_THDPercent;
  percent capacitorPhase3Current_THDPercent;
  amp capacitorPhase1Current_RMS;
  amp capacitorPhase2Current_RMS;
  amp capacitorPhase3Current_RMS;
  amp capacitorEarthFaultCurrent_RMS;
  amp capacitorPhase1Current_Fundamental;
  amp capacitorPhase2Current_Fundamental;
  amp capacitorPhase3Current_Fundamental;
  amp capacitorPhase1Current_THD;
  amp capacitorPhase2Current_THD;
  amp capacitorPhase3Current_THD;
  amp averageCapacitorCurrent_THD;
  var capacitorPhase1InjectedReactivePower_Fundamental;
  var capacitorPhase2InjectedReactivePower_Fundamental;
  var capacitorPhase3InjectedReactivePower_Fundamental;
  var capacitorOverallInjectedReactivePower_Fundamental;
  BankStatusData bankStatus;
  FaultData faultData;
  AuxFnData auxFnData;

  amp phase1Current_Harmonics(size_t harmonic);
  amp phase2Current_Harmonics(size_t harmonic);
  amp phase3Current_Harmonics(size_t harmonic);
  void bigEndian();
  static IntervalData512 fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;

static_assert(sizeof(IntervalData512) == 775);
static_assert(std::is_standard_layout_v<IntervalData512>);
}  // namespace tas_powertek::spf21y