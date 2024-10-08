// main.cpp
#include <aws/lambda-runtime/runtime.h>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <folly/ExceptionString.h>
#include <folly/base64.h>
#include <folly/json/json.h>
#include <folly/logging/xlog.h>

#include "../tas_powertek/spf-21y/Record.h"
#include "../tas_powertek/spf-21y/Response.h"

using namespace aws::lambda_runtime;
using namespace tas_powertek::spf21y;

namespace {
invocation_response createFailure(const std::exception& e) {
  folly::dynamic result = folly::dynamic::object;
  result["statusCode"] = 400;
  result["headers"] = folly::dynamic::object;
  result["headers"]["err"] = folly::exceptionStr(e);
  result["body"] = folly::exceptionStr(e);
  // https://github.com/awslabs/aws-lambda-cpp/issues/200
  return invocation_response::success(folly::toJson(result),
                                      "application/json");
}

std::string stringToHex(std::string_view input) {
  static const char hex_digits[] = "0123456789ABCDEF";

  std::string output;
  output.reserve(input.length() * 2);
  for (unsigned char c : input) {
    output.push_back(hex_digits[c >> 4]);
    output.push_back(hex_digits[c & 15]);
    output.push_back(' ');
  }
  return output;
}

static const std::unordered_set<std::string> kAcceptedMimeTypes{
    "binary/octet-stream", "application/octet-stream"};
}  // namespace

// Sample request -
// {
//     "version": "2.0",
//     "routeKey": "$default",
//     "rawPath": "/",
//     "rawQueryString": "",
//     "headers": {
//         "content-length": "18",
//         "x-amzn-tls-version": "TLSv1.3",
//         "x-forwarded-proto": "https",
//         "postman-token": "06a0350b-dc49-432d-ab5d-ec710c880395",
//         "x-forwarded-port": "443",
//         "x-forwarded-for": "24.18.126.210",
//         "accept": "*/*",
//         "x-amzn-tls-cipher-suite": "TLS_AES_128_GCM_SHA256",
//         "x-amzn-trace-id": "Root=1-66a87b13-4be05f60501545364549fb5c",
//         "host":
//         "c7665itegvbeeq64uigoh65m640mnxam.lambda-url.ap-south-1.on.aws",
//         "content-type": "text/plain",
//         "accept-encoding": "gzip, deflate, br",
//         "user-agent": "PostmanRuntime/7.40.0"
//     },
//     "requestContext": {
//         "accountId": "anonymous",
//         "apiId": "c7665itegvbeeq64uigoh65m640mnxam",
//         "domainName":
//         "c7665itegvbeeq64uigoh65m640mnxam.lambda-url.ap-south-1.on.aws",
//         "domainPrefix": "c7665itegvbeeq64uigoh65m640mnxam",
//         "http": {
//             "method": "POST",
//             "path": "/",
//             "protocol": "HTTP/1.1",
//             "sourceIp": "24.18.126.210",
//             "userAgent": "PostmanRuntime/7.40.0"
//         },
//         "requestId": "2dc2584d-39bb-4cd1-b830-9226a6079d7e",
//         "routeKey": "$default",
//         "stage": "$default",
//         "time": "30/Jul/2024:05:33:07 +0000",
//         "timeEpoch": 1722317587854
//     },
//     "body": "foo-bar donkey doo",
//     "isBase64Encoded": false
// }

invocation_response my_handler(invocation_request const& request) {
  try {
    XLOG(INFO) << "Received a request with payload: " << request.payload;
    folly::dynamic parsedJson = folly::parseJson(request.payload);
    auto requestContext = parsedJson.at("requestContext");
    auto requestHttpContext = requestContext.at("http");
    if (requestHttpContext.at("method") != "POST") {
      throw std::logic_error("Only POST requests are supported");
    }
    if (!kAcceptedMimeTypes.contains(
            parsedJson.at("headers").at("content-type").asString())) {
      throw std::logic_error(fmt::format(
          "Content-Type must be set to one of {}", kAcceptedMimeTypes));
    }

    auto requestBody = parsedJson.at("body").asString();
    if (parsedJson.at("isBase64Encoded") == true) {
      requestBody = folly::base64Decode(requestBody);
    }

    XLOG(INFO) << "The raw record is " << stringToHex(requestBody);
    Record record(requestBody);

    Response response(record);
    return invocation_response::success(response.serialize(),
                                        "application/octet-stream");
  } catch (const std::exception& e) {
    XLOG(ERR) << "Exception: " << folly::exceptionStr(e);
    return createFailure(e);
  }
}

int main() {
  run_handler(my_handler);
  return 0;
}