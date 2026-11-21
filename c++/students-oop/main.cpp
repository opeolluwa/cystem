#include <iostream>

#include "students.h"


int main() {
    Student alex("peter", "brown", "test@mailer.com");
    // Student bryan("d");

    std::cout << alex.full_name() << std::endl;
    return 0;
}
