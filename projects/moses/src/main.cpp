#include "boar.hpp"
#include <cstdlib>
#include <exception>
#include <termcolor/termcolor.hpp>

int main() {
  try {
    boar::Boar parser;
    boar::Options options = parser.parse_options();
    auto app = new boar::Boar(options);
    app->exec();
  } catch (std::exception &err) {
    std::cout << termcolor::red << err.what() << termcolor::reset;
    return EXIT_FAILURE;
  }
}
