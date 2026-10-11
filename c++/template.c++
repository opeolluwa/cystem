#include <iostream>
template <typename T> T greater(T val_one, T val_two) {
  return val_one > val_two ? val_one : val_two;
}

template <typename T, typename S> S concat_int(S val, T val_two){
    return std::format("{} {}", val, val_two);
}

int main() {
  std::cout << greater("a", "b");
  std::cout << greater(4, 3);
}
