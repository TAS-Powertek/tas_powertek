#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include "../Record.h"

namespace tas_powertek::spf21y {

TEST(RecordTest, xlsRequest) {
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
  EXPECT_EQ(record.companyCode(), "TAS");
  EXPECT_EQ(record.productSerialNumber(), "1010004240020080");
  EXPECT_EQ(record.dataType(), DataType::INTERVAL_64);
  EXPECT_EQ(record.productId(), "SPF-21YFK60");
  EXPECT_EQ(record.unitId(), "00010001");
  EXPECT_EQ(record.dataLength(), sizeof(IntervalData64));
  EXPECT_EQ(record.dataRecordId(), "00001840");
  EXPECT_EQ(record.clientTransmissionTime().toTimePoint().time_since_epoch(),
            std::chrono::seconds{1832527311});
  EXPECT_EQ(record.checksum(), detail::CheckSum16{0xcbec});

  const IntervalData64& data = record.data<IntervalData64>();
  EXPECT_EQ(data.time.toTimePoint().time_since_epoch(),
            std::chrono::seconds{1713417828});
  // Too lazy to do the exhaustive assertion of the data - we got other tests
  // for that.
}
}  // namespace tas_powertek::spf21y