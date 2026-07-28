#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main() {

  std::cout << " the absolute of -3 = " << abs(-3) << std::endl;
  std::cout << " the ceil of 2.3 = " << ceil(2.3) << std::endl;
  std::cout << " the floor of 2.4 = " << floor(2.4) << std::endl;
  std::cout << " the exp of 2.4 = " << exp(2.4) << std::endl;
  std::cout << " the log of 2.4 = " << log(2.4) << std::endl;
  std::cout << " the log base 10 of 2.4 = " << log10(2.4) << std::endl;
  std::cout << " the power of 2 to the 4  = " << pow(2, 4) << std::endl;
  std::cout << " the sqrt of 4 = " << sqrt(4) << std::endl;
  std::cout << " the round of 2.4 = " << round(2.4) << std::endl;

  std::cout << " the precision  = " << std::fixed << std::setprecision(3)
            << 2.445 << std::endl;

  int a{16}, b{66};
  std::cout << std::setw(5) << a << std::setw(5) << b << std::endl;
  std::cout << std::left << std::setw(5) << a << std::setw(5) << b << std::endl;
  std::cout << " a = " << std::setbase(16) << std::setw(6) << std::showbase << a
            << " b = " << std::setw(6) << b << std::endl;
  std::cout << std::setw(10) << a << std::setw(10) << b << std::endl;

  /*
   * As seen earlier in this chapter, the std::round(), lround(), and llround() functions from the cmath
   header allow you to round floating-point numbers to the nearest integer. In many cases, this is better than
   (implicit or explicit) casting, where truncation is used instead.
   */
  return EXIT_SUCCESS;
}
