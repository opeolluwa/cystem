#include <cstddef>
#include <iostream>
#include <string>

// compile with g++ do-while.cpp -o .out -std=c++17 -Wall
int main() {
  std::string directories[]{"src", "assets", "include", "external", "lib"};

  size_t counter{};
  do {
    std::cout << directories[counter] << std::endl;
    counter++;
  } while (counter < std::size(directories));
}
