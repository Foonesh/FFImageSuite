cmake_minimum_required(VERSION 3.5)

project(Converter)

set (CMAKE_CXX_STANDARD 14)

set(SOURCES
	src/main.cpp
	src/commands/command_factory.cpp
	src/commands/impl/command_exit.cpp
	src/commands/impl/command_help.cpp
	src/commands/impl/command_load_bmp.cpp
	src/utils/binary_reader.cpp
	tests/main.cpp
)

set(HEADERS
	inc/commands/command_factory.hpp
	inc/commands/command.hpp
	inc/commands/impl/command_exit.hpp
	inc/commands/impl/command_help.hpp
	inc/commands/impl/command_load_bmp.hpp
	inc/utils/binary_reader.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE inc)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
