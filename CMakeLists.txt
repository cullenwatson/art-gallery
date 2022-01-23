cmake_minimum_required(VERSION 3.16)
project(22s_pa01_cullen_w)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
configure_file(input/input.txt input.txt COPYONLY)
#[[configure_file(output/input-bruteforce.txt input-bruteforce.txt COPYONLY)
configure_file(output/input-custom.txt input-custom.txt COPYONLY)
configure_file(output/input-highvalue.txt input-highvalue.txt COPYONLY)]]

add_executable(22s_pa01_cullen_w
        src/Algos.h
        src/main.cpp
        src/Painting.cpp
        src/Painting.h)
