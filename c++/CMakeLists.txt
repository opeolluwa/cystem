cmake_minimum_required(VERSION 3.28.0)
    project(myapp)

    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    add_executable(${PROJECT_NAME})
    target_sources(${PROJECT_NAME} PRIVATE src/main.cpp src/myapp.cpp src/myapp.hpp)
    target_link_libraries(${PROJECT_NAME} PRIVATE)

    enable_testing()
    add_executable(${PROJECT_NAME}_tests)
    target_sources(${PROJECT_NAME}_tests PRIVATE tests/myapp_spec.cpp src/myapp.cpp src/myapp.hpp)
    target_include_directories(${PROJECT_NAME}_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(${PROJECT_NAME}_tests PRIVATE GTest::gtest_main)

    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    FetchContent_MakeAvailable(googletest)
    include(GoogleTest)
    gtest_discover_tests(${PROJECT_NAME}_tests)

