#pragma once

#include <string_view>
namespace nested_namespace {
void call_alice(std::string_view alice);
namespace inner {
void marry_alice(std::string_view bryan);
int add_to_one(int val);
} // namespace inner
} // namespace nested_namespace
