cmake_minimum_required(VERSION 3.16)
project(22s_pa01_cullen_w)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(input)
configure_file(input/input.txt input.txt COPYONLY)

add_executable(22s_pa01_cullen_w
        src/Algos.h
        src/main.cpp
        src/Painting.cpp
        src/Painting.h)
