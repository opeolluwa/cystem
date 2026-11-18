#include <iostream>
#include <utility>

class Friend {
public:
    std::string name;

    explicit Friend(std::string name) : name(std::move(name)) {
    };
};

int main() {
    int friendsCount{};
    std::cout << "How many friends?\n";
    std::cin >> friendsCount;

    std::vector<Friend> friends;


    while (std::size(friends) < friendsCount) {
        std::cout << "Enter friend's name: ";
        std::string friendName;
        std::cin >> friendName;

        friends.emplace_back(friendName);
    }


    for (const auto &frnd: friends) {
        std::cout << frnd.name << '\n';
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
