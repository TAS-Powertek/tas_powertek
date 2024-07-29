// main.cpp
#include <aws/lambda-runtime/runtime.h>
#include <fmt/core.h>
#include <folly/logging/xlog.h>

using namespace aws::lambda_runtime;

invocation_response my_handler(invocation_request const& request) {
  XLOG(INFO) << "The request has payload: " << request.payload;
  return invocation_response::success(
      fmt::format("Hello, World! The request payload was {}", request.payload),
      "text/plain");
}

int main() {
  run_handler(my_handler);
  return 0;
}