add_library(commander)

target_sources(commander
  PRIVATE
    commander.cpp

    PUBLIC
      FILE_SET HEADERS
      FILES
        commander.h
)
