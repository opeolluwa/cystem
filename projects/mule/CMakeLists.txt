cmake_minimum_required(VERSION 4.4.2)
project(mule)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE structopt::structopt commander)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)
FetchContent_Declare(
    structopt
    GIT_REPOSITORY https://github.com/p-ranav/structopt
    GIT_TAG        v0.1.3
)
FetchContent_MakeAvailable(structopt)

add_subdirectory(commander)
