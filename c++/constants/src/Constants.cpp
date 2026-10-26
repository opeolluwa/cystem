#include "Constants.h"
#include <iostream>
int main() {
  std::cout << "pi has the value " << constants::pi << std::endl;
  std::cout << "This should be 2: " << constants::sqrt_2 * constants::sqrt_2
            << std::endl;
}
