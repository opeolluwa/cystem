#include <array>
#include <cstddef>
#include <iostream>

int sum_up(int *array, std::size_t size) {
  int sum{};
  for (size_t i{}; i < size; ++i) {
    sum += *array++;
  }

  return sum;
}
int main() {
  int age[]{1, 2, 3};
  int result = sum_up(age, std::size(age));
  std::cout << result;
}
