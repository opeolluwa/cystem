#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main() {
  const std::vector<std::string> friends{"alex", "bryan", "crystal", "phillip"};

  for (auto name : friends)
    std::cout << name << " is my friends\n";

  // equivalent to first and last in rust
  std::cout << friends.front() << std::endl;
  std::cout << friends.back() << std::endl;
  /**
   * You can remove all the elements from a vector<> by calling the clear()
   function for the vector object. Here’s an example: std::vector<int> data(100,
   99); // Contains 100 elements initialized to 99 data.clear();
   */

  // A vector<> does not have a fill() member, though. Instead, it offers
  // assign() functions that can be used to reinitialize the contents of a
  // vector<>, much like you would when initializing it for the first time:
  std::vector<long> numbers(20, 99L);
  numbers.assign(99, 20L);
  numbers.assign({99L, 20L});

  // a vector also has empty
  numbers.clear();
  bool number_is_empty = numbers.empty();
  std::cout << " numbers are empty " << std::boolalpha << number_is_empty;
}
