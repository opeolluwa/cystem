#include "box.h"

Box::Box(double lengthValue, double widthValue, double heightValue) {
  length = lengthValue;
  height = heightValue;
  width = widthValue;
}

double Box::volume() { return length * width * height; }
