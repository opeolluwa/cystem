cmake_minimum_required(VERSION 4.3)
project(dreamdb)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp
        dreamdb.h
        dreamdb.cpp)
