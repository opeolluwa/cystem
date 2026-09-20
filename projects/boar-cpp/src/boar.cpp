#include "boar.hpp"
#include <string>

boar::Options boar::Boar::parse_options() {
  boar::Options options;

  bool use_cmake = boar::parse_input<bool>("Use CMake?: ", true);
  
  std::string app_name = boar::parse_input<std::string>("App name: ");

  options.use_cmake = use_cmake;
  options.app_name = app_name;

  return options;
}

void boar::Boar::exec(const boar::Options &option) {
}
