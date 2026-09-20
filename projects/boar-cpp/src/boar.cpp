#include "boar.hpp"
#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>

using boar::Boar;
using boar::parse_input;
using std::string;
using std::string_view;

namespace fs = std::filesystem;

Boar::Boar(const boar::Options &opts) : option(opts) {}

boar::Options boar::Boar::parse_options() {
  boar::Options options;

  options.use_cmake = parse_input<bool>("Use CMake?");
  options.app_name = parse_input<string>("App name");
  if (options.use_cmake) {
    options.cmake_version = parse_input<string>("Cmake version");
    options.add_gtest = parse_input<bool>("add gtest");
  }
  options.add_readme = parse_input<bool>("add readme?");

  return options;
}

void Boar::exec() {
  if (option.use_cmake)
    file_exist_or_create("CMakeLists.txt", build_cmake_template());

  if (option.add_readme)
    file_exist_or_create("README.md",
                         std::format(README_TEMPLATE, option.app_name));
}

void Boar::file_exist_or_create(std::string_view file_name,
                                std::string_view content) {
  fs::path filepath = fs::current_path() / file_name;
  bool can_write =
      !fs::exists(filepath) ||
      parse_input<bool>(std::format("{} exists, overwrite?", file_name));

  if (can_write)
    std::ofstream(filepath) << content;
}

std::string Boar::build_cmake_template() {
  auto cmake_gtest_template_addon =
      std::format(boar::GTEST_TEMPLATE, option.app_name);

  if (!option.add_gtest)
    cmake_gtest_template_addon = "";

  return std::format(boar::CMAKE_TEMPLATE,
                     option.cmake_version.value_or(
                         "") /*todo: parse the currntly cmake version */,
                     option.app_name, cmake_gtest_template_addon);
}
