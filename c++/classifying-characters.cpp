#include <cctype>
#include <iostream>

int main() {
  char first{}, second;

  std::cout << "Enter a character: " << std::endl;
  std::cin >> first;

  std::cout << "Enter another one character: " << std::endl;
  std::cin >> second;

  if (!std::isalpha(first) && !std::isalpha(second))
    std::cout << "Please provided a-z|A-Z";

  return 0;
}
