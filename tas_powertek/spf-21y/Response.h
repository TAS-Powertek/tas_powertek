#pragma once
#include <chrono>
#include <string>
#include <string_view>

#include "Enums.h"
#include "Record.h"
#include "detail/CheckSum.h"

namespace tas_powertek::spf21y {

// aka acknowledgement
class Response {
 public:
  explicit Response(const Record& record) : record(record) {}
  Response(const Response&) = default;
  Response& operator=(const Response&) = delete;
  ~Response() = default;

  std::string serialize(std::chrono::sys_seconds curTime =
                            std::chrono::time_point_cast<std::chrono::seconds>(
                                std::chrono::system_clock::now())) const;

 private:
  const Record& record;
};

}  // namespace tas_powertek::spf21y