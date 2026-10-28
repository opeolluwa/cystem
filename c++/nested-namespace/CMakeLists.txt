cmake_minimum_required(VERSION 4.4.2)
    project(nested-namespace)

    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    add_executable(${PROJECT_NAME})
    target_sources(${PROJECT_NAME} PRIVATE src/main.cpp src/nested-namespace.cpp src/nested-namespace.hpp)
    target_link_libraries(${PROJECT_NAME} PRIVATE)

    
