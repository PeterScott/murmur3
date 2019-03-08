cmake_minimum_required(VERSION 3.13)

add_library(murmur3 murmur3.c murmur3.h)

add_executable(example example.c)

target_link_libraries(example murmur3)

add_executable(test test.c)

target_link_libraries(test murmur3)