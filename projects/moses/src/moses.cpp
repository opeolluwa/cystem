#include "moses.hpp"
#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>

using moses::Moses;
using moses::Options;
using moses::parse_input;
using std::string;
using std::string_view;

namespace fs = std::filesystem;

Moses::Moses(const Options &opts) : option(opts) {}

Options Moses::parse_options() {
  Options options;
  options.use_cmake = parse_input<bool>("Use CMake?");
  options.app_name = parse_input<string>("App name");
  if (options.use_cmake) {
    options.cmake_version = parse_input<string>("Cmake version");
    options.add_gtest = parse_input<bool>("add gtest");
  }
  options.add_readme = parse_input<bool>("add readme?");

  return options;
}

void Moses::exec() {
  fs::create_directories("src");

  // Generate main.cpp
  {
    auto main_content = std::format(MAIN_TEMPLATE, option.app_name);
    file_exist_or_create("src/main.cpp", main_content);
  }

  // Generate app header and source
  {
    auto header_content = std::format(APP_HEADER_TEMPLATE, option.app_name);
    auto source_content = std::format(APP_SOURCE_TEMPLATE, option.app_name);
    file_exist_or_create(std::format("src/{}.hpp", option.app_name),
                         header_content);
    file_exist_or_create(std::format("src/{}.cpp", option.app_name),
                         source_content);
  }

  if (option.use_cmake) {
    file_exist_or_create("CMakeLists.txt", build_cmake_template());
    if (option.add_gtest) {
      fs::create_directories("tests");
      auto spec_content = std::format(SPEC_TEMPLATE, option.app_name);
      file_exist_or_create(std::format("tests/{}_spec.cpp", option.app_name),
                           spec_content);
    }
  }

  if (option.add_readme) {
    file_exist_or_create("README.md",
                         std::format(README_TEMPLATE, option.app_name));
  }
}

void Moses::file_exist_or_create(std::string_view file_name,
                                 std::string_view content) {
  fs::path filepath = fs::current_path() / file_name;
  bool can_write =
      !fs::exists(filepath) ||
      parse_input<bool>(std::format("{} exists, overwrite?", file_name));

  if (can_write)
    std::ofstream(filepath) << content;
}

std::string Moses::build_cmake_template() {
  auto cmake_gtest_template_addon =
      std::format(moses::GTEST_TEMPLATE, option.app_name);

  if (!option.add_gtest)
    cmake_gtest_template_addon = "";

  return std::format(moses::CMAKE_TEMPLATE,
                     option.cmake_version.value_or(
                         "") /*todo: parse the currntly cmake version */,
                     option.app_name, cmake_gtest_template_addon);
}
