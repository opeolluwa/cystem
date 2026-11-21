#include <cstdint>
#include <iostream>

class Uint {
    std::uint64_t val{};

public:
    explicit Uint(std::uint64_t val) : val{val} {}

    Uint operator+(const Uint& cmd) const {
        return Uint(this->val + cmd.val);
    }

    friend std::ostream& operator<<(std::ostream& os, const Uint& value) {
        return os << value.val;
    }
};

int main() {
    const Uint age(45);
    const Uint newAge(6);

    const auto total = age + newAge;

    std::cout << total << '\n';
}