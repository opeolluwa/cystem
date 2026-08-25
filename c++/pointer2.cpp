#include <iostream>

int main() {
  int v{5};
  int *pv{nullptr};
  int *qv{nullptr};

  pv = qv;

  std::cout << pv;
}
