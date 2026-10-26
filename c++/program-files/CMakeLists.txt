cmake_minimum_required(VERSION 4.4.2)
    project(program-files)

    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    add_executable(${PROJECT_NAME})
    target_sources(${PROJECT_NAME} PRIVATE src/main.cpp src/program-files.cpp src/program-files.hpp)
    target_link_libraries(${PROJECT_NAME} PRIVATE)

    
