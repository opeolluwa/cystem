/**
 * Exercise 3-1. Create a program that prompts for input of an integer and store
 it as an int. Invert all the bits in the value and store the result. Output the
 original value, the value with the bits inverted, and the inverted value plus
 1, each in hexadecimal representation and on one line. On the next line, output
 the same numbers in decimal representation. These two lines should be formatted
 such that they look like a table, where the values in the same column are right
 aligned in a suitable field width. All hexadecimal values should have leading
 zeros so eight hexadecimal digits always appear.
 */

#include <iomanip>
#include <ios>
#include <iostream>

int main() {
  int input{};

  std::cout << "Please provide an input: " << std::endl;
  std::cin >> input;

  int result{~input};

  std::cout << "Original value: " << "Invited bits: " << "Inverted bits + 1\n"
            << std::setfill('0') << std::setw(8) << std::hex << input << " "
            << result << " " << result + 1 << "\n"
            << std::setfill('0') << std::setw(8) << std::dec << input << " "
            << result << " " << result + 1 << "\n"
  ;
}
