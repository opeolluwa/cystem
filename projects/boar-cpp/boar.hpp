#pragma once

#include <exception>
#include <ios>
#include <iostream>
#include <limits>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>
namespace boar {

struct Options {
  std::vector<std::string> dirs;
  std::string  app_name;
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

  T value;

  std::cout << prompt;
  std::cin >> value;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw std::runtime_error("invalid format");
  }
  return value;
}
}; // namespace boar
