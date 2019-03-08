cmake_minimum_required(VERSION 3.13)

enable_language(C)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_library(murmur3 murmur3.c murmur3.h)

add_executable(example example.c)

target_link_libraries(example murmur3)

add_executable(unit_test test.c)

target_link_libraries(unit_test murmur3)