#pragma once
#include <chrono>
#include <string>
#include <string_view>

#include "Enums.h"
#include "RecordData.h"
#include "detail/CheckSum.h"

namespace tas_powertek::spf21y {

using TimePoint =
    std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>;

class Record {
 public:
  explicit Record(std::string_view raw);
  Record(const Record&) = delete;
  Record(Record&&) noexcept = default;
  Record& operator=(const Record&) = delete;
  Record& operator=(Record&&) noexcept = default;
  ~Record() = default;

  bool isValid() const;
  std::string_view companyCode() const;
  std::string_view productSerialNumber() const;
  DataType dataType() const;
  // productId == model number
  std::string_view productId() const;
  std::string_view unitId() const;
  size_t dataLength() const;
  std::string_view dataRecordId() const;
  TimePoint timestamp() const;

  const RecordData& data() const;

  template <typename T>
    requires std::derived_from<T, RecordData>
  const T& data() const;

  detail::CheckSum16 checksum() const;

 private:
  bool isValid_ = false;
  std::string companyCode_;
  std::string productSerialNumber_;
  std::string productId_;
  std::string unitId_;
  size_t dataLength_;
  std::string dataRecordId_;
  TimePoint timestamp_;

  std::unique_ptr<RecordData> data_;
  detail::CheckSum16 checksum_;
};

}  // namespace tas_powertek::spf21y