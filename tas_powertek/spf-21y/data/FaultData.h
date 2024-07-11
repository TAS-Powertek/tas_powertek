#pragma once

#include <folly/Portability.h>

#include <chrono>
#include <cstdint>

namespace tas_powertek::spf21y {

/**
 * FaultData with only half the bytes (and data). Contains the low 4 words (8
 * bytes) of data.
 */
struct FaultDataLow {
  std::bitset<56> faultBits;

  auto OVR() { return faultBits[0 * 16 + 0]; }
  auto UVR() { return faultBits[0 * 16 + 1]; }
  auto OVY() { return faultBits[0 * 16 + 2]; }
  auto UVY() { return faultBits[0 * 16 + 3]; }
  auto OVB() { return faultBits[0 * 16 + 4]; }
  auto UVB() { return faultBits[0 * 16 + 5]; }
  auto OCR() { return faultBits[0 * 16 + 6]; }
  auto ULR() { return faultBits[0 * 16 + 7]; }
  auto OCY() { return faultBits[0 * 16 + 8]; }
  auto ULY() { return faultBits[0 * 16 + 9]; }
  auto OCB() { return faultBits[0 * 16 + 10]; }
  auto ULB() { return faultBits[0 * 16 + 11]; }
  auto COR() { return faultBits[0 * 16 + 12]; }
  auto CUR() { return faultBits[0 * 16 + 13]; }
  auto COY() { return faultBits[0 * 16 + 14]; }
  auto CUY() { return faultBits[0 * 16 + 15]; }
  auto COB() { return faultBits[1 * 16 + 0]; }
  auto CUB() { return faultBits[1 * 16 + 1]; }
  auto SOF() { return faultBits[1 * 16 + 2]; }
  auto SUF() { return faultBits[1 * 16 + 3]; }
  auto MOT() { return faultBits[1 * 16 + 4]; }
  auto ChR() { return faultBits[1 * 16 + 5]; }
  auto ChY() { return faultBits[1 * 16 + 6]; }
  auto ChB() { return faultBits[1 * 16 + 7]; }
  auto OBF() { return faultBits[1 * 16 + 8]; }
  auto UBA() { return faultBits[1 * 16 + 9]; }
  auto OCN() { return faultBits[1 * 16 + 10]; }
  auto EOT() { return faultBits[1 * 16 + 11]; }
  auto PDN() { return faultBits[1 * 16 + 12]; }
  auto PUP() { return faultBits[1 * 16 + 13]; }
  auto RTC() { return faultBits[1 * 16 + 14]; }
  auto NVF() { return faultBits[1 * 16 + 15]; }
  auto ZCF() { return faultBits[2 * 16 + 0]; }
  auto ZVF() { return faultBits[2 * 16 + 1]; }
  auto MDW() { return faultBits[2 * 16 + 2]; }
  auto MDV() { return faultBits[2 * 16 + 3]; }
  auto UBV() { return faultBits[2 * 16 + 4]; }
  auto UBC() { return faultBits[2 * 16 + 5]; }
  auto __na_1_() { return faultBits[2 * 16 + 6]; }
  auto CEL() { return faultBits[2 * 16 + 7]; }
  auto VHF() { return faultBits[2 * 16 + 8]; }
  auto CHF() { return faultBits[2 * 16 + 9]; }
  auto PFR() { return faultBits[2 * 16 + 10]; }
  auto PFY() { return faultBits[2 * 16 + 11]; }
  auto PFB() { return faultBits[2 * 16 + 12]; }
  auto AVL() { return faultBits[2 * 16 + 13]; }
  auto AVH() { return faultBits[2 * 16 + 14]; }
  auto CBF() { return faultBits[2 * 16 + 15]; }
  auto SyF() { return faultBits[3 * 16 + 0]; }
  auto CTM() { return faultBits[3 * 16 + 1]; }
  auto ERU() { return faultBits[3 * 16 + 2]; }
  auto EWU() { return faultBits[3 * 16 + 3]; }
  auto RM1() { return faultBits[3 * 16 + 4]; }
  auto RM2() { return faultBits[3 * 16 + 5]; }
  auto DSB() { return faultBits[3 * 16 + 6]; }
  auto HLD() { return faultBits[3 * 16 + 7]; }
  auto AMG() { return faultBits[3 * 16 + 8]; }
  auto WDR() { return faultBits[3 * 16 + 9]; }
  auto SyA() { return faultBits[3 * 16 + 10]; }
  auto SyP() { return faultBits[3 * 16 + 11]; }
  auto ASM() { return faultBits[3 * 16 + 12]; }
  auto PEM() { return faultBits[3 * 16 + 13]; }
  auto _EOF() { return faultBits[3 * 16 + 14]; }
  auto _4GN() { return faultBits[3 * 16 + 15]; }

  bool OVR() const { return faultBits[0 * 16 + 0]; }
  bool UVR() const { return faultBits[0 * 16 + 1]; }
  bool OVY() const { return faultBits[0 * 16 + 2]; }
  bool UVY() const { return faultBits[0 * 16 + 3]; }
  bool OVB() const { return faultBits[0 * 16 + 4]; }
  bool UVB() const { return faultBits[0 * 16 + 5]; }
  bool OCR() const { return faultBits[0 * 16 + 6]; }
  bool ULR() const { return faultBits[0 * 16 + 7]; }
  bool OCY() const { return faultBits[0 * 16 + 8]; }
  bool ULY() const { return faultBits[0 * 16 + 9]; }
  bool OCB() const { return faultBits[0 * 16 + 10]; }
  bool ULB() const { return faultBits[0 * 16 + 11]; }
  bool COR() const { return faultBits[0 * 16 + 12]; }
  bool CUR() const { return faultBits[0 * 16 + 13]; }
  bool COY() const { return faultBits[0 * 16 + 14]; }
  bool CUY() const { return faultBits[0 * 16 + 15]; }
  bool COB() const { return faultBits[1 * 16 + 0]; }
  bool CUB() const { return faultBits[1 * 16 + 1]; }
  bool SOF() const { return faultBits[1 * 16 + 2]; }
  bool SUF() const { return faultBits[1 * 16 + 3]; }
  bool MOT() const { return faultBits[1 * 16 + 4]; }
  bool ChR() const { return faultBits[1 * 16 + 5]; }
  bool ChY() const { return faultBits[1 * 16 + 6]; }
  bool ChB() const { return faultBits[1 * 16 + 7]; }
  bool OBF() const { return faultBits[1 * 16 + 8]; }
  bool UBA() const { return faultBits[1 * 16 + 9]; }
  bool OCN() const { return faultBits[1 * 16 + 10]; }
  bool EOT() const { return faultBits[1 * 16 + 11]; }
  bool PDN() const { return faultBits[1 * 16 + 12]; }
  bool PUP() const { return faultBits[1 * 16 + 13]; }
  bool RTC() const { return faultBits[1 * 16 + 14]; }
  bool NVF() const { return faultBits[1 * 16 + 15]; }
  bool ZCF() const { return faultBits[2 * 16 + 0]; }
  bool ZVF() const { return faultBits[2 * 16 + 1]; }
  bool MDW() const { return faultBits[2 * 16 + 2]; }
  bool MDV() const { return faultBits[2 * 16 + 3]; }
  bool UBV() const { return faultBits[2 * 16 + 4]; }
  bool UBC() const { return faultBits[2 * 16 + 5]; }
  bool __na_1_() const { return faultBits[2 * 16 + 6]; }
  bool CEL() const { return faultBits[2 * 16 + 7]; }
  bool VHF() const { return faultBits[2 * 16 + 8]; }
  bool CHF() const { return faultBits[2 * 16 + 9]; }
  bool PFR() const { return faultBits[2 * 16 + 10]; }
  bool PFY() const { return faultBits[2 * 16 + 11]; }
  bool PFB() const { return faultBits[2 * 16 + 12]; }
  bool AVL() const { return faultBits[2 * 16 + 13]; }
  bool AVH() const { return faultBits[2 * 16 + 14]; }
  bool CBF() const { return faultBits[2 * 16 + 15]; }
  bool SyF() const { return faultBits[3 * 16 + 0]; }
  bool CTM() const { return faultBits[3 * 16 + 1]; }
  bool ERU() const { return faultBits[3 * 16 + 2]; }
  bool EWU() const { return faultBits[3 * 16 + 3]; }
  bool RM1() const { return faultBits[3 * 16 + 4]; }
  bool RM2() const { return faultBits[3 * 16 + 5]; }
  bool DSB() const { return faultBits[3 * 16 + 6]; }
  bool HLD() const { return faultBits[3 * 16 + 7]; }
  bool AMG() const { return faultBits[3 * 16 + 8]; }
  bool WDR() const { return faultBits[3 * 16 + 9]; }
  bool SyA() const { return faultBits[3 * 16 + 10]; }
  bool SyP() const { return faultBits[3 * 16 + 11]; }
  bool ASM() const { return faultBits[3 * 16 + 12]; }
  bool PEM() const { return faultBits[3 * 16 + 13]; }
  bool _EOF() const { return faultBits[3 * 16 + 14]; }
  bool _4GN() const { return faultBits[3 * 16 + 15]; }

  void bigEndian();
  static FaultDataLow fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;

static_assert(sizeof(FaultDataLow) == 8);
static_assert(std::is_standard_layout_v<FaultDataLow>);

struct FaultData {
  std::bitset<128> faultBits;

  auto OVR() { return faultBits[0 * 16 + 0]; }
  auto UVR() { return faultBits[0 * 16 + 1]; }
  auto OVY() { return faultBits[0 * 16 + 2]; }
  auto UVY() { return faultBits[0 * 16 + 3]; }
  auto OVB() { return faultBits[0 * 16 + 4]; }
  auto UVB() { return faultBits[0 * 16 + 5]; }
  auto OCR() { return faultBits[0 * 16 + 6]; }
  auto ULR() { return faultBits[0 * 16 + 7]; }
  auto OCY() { return faultBits[0 * 16 + 8]; }
  auto ULY() { return faultBits[0 * 16 + 9]; }
  auto OCB() { return faultBits[0 * 16 + 10]; }
  auto ULB() { return faultBits[0 * 16 + 11]; }
  auto COR() { return faultBits[0 * 16 + 12]; }
  auto CUR() { return faultBits[0 * 16 + 13]; }
  auto COY() { return faultBits[0 * 16 + 14]; }
  auto CUY() { return faultBits[0 * 16 + 15]; }
  auto COB() { return faultBits[1 * 16 + 0]; }
  auto CUB() { return faultBits[1 * 16 + 1]; }
  auto SOF() { return faultBits[1 * 16 + 2]; }
  auto SUF() { return faultBits[1 * 16 + 3]; }
  auto MOT() { return faultBits[1 * 16 + 4]; }
  auto ChR() { return faultBits[1 * 16 + 5]; }
  auto ChY() { return faultBits[1 * 16 + 6]; }
  auto ChB() { return faultBits[1 * 16 + 7]; }
  auto OBF() { return faultBits[1 * 16 + 8]; }
  auto UBA() { return faultBits[1 * 16 + 9]; }
  auto OCN() { return faultBits[1 * 16 + 10]; }
  auto EOT() { return faultBits[1 * 16 + 11]; }
  auto PDN() { return faultBits[1 * 16 + 12]; }
  auto PUP() { return faultBits[1 * 16 + 13]; }
  auto RTC() { return faultBits[1 * 16 + 14]; }
  auto NVF() { return faultBits[1 * 16 + 15]; }
  auto ZCF() { return faultBits[2 * 16 + 0]; }
  auto ZVF() { return faultBits[2 * 16 + 1]; }
  auto MDW() { return faultBits[2 * 16 + 2]; }
  auto MDV() { return faultBits[2 * 16 + 3]; }
  auto UBV() { return faultBits[2 * 16 + 4]; }
  auto UBC() { return faultBits[2 * 16 + 5]; }
  auto __na_1_() { return faultBits[2 * 16 + 6]; }
  auto CEL() { return faultBits[2 * 16 + 7]; }
  auto VHF() { return faultBits[2 * 16 + 8]; }
  auto CHF() { return faultBits[2 * 16 + 9]; }
  auto PFR() { return faultBits[2 * 16 + 10]; }
  auto PFY() { return faultBits[2 * 16 + 11]; }
  auto PFB() { return faultBits[2 * 16 + 12]; }
  auto AVL() { return faultBits[2 * 16 + 13]; }
  auto AVH() { return faultBits[2 * 16 + 14]; }
  auto CBF() { return faultBits[2 * 16 + 15]; }
  auto SyF() { return faultBits[3 * 16 + 0]; }
  auto CTM() { return faultBits[3 * 16 + 1]; }
  auto ERU() { return faultBits[3 * 16 + 2]; }
  auto EWU() { return faultBits[3 * 16 + 3]; }
  auto RM1() { return faultBits[3 * 16 + 4]; }
  auto RM2() { return faultBits[3 * 16 + 5]; }
  auto DSB() { return faultBits[3 * 16 + 6]; }
  auto HLD() { return faultBits[3 * 16 + 7]; }
  auto AMG() { return faultBits[3 * 16 + 8]; }
  auto WDR() { return faultBits[3 * 16 + 9]; }
  auto SyA() { return faultBits[3 * 16 + 10]; }
  auto SyP() { return faultBits[3 * 16 + 11]; }
  auto ASM() { return faultBits[3 * 16 + 12]; }
  auto PEM() { return faultBits[3 * 16 + 13]; }
  auto _EOF() { return faultBits[3 * 16 + 14]; }
  auto _4GN() { return faultBits[3 * 16 + 15]; }
  auto ERC() { return faultBits[4 * 16 + 0]; }
  auto ERP() { return faultBits[4 * 16 + 1]; }
  auto ERE() { return faultBits[4 * 16 + 2]; }
  auto ERL() { return faultBits[4 * 16 + 3]; }
  auto EWC() { return faultBits[4 * 16 + 4]; }
  auto EWP() { return faultBits[4 * 16 + 5]; }
  auto EWE() { return faultBits[4 * 16 + 6]; }
  auto EWL() { return faultBits[4 * 16 + 7]; }
  auto CM1() { return faultBits[4 * 16 + 8]; }
  auto CM2() { return faultBits[4 * 16 + 9]; }
  auto PSV() { return faultBits[4 * 16 + 10]; }
  auto CRT() { return faultBits[4 * 16 + 11]; }
  auto MRT() { return faultBits[4 * 16 + 12]; }
  auto UCR() { return faultBits[4 * 16 + 13]; }
  auto WST() { return faultBits[4 * 16 + 14]; }
  auto __na_2_() { return faultBits[4 * 16 + 15]; }
  auto ZVR() { return faultBits[5 * 16 + 0]; }
  auto ZVY() { return faultBits[5 * 16 + 1]; }
  auto ZVB() { return faultBits[5 * 16 + 2]; }
  auto ZCR() { return faultBits[5 * 16 + 3]; }
  auto ZCY() { return faultBits[5 * 16 + 4]; }
  auto ZCB() { return faultBits[5 * 16 + 5]; }
  auto VHR() { return faultBits[5 * 16 + 6]; }
  auto VHY() { return faultBits[5 * 16 + 7]; }
  auto VHB() { return faultBits[5 * 16 + 8]; }
  auto CHR() { return faultBits[5 * 16 + 9]; }
  auto CHY() { return faultBits[5 * 16 + 10]; }
  auto CHB() { return faultBits[5 * 16 + 11]; }
  auto OBR() { return faultBits[5 * 16 + 12]; }
  auto OBY() { return faultBits[5 * 16 + 13]; }
  auto OBB() { return faultBits[5 * 16 + 14]; }
  auto VRH() { return faultBits[5 * 16 + 15]; }
  auto VYH() { return faultBits[6 * 16 + 0]; }
  auto VBH() { return faultBits[6 * 16 + 1]; }
  auto UVF() { return faultBits[6 * 16 + 2]; }
  auto OVF() { return faultBits[6 * 16 + 3]; }
  auto PFL() { return faultBits[6 * 16 + 4]; }
  auto OCF() { return faultBits[6 * 16 + 5]; }
  auto COF() { return faultBits[6 * 16 + 6]; }
  auto CUF() { return faultBits[6 * 16 + 7]; }
  auto VhF() { return faultBits[6 * 16 + 8]; }
  auto ChF() { return faultBits[6 * 16 + 9]; }
  auto ULF() { return faultBits[6 * 16 + 10]; }
  auto ASP() { return faultBits[6 * 16 + 11]; }
  auto ABD() { return faultBits[6 * 16 + 12]; }
  auto ABP() { return faultBits[6 * 16 + 13]; }
  auto MAN() { return faultBits[6 * 16 + 14]; }
  auto __na_3_() { return faultBits[6 * 16 + 15]; }
  auto VOL() { return faultBits[7 * 16 + 0]; }
  auto VOH() { return faultBits[7 * 16 + 1]; }
  auto VOR() { return faultBits[7 * 16 + 2]; }
  auto BDF() { return faultBits[7 * 16 + 3]; }
  auto BDA() { return faultBits[7 * 16 + 4]; }
  auto BDP() { return faultBits[7 * 16 + 5]; }
  auto __na_4_() { return faultBits[7 * 16 + 6]; }
  auto __na_5_() { return faultBits[7 * 16 + 7]; }
  auto __na_6_() { return faultBits[7 * 16 + 8]; }
  auto __na_7_() { return faultBits[7 * 16 + 9]; }
  auto __na_8_() { return faultBits[7 * 16 + 10]; }
  auto __na_9_() { return faultBits[7 * 16 + 11]; }
  auto __na_10_() { return faultBits[7 * 16 + 12]; }
  auto __na_11_() { return faultBits[7 * 16 + 13]; }
  auto __na_12_() { return faultBits[7 * 16 + 14]; }
  auto IOK() { return faultBits[7 * 16 + 15]; }

  bool OVR() const { return faultBits[0 * 16 + 0]; }
  bool UVR() const { return faultBits[0 * 16 + 1]; }
  bool OVY() const { return faultBits[0 * 16 + 2]; }
  bool UVY() const { return faultBits[0 * 16 + 3]; }
  bool OVB() const { return faultBits[0 * 16 + 4]; }
  bool UVB() const { return faultBits[0 * 16 + 5]; }
  bool OCR() const { return faultBits[0 * 16 + 6]; }
  bool ULR() const { return faultBits[0 * 16 + 7]; }
  bool OCY() const { return faultBits[0 * 16 + 8]; }
  bool ULY() const { return faultBits[0 * 16 + 9]; }
  bool OCB() const { return faultBits[0 * 16 + 10]; }
  bool ULB() const { return faultBits[0 * 16 + 11]; }
  bool COR() const { return faultBits[0 * 16 + 12]; }
  bool CUR() const { return faultBits[0 * 16 + 13]; }
  bool COY() const { return faultBits[0 * 16 + 14]; }
  bool CUY() const { return faultBits[0 * 16 + 15]; }
  bool COB() const { return faultBits[1 * 16 + 0]; }
  bool CUB() const { return faultBits[1 * 16 + 1]; }
  bool SOF() const { return faultBits[1 * 16 + 2]; }
  bool SUF() const { return faultBits[1 * 16 + 3]; }
  bool MOT() const { return faultBits[1 * 16 + 4]; }
  bool ChR() const { return faultBits[1 * 16 + 5]; }
  bool ChY() const { return faultBits[1 * 16 + 6]; }
  bool ChB() const { return faultBits[1 * 16 + 7]; }
  bool OBF() const { return faultBits[1 * 16 + 8]; }
  bool UBA() const { return faultBits[1 * 16 + 9]; }
  bool OCN() const { return faultBits[1 * 16 + 10]; }
  bool EOT() const { return faultBits[1 * 16 + 11]; }
  bool PDN() const { return faultBits[1 * 16 + 12]; }
  bool PUP() const { return faultBits[1 * 16 + 13]; }
  bool RTC() const { return faultBits[1 * 16 + 14]; }
  bool NVF() const { return faultBits[1 * 16 + 15]; }
  bool ZCF() const { return faultBits[2 * 16 + 0]; }
  bool ZVF() const { return faultBits[2 * 16 + 1]; }
  bool MDW() const { return faultBits[2 * 16 + 2]; }
  bool MDV() const { return faultBits[2 * 16 + 3]; }
  bool UBV() const { return faultBits[2 * 16 + 4]; }
  bool UBC() const { return faultBits[2 * 16 + 5]; }
  bool __na_1_() const { return faultBits[2 * 16 + 6]; }
  bool CEL() const { return faultBits[2 * 16 + 7]; }
  bool VHF() const { return faultBits[2 * 16 + 8]; }
  bool CHF() const { return faultBits[2 * 16 + 9]; }
  bool PFR() const { return faultBits[2 * 16 + 10]; }
  bool PFY() const { return faultBits[2 * 16 + 11]; }
  bool PFB() const { return faultBits[2 * 16 + 12]; }
  bool AVL() const { return faultBits[2 * 16 + 13]; }
  bool AVH() const { return faultBits[2 * 16 + 14]; }
  bool CBF() const { return faultBits[2 * 16 + 15]; }
  bool SyF() const { return faultBits[3 * 16 + 0]; }
  bool CTM() const { return faultBits[3 * 16 + 1]; }
  bool ERU() const { return faultBits[3 * 16 + 2]; }
  bool EWU() const { return faultBits[3 * 16 + 3]; }
  bool RM1() const { return faultBits[3 * 16 + 4]; }
  bool RM2() const { return faultBits[3 * 16 + 5]; }
  bool DSB() const { return faultBits[3 * 16 + 6]; }
  bool HLD() const { return faultBits[3 * 16 + 7]; }
  bool AMG() const { return faultBits[3 * 16 + 8]; }
  bool WDR() const { return faultBits[3 * 16 + 9]; }
  bool SyA() const { return faultBits[3 * 16 + 10]; }
  bool SyP() const { return faultBits[3 * 16 + 11]; }
  bool ASM() const { return faultBits[3 * 16 + 12]; }
  bool PEM() const { return faultBits[3 * 16 + 13]; }
  bool _EOF() const { return faultBits[3 * 16 + 14]; }
  bool _4GN() const { return faultBits[3 * 16 + 15]; }
  bool ERC() const { return faultBits[4 * 16 + 0]; }
  bool ERP() const { return faultBits[4 * 16 + 1]; }
  bool ERE() const { return faultBits[4 * 16 + 2]; }
  bool ERL() const { return faultBits[4 * 16 + 3]; }
  bool EWC() const { return faultBits[4 * 16 + 4]; }
  bool EWP() const { return faultBits[4 * 16 + 5]; }
  bool EWE() const { return faultBits[4 * 16 + 6]; }
  bool EWL() const { return faultBits[4 * 16 + 7]; }
  bool CM1() const { return faultBits[4 * 16 + 8]; }
  bool CM2() const { return faultBits[4 * 16 + 9]; }
  bool PSV() const { return faultBits[4 * 16 + 10]; }
  bool CRT() const { return faultBits[4 * 16 + 11]; }
  bool MRT() const { return faultBits[4 * 16 + 12]; }
  bool UCR() const { return faultBits[4 * 16 + 13]; }
  bool WST() const { return faultBits[4 * 16 + 14]; }
  bool __na_2_() const { return faultBits[4 * 16 + 15]; }
  bool ZVR() const { return faultBits[5 * 16 + 0]; }
  bool ZVY() const { return faultBits[5 * 16 + 1]; }
  bool ZVB() const { return faultBits[5 * 16 + 2]; }
  bool ZCR() const { return faultBits[5 * 16 + 3]; }
  bool ZCY() const { return faultBits[5 * 16 + 4]; }
  bool ZCB() const { return faultBits[5 * 16 + 5]; }
  bool VHR() const { return faultBits[5 * 16 + 6]; }
  bool VHY() const { return faultBits[5 * 16 + 7]; }
  bool VHB() const { return faultBits[5 * 16 + 8]; }
  bool CHR() const { return faultBits[5 * 16 + 9]; }
  bool CHY() const { return faultBits[5 * 16 + 10]; }
  bool CHB() const { return faultBits[5 * 16 + 11]; }
  bool OBR() const { return faultBits[5 * 16 + 12]; }
  bool OBY() const { return faultBits[5 * 16 + 13]; }
  bool OBB() const { return faultBits[5 * 16 + 14]; }
  bool VRH() const { return faultBits[5 * 16 + 15]; }
  bool VYH() const { return faultBits[6 * 16 + 0]; }
  bool VBH() const { return faultBits[6 * 16 + 1]; }
  bool UVF() const { return faultBits[6 * 16 + 2]; }
  bool OVF() const { return faultBits[6 * 16 + 3]; }
  bool PFL() const { return faultBits[6 * 16 + 4]; }
  bool OCF() const { return faultBits[6 * 16 + 5]; }
  bool COF() const { return faultBits[6 * 16 + 6]; }
  bool CUF() const { return faultBits[6 * 16 + 7]; }
  bool VhF() const { return faultBits[6 * 16 + 8]; }
  bool ChF() const { return faultBits[6 * 16 + 9]; }
  bool ULF() const { return faultBits[6 * 16 + 10]; }
  bool ASP() const { return faultBits[6 * 16 + 11]; }
  bool ABD() const { return faultBits[6 * 16 + 12]; }
  bool ABP() const { return faultBits[6 * 16 + 13]; }
  bool MAN() const { return faultBits[6 * 16 + 14]; }
  bool __na_3_() const { return faultBits[6 * 16 + 15]; }
  bool VOL() const { return faultBits[7 * 16 + 0]; }
  bool VOH() const { return faultBits[7 * 16 + 1]; }
  bool VOR() const { return faultBits[7 * 16 + 2]; }
  bool BDF() const { return faultBits[7 * 16 + 3]; }
  bool BDA() const { return faultBits[7 * 16 + 4]; }
  bool BDP() const { return faultBits[7 * 16 + 5]; }
  bool __na_4_() const { return faultBits[7 * 16 + 6]; }
  bool __na_5_() const { return faultBits[7 * 16 + 7]; }
  bool __na_6_() const { return faultBits[7 * 16 + 8]; }
  bool __na_7_() const { return faultBits[7 * 16 + 9]; }
  bool __na_8_() const { return faultBits[7 * 16 + 10]; }
  bool __na_9_() const { return faultBits[7 * 16 + 11]; }
  bool __na_10_() const { return faultBits[7 * 16 + 12]; }
  bool __na_11_() const { return faultBits[7 * 16 + 13]; }
  bool __na_12_() const { return faultBits[7 * 16 + 14]; }
  bool IOK() const { return faultBits[7 * 16 + 15]; }

  void bigEndian();
  static FaultData fromByteStream(std::string_view data);
} FOLLY_PACK_ATTR;

static_assert(sizeof(FaultData) == 16);
static_assert(std::is_standard_layout_v<FaultData>);
}  // namespace tas_powertek::spf21y