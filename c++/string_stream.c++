#include <iostream>
#include <string>

int main() {
  std::string text;
  std::string word;

  std::cout << "Enter the string to be searched and press enter\n ";
  std::getline(std::cin, text);

  std::cout << "Enter the string to be found and press Enter:\n";
  std::getline(std::cin, word);

  size_t count{};
  size_t index{};

  while ((index = text.find(word, index)) != std::string::npos) {
    ++count;
    index += word.length();
  }

  std::cout << "Your text contained " << count << " occurrences of \"" << word
            << "\"." << std::endl;
}
