#include <iostream>
#include <array>

int main() {
    unsigned int age[]{23, 45, 67, 9, 12, 45};

    unsigned sum{};

    for(size_t n: age) sum += n;

    std::cout << "The sum of " << " ages " << " is " << sum << std::endl;
}
