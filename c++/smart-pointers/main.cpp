#include <iostream>
#include <memory>
int main() {
  // in the olden days,  this was done
  std::unique_ptr<double> pdate{new double{56}};

  // more recently
  std::unique_ptr<double> pdata2{
      std::make_unique<double>(/*value may go here, eg 44 */)};

  std::cout << *pdata2.get();
}
