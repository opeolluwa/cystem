#include "nested-namespace.hpp"
#include <iostream>
#include <string>

int main() {
  std::string alice{"alice"};
  std::string bryan{"bryan"};

  nested_namespace::call_alice(alice);
  nested_namespace::inner::marry_alice(bryan);
  auto result = nested_namespace::inner::add_to_one(23);

  std::cout << result;
}
