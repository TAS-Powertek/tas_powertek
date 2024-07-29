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
  explicit Response(const Record& record);
  Response(const Response&) = default;
  Response& operator=(const Response&) = delete;
  ~Response() = default;

  std::string serialize() const;

 private:
  const Record& record;
};

}  // namespace tas_powertek::spf21y