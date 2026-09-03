#include <iostream>

void do_nothing(int age, int multiplier);
int main() { do_nothing(5, 2); }

void do_nothing(int age, int multiplier) {
  if (age <= 0)
    return;

  std::cout << age * multiplier;
  return;
}
