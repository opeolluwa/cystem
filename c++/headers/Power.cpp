// Ex10_05.cpp
// g++ -Wall Power.cpp -o out
// Creating and including your own header file
#include "Power.h" // Contains the prototype for the power() function
#include <iomanip>
#include <iostream>
int main() {
  for (int i{-3}; i <= 3; ++i) // Calculate powers of 8 from -3 to +3
    std::cout << std::setw(10) << power(8.0, i);
  std::cout << std::endl;
}

double power(double x, int n) {
  double result{1.0};
  int exp{n < 0 ? -n : n};
  for (int i{0}; i < exp; ++i) result *= x;
  return n < 0 ? 1.0 / result : result;
}
