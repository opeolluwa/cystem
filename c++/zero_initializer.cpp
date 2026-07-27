#include <cstdlib>
#include <iostream>

int main() {
  // int final_count{static_cast<int>(3.6)};
  int final_count {};
  int prev_count  {0};

  std::cout << "the final count is  same as the pre count " << (final_count == prev_count);

  return EXIT_SUCCESS;
}
