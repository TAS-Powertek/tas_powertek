#include "UserSettingData.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>

#include <cstring>

namespace tas_powertek::spf21y {
namespace {
template <typename T, size_t kSize>
void toLittleEndian(std::array<T, kSize>& arr) {
  for (T& item : arr) {
    item = folly::Endian::little(item);
  }
}
}  // namespace

void UserSettingData::littleEndian() {
  COM1_Unit_ID = folly::Endian::little(COM1_Unit_ID);
  toLittleEndian(EX_BankUseage_Check_Limit);
  toLittleEndian(_EX_Bank_kVAr);
  _EX_Rated_V = folly::Endian::little(_EX_Rated_V);
  ES_Rated_VLL = folly::Endian::little(ES_Rated_VLL);
  ES_SCT_Primary = folly::Endian::little(ES_SCT_Primary);
  ES_CCT_Primary = folly::Endian::little(ES_CCT_Primary);
  EX_SCT_Primary = folly::Endian::little(EX_SCT_Primary);
  EX_CCT_Primary = folly::Endian::little(EX_CCT_Primary);
  toLittleEndian(_ES_Bank_kVAr);
  _ES_Target_DPF = folly::Endian::little(_ES_Target_DPF);
  _EX_Target_DPF_Grid = folly::Endian::little(_EX_Target_DPF_Grid);
  _EX_Target_DPF_Generator = folly::Endian::little(_EX_Target_DPF_Generator);
  EX_PT_Ratio = folly::Endian::little(EX_PT_Ratio);
  _EX_DT_Ratio = folly::Endian::little(_EX_DT_Ratio);
  _EX_Correction_Time = folly::Endian::little(_EX_Correction_Time);
  EX_Discharge_Time = folly::Endian::little(EX_Discharge_Time);
  _EX_Interleave_Time = folly::Endian::little(_EX_Interleave_Time);
  toLittleEndian(FLT_RST_TIME_Uch);
  toLittleEndian(_FLT_SET_Limit_Uch);
  toLittleEndian(_FLT_RST_Limit_Uch);
  COM2_Unit_ID = folly::Endian::little(COM2_Unit_ID);
  Password = folly::Endian::little(Password);
  Set_Year = folly::Endian::little(Set_Year);
  Display_Contrast = folly::Endian::little(Display_Contrast);
  Aux_In_Mul_Fact = folly::Endian::little(Aux_In_Mul_Fact);
  log_Interval = folly::Endian::little(log_Interval);
  Temp_Bank_Ptr = folly::Endian::little(Temp_Bank_Ptr);
  Temp_Fault_Ptr = folly::Endian::little(Temp_Fault_Ptr);
  Temp_AuxIN_Ptr = folly::Endian::little(Temp_AuxIN_Ptr);
  Temp_AuxOUT_Ptr = folly::Endian::little(Temp_AuxOUT_Ptr);
  EX_RatedV_Config = folly::Endian::little(EX_RatedV_Config);
  ES_Rated_Freq = folly::Endian::little(ES_Rated_Freq);
  EX_Rated_Freq = folly::Endian::little(EX_Rated_Freq);
  Application = folly::Endian::little(Application);
  Meas_Config = folly::Endian::little(Meas_Config);
  Scheme = folly::Endian::little(Scheme);
  CapCT_Config = folly::Endian::little(CapCT_Config);
  ES_SCT_Secondary = folly::Endian::little(ES_SCT_Secondary);
  ES_CCT_Secondary = folly::Endian::little(ES_CCT_Secondary);
  EX_SCT_Secondary = folly::Endian::little(EX_SCT_Secondary);
  EX_CCT_Secondary = folly::Endian::little(EX_CCT_Secondary);
  ES_NumCap_Bank = folly::Endian::little(ES_NumCap_Bank);
  toLittleEndian(ES_Bank_Config);
  toLittleEndian(EX_Bank_Config);
  toLittleEndian(Bank_Utilisation_Reset);
  toLittleEndian(Bank_kVAr_Reset);
  toLittleEndian(Manual_Bank_Setting);
  toLittleEndian(EX_Bank_Unit);
  ES_DPF_Sign = folly::Endian::little(ES_DPF_Sign);
  EX_DPF_Sign_Grid = folly::Endian::little(EX_DPF_Sign_Grid);
  EX_DPF_Sign_Generator = folly::Endian::little(EX_DPF_Sign_Generator);
  EX_Vector_Group = folly::Endian::little(EX_Vector_Group);
  EX_MD_Window_Time = folly::Endian::little(EX_MD_Window_Time);
  EX_Resolution = folly::Endian::little(EX_Resolution);
  EX_Offset = folly::Endian::little(EX_Offset);
  EX_Correction_Time_Config = folly::Endian::little(EX_Correction_Time_Config);
  toLittleEndian(FLT_RES_Type_Uch);
  toLittleEndian(FLT_EN_DS);
  toLittleEndian(FLT_ACT);
  AuxIN_Function_1 = folly::Endian::little(AuxIN_Function_1);
  AuxIN_Function_2 = folly::Endian::little(AuxIN_Function_2);
  AuxOUT_Function_1 = folly::Endian::little(AuxOUT_Function_1);
  AuxOUT_Function_2 = folly::Endian::little(AuxOUT_Function_2);
  AuxOUT_Function_3 = folly::Endian::little(AuxOUT_Function_3);
  AuxOUT_Function_4 = folly::Endian::little(AuxOUT_Function_4);
  ES_Mode_Config = folly::Endian::little(ES_Mode_Config);
  _1A_OFFSET = folly::Endian::little(_1A_OFFSET);
  _2A_OFFSET = folly::Endian::little(_2A_OFFSET);
  _3A_OFFSET = folly::Endian::little(_3A_OFFSET);
  _1A_CT_Polarity = folly::Endian::little(_1A_CT_Polarity);
  _2A_CT_Polarity = folly::Endian::little(_2A_CT_Polarity);
  _3A_CT_Polarity = folly::Endian::little(_3A_CT_Polarity);
  _1CA_OFFSET = folly::Endian::little(_1CA_OFFSET);
  _2CA_OFFSET = folly::Endian::little(_2CA_OFFSET);
  _3CA_OFFSET = folly::Endian::little(_3CA_OFFSET);
  _1CA_CT_Polarity = folly::Endian::little(_1CA_CT_Polarity);
  _2CA_CT_Polarity = folly::Endian::little(_2CA_CT_Polarity);
  _3CA_CT_Polarity = folly::Endian::little(_3CA_CT_Polarity);
  log_Frame_Type = folly::Endian::little(log_Frame_Type);
  COM1_BuadRate = folly::Endian::little(COM1_BuadRate);
  COM1_Function = folly::Endian::little(COM1_Function);
  COM2_BuadRate = folly::Endian::little(COM2_BuadRate);
  COM2_Function = folly::Endian::little(COM2_Function);
  Reset_LogData = folly::Endian::little(Reset_LogData);
  Energy_Reset_EnDs = folly::Endian::little(Energy_Reset_EnDs);
  Energy_Reset_Date = folly::Endian::little(Energy_Reset_Date);
  Energy_Reset_Hr = folly::Endian::little(Energy_Reset_Hr);
  Energy_Reset_Min = folly::Endian::little(Energy_Reset_Min);
  MD_Reset_EnDs = folly::Endian::little(MD_Reset_EnDs);
  MD_Reset_Date = folly::Endian::little(MD_Reset_Date);
  MD_Reset_Hr = folly::Endian::little(MD_Reset_Hr);
  MD_Reset_Min = folly::Endian::little(MD_Reset_Min);
  Max_Reset_EnDs = folly::Endian::little(Max_Reset_EnDs);
  Max_Reset_Date = folly::Endian::little(Max_Reset_Date);
  Max_Reset_Hr = folly::Endian::little(Max_Reset_Hr);
  Max_Reset_Min = folly::Endian::little(Max_Reset_Min);
  GPRS_APN = folly::Endian::little(GPRS_APN);
  Password_EnDs = folly::Endian::little(Password_EnDs);
  Load_Default = folly::Endian::little(Load_Default);
  Reset_RTC_Date_EnDs = folly::Endian::little(Reset_RTC_Date_EnDs);
  Reset_RTC_Time_EnDs = folly::Endian::little(Reset_RTC_Time_EnDs);
  Set_Date = folly::Endian::little(Set_Date);
  Set_Month = folly::Endian::little(Set_Month);
  Set_Hr = folly::Endian::little(Set_Hr);
  Set_Min = folly::Endian::little(Set_Min);
  Set_Sec = folly::Endian::little(Set_Sec);
  Remote_Update_EnDs = folly::Endian::little(Remote_Update_EnDs);
  PowerUp_Mode = folly::Endian::little(PowerUp_Mode);
  toLittleEndian(EX_Bank_HelthCheck_EnDs);
  toLittleEndian(EX_Bank_HelthCheck_Lval);
  toLittleEndian(EX_Bank_HelthCheck_Uval);
  toLittleEndian(EX_BankUseage_Check_EnDs);
  EX_Temp_Mains_Gen_Sel = folly::Endian::little(EX_Temp_Mains_Gen_Sel);
  Remote_Operation_Mode = folly::Endian::little(Remote_Operation_Mode);
  Remote_Mode_Timeout = folly::Endian::little(Remote_Mode_Timeout);
  Remote_Mode_Timeout_Act = folly::Endian::little(Remote_Mode_Timeout_Act);
  Step_Config = folly::Endian::little(Step_Config);
  Language_Support = folly::Endian::little(Language_Support);
  Display_Scroll_Config = folly::Endian::little(Display_Scroll_Config);
  AutoSync_Retry = folly::Endian::little(AutoSync_Retry);
  AutoSync_FL_Option = folly::Endian::little(AutoSync_FL_Option);
  Load_Balancing_En = folly::Endian::little(Load_Balancing_En);
  Utilisation_Div_TFact = folly::Endian::little(Utilisation_Div_TFact);
  Utilisation_Div_CFact = folly::Endian::little(Utilisation_Div_CFact);
  Num_RT_Data_Frames = folly::Endian::little(Num_RT_Data_Frames);
  AutoDetect_Bank_kVAr = folly::Endian::little(AutoDetect_Bank_kVAr);
  VA_Type = folly::Endian::little(VA_Type);
}

/* static */ UserSettingData UserSettingData::fromByteStream(
    std::string_view data) {
  if (data.size() != sizeof(UserSettingData)) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into UserSettingData of size {}",
        data.size(), sizeof(UserSettingData)));
  }

  UserSettingData result;
  std::memcpy(&result, data.data(), sizeof(UserSettingData));
  result.littleEndian();
  return result;
}
}  // namespace tas_powertek::spf21y