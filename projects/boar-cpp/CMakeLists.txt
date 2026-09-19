cmake_minimum_required(VERSION 4.4.2)
project(boar)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp boar.cpp boar.hpp)
target_link_libraries(${PROJECT_NAME} PRIVATE termcolor::termcolor)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
include(FetchContent)
FetchContent_Declare(
    termcolor
    GIT_REPOSITORY https://github.com/ikalnytskyi/termcolor
    GIT_TAG        v2.1.0
)
FetchContent_MakeAvailable(termcolor)
