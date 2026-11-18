#include <iostream>
#include <tuple>
#include <vector>
#include "friends.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    size_t counter;
    std::vector<Friend> friends;

    std::tie(counter, friends) = friendsList();
    std::cout << counter << std::endl;

    for (auto &f: friends) std::cout << f.name << std::endl;
}
