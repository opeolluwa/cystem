#pragma once

#include <cctype>
#include <concepts>
#include <exception>
#include <format>
#include <ios>
#include <iostream>
#include <limits>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <termcolor/termcolor.hpp>
#include <type_traits>
#include <vector>

namespace boar {

constexpr auto CMAKE_TEMPLATE = R"(cmake_minimum_required(VERSION {0})
    project({1})

    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    add_executable(${PROJECT_NAME})
    target_sources(${PROJECT_NAME} PRIVATE src/main.cpp src/{1}.cpp src/{1}.hpp)
    target_link_libraries(${PROJECT_NAME} PRIVATE)
)";


constexpr auto GTEST_TEMPLATE = R"(enable_testing()
    add_executable(${PROJECT_NAME}_tests)
    target_sources(${PROJECT_NAME}_tests PRIVATE tests/boar_spec.cpp src/boar.cpp src/boar.hpp)
    target_include_directories(${PROJECT_NAME}_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(${PROJECT_NAME}_tests PRIVATE GTest::gtest_main  termcolor::termcolor)

    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    FetchContent_MakeAvailable(termcolor googletest)
    include(GoogleTest)
    gtest_discover_tests(${PROJECT_NAME}_tests)
)";

struct Options {
  std::vector<std::string> dirs;
  std::string app_name;
  bool use_cmake;
  std::optional<std::string> cmake_version;
  bool add_readme;
  bool add_gtest;
};

class Boar {
private:
  Options option;
  std::string render_cmake_content();
  bool cmake_file_exists();
  bool readme_exist();
  void build_cmake_template();

public:
  Boar() = default;
  explicit Boar(const Options &opts);
  Options parse_options();
  void exec();
};

template <typename T> T parse_input(std::string_view prompt) {
  constexpr bool is_boolean = std::same_as<T, bool>;
  std::cout << termcolor::blue << prompt << (is_boolean ? " y/n: " : ": ")
            << termcolor::reset;

  if constexpr (is_boolean) {
    char result;
    std::cin >> result;

    result =
        static_cast<char>(std::tolower(static_cast<unsigned char>(result)));

    if (result != 'y' && result != 'n') {
      throw std::runtime_error(
          std::format("invalid format, expected y/n got {}", result));
    }

    return result == 'y';
  }

  T value;

  if (!(std::cin >> value)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    throw std::runtime_error("invalid format");
  }

  return value;
}

}; // namespace boar
