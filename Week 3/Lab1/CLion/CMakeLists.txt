cmake_minimum_required(VERSION 3.8)
project(CLion)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c guesser.c guesser.h)
add_executable(CLion ${SOURCE_FILES})