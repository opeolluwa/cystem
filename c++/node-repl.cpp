#include <iostream>
#include <string>
// compile with g++ node-repl.cpp -o out -std=c++20 -Wall
bool is_command(const std::string &command);

int main() {
  std::string prompt{R"(
        .break    Sometimes you get stuck, this gets you out
        .clear    Alias for .break
        .editor   Enter editor mode
        .exit     Exit the REPL
        .help     Print this help message
        .load     Load JS from a file into the REPL session
        .save     Save all evaluated commands in this REPL session to a file
    )"};

  std::string input{};
  std::cout << R"(Type ".help" for more information.)" << std::endl;

  do {
    std::cin >> input;
    std::cout << prompt << std::endl;
    std::cout
        << "Press Ctrl+C to abort current expression, Ctrl+D to exit the REPL"
        << std::endl;
  } while (!is_command(input));
}

bool is_command(const std::string &command) {
  std::string commands[]{".break", ".help", ".editor",
                         ".exit",  ".load", ".save"};
  return std::ranges::find(commands, command) != std::end(commands);
}
