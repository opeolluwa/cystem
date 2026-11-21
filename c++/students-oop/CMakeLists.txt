cmake_minimum_required(VERSION 4.3)
project(students_oop)

set(CMAKE_CXX_STANDARD 20)

add_executable(students_oop main.cpp
        students.cpp
        students.h
        People.cpp
        People.h)
