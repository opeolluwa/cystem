//
// Created by URANIUM on 21/11/2026.
//

#ifndef STUDENTS_OOP_STUDENTS_H
#define STUDENTS_OOP_STUDENTS_H

#include <format>
#include <string>

#include "People.h"


class Student : public People {
    std::string email;

public:
    Student(const std::string_view &first_name, const std::string_view &last_name,
            const std::string_view &email) : People(first_name, last_name), email(email) {
    }

    Student(const std::string_view &email) : People(), email(email) {
    };

    Student(const std::string_view &first_name, const std::string_view &last_name) : People(first_name, last_name) {
    }
};


#endif //STUDENTS_OOP_STUDENTS_H
