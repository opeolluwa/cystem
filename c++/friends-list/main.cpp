#include <array>
#include <cstddef>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

int main() {
  std::size_t friends_count{};
  std::cout << "Enter your number of friends: ";

  while (!(std::cin >> friends_count)) {
    std::cout << "you may may not enter a negative number";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  // what is the difference between these two
  //
  // std::array<std::string, friends_count> *friends{
  // new std::array<std::string, friends_count>};
  // auto *friends{new std::string[friends_count]};
  //
  // both are illogical best to use a vector

  auto *friends{new std::string[friends_count]};
  for (size_t counter{1}; counter <= friends_count; counter++) {
    auto cardinal{counter == 1   ? "st"
                  : counter == 2 ? "nd"
                  : counter == 3 ? "rd"
                                 : "th"};
    std::cout << std::format("What is the name of your {}{} friend ", counter,
                             cardinal);
    std::cin >> (*friends)[counter];
  }
  std::cout << "Hello world";
}
