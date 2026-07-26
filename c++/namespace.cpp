namespace toulene {
const int MAX_OUTPUT = 45;
}

#include <cstdlib>
#include <iostream>

int main() {
  std::cout << "The maximum possible value is " << toulene::MAX_OUTPUT
            << std::endl;

  return EXIT_SUCCESS;
}
