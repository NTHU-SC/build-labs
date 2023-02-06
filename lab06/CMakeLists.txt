cmake_minimum_required(VERSION 2.6)
project(main)
include_directories(${CMAKE_SOURCE_DIR})
add_executable(main.elf main.c)

if(NOT STATIC_MATH)
	set(STATIC_MATH FALSE)
endif()

message(STATUS "Build libmath statically = " ${STATIC_MATH})

if(STATIC_MATH)
	add_library(math STATIC add.c sub.c)
else()
	add_library(math SHARED add.c sub.c)
endif(STATIC_MATH)

target_link_libraries(main.elf math)


