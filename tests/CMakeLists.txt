cmake_minimum_required(VERSION 3.5)
project(Tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)
add_executable(Tests ${SOURCE_FILES})

add_subdirectory(gtest-1.8.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
enable_testing()
target_link_libraries(Tests gtest_main)