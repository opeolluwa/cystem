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
#include <type_traits>
#include <vector>

namespace boar {

struct Options {
  std::vector<std::string> dirs;
  std::string app_name;
  std::optional<bool> use_cmake;
  std::optional<std::string> cmake_version;
  std::optional<bool> add_readme;
};

class Boar {
private:
  Options option;
  std::string render_cmake_content();
  bool cmake_file_exists();

public:
  Options parse_options();
  void exec(const boar::Options &option);
};

template <typename T> T parse_input(std::string_view prompt) {
  constexpr bool is_boolean = std::same_as<T, bool>;
  std::cout << prompt << (is_boolean ? " y/n: " : ": ");

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
