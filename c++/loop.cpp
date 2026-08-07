#include <iostream>

int main() {
  unsigned int age[6]{23, 45, 67, 9, 12, 45};

  for (size_t n{}; n < 6; ++n) {
    std::cout << "The element at " << n << " is " << age[n] << std::endl;
  }
}
