// main.cpp
#include <aws/core/Aws.h>
#include <aws/lambda-runtime/runtime.h>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <folly/ExceptionString.h>
#include <folly/base64.h>
#include <folly/json/json.h>
#include <folly/logging/xlog.h>

#include "../tas_powertek/spf-21y/Record.h"
#include "../tas_powertek/spf-21y/Response.h"
#include "DynamoStore.h"

using namespace aws::lambda_runtime;
using namespace tas_powertek::spf21y;

namespace {
static constexpr std::string_view kUserName = "";
static constexpr std::string_view kPassword = "";

static const std::string kBasicAuthString =
    fmt::format("{}:{}", kUserName, kPassword);
static const std::string kBasicAuthBase64 =
    folly::base64Encode(kBasicAuthString);

bool authenticate(const folly::dynamic& parsedRequest) {
  auto headers = parsedRequest.at("headers");
  if (headers.find("authorization") == headers.items().end()) {
    XLOG(INFO) << "Authorization header not found";
    return false;
  }
  std::string authorizationHeader = headers.at("authorization").asString();
  if (authorizationHeader.find("Basic ") != 0) {
    XLOG(INFO) << "Authorization header is not Basic";
    return false;
  }
  std::string authString = authorizationHeader.substr(6);
  if (authString != kBasicAuthBase64) {
    XLOG(INFO) << "Authorization header failed";
    return false;
  }

  XLOG(INFO) << "Authorization header passed";
  return true;
}
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

invocation_response createAccessDenied() {
  folly::dynamic result = folly::dynamic::object;
  result["statusCode"] = 403;
  result["headers"] = folly::dynamic::object;
  result["body"] = "Invalid credentials";
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
    if (!authenticate(parsedJson)) {
      return createAccessDenied();
    }

    auto requestBody = parsedJson.at("body").asString();
    if (parsedJson.at("isBase64Encoded") == true) {
      requestBody = folly::base64Decode(requestBody);
    }

    XLOG(INFO) << "The raw record is " << stringToHex(requestBody);
    Record record(requestBody);
    XLOGF(INFO,
          "Parsed Record: CompanyCode: {}, "
          "ProductSerialNumber: {}, DataType: {}, "
          "ProductId: {}, UnitId: {}, DataLength: {}, "
          "RecordId: {}, Transmission Time: {}, "
          "CheckSum: {}, Data: {}", record.companyCode(),
          record.productSerialNumber(), toString(record.dataType()), record.productId(), record.unitId(),
          record.dataLength(), record.dataRecordId(), record.clientTransmissionTime().toTimePoint().time_since_epoch().count(),
          stringToHex(record.checksum().toString()), "<TODO>");
    DynamoStore().put(record);
    Response response(record);
    std::string serializedResponse = response.serialize();
    XLOG(INFO) << "The raw response is " << stringToHex(serializedResponse);
    return invocation_response::success(std::move(serializedResponse),
                                        "application/octet-stream");
  } catch (const std::exception& e) {
    XLOG(ERR) << "Exception: " << folly::exceptionStr(e);
    return createFailure(e);
  }
}

int main() {
  Aws::SDKOptions options;
  options.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Info;
  Aws::InitAPI(options);
  run_handler(my_handler);
  Aws::ShutdownAPI(options);
  return 0;
}
