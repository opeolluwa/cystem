#include <iostream>
#include <array>

int main() {
    unsigned int age[]{23, 45, 67, 9, 12, 45};

    unsigned sum{};
    size_t n {};
    for(; n < std::size(age); ++n) sum += age[n];

    std::cout << "The sum of " << n  << " ages " << " is " << sum << std::endl;
}
