#include <iostream>

int main() {
  enum class Day {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
  };

  Day today{Day::Friday};

  std::cout << "Today is " << static_cast<int>(today) << std::endl;

  enum class Punctuation : char {
    Comma = ',',
    Exclamation = '!',
    Question='?' };

  }
