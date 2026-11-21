//
// Created by URANIUM on 21/11/2026.
//

#include "People.h"

#include <format>

People::People(const std::string_view &first_name, const std::string_view &last_name) : first_name(first_name),
    last_name(last_name) {
};



std::string People::full_name() {
    return std::format("{} {}", this->first_name, this->last_name);
}
