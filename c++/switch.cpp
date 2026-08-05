#include <iostream>

int main() {
  enum class DaysOfTheWeek {
    Sunday = 7,
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
  };

  int entry{};
  std::cout << "Input a value between the days of the week: " << std::endl;

  std::cin >> entry;

  switch (entry) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    std::cout << "That's a week day" << std::endl;
    break;
  case 6:
  case 7:
    std::cout << "That's a weekend" << std::endl;
    break;
  default:
    std::cout << "Bad input, entry cannot be less than 1 or greater than 7"
              << std::endl;
  }
}
