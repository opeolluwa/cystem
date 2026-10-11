#include <iostream>

int multiplier(int *multiplier);
int main() {
  int age{5};
  std::cout << age << std::endl;

  int result{multiplier(&age)};
  std::cout << age << std::endl;
}

int multiplier(int *multiplier) {
  *multiplier = +20;
  return *multiplier;
}
