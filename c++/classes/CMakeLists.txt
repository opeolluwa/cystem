cmake_minimum_required(VERSION 4.4.2)
    project(classes)

    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    add_executable(${PROJECT_NAME}
            Students.cpp
            Students.h)
    target_sources(${PROJECT_NAME} PRIVATE main.cpp)


    
