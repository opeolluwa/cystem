#include <iostream>

int main() {
  unsigned short number{16387};
  std::cout << "answer " << number;
  auto result{static_cast<unsigned short>(number << 2)};
  std::cout << "result "  << result;
}
