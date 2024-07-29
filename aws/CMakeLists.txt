cmake_minimum_required(VERSION 3.10)

project(spf21ytester LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(aws-lambda-runtime REQUIRED)
find_package(folly CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(${PROJECT_NAME} "spf21ytester.cpp")
target_link_libraries(${PROJECT_NAME} PUBLIC AWS::aws-lambda-runtime Folly::folly Folly::folly_deps)
aws_lambda_package_target(${PROJECT_NAME})