
#include <aws/core/Aws.h>
#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/dynamodb/model/AttributeDefinition.h>
#include <aws/dynamodb/model/GetItemRequest.h>

namespace tas_powertek::spf21y {

namespace {
constexpr std::string_view kTableName{"spf21ytester"};
constexpr std::string_view kCompanyCode{"company_code"};
constexpr std::string_view kProductSerialNumber{"product_serial_number"};
constexpr std::string_view kDataType{"data_type"};
constexpr std::string_view kProductId{"product_id"};
constexpr std::string_view kUnitId{"unit_id"};
constexpr std::string_view kDataLength{"data_length"};
constexpr std::string_view kDataRecordId{"record_id"};
constexpr std::string_view kClientTransmissionTime{"transmission_time"};
constexpr std::string_view kChecksum{"checksum"};

std::string epochSecString(const TimeData& data) {
  return std::to_string(data.toTimePoint().time_since_epoch().count());
}
}  // namespace

namespace {

void addAttributes(Aws::DynamoDB::Model::PutItemRequest& destination,
                   const EventData& data) {}
void addAttributes(Aws::DynamoDB::Model::PutItemRequest& destination,
                   const IntervalData64& data) {}
void addAttributes(Aws::DynamoDB::Model::PutItemRequest& destination,
                   const IntervalData128& data) {}
void addAttributes(Aws::DynamoDB::Model::PutItemRequest& destination,
                   const IntervalData256& data) {}
void addAttributes(Aws::DynamoDB::Model::PutItemRequest& destination,
                   const IntervalData512& data) {}
void addAttributes(Aws::DynamoDB::Model::PutItemRequest& destination,
                   const DailyData& data) {}
void addAttributes(Aws::DynamoDB::Model::PutItemRequest& destination,
                   const UserSettingData& data) {}

// The below aren't strictly required, but it helps us to be consistent and have
// this function defined for all data types
void addAttributes(Aws::DynamoDB::Model::PutItemRequest& destination,
                   const RealTimeData64& data) {
  addAttributes(destination, static_cast<const IntervalData64&>(data));
}
void addAttributes(Aws::DynamoDB::Model::PutItemRequest& destination,
                   const RealTimeData128& data) {
  addAttributes(destination, static_cast<const IntervalData128&>(data));
}
void addAttributes(Aws::DynamoDB::Model::PutItemRequest& destination,
                   const RealTimeData256& data) {
  addAttributes(destination, static_cast<const IntervalData256&>(data));
}
void addAttributes(Aws::DynamoDB::Model::PutItemRequest& destination,
                   const RealTimeData512& data) {
  addAttributes(destination, static_cast<const IntervalData512&>(data));
}
}  // namespace

void DynamoStore::put(const Record& record) {
  Aws::Client::ClientConfiguration clientConfiguration;
  Aws::DynamoDB::DynamoDBClient dynamoClient(clientConfiguration);

  Aws::DynamoDB::Model::PutItemRequest putItemRequest;
  putItemRequest.SetTableName(kTableName.data());

  putItemRequest.AddItem(
      kCompanyCode,
      Aws::DynamoDB::Model::AttributeValue().SetS(record.companyCode().data()));
  putItemRequest.AddItem(kProductSerialNumber,
                         Aws::DynamoDB::Model::AttributeValue().SetS(
                             record.productSerialNumber().data()));
  putItemRequest.AddItem(kDataType, Aws::DynamoDB::Model::AttributeValue().SetS(
                                        record.productSerialNumber().data()));
  putItemRequest.AddItem(
      kProductId,
      Aws::DynamoDB::Model::AttributeValue().SetS(record.productId().data()));
  putItemRequest.AddItem(kUnitId, Aws::DynamoDB::Model::AttributeValue().SetS(
                                      record.unitId().data()));
  putItemRequest.AddItem(kDataLength,
                         Aws::DynamoDB::Model::AttributeValue().SetN(
                             std::to_string(record.dataLength())));
  putItemRequest.AddItem(kClientTransmissionTime,
                         Aws::DynamoDB::Model::AttributeValue().SetN(
                             epochSecString(record.clientTransmissionTime())));
  putItemRequest.AddItem(
      kChecksum, Aws::DynamoDB::Model::AttributeValue().SetS(
                     fmt::format("{:x}", record.checksum().underlying())));

  std::visit(
      [&](const auto& data) mutable { addAttributes(putItemRequest, *data); },
      record.dataVariant());

  const Aws::DynamoDB::Model::PutItemOutcome outcome =
      dynamoClient.PutItem(putItemRequest);
  if (!outcome.IsSuccess()) {
    throw std::runtime_error(fmt::format(
        "AWS DynamoStore error: Could not store data due to error: {}",
        outcome.GetError().GetMessage()));
  }
}
}  // namespace tas_powertek::spf21y