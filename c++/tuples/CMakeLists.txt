cmake_minimum_required(VERSION 4.3)
project(tuples)

set(CMAKE_CXX_STANDARD 20)

add_executable(tuples main.cpp
        friends.cpp
        friends.h)
