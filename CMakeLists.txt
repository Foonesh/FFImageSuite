cmake_minimum_required(VERSION 3.6)
project(Application)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Application/main.cpp)

add_executable(Application ${SOURCE_FILES})

project(Tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Tests/main.cpp)

add_executable(Tests ${SOURCE_FILES})