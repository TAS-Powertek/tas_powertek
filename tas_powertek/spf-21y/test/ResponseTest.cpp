#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include "../Response.h"

namespace tas_powertek::spf21y {

TEST(ResponseTest, xlsResponse) {
  constexpr std::string_view kSampleRequest{
      "\x02TAS 1010004240020080IN "
      "SPF-"
      "21YFK600001000100630000184036350A120407E8\x0D\x0A\x30\x35\x0a\x12\x04"
      "\x07\xe8\x42\x48\x2c\xb2\x43\x6f\xd4\x1a\x43\x6f\xd4\x1a\x3f\xc9\x34\x57"
      "\x43\xcf\x9a\xb8\x43\xcf\x9a\xb8\x44\x00\x25\xa8\x43\x4a\x9d\xdf\x48\xa5"
      "\x8a\xe7\x45\xac\x4e\x78\x3f\x7f\xbe\x77\x43\xb6\x76\x0b\x43\xae\xb7\x95"
      "\x43\xb6\x5a\xe3\x44\x28\x08\xb1\x43\x91\xc1\xb8\x43\x8e\xc9\x53\x43\x96"
      "\xa2\xf1\x43\x4f\xeb\xb9\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x11\x00"
      "\xcb\xec\x03",
      169};
  Record record{kSampleRequest};
  Response response{record};
  std::string serializedResponse = response.serialize(
      std::chrono::sys_seconds(std::chrono::seconds(1722380117)));
  std::string_view sv{serializedResponse};
  EXPECT_EQ(sv.substr(0, 1), "\x02");
  EXPECT_EQ(sv.substr(1, 4), record.companyCode());
  EXPECT_EQ(sv.substr(5, 16), record.productSerialNumber());
  EXPECT_EQ(sv.substr(21, 3), "IN ");
  EXPECT_EQ(sv.substr(24, 11), record.productId());
  EXPECT_EQ(sv.substr(35, 8), record.unitId());
  EXPECT_EQ(sv.substr(43, 4), fmt::format("{:0>4X}", 99));
  EXPECT_EQ(sv.substr(47, 8), record.dataRecordId());
  // client time
  EXPECT_EQ(sv.substr(55, 2), fmt::format("{:0>2X}", 54));    // s
  EXPECT_EQ(sv.substr(57, 2), fmt::format("{:0>2X}", 53));    // m
  EXPECT_EQ(sv.substr(59, 2), fmt::format("{:0>2X}", 10));    // h
  EXPECT_EQ(sv.substr(61, 2), fmt::format("{:0>2X}", 18));    // d
  EXPECT_EQ(sv.substr(63, 2), fmt::format("{:0>2X}", 4));     // mo
  EXPECT_EQ(sv.substr(65, 4), fmt::format("{:0>4X}", 2024));  // y
  // server / ack time
  EXPECT_EQ(sv.substr(69, 2), fmt::format("{:0>2X}", 17));       // s
  EXPECT_EQ(sv.substr(71, 2), fmt::format("{:0>2X}", 25));       // m
  EXPECT_EQ(sv.substr(73, 2), fmt::format("{:0>2X}", 04));       // h
  EXPECT_EQ(sv.substr(75, 2), fmt::format("{:0>2X}", 31));       // d
  EXPECT_EQ(sv.substr(77, 2), fmt::format("{:0>2X}", 7));        // mo
  EXPECT_EQ(sv.substr(79, 4), fmt::format("{:0>4X}", 2024));     // y
  EXPECT_EQ(sv.substr(83, 4), std::string_view("\0\0\0\0", 4));  // ack body

  // Validate checksum.
  detail::CheckSum16 computed = detail::CheckSum16::compute(sv.substr(0, 86));
  std::string_view checkSumSv = sv.substr(87, 2);
  uint16_t checksumInResponse;
  std::memcpy(&checksumInResponse, checkSumSv.data(), sizeof(uint16_t));
  checksumInResponse = folly::Endian::big(checksumInResponse);
  EXPECT_EQ(checksumInResponse, computed.underlying());
}
}  // namespace tas_powertek::spf21y
