#include <argparser.h>
#include <commander.h>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[argc + 1]) {
  const size_t MIN_ARGUMENT_COUNT{2};
  try {
    if (argc < MIN_ARGUMENT_COUNT)
      throw std::runtime_error("No command was supplied");

    std::string command{argv[1]};
    bool valid_command{argparser::validate_command(argv[1])};
    if (!valid_command)
      throw std::runtime_error(R"(invalid command {})");

    commander::execute_command(command);

  } catch (const std::runtime_error &err) {
    std::cout << "Forge crumbled due to " << err.what() << std::endl;
    return EXIT_FAILURE;
  }
}
