#include <iostream>
#include <string>

int main() {
  std::string text{"Many Mickle make a Muckle"};
  std::string word{"OOps"};

  text.insert(0, word + " ");

  std::cout << text;

  // rfind
  //  remove
  //  replace
  // clear
  // empty

  text.erase(0, word.length() + 1);
  std::cout << text;


}
