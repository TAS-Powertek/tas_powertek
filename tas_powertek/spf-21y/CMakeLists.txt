cmake_minimum_required(VERSION 3.10)

project(spf21y)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
add_compile_options(-Wall -Wextra -Wpedantic -Wswitch-enum)

find_package(fmt CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(gtest CONFIG REQUIRED)
find_package(folly CONFIG REQUIRED)

add_library(spf21y Enums.cpp)
target_include_directories(spf21y PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR})

# Testing
enable_testing()
add_executable(Tests test/EnumTest.cpp)
add_definitions(-DGLOG_NO_EXPORT)
target_link_libraries(Tests spf21y GTest::gtest_main glog::glog Folly::folly)
include (GoogleTest)
gtest_discover_tests(Tests)

#target_include_directories(spf21y )
#target_link_libraries(HelloWorld PRIVATE fmt::fmt)