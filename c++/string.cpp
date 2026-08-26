#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>

int main() {
  std::string proverb{"many mickle makes a muckle"};

  // to convert to c_str //
  const char *cstr_1 = proverb.c_str(); // pre c++ 17
  char *proverb_data = proverb.data();

  std::cout << "str_1 " << cstr_1 << std::endl;
  std::cout << "proverb_data " << proverb_data << std::endl;

  // length
  size_t length = proverb.length();
  std::cout << "length of proverb " << length << std::endl;

  // partial initialization
  std::string str_literal{"Least said soonest mended"};
  std::cout << "str_literal " << str_literal << std::endl;

  std::string sleeping(6, 'z');
  // The string object, sleeping, will contain "zzzzzz". The string length will
  // be 6. If you want to define a3
  //
  // from ans existing string
  std::string sentence{proverb};
  std::string sentence_2{
      proverb, 0, 13}; // 0 = starting point, 13 = length // many a muckle

  std::string noun{"Aice"};
  std::string attributes{"cycling"};

  attributes = " is cycling ";
  std::string possibilities{noun + attributes};

  std::cout << possibilities << std::endl;

  std::string testes{" uuu"
                     " test " +
                     noun};
  std::cout << testes << std::endl;

  // using append
  std::string first_name, second, full_name;
  std::cout << "Enter your names";

  // std::cin >> first_name;
  // std::cin >> second;

  // full_name = first_name.append(" ").append(second);
  // std::cout << "your full name is " << full_name << std::endl;

  // full_name.c_str();
  //
  int64_t answer{56};
  std::string response{" result  is"};

  // std::string erratic_answer{response + 56};
  // strings and numbers
  std::string valid_answer{response + std::to_string(answer)};

  std::cout << " " << " valid " << valid_answer << std::endl;

  // characters in a string
  for (auto ch : valid_answer)
    std::cout << ch << std::endl;
}
