/*
 *
 Exercise 2-3. Create a program that converts inches to feet and inches. In case
 you’re unfamiliar with imperial units: 1 foot equals 12 inches. An input of 77
 inches, for instance, should thus produce an output of 6 feet and 5 inches.
 Prompt the user to enter an integer value corresponding to the number of inches
 and then make the conversion and output the result.
 */

#include <iostream>

int main() {
  const int foot_per_inches{12};
  int inches{}, feet{}, raw_value{};

  std::cout << "Enter the raw value ";
  std::cin >> raw_value;

  inches = raw_value % foot_per_inches;
  feet = (raw_value - inches) / foot_per_inches;

  std::cout << "You entered " << raw_value
            << " this is equivalent to inches = " << inches << " feet = " << feet
            << std::endl;
}
