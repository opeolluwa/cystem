#include <cctype>
#include <iostream>


/**
 * compile with g++ -o .out conditional-initialization.cpp -Wall -std=c++17
 */
int main() {
  int entry {};
  
  std::cout << "Enter a number lol: " << std::endl;
  std::cin >> entry;
  
  
  if (auto lower{static_cast<char>(std::tolower(entry))};
      lower >= 'a' && lower <= 'z') {
    std::cout << "You've entered the letter '" << lower << '\'' << std::endl;
  }
}
