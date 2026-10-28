#include "nested-namespace.hpp"
#include <iostream>

namespace nested_namespace::inner {
void marry_alice(std::string_view bryan) { std::cout << bryan; }
} // namespace nested_namespace::inner

namespace nested_namespace {
void call_alice(std::string_view alice) { std::cout << alice; }

namespace inner {
int add_to_one(int val) { return val + 1; }
} // namespace inner
} // namespace nested_namespace
