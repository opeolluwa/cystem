#include <iostream>

void call(int arg, int arg2, std::function<void(int, int)> func) {
    func(arg, arg2);
};


int main() {
    auto sum = [](const int x, const int y) -> int { return x + y; };
    std::cout << sum(2, 3) << std::endl;

    call(2, 5, sum);

    return 0;
}
