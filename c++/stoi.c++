#include <iostream>
#include <string>

int main() {
  std::string number_string{"234"};
  int casted{std::stoi(number_string)};
  std::cout << casted << std::endl;
}
