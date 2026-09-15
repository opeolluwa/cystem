#include <cstdlib>
#include <exception>
#include <format>
#include <iostream>
#include <stdexcept>
#include <string>
unsigned factorial(unsigned n);

// compile with g++ recursion.cpp -o out -std=c++20
int main(int argc, char *argv[]) {
  unsigned int counter{};

  try {
    if (argc < 2) {
      throw std::runtime_error("Counter in required");
      return EXIT_FAILURE;
    }

    counter = static_cast<unsigned>(std::stoi(argv[1]));
    const unsigned result = factorial(counter);
    std::cout << std::format("the value of factorial({}) is {}", counter,
                             result)
              << std::endl;
  } catch (const std::exception &err) {
    std::cout << err.what() << R"(
Usage bin <counter>
        )" << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

unsigned factorial(unsigned n) {
  if (n == 0)
    return 1;

  if (n == 1)
    return 1U;

  return n * factorial(n - 1);
}
