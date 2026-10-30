#include "box.h"

Box::Box(double lengthValue, double widthValue, double heightValue) {
  length = lengthValue;
  height = heightValue;
  width = widthValue;
}

Box::Box(double side) : Box{side, side, side} {};

// Box::Box(double lengthValue, double widthValue, double heightValue)
//     : length{lengthValue}, width{widthValue}, height{heightValue} {}
double Box::volume() { return length * width * height; }
