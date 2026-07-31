/**
 * Exercise 2-6. Here’s an extra exercise for puzzle fans. Write a program that
 will prompt the user to enter two different positive integers. Identify in the
 output the value of the larger integer and the value of the smaller integer.
 Using the decision-making facilities of Chapter 5, this would be like stealing
 a piece of cake from a baby while walking in the park. What makes this a brain
 teaser, though, is that this can be done solely with the operators you’ve
 learned about in this chapter!
 */

#include <iostream>

int main() {
  int num_one{}, num_two{};

  std::cout << "Enter the first number ";
  std::cin >> num_one;

  std::cout << "Enter the second number ";
  std::cin >> num_two;

  if (num_one > num_two) {
    std::cout << "the greater is  " << num_one;
  } else if (num_two > num_one) {
    std::cout << "the greater is  " << num_two;
  } else {
    std::cout << "looks lie both are the same" << num_one;
  }
}
