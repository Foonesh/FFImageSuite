cmake_minimum_required(VERSION 3.5)
project(Tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)

set(SOURCES
        ../src/commands/command_factory.cpp
        ../src/commands/impl/command_exit.cpp
        ../src/commands/impl/command_help.cpp
        ../src/commands/impl/command_load_bmp.cpp
        ../src/commands/impl/command_man.cpp
        ../src/commands/impl/command_greyscale.cpp
        ../src/commands/impl/command_split.cpp
        ../src/commands/impl/command_rotate.cpp
        ../src/utils/binary_reader.cpp
        )

set(HEADERS
        ../inc/commands/command_factory.hpp
        ../inc/commands/command.hpp
        ../inc/commands/impl/command_exit.hpp
        ../inc/commands/impl/command_help.hpp
        ../inc/commands/impl/command_load_bmp.hpp
        ../inc/commands/impl/command_man.hpp
        ../inc/commands/impl/command_greyscale.hpp
        ../inc/commands/impl/command_split.hpp
        ../inc/commands/impl/command_rotate.hpp
        ../inc/utils/binary_reader.hpp
        )
add_executable(Tests ${SOURCE_FILES} ${SOURCES})
add_subdirectory(gtest-1.8.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${HEADERS})
enable_testing()
target_link_libraries(Tests gtest_main)
target_include_directories(${PROJECT_NAME} PRIVATE ../inc)