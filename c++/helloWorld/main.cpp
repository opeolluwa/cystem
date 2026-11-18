#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;


    int age {45};
    int16_t age2 {45};
    int32_t age3 {45};
    int64_t age4 {45};

    int* age_pointer = &age;
    std::cout << age_pointer << std::endl;
    std::cout << *age_pointer << std::endl;
    return 0;
}
