cmake_minimum_required(VERSION 4.4.2)
project(moses)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp src/moses.cpp src/moses.hpp)
target_link_libraries(${PROJECT_NAME} PRIVATE termcolor::termcolor)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

add_executable(${PROJECT_NAME}_tests)
target_sources(${PROJECT_NAME}_tests PRIVATE tests/moses_spec.cpp src/moses.cpp src/moses.hpp)
target_include_directories(${PROJECT_NAME}_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}_tests PRIVATE GTest::gtest_main  termcolor::termcolor)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
include(FetchContent)
FetchContent_Declare(
    termcolor
    GIT_REPOSITORY https://github.com/ikalnytskyi/termcolor
    GIT_TAG        v2.1.0
    EXCLUDE_FROM_ALL
)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(termcolor googletest)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)
