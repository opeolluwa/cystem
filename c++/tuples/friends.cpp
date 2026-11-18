#include <string>
#include <iostream>
#include "friends.h"

//
// Created by URANIUM on 18/11/2026.
//


Friend::Friend(std::string name) : name(std::move(name)) {
}
Friend::Friend(std::string name, uint8_t age) : name(std::move(name)), age(age) {
}


std::tuple<int, std::vector<Friend> > friendsList() {
    size_t counter, total{};

    std::cout << "How many friends?" << std::endl;
    std::cin >> counter;
    total = counter;
    std::vector<Friend> friends;

    while (counter) {
        std::string name;
        std::cout << "Friends name?" << std::endl;
        std::cin >> name;
        friends.emplace_back(name);
        counter--;
    }

    return std::make_tuple(total, friends);
}
