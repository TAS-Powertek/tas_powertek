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

struct DailyData {
  TimeData time;
  volt maxPhase1ToNeutralVoltage_RMS;
  volt maxPhase2ToNeutralVoltage_RMS;
  volt maxPhase3ToNeutralVoltage_RMS;
  volt maxPhasesToNetralVoltage_THD;
  volt maxPhase1ToPhase2Voltage_RMS;
  volt maxPhase2ToPhase3Voltage_RMS;
  volt maxPhase3ToPhase1Voltage_RMS;
  volt maxPhaseToPhaseVoltage_THD;
  amp maxPhase1Current_RMS;
  amp maxPhase2Current_RMS;
  amp maxPhase3Current_RMS;
  amp maxNeutralCurrent_RMS;
  amp maxPhase1Current_THD;
  amp maxPhase2Current_THD;
  amp maxPhase3Current_THD;
  amp maxNeutralCurrent_THD;
  amp maxCapacitorCurrent_THD;
  va maxDemandOverallVA;
  watt maxDemandOverallWatt;
  std::array<var, 16> capacitorBank_VAR;
  celsius maxExternalTempPT100;
  kwh overallActiveEnergyGeneration_Negative;
  kwh overallActiveEnergyConsumption_Positive;
  kvarh overallReactiveEnergyImport_Negative;
  kvarh overallReactiveEnergyExport_Positive;
  kvah overallApparentEnergy;
  kvarh capacitorReactiveFundamentalEnergyExported;
  std::array<uint32_t, 16> capacitorUtilizationCounters;
  uint32_t numPowerInterruptions;
  percent maxPhasesToNetralVoltage_THDPercent;
  percent maxPhaseToPhaseVoltage_THDPercent;
  percent maxPhaseCurrent_TDDPercent;
  percent maxCapacitorPhaseCurrent_TDDPercent;

  void bigEndian();
  static DailyData fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;

static_assert(sizeof(DailyData) == 271);
static_assert(std::is_standard_layout_v<DailyData>);
}  // namespace tas_powertek::spf21y