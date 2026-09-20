cmake_minimum_required(VERSION 4.4.2)
project(boar)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp src/boar.cpp src/boar.hpp)
target_link_libraries(${PROJECT_NAME} PRIVATE termcolor::termcolor)

add_executable(${PROJECT_NAME}_tests)
target_sources(${PROJECT_NAME}_tests PRIVATE tests/boar_spec.cpp src/boar.cpp src/boar.hpp)
target_include_directories(${PROJECT_NAME}_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}_tests PRIVATE GTest::gtest_main)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
include(FetchContent)
FetchContent_Declare(
    termcolor
    GIT_REPOSITORY https://github.com/ikalnytskyi/termcolor
    GIT_TAG        v2.1.0
)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(termcolor googletest)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)
