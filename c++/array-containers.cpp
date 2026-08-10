#include <array>
#include <iostream>
#include <string>
int main() {
  std::array<std::string, 5> friends{
      "alex", "philip", "crystal", "bryan", "tylor",
  };

  for (auto friend_name : friends) {
    std::cout << friend_name << " is my friend" << std::endl;
  }

  // fill the array with values
  friends.fill("alex");
  for (auto friend_name : friends) {
    std::cout << friend_name << " is my friend" << std::endl;
  }

  // get the size with .size
  std::cout << " i have " << friends.size() << " friends " << std::endl;


  // The expression values.at(i) is equivalent to values[i]
  // 
  // 
  std::array<double,4> these {1.0, 2.0, 3.0, 4.0};
  std::array<double,4> those {1.0, 2.0, 3.0, 4.0};
  std::array<double,4> them {1.0, 1.0, 5.0, 5.0};
  if (these == those) std::cout << "these and those are equal." << std::endl;
  if (those != them) std::cout << "those and them are not equal." << std::endl;
  if (those > them) std::cout << "those are greater than them." << std::endl;
  if (them < those) std::cout << "them are less than those." << std::endl;
}
