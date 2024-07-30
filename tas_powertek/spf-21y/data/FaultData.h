#pragma once

#include <folly/Portability.h>

#include <bitset>
#include <chrono>
#include <cstdint>

namespace tas_powertek::spf21y {

/**
 * FaultData with only half the bytes (and data). Contains the low 4 words (8
 * bytes) of data.
 */
struct FaultDataLow {
  uint64_t bits;

  std::bitset<64> faultBits() const { return std::bitset<64>(bits); }

  bool OVR() const { return faultBits()[0 * 16 + 0]; }
  bool UVR() const { return faultBits()[0 * 16 + 1]; }
  bool OVY() const { return faultBits()[0 * 16 + 2]; }
  bool UVY() const { return faultBits()[0 * 16 + 3]; }
  bool OVB() const { return faultBits()[0 * 16 + 4]; }
  bool UVB() const { return faultBits()[0 * 16 + 5]; }
  bool OCR() const { return faultBits()[0 * 16 + 6]; }
  bool ULR() const { return faultBits()[0 * 16 + 7]; }
  bool OCY() const { return faultBits()[0 * 16 + 8]; }
  bool ULY() const { return faultBits()[0 * 16 + 9]; }
  bool OCB() const { return faultBits()[0 * 16 + 10]; }
  bool ULB() const { return faultBits()[0 * 16 + 11]; }
  bool COR() const { return faultBits()[0 * 16 + 12]; }
  bool CUR() const { return faultBits()[0 * 16 + 13]; }
  bool COY() const { return faultBits()[0 * 16 + 14]; }
  bool CUY() const { return faultBits()[0 * 16 + 15]; }
  bool COB() const { return faultBits()[1 * 16 + 0]; }
  bool CUB() const { return faultBits()[1 * 16 + 1]; }
  bool SOF() const { return faultBits()[1 * 16 + 2]; }
  bool SUF() const { return faultBits()[1 * 16 + 3]; }
  bool MOT() const { return faultBits()[1 * 16 + 4]; }
  bool ChR() const { return faultBits()[1 * 16 + 5]; }
  bool ChY() const { return faultBits()[1 * 16 + 6]; }
  bool ChB() const { return faultBits()[1 * 16 + 7]; }
  bool OBF() const { return faultBits()[1 * 16 + 8]; }
  bool UBA() const { return faultBits()[1 * 16 + 9]; }
  bool OCN() const { return faultBits()[1 * 16 + 10]; }
  bool EOT() const { return faultBits()[1 * 16 + 11]; }
  bool PDN() const { return faultBits()[1 * 16 + 12]; }
  bool PUP() const { return faultBits()[1 * 16 + 13]; }
  bool RTC() const { return faultBits()[1 * 16 + 14]; }
  bool NVF() const { return faultBits()[1 * 16 + 15]; }
  bool ZCF() const { return faultBits()[2 * 16 + 0]; }
  bool ZVF() const { return faultBits()[2 * 16 + 1]; }
  bool MDW() const { return faultBits()[2 * 16 + 2]; }
  bool MDV() const { return faultBits()[2 * 16 + 3]; }
  bool UBV() const { return faultBits()[2 * 16 + 4]; }
  bool UBC() const { return faultBits()[2 * 16 + 5]; }
  bool __na_1_() const { return faultBits()[2 * 16 + 6]; }
  bool CEL() const { return faultBits()[2 * 16 + 7]; }
  bool VHF() const { return faultBits()[2 * 16 + 8]; }
  bool CHF() const { return faultBits()[2 * 16 + 9]; }
  bool PFR() const { return faultBits()[2 * 16 + 10]; }
  bool PFY() const { return faultBits()[2 * 16 + 11]; }
  bool PFB() const { return faultBits()[2 * 16 + 12]; }
  bool AVL() const { return faultBits()[2 * 16 + 13]; }
  bool AVH() const { return faultBits()[2 * 16 + 14]; }
  bool CBF() const { return faultBits()[2 * 16 + 15]; }
  bool SyF() const { return faultBits()[3 * 16 + 0]; }
  bool CTM() const { return faultBits()[3 * 16 + 1]; }
  bool ERU() const { return faultBits()[3 * 16 + 2]; }
  bool EWU() const { return faultBits()[3 * 16 + 3]; }
  bool RM1() const { return faultBits()[3 * 16 + 4]; }
  bool RM2() const { return faultBits()[3 * 16 + 5]; }
  bool DSB() const { return faultBits()[3 * 16 + 6]; }
  bool HLD() const { return faultBits()[3 * 16 + 7]; }
  bool AMG() const { return faultBits()[3 * 16 + 8]; }
  bool WDR() const { return faultBits()[3 * 16 + 9]; }
  bool SyA() const { return faultBits()[3 * 16 + 10]; }
  bool SyP() const { return faultBits()[3 * 16 + 11]; }
  bool ASM() const { return faultBits()[3 * 16 + 12]; }
  bool PEM() const { return faultBits()[3 * 16 + 13]; }
  bool _EOF() const { return faultBits()[3 * 16 + 14]; }
  bool _4GN() const { return faultBits()[3 * 16 + 15]; }

  void bigEndian();
  static FaultDataLow fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;

static_assert(sizeof(FaultDataLow) == 8);
static_assert(std::is_standard_layout_v<FaultDataLow>);

struct FaultDataHigh {
  uint64_t bits;

  std::bitset<64> faultBits() const { return std::bitset<64>(bits); }

  bool ERC() const { return faultBits()[0 * 16 + 0]; }
  bool ERP() const { return faultBits()[0 * 16 + 1]; }
  bool ERE() const { return faultBits()[0 * 16 + 2]; }
  bool ERL() const { return faultBits()[0 * 16 + 3]; }
  bool EWC() const { return faultBits()[0 * 16 + 4]; }
  bool EWP() const { return faultBits()[0 * 16 + 5]; }
  bool EWE() const { return faultBits()[0 * 16 + 6]; }
  bool EWL() const { return faultBits()[0 * 16 + 7]; }
  bool CM1() const { return faultBits()[0 * 16 + 8]; }
  bool CM2() const { return faultBits()[0 * 16 + 9]; }
  bool PSV() const { return faultBits()[0 * 16 + 10]; }
  bool CRT() const { return faultBits()[0 * 16 + 11]; }
  bool MRT() const { return faultBits()[0 * 16 + 12]; }
  bool UCR() const { return faultBits()[0 * 16 + 13]; }
  bool WST() const { return faultBits()[0 * 16 + 14]; }
  bool __na_2_() const { return faultBits()[0 * 16 + 15]; }
  bool ZVR() const { return faultBits()[1 * 16 + 0]; }
  bool ZVY() const { return faultBits()[1 * 16 + 1]; }
  bool ZVB() const { return faultBits()[1 * 16 + 2]; }
  bool ZCR() const { return faultBits()[1 * 16 + 3]; }
  bool ZCY() const { return faultBits()[1 * 16 + 4]; }
  bool ZCB() const { return faultBits()[1 * 16 + 5]; }
  bool VHR() const { return faultBits()[1 * 16 + 6]; }
  bool VHY() const { return faultBits()[1 * 16 + 7]; }
  bool VHB() const { return faultBits()[1 * 16 + 8]; }
  bool CHR() const { return faultBits()[1 * 16 + 9]; }
  bool CHY() const { return faultBits()[1 * 16 + 10]; }
  bool CHB() const { return faultBits()[1 * 16 + 11]; }
  bool OBR() const { return faultBits()[1 * 16 + 12]; }
  bool OBY() const { return faultBits()[1 * 16 + 13]; }
  bool OBB() const { return faultBits()[1 * 16 + 14]; }
  bool VRH() const { return faultBits()[1 * 16 + 15]; }
  bool VYH() const { return faultBits()[2 * 16 + 0]; }
  bool VBH() const { return faultBits()[2 * 16 + 1]; }
  bool UVF() const { return faultBits()[2 * 16 + 2]; }
  bool OVF() const { return faultBits()[2 * 16 + 3]; }
  bool PFL() const { return faultBits()[2 * 16 + 4]; }
  bool OCF() const { return faultBits()[2 * 16 + 5]; }
  bool COF() const { return faultBits()[2 * 16 + 6]; }
  bool CUF() const { return faultBits()[2 * 16 + 7]; }
  bool VhF() const { return faultBits()[2 * 16 + 8]; }
  bool ChF() const { return faultBits()[2 * 16 + 9]; }
  bool ULF() const { return faultBits()[2 * 16 + 10]; }
  bool ASP() const { return faultBits()[2 * 16 + 11]; }
  bool ABD() const { return faultBits()[2 * 16 + 12]; }
  bool ABP() const { return faultBits()[2 * 16 + 13]; }
  bool MAN() const { return faultBits()[2 * 16 + 14]; }
  bool __na_3_() const { return faultBits()[2 * 16 + 15]; }
  bool VOL() const { return faultBits()[3 * 16 + 0]; }
  bool VOH() const { return faultBits()[3 * 16 + 1]; }
  bool VOR() const { return faultBits()[3 * 16 + 2]; }
  bool BDF() const { return faultBits()[3 * 16 + 3]; }
  bool BDA() const { return faultBits()[3 * 16 + 4]; }
  bool BDP() const { return faultBits()[3 * 16 + 5]; }
  bool __na_4_() const { return faultBits()[3 * 16 + 6]; }
  bool __na_5_() const { return faultBits()[3 * 16 + 7]; }
  bool __na_6_() const { return faultBits()[3 * 16 + 8]; }
  bool __na_7_() const { return faultBits()[3 * 16 + 9]; }
  bool __na_8_() const { return faultBits()[3 * 16 + 10]; }
  bool __na_9_() const { return faultBits()[3 * 16 + 11]; }
  bool __na_10_() const { return faultBits()[3 * 16 + 12]; }
  bool __na_11_() const { return faultBits()[3 * 16 + 13]; }
  bool __na_12_() const { return faultBits()[3 * 16 + 14]; }
  bool IOK() const { return faultBits()[3 * 16 + 15]; }

  void bigEndian();
  static FaultDataHigh fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;

static_assert(sizeof(FaultDataHigh) == 8);
static_assert(std::is_standard_layout_v<FaultDataHigh>);

struct FaultData {
  FaultDataLow low;
  FaultDataHigh high;

  bool OVR() const { return low.OVR(); }
  bool UVR() const { return low.UVR(); }
  bool OVY() const { return low.OVY(); }
  bool UVY() const { return low.UVY(); }
  bool OVB() const { return low.OVB(); }
  bool UVB() const { return low.UVB(); }
  bool OCR() const { return low.OCR(); }
  bool ULR() const { return low.ULR(); }
  bool OCY() const { return low.OCY(); }
  bool ULY() const { return low.ULY(); }
  bool OCB() const { return low.OCB(); }
  bool ULB() const { return low.ULB(); }
  bool COR() const { return low.COR(); }
  bool CUR() const { return low.CUR(); }
  bool COY() const { return low.COY(); }
  bool CUY() const { return low.CUY(); }
  bool COB() const { return low.COB(); }
  bool CUB() const { return low.CUB(); }
  bool SOF() const { return low.SOF(); }
  bool SUF() const { return low.SUF(); }
  bool MOT() const { return low.MOT(); }
  bool ChR() const { return low.ChR(); }
  bool ChY() const { return low.ChY(); }
  bool ChB() const { return low.ChB(); }
  bool OBF() const { return low.OBF(); }
  bool UBA() const { return low.UBA(); }
  bool OCN() const { return low.OCN(); }
  bool EOT() const { return low.EOT(); }
  bool PDN() const { return low.PDN(); }
  bool PUP() const { return low.PUP(); }
  bool RTC() const { return low.RTC(); }
  bool NVF() const { return low.NVF(); }
  bool ZCF() const { return low.ZCF(); }
  bool ZVF() const { return low.ZVF(); }
  bool MDW() const { return low.MDW(); }
  bool MDV() const { return low.MDV(); }
  bool UBV() const { return low.UBV(); }
  bool UBC() const { return low.UBC(); }
  bool __na_1_() const { return low.__na_1_(); }
  bool CEL() const { return low.CEL(); }
  bool VHF() const { return low.VHF(); }
  bool CHF() const { return low.CHF(); }
  bool PFR() const { return low.PFR(); }
  bool PFY() const { return low.PFY(); }
  bool PFB() const { return low.PFB(); }
  bool AVL() const { return low.AVL(); }
  bool AVH() const { return low.AVH(); }
  bool CBF() const { return low.CBF(); }
  bool SyF() const { return low.SyF(); }
  bool CTM() const { return low.CTM(); }
  bool ERU() const { return low.ERU(); }
  bool EWU() const { return low.EWU(); }
  bool RM1() const { return low.RM1(); }
  bool RM2() const { return low.RM2(); }
  bool DSB() const { return low.DSB(); }
  bool HLD() const { return low.HLD(); }
  bool AMG() const { return low.AMG(); }
  bool WDR() const { return low.WDR(); }
  bool SyA() const { return low.SyA(); }
  bool SyP() const { return low.SyP(); }
  bool ASM() const { return low.ASM(); }
  bool PEM() const { return low.PEM(); }
  bool _EOF() const { return low._EOF(); }
  bool _4GN() const { return low._4GN(); }
  bool ERC() const { return high.ERC(); }
  bool ERP() const { return high.ERP(); }
  bool ERE() const { return high.ERE(); }
  bool ERL() const { return high.ERL(); }
  bool EWC() const { return high.EWC(); }
  bool EWP() const { return high.EWP(); }
  bool EWE() const { return high.EWE(); }
  bool EWL() const { return high.EWL(); }
  bool CM1() const { return high.CM1(); }
  bool CM2() const { return high.CM2(); }
  bool PSV() const { return high.PSV(); }
  bool CRT() const { return high.CRT(); }
  bool MRT() const { return high.MRT(); }
  bool UCR() const { return high.UCR(); }
  bool WST() const { return high.WST(); }
  bool __na_2_() const { return high.__na_2_(); }
  bool ZVR() const { return high.ZVR(); }
  bool ZVY() const { return high.ZVY(); }
  bool ZVB() const { return high.ZVB(); }
  bool ZCR() const { return high.ZCR(); }
  bool ZCY() const { return high.ZCY(); }
  bool ZCB() const { return high.ZCB(); }
  bool VHR() const { return high.VHR(); }
  bool VHY() const { return high.VHY(); }
  bool VHB() const { return high.VHB(); }
  bool CHR() const { return high.CHR(); }
  bool CHY() const { return high.CHY(); }
  bool CHB() const { return high.CHB(); }
  bool OBR() const { return high.OBR(); }
  bool OBY() const { return high.OBY(); }
  bool OBB() const { return high.OBB(); }
  bool VRH() const { return high.VRH(); }
  bool VYH() const { return high.VYH(); }
  bool VBH() const { return high.VBH(); }
  bool UVF() const { return high.UVF(); }
  bool OVF() const { return high.OVF(); }
  bool PFL() const { return high.PFL(); }
  bool OCF() const { return high.OCF(); }
  bool COF() const { return high.COF(); }
  bool CUF() const { return high.CUF(); }
  bool VhF() const { return high.VhF(); }
  bool ChF() const { return high.ChF(); }
  bool ULF() const { return high.ULF(); }
  bool ASP() const { return high.ASP(); }
  bool ABD() const { return high.ABD(); }
  bool ABP() const { return high.ABP(); }
  bool MAN() const { return high.MAN(); }
  bool __na_3_() const { return high.__na_3_(); }
  bool VOL() const { return high.VOL(); }
  bool VOH() const { return high.VOH(); }
  bool VOR() const { return high.VOR(); }
  bool BDF() const { return high.BDF(); }
  bool BDA() const { return high.BDA(); }
  bool BDP() const { return high.BDP(); }
  bool __na_4_() const { return high.__na_4_(); }
  bool __na_5_() const { return high.__na_5_(); }
  bool __na_6_() const { return high.__na_6_(); }
  bool __na_7_() const { return high.__na_7_(); }
  bool __na_8_() const { return high.__na_8_(); }
  bool __na_9_() const { return high.__na_9_(); }
  bool __na_10_() const { return high.__na_10_(); }
  bool __na_11_() const { return high.__na_11_(); }
  bool __na_12_() const { return high.__na_12_(); }
  bool IOK() const { return high.IOK(); }

  void bigEndian();
  static FaultData fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;

static_assert(sizeof(FaultData) == 16);
static_assert(std::is_standard_layout_v<FaultData>);
}  // namespace tas_powertek::spf21y