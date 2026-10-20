#include "moses.hpp"
#include <cstdlib>
#include <exception>
#include <string>
#include <termcolor/termcolor.hpp>
#include <vector>

void moses::print_usage() {
  std::cout << "usage:\n"
            << "  moses               interactive scaffolding\n"
            << "  moses new <dir>      scaffold a non-interactively into "
               "<dir> (cmake + readme + gitignore)\n";
}

int main(int argc, char **argv) {
  try {
    std::vector<std::string> args(argv + 1, argv + argc);

    if (args.empty()) {
      moses::Moses parser;
      moses::Options options = parser.parse_options();
      moses::Moses app(options);
      app.exec();
    } else if (args.size() == 2 && args[0] == "new") {
      moses::Options options = moses::Moses::parse_new_options({args[1]});
      moses::Moses app(options);
      app.exec();
      std::cout << "created project '" << options.app_name << "' in "
                << options.target_dir << '\n';
    } else if (args.size() == 1 && (args[0] == "help" || args[0] == "--help" ||
                                    args[0] == "-h")) {
      moses::print_usage();
    } else {
      moses::print_usage();
      return EXIT_FAILURE;
    }
  } catch (std::exception &err) {
    std::cout << termcolor::red << err.what() << termcolor::reset << '\n';
    return EXIT_FAILURE;
  }
}
