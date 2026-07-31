/*
 *
 Exercise 2-5. Your body mass index (BMI) is your weight, w, in kilograms
 divided by the square of your height, h, in meters (w/(h*h)). Write a program
 to calculate the BMI from a weight entered in pounds and a height entered in
 feet and weight. A kilogram is 2.2 pounds, and a foot is 0.3048 meters.
 */

int convert_inches_and_feet_to_feet(int inches, int feet);
double convert_feet_to_meters(double feet);
double convert_pounds_to_kilogram(double pounds);

#include <iostream>

int main() {
  double weight{}, height{};
  int inches{}, feet{};

  std::cout << "Enter the weight value ";
  std::cin >> weight;

  std::cout << "Enter the height value in inches and feet ";
  std::cout << "Enter the inches value ";
  std::cin >> inches;

  std::cout << "Enter the feet value ";
  std::cin >> feet;
  int height_inches{convert_inches_and_feet_to_feet(inches, feet)};
  double height_meters{convert_feet_to_meters(height_inches)};

  double bmi{weight / (height * height)};

  std::cout << "You entered height = " << height << " weight = " << weight
            << " you got height = " << bmi << std::endl;
}

int convert_inches_and_feet_to_feet(int inches, int feet) {
  const int inches_per_foot{12};

  if (feet == 0)
    return inches;
  else if (inches == 0)
    return inches_per_foot * feet;
  else
    return ((inches_per_foot * feet) + inches);
}

double convert_pounds_to_kilogram(double pounds) {

  double pounds_per_kilogram{2.2};

  return pounds_per_kilogram * pounds;
}

double convert_feet_to_meters(double feet) {

  double meters_per_feet{0.3048};

  return meters_per_feet * feet;
}
