#include <array>
#include <iostream>

void help(const int &age);
int sum_of_10(const std::array<int, 10> &values);
int main() {
  std::array<int, 10> values = {1, 2, 3, 4, 5, 6, 78, 9, 9};
  int result = sum_of_10(values);
  std::cout << result;
}

void help(const int &age) {}

int sum_of_10(const std::array<int, 10> &values) {
  int sum{};
  for (auto i : values)
    sum += i;

  return sum;
}
