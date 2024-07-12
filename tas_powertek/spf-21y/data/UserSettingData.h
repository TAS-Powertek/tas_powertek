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

struct UserSettingData {
  uint32_t COM1_Unit_ID;
  std::array<uint32_t, 17> EX_BankUseage_Check_Limit;
  std::array<uint32_t, 16> _EX_Bank_kVAr;  // raw value
  float EX_Bank_kVAr(size_t index) const {
    return _EX_Bank_kVAr.at(index) / 100.0;
  }

  uint16_t _EX_Rated_V;
  float EX_Rated_V() const { return _EX_Rated_V / 10.0; }

  uint16_t ES_Rated_VLL;
  uint16_t ES_SCT_Primary;
  uint16_t ES_CCT_Primary;
  uint16_t EX_SCT_Primary;
  uint16_t EX_CCT_Primary;
  std::array<uint16_t, 16> _ES_Bank_kVAr;
  float ES_Bank_kVAr(size_t index) const {
    return _ES_Bank_kVAr.at(index) / 10.0;
  }

  uint16_t _ES_Target_DPF;
  float ES_Target_DPF() const { return _ES_Target_DPF / 1000.0; }
  uint16_t _EX_Target_DPF_Grid;
  float EX_Target_DPF_Grid() const { return _EX_Target_DPF_Grid / 1000.0; }
  uint16_t _EX_Target_DPF_Generator;
  float EX_Target_DPF_Generator() const {
    return _EX_Target_DPF_Generator / 1000.0;
  }

  uint16_t EX_PT_Ratio;
  uint16_t _EX_DT_Ratio;
  float EX_DT_Ratio() const { return _EX_DT_Ratio / 10.0; }
  uint16_t _EX_Correction_Time;
  float EX_Correction_Time() const { return _EX_Correction_Time / 10.0; }
  uint16_t EX_Discharge_Time;
  uint16_t _EX_Interleave_Time;
  float EX_Interleave_Time() const { return _EX_Interleave_Time / 10.0; }

  std::array<uint16_t, 28> FLT_RST_TIME_Uch;
  std::array<uint16_t, 28> _FLT_SET_Limit_Uch;
  float FLT_SET_Limit_Uch(size_t index) const {
    return _FLT_SET_Limit_Uch.at(index) / 10.0;
  }
  std::array<uint16_t, 28> _FLT_RST_Limit_Uch;
  float FLT_RST_Limit_Uch(size_t index) const {
    return _FLT_RST_Limit_Uch.at(index) / 10.0;
  }

  uint16_t COM2_Unit_ID;
  uint16_t Password;
  uint16_t Set_Year;
  uint16_t Display_Contrast;
  uint16_t Aux_In_Mul_Fact;
  uint8_t log_Interval;
  uint8_t Temp_Bank_Ptr;
  uint8_t Temp_Fault_Ptr;
  uint8_t Temp_AuxIN_Ptr;
  uint8_t Temp_AuxOUT_Ptr;
  uint8_t EX_RatedV_Config;
  uint8_t ES_Rated_Freq;
  uint8_t EX_Rated_Freq;
  uint8_t Application;
  uint8_t Meas_Config;
  uint8_t Scheme;
  uint8_t CapCT_Config;
  uint8_t ES_SCT_Secondary;
  uint8_t ES_CCT_Secondary;
  uint8_t EX_SCT_Secondary;
  uint8_t EX_CCT_Secondary;
  uint8_t ES_NumCap_Bank;
  std::array<uint8_t, 16> ES_Bank_Config;
  std::array<uint8_t, 16> EX_Bank_Config;
  std::array<uint8_t, 16> Bank_Utilisation_Reset;
  std::array<uint8_t, 16> Bank_kVAr_Reset;
  std::array<uint8_t, 16> Manual_Bank_Setting;
  std::array<uint8_t, 16> EX_Bank_Unit;
  uint8_t ES_DPF_Sign;
  uint8_t EX_DPF_Sign_Grid;
  uint8_t EX_DPF_Sign_Generator;
  uint8_t EX_Vector_Group;
  uint8_t EX_MD_Window_Time;
  uint8_t EX_Resolution;
  uint8_t EX_Offset;
  uint8_t EX_Correction_Time_Config;
  std::array<uint8_t, 28> FLT_RES_Type_Uch;
  std::array<uint8_t, 28> FLT_EN_DS;
  std::array<uint8_t, 28> FLT_ACT;
  uint8_t AuxIN_Function_1;
  uint8_t AuxIN_Function_2;
  uint8_t AuxOUT_Function_1;
  uint8_t AuxOUT_Function_2;
  uint8_t AuxOUT_Function_3;
  uint8_t AuxOUT_Function_4;
  uint8_t ES_Mode_Config;
  uint8_t _1A_OFFSET;
  uint8_t _2A_OFFSET;
  uint8_t _3A_OFFSET;
  uint8_t _1A_CT_Polarity;
  uint8_t _2A_CT_Polarity;
  uint8_t _3A_CT_Polarity;
  uint8_t _1CA_OFFSET;
  uint8_t _2CA_OFFSET;
  uint8_t _3CA_OFFSET;
  uint8_t _1CA_CT_Polarity;
  uint8_t _2CA_CT_Polarity;
  uint8_t _3CA_CT_Polarity;
  uint8_t log_Frame_Type;
  uint8_t COM1_BuadRate;
  uint8_t COM1_Function;
  uint8_t COM2_BuadRate;
  uint8_t COM2_Function;
  uint8_t Reset_LogData;
  uint8_t Energy_Reset_EnDs;
  uint8_t Energy_Reset_Date;
  uint8_t Energy_Reset_Hr;
  uint8_t Energy_Reset_Min;
  uint8_t MD_Reset_EnDs;
  uint8_t MD_Reset_Date;
  uint8_t MD_Reset_Hr;
  uint8_t MD_Reset_Min;
  uint8_t Max_Reset_EnDs;
  uint8_t Max_Reset_Date;
  uint8_t Max_Reset_Hr;
  uint8_t Max_Reset_Min;
  uint8_t GPRS_APN;
  fixed_sized_string<16> Other_APN;
  fixed_sized_string<16> IP_Address;
  fixed_sized_string<64> Main_Server_Name;
  fixed_sized_string<4> Port;
  fixed_sized_string<16> Sub_Server_Name;
  uint8_t Password_EnDs;
  uint8_t Load_Default;
  uint8_t Reset_RTC_Date_EnDs;
  uint8_t Reset_RTC_Time_EnDs;
  uint8_t Set_Date;
  uint8_t Set_Month;
  uint8_t Set_Hr;
  uint8_t Set_Min;
  uint8_t Set_Sec;
  uint8_t Remote_Update_EnDs;
  uint8_t PowerUp_Mode;
  std::array<uint8_t, 17> EX_Bank_HelthCheck_EnDs;
  std::array<uint8_t, 17> EX_Bank_HelthCheck_Lval;
  std::array<uint8_t, 17> EX_Bank_HelthCheck_Uval;
  std::array<uint8_t, 17> EX_BankUseage_Check_EnDs;
  uint8_t EX_Temp_Mains_Gen_Sel;
  uint8_t Remote_Operation_Mode;
  uint8_t Remote_Mode_Timeout;
  uint8_t Remote_Mode_Timeout_Act;
  uint8_t Step_Config;
  uint8_t Language_Support;
  uint8_t Display_Scroll_Config;
  uint8_t AutoSync_Retry;
  uint8_t AutoSync_FL_Option;
  fixed_sized_string<8> Project_Name;
  uint8_t Load_Balancing_En;
  uint8_t Utilisation_Div_TFact;
  uint8_t Utilisation_Div_CFact;
  uint8_t Num_RT_Data_Frames;
  uint8_t AutoDetect_Bank_kVAr;
  uint8_t VA_Type;
  // There is an un-used gap that's probably for future settings.
  std::array<uint8_t, 59> _unused;
  fixed_sized_string<10> Firmware_Version;

  // User settings are surprisingly little endian :(
  void littleEndian();
  static UserSettingData fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;

static_assert(sizeof(UserSettingData) == 904);
static_assert(std::is_standard_layout_v<UserSettingData>);
}  // namespace tas_powertek::spf21y