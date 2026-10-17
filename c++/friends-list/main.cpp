#include <array>
#include <cstddef>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

int main() {
  std::size_t friends_count{};
  std::cout << "Enter your number of friends";
  std::cin >> friends_count;
  while (friends_count < 0) {
    std::cout << "you may may not enter a negative number";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  // what is the difference between these two 
  // 
  // std::array<std::string, friends_count> *friends{
  // new std::array<std::string, friends_count>};
  auto *friends{new std::string[friends_count]};

  std::cout << "Hello world";
}
