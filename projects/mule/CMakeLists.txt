cmake_minimum_required(VERSION 4.4.2)
project(mule)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE structopt::structopt commander termcolor::termcolor)
target_include_directories(${PROJECT_NAME} PRIVATE include)


set(CMAKE_POLICY_VERSION_MINIMUM 3.0)
include(FetchContent)
FetchContent_Declare(
    structopt
    GIT_REPOSITORY https://github.com/p-ranav/structopt
    GIT_TAG        v0.1.3
)
FetchContent_MakeAvailable(structopt)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
include(FetchContent)
FetchContent_Declare(
    termcolor
    GIT_REPOSITORY https://github.com/ikalnytskyi/termcolor
    GIT_TAG        v2.1.0
)
FetchContent_MakeAvailable(termcolor)

add_subdirectory(commander)
