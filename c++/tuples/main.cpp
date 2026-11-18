#include <iostream>
#include "friends.h"

int main() {
    std::cout << "Hello, World!" << std::endl;


    // std::tie(counter, friends) = friendsList();
    auto [counter, friends] = friendsList();
    std::cout << counter << std::endl;

    for (auto &f: friends) std::cout << f.name << std::endl;
}
