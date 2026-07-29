/*
 *
 Exercise 2-2. Using your solution for Exercise 2-1, improve the code so that the user
 can control the precision of the output by entering the number of digits required. To
 really show off how accurate floating-point numbers can be, you can perhaps switch
 to double-precision floating-point arithmetic as well. You’ll need a more precise
 approximation of π. 3.141592653589793238 will do fine.
 */

#include <iostream>
#include <iomanip>

int main() {
  double radius{};
  double area{};
  int precision{};
  const double pi{3.141592653589793238};

  std::cout << "Enter the radius of the circle ";
  std::cin >> radius;

  std::cout << "Enter the precision level of the result ";
  std::cin >> precision;

  area = pi * radius * radius;

  std::cout << "The area of the circle is " << std::fixed
            << std::setprecision(precision) << area << std::endl;
}
