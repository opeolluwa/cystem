#include <cctype>
#include <commander.h>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <mule.h>
#include <stdexcept>
#include <string>
#include <termcolor/termcolor.hpp>
#include <vector>

namespace fs = std::filesystem;

namespace commander {
void init_command(const std::optional<std::string> &name,
                  const std::optional<std::string> &path) {

  std::string target_dir{};
  std::string application_name{};

  if (!name && !path)
    throw std::runtime_error(
        "name and path may not be empty, please provide one");
  else if (!name)
    throw std::runtime_error("name may not be empty, please provide one");
  else {
    application_name = name.value();
    target_dir = fs::path(path.value());
  }

  if (!fs::is_empty(target_dir)) {
    char answer{};
    std::cout << termcolor::yellow << "current path is not empty "
              << "remove content(y/n): " << termcolor::reset;
    std::cin >> answer;
    if (std::tolower(answer) == 'y')
      target_dir = fs::path(name.value()) / application_name;
    else
      std::exit(EXIT_FAILURE);
  }

  std::vector<fs::path> dirs{};
  for (auto dir : mule::PROJECT_DIRS) {
    fs::path full_path{fs::path(target_dir) / dir};
    dirs.push_back(full_path);
    std::cout << full_path;
  }
}

}; // namespace commander
