#include "boar.hpp"
#include <string>
#include <string_view>

using boar::Boar;
using boar::parse_input;

Boar::Boar(const boar::Options &opts) : option(opts) {}

boar::Options boar::Boar::parse_options() {
  boar::Options options;

  options.use_cmake = parse_input<bool>("Use CMake?");
  options.app_name = parse_input<std::string>("App name");
  if (options.use_cmake) {
    options.cmake_version = parse_input<std::string>("Cmake version");
    options.add_gtest = parse_input<bool>("add gtest");
  }
  options.add_readme = parse_input<bool>("add readme?");
  return options;
}

void Boar::exec() {
  if (option.use_cmake) {
    build_cmake_template();
  }
}
void Boar::build_cmake_template() {
    auto cmake_template = std::format(boar::CMAKE_TEMPLATE, option.cmake_version, )
}
