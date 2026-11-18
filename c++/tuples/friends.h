//
// Created by URANIUM on 18/11/2026.
//


#ifndef TUPLES_FRIENDS_H
#define TUPLES_FRIENDS_H

#include <tuple>
#include <vector>
#include <string>

class Friend {
public:
    std::string name;
    uint8_t age{};

    explicit Friend(std::string name);

    Friend(std::string name, uint8_t age);
};

std::tuple<int, std::vector<Friend>> friendsList();


#endif //TUPLES_FRIENDS_H
