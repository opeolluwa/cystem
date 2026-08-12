#include <array>
#include <cstddef>
#include <ios>
#include <iostream>

// compile with g++ -o out pointer.cpp -Wall -std=c++17
int main() {
  long *pnumber{};

  std::cout << (pnumber == nullptr) << std::endl;

  // when we create a const pointer to char type, the interpreter sees it as a
  // C-style string
  const char *lies{"the things that never happen are called lies"};
  std::cout << lies;

  long numbers[]{10, 20, 30, 40, 50, 60, 70, 80};
  long *pnum1{&numbers[6]};
  long *pnum2{&numbers[1]}; // Points to 7th array element
  // Points to 2nd array element

  std::cout << " pnum1: " << pnum1 << " pnum2: " << pnum2 << std::endl;
  std::cout << std::boolalpha << (pnum2 < pnum1);

  std::ptrdiff_t diff{pnum2 - pnum1};

  std::cout << diff;

  /**
   * numbers give give the address of the first element of the array.
   * so, (data+ i) gives the next address of the ith element 
   * *(data), uses the indirection operation to get the element 
   * 
   * *(data +i) = 2 * (i+1) uses the indirection operator and pointer arithmetic to set the value of the ith element to 2 * (1+i){2, 4, 6, ...}
   */
  for (size_t i{}; i < std::size(numbers); ++i) {
    *(numbers + i) = 2 * (i + 1);
  }
}
