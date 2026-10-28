#include "box.h"
#include <iostream>

int main() {
  Box myBox{2.0, 3.5, 4.0};
  Box newBox(2,3,5);
  myBox.volume();
  std::cout << "Volume of myBox is " << myBox.volume() << std::endl;
}
