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

template <typename T>
T parse_input(std::string_view prompt, bool as_boolean = false) {

//   std::cout << prompt <<( as_boolean? "y/n" :"");
// if (as_boolean){
//     char value;
//     std::cin >> value;

//     value = static_cast<char>(
//                 std::tolower(static_cast<unsigned char>(value))
//             );
//         if (value != 'y' && value!='n') throw std::runtime_error(std::format("invalid format, expected y/n got {}", value));
//         return value;
// }

// T value;

//   if (std::cin.fail()) {
//     std::cin.clear();
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     throw std::runtime_error("invalid format");
//   }
//   return value;
}
}; // namespace boar
