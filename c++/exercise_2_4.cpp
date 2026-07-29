/*
 *
 Exercise 2-4. For your birthday you’ve been given a long tape measure and an
 instrument that measures angles (the angle between the horizontal and a line to
 the top of a tree, for instance). If you know the distance, d, you are from a
 tree, and the height, h, of your eye when peering into your angle-measuring
 device, you can calculate the height of the tree with the formula h +
 d*tan(angle). Create a program to read h in inches, d in feet and inches, and
 angle in degrees from the keyboard, and output the height of the tree in feet.
 */

int convert_inches_and_feet_to_inches(int inches, int feet);

#include <cmath>
#include <iostream>

int main() {
  int inches{}, feet{};
  double angle{};
  std::cout << "Enter the inches value ";
  std::cin >> inches;

  std::cout << "Enter the feet value ";
  std::cin >> feet;

  std::cout << "Enter the angle value ";
  std::cin >> angle;

  int distance_in_inches{convert_inches_and_feet_to_inches(inches, feet)};
  double height_in_inches{distance_in_inches * std::tan(angle)};

  std::cout << "You entered angle = " << angle
            << " distance(in inches) = " << distance_in_inches
            << " you got height = " << height_in_inches << std::endl;
}

int convert_inches_and_feet_to_inches(int inches, int feet) {
  const int foot_per_inches{12};

  if (feet == 0)
    return inches;
  else if (inches == 0)
    return foot_per_inches * feet;
  else
    return ((foot_per_inches * feet) + inches);
}
