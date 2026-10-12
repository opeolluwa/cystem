#include <iostream>
#include <string>

int main() {

  double *pValue{nullptr};
  pValue = new double;

  *pValue = 3.142;
  std::cout << pValue << " " << *pValue << std::endl;

  // this can also be done as
  int *intValue{new int{45}};
  std::cout << intValue << " " << *intValue << std::endl;

  // When you no longer need a dynamically allocated variable, you free the
  // memory that it occupies using  the delete operator:
  delete pValue;
  delete intValue;

  std::cout << "(int value) after delete " << intValue << " " << *intValue
            << std::endl;
  std::cout << "(pValue) after delete " << pValue << " " << *pValue
            << std::endl;

  /**
   *
   *
   *  A pointer that contains such a spurious address is sometimes
  called a dangling pointer. Dereferencing a dangling pointer is a sweet recipe
  for disaster, so you should get in the habit of always resetting a pointer
  when you release the memory to which it points, like this: delete pvalue;
  pvalue = nullptr; // Release memory pointed to by pvalue
  // Reset the pointer
  //
  //
   */

  pValue = nullptr;
  intValue = nullptr;

  std::cout << "(int value) after =nullptr " << intValue << " " << *intValue
            << std::endl;
  std::cout << "(pValue)  after =nullptr " << pValue << " " << *pValue
            << std::endl;

  // dynamic array
  std::string *friends{new std::string[100]}; // dynamic array of 100 friends
  // free the store
  delete[] friends;
  friends = nullptr;
}
