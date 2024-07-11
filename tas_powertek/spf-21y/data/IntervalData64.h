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

struct IntervalData64 {
  TimeData time;
  hertz supplyFrequency;
  volt averagePhaseToNeutralVolage_RMS;
  volt averagePhaseToNeutralVoltage_Fundamental;
  volt averagePhaseToNeutralVolage_THD;
  volt averagePhaseToPhaseVoltage_RMS;
  volt averagePhaseToPhaseVoltage_Fundamental;
  amp averagePhaseCurrent_RMS;
  amp averagePhaseCurrent_THD;
  watt overall3PhActivePower_Fundamental;
  var overall3PhReactivePower_Fundamental;
  dpf powerFactor_Fundamental_OverallThreePhase;
  amp capacitorPhase1Current_RMS;
  amp capacitorPhase2Current_RMS;
  amp capacitorPhase3Current_RMS;
  amp capacitorEarthFaultCurrent_RMS;
  amp capacitorPhase1Current_Fundamental;
  amp capacitorPhase2Current_Fundamental;
  amp capacitorPhase3Current_Fundamental;
  amp capacitorAverageCurrent_THD;
  FaultDataLow faultData;
  AuxFnData auxFnData;

  void bigEndian();
  static IntervalData64 fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;

static_assert(sizeof(IntervalData64) == 95);
static_assert(std::is_standard_layout_v<IntervalData64>);
}  // namespace tas_powertek::spf21y