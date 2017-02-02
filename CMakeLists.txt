cmake_minimum_required(VERSION 3.5)

project(Converter)

set (CMAKE_CXX_STANDARD 14)

set(SOURCES
	src/main.cpp
	src/commands/command_factory.cpp
	src/commands/impl/command_exit.cpp
	src/commands/impl/command_help.cpp
	src/commands/impl/command_load_bmp.cpp
	src/commands/impl/command_man.cpp
	src/commands/impl/command_greyscale.cpp
	src/commands/impl/command_split.cpp
	src/commands/impl/command_rotate.cpp
	src/commands/impl/command_merge.cpp
	src/commands/impl/command_mix.cpp
	src/commands/impl/command_flip.cpp
	src/utils/binary_reader.cpp
	src/utils/binary_writer.cpp
)

set(HEADERS
	inc/commands/command_factory.hpp
	inc/commands/command.hpp
	inc/commands/impl/command_exit.hpp
	inc/commands/impl/command_help.hpp
	inc/commands/impl/command_load_bmp.hpp
	inc/commands/impl/command_man.hpp
	inc/commands/impl/command_greyscale.hpp
	inc/commands/impl/command_split.hpp
	inc/commands/impl/command_rotate.hpp
	inc/commands/impl/command_merge.hpp
	inc/commands/impl/command_mix.hpp
	inc/commands/impl/command_flip.hpp
	inc/utils/binary_reader.hpp
	inc/utils/binary_writer.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE inc)

#target_compile_options(${PROJECT_NAME} PRIVATE -Wall)