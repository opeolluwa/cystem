#include <iostream>

int main() {
  bool is_valid{true};
  char first{}, second{};

  std::cout << "Enter a character: " << std::endl;
  std::cin >> first;

  std::cout << "Enter another one character: " << std::endl;
  std::cin >> second;

  std::cout << std::boolalpha << "The value of the expression " << first << '<'
            << second << " is: " << (first < second) << std::endl;
  std::cout << "The value of the expression " << first << "==" << second
            << " is: " << (first == second) << std::endl;

  std::cout << "Bool alpha " << std::boolalpha << is_valid << "No bool alpha "
            << std::noboolalpha << is_valid << std::endl;
}
