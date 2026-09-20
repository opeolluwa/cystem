#include "boar.hpp"
#include <cstdlib>
#include <exception>
#include <termcolor/termcolor.hpp>

int main() {
  try {
    auto app = new boar::Boar();
    boar::Options options = app->parse_options();
    app->exec(options);
  } catch (std::exception &err) {
    std::cout << termcolor::red << err.what() << termcolor::reset;
    return EXIT_FAILURE;
  }
}
