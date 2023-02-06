cmake_minimum_required(VERSION 2.6)

project(main)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(main.elf main.c)
add_library(math SHARED add.c sub.c)

target_link_libraries(main.elf math)


