#include <iostream>

int main() {
    char* c {"alex is my friend"};

    std::string to_string  {(std::string)c};

    std::string res { "alex " " peter"};

    // raw string
    auto rw { R"(C://file/example\)"};

    std::cout << res.size() << to_string.length() << std::endl;

    return 0;
}
