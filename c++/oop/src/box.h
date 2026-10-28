#ifndef BOX_H
#define BOX_H

class Box {
private:
  double length;
  double width;
  double height;

public:
  // Box() {}; // default constructor;
  Box() = default; // another style for default
  Box(double lengthValue, double widthValue, double heightValue);
  double volume();
};

#endif
