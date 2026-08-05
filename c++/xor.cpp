#include <iostream>

int main() {
  int price{};
  int limit{};

  std::cout << "Enter price: ";
  std::cin >> price;

  std::cout << "Enter limit: ";
  std::cin >> limit;

  if ((price > 100) ^ (limit < 100))
    std::cout << "Valid!";
  else
    std::cout << "Oops! Price must be greater than 100 and limit must be less "
                 "than 100, both both at a time";
}
