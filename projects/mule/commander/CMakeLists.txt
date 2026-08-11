add_library(commander)

target_sources(commander
  PRIVATE
    commander.cpp

    PUBLIC
      FILE_SET HEADERS
      FILES
        commander.h
)

target_link_libraries(commander PUBLIC termcolor::termcolor)
target_include_directories(commander PRIVATE ${CMAKE_SOURCE_DIR}/include)