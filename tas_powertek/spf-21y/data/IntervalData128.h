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

struct IntervalData128 {
  TimeData time;
  hertz supplyFrequency;
  volt phase1ToNeutralVoltage_RMS;
  volt phase2ToNeutralVoltage_RMS;
  volt phase3ToNeutralVoltage_RMS;
  volt averagePhaseToNeutralVoltage_Fundamental;
  volt averagePhaseToNeutralVolage_THD;
  volt averagePhaseToPhaseVoltage_RMS;
  volt averagePhaseToPhaseVoltage_Fundamental;
  amp phase1Current_RMS;
  amp phase2Current_RMS;
  amp phase3Current_RMS;
  amp neutralCurrent_RMS;
  amp averagePhaseCurrent_Fundamental;
  amp averagePhaseCurrent_THD;
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
  percent capacitorPhase1Current_THDPercent;
  percent capacitorPhase2Current_THDPercent;
  percent capacitorPhase3Current_THDPercent;
  pf powerFactor_OverallThreePhase;
  dpf powerFactor_Fundamental_OverallThreePhase;
  va overall3PhApparentPower_Combined;
  watt overall3PhActivePower_Fundamental;
  var overall3PhReactivePower_Fundamental;
  va overall3PhApparentPower_Fundamental;
  va overall3PhDistortionPower_IEC_IEEE;
  watt phase1ActivePower_Fundamental;
  watt phase2ActivePower_Fundamental;
  watt phase3ActivePower_Fundamental;
  var phase1ReactivePower_Fundamental;
  var phase2ReactivePower_Fundamental;
  var phase3ReactivePower_Fundamental;
  var capacitorOverallInjectedReactivePower_Fundamental;
  FaultDataLow faultData;
  AuxFnData auxFnData;

  void bigEndian();
  static IntervalData128 fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;

static_assert(sizeof(IntervalData128) == 174);
static_assert(std::is_standard_layout_v<IntervalData128>);
}  // namespace tas_powertek::spf21y