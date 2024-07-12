cmake_minimum_required(VERSION 3.10)

project(spf21y)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
add_compile_options(-Wall -Wextra -Wpedantic -Wswitch-enum)

find_package(fmt CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(gtest CONFIG REQUIRED)
find_package(folly CONFIG REQUIRED)
find_package(date CONFIG REQUIRED) # Part of C++20 but not commonly adopted by compilers

add_library(data 
    data/AuxFnData.cpp
    data/BankStatusData.cpp
    data/DailyData.cpp
    data/EventData.cpp
    data/FaultData.cpp
    data/IntervalData64.cpp
    data/IntervalData128.cpp
    data/IntervalData256.cpp
    data/IntervalData512.cpp
    data/TimeData.cpp)
target_link_libraries(data date::date date::date-tz Folly::folly Folly::folly_deps)

add_library(spf21y Enums.cpp Record.cpp)
add_definitions(-DGLOG_NO_EXPORT)
target_link_libraries(spf21y PUBLIC data Folly::folly Folly::folly_deps)
target_include_directories(spf21y PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR})

# Testing
enable_testing()
add_executable(Tests
    test/AuxFnDataTest.cpp
    test/BankStatusDataTest.cpp
    test/CheckSumTest.cpp
    test/DailyDataTest.cpp
    test/EnumTest.cpp
    test/EventDataTest.cpp
    test/FaultDataTest.cpp
    test/IntervalData64Test.cpp
    test/IntervalData128Test.cpp
    test/IntervalData256Test.cpp
    test/IntervalData512Test.cpp
    test/RecordTest.cpp
    test/TimeDataTest.cpp)
target_link_libraries(Tests spf21y GTest::gtest_main glog::glog)
include (GoogleTest)
gtest_discover_tests(Tests)
