#include "references.hpp"
#include <iostream>

int main() {
  double data{45};
  double &reference_to_date{data}; // defines a reference by adding ampersand in
                                   // front of the type > Type7
                                   //
  reference_to_date += 45;
  std::cout << "the data is" << data << " and the reference is "
            << reference_to_date;

  return 0;
}
