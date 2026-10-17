#include "moses.hpp"
#include <cstdlib>
#include <exception>
#include <termcolor/termcolor.hpp>

int main() {
  try {
    moses::Moses parser;
    moses::Options options = parser.parse_options();
    auto app = new moses::Moses(options);
    app->exec();
  } catch (std::exception &err) {
    std::cout << termcolor::red << err.what() << termcolor::reset;
    return EXIT_FAILURE;
  }
}
