#include "moses.h"
#include <cstdlib>
#include <exception>
#include <string>
#include <termcolor/termcolor.hpp>
#include <vector>


int main(int argc, char **argv) {
  try {
    std::vector<std::string> args(argv + 1, argv + argc);

    if (args.empty()) {
      Moses parser;
      CliOptions options = parser.parse_options();
      Moses app(options);
      app.exec();
      
    } else if (args.size() == 2 && args[0] == "new") {
      CliOptions options = Moses::parse_new_options({args[1]});
      Moses app(options);
      app.exec();
      std::cout << "created project '" << options.app_name << "' in "
                << options.target_dir << '\n';
    } else if (args.size() == 1 && (args[0] == "help" || args[0] == "--help" ||
                                    args[0] == "-h")) {
      print_usage();
    } else {
      print_usage();
      return EXIT_FAILURE;
    }
  } catch (std::exception &err) {
    std::cout << termcolor::red << err.what() << termcolor::reset << '\n';
    return EXIT_FAILURE;
  }
}
