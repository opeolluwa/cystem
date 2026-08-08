cmake_minimum_required(VERSION 4.4.2)

project(forge)

add_executable(forge)

target_sources(forge PRIVATE src/main.cpp)

target_link_libraries(forge PRIVATE argparser commander)

add_library(argparser)

target_sources(argparser
PRIVATE
  argparser/argparser.cpp

PUBLIC
  FILE_SET HEADERS
  BASE_DIRS
    argparser
  FILES
    argparser/argparser.h
)


add_library(commander)

target_sources(commander
  PRIVATE 
    commander/commander.cpp

  PUBLIC  
    FILE_SET HEADERS
    BASE_DIRS 
      commander
    FILES
      commander/commander.h
)
