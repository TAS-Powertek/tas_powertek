#pragma once
#include <chrono>
#include <string>
#include <string_view>

#include "Enums.h"
#include "data/DailyData.h"
#include "data/EventData.h"
#include "data/IntervalData128.h"
#include "data/IntervalData256.h"
#include "data/IntervalData512.h"
#include "data/IntervalData64.h"
#include "data/RealTimeData.h"
#include "data/UserSettingData.h"
#include "detail/CheckSum.h"

namespace tas_powertek::spf21y {

class Record {
 public:
  explicit Record(std::string_view raw);
  Record(const Record&) = delete;
  Record(Record&&) noexcept = default;
  Record& operator=(const Record&) = delete;
  Record& operator=(Record&&) noexcept = default;
  ~Record() = default;

  std::string_view companyCode() const { return companyCode_; }
  std::string_view productSerialNumber() const { return productSerialNumber_; }
  DataType dataType() const;
  // productId == model number
  std::string_view productId() const { return productId_; }
  std::string_view unitId() const { return unitId_; }
  size_t dataLength() const { return dataLength_; }
  std::string_view dataRecordId() const { return dataRecordId_; }
  const TimeData& clientTransmissionTime() const {
    return clientTransmissionTime_;
  }

  template <typename T>
  const T& data() const {
    return *(std::get<std::unique_ptr<T>>(data_));
  }
  template <typename T>
  T data() && {
    return std::move(*(std::get<std::unique_ptr<T>>(data_)));
  }

  detail::CheckSum16 checksum() const { return checksum_; }

 private:
  std::string companyCode_;
  std::string productSerialNumber_;
  std::string productId_;
  std::string unitId_;
  size_t dataLength_;
  std::string dataRecordId_;
  TimeData clientTransmissionTime_;

  std::variant<
      std::unique_ptr<EventData>, std::unique_ptr<IntervalData64>,
      std::unique_ptr<IntervalData128>, std::unique_ptr<IntervalData256>,
      std::unique_ptr<IntervalData512>, std::unique_ptr<DailyData>,
      std::unique_ptr<UserSettingData>, std::unique_ptr<RealTimeData64>,
      std::unique_ptr<RealTimeData128>, std::unique_ptr<RealTimeData256>,
      std::unique_ptr<RealTimeData512>>
      data_;
  detail::CheckSum16 checksum_;
};

}  // namespace tas_powertek::spf21y