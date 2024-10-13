cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
add_compile_options(-Wall -Wextra -Wpedantic -Wswitch-enum)

project(spf21ytester LANGUAGES CXX)

add_subdirectory(../tas_powertek/spf-21y spf21y)
find_package(aws-lambda-runtime REQUIRED)
find_package(aws-sdk-cpp REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(folly CONFIG REQUIRED)
find_package(date CONFIG REQUIRED)

add_executable(${PROJECT_NAME} 
    spf21ytester.cpp
    DynamoStore.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC AWS::aws-lambda-runtime AWS::aws-sdk-spp Folly::folly Folly::folly_deps spf21y)
aws_lambda_package_target(${PROJECT_NAME})