cmake_minimum_required(VERSION 3.26)
project(CPP_Sem2)

set(CMAKE_CXX_STANDARD 17)

include_directories(..)
include_directories(../heap)
include_directories(../other)
include_directories(.)

add_executable(CPP_Sem2
        main.cpp
        vect.cpp
        vect.h)
