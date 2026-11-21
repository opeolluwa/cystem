//
// Created by URANIUM on 21/11/2026.
//

#ifndef STUDENTS_OOP_PEOPLE_H
#define STUDENTS_OOP_PEOPLE_H
#include <string>


class People {
protected:
    std::string first_name;
    std::string last_name;

public:
    People(const std::string_view &first_name, const std::string_view &last_name);

    People();

    std::string full_name();
};


#endif //STUDENTS_OOP_PEOPLE_H
