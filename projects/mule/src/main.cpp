#include <cstdio>
#include <iostream>
#include <string>

int main() {
  std::string baseDir{};

  std::printf("Enter the base directory: ");
  std::cin >> baseDir;

  std::cout << " you entered " << baseDir << std::endl;
  std::string directories[4]{"src", "include", "external", "assets"};

}
