#pragma once

#include "../tas_powertek/spf-21y/Record.h"
#include "../tas_powertek/spf-21y/Response.h"

namespace tas_powertek::spf21y {

class DynamoStore {
 public:
  void put(const Record& record);
};
}  // namespace tas_powertek::spf21y