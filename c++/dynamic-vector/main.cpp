#include <iostream>
#include <vector>
int main() {

  auto *pdata{new std::vector<int>{}};

  std::vector<int> data;
  pdata = &data;

  // both of these do the dame thing
  (*pdata).push_back(45);
  pdata->push_back(47);

  for (auto elem : *pdata)
    std::cout << elem << '\n';

    
}
