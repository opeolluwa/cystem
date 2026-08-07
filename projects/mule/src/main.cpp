#include <cstdio>
#include <iostream>
#include <string>

int main() {
  std::string baseDir{};
  const  std::string directories[]{
      "src",
      "include",
      "external",
      "assets"
  };

  std::printf("Enter the base directory: ");
  std::cin >> baseDir;
  std::cout << " you entered " << baseDir << std::endl;

  for(auto dir : directories) std::cout << dir <<std::endl;
}
