#include <iostream>

template <typename T> T greater(T val_one, T val_two) {
  return val_one > val_two ? val_one : val_two;
}

int main() {
  std::cout << greater("a", "b");
  std::cout << greater(4, 3);
}
