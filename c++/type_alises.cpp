#include <iostream>
#include <map>
#include <memory>
#include <string>
/**
 * type aliases are defined with "using" and typedef keywords
 */
int main() {

  using LargePositiveNumbers = unsigned long long;
  // using <new type> =  <type>
  typedef unsigned short int SmallPositiveNumbers;
  // typedef <types...> <new type>
  // this is legacy code tho
  /**
   * 1The other advantages of the using syntax over the typedef syntax manifest
   themselves only when specifying aliases for more advanced types. Using using,
   for instance, it’s much easier to specify aliases for function types. You’ll
   see this in Chapter 18. The using keyword moreover allows you to specify
   so-called type alias templates, or parameterized type aliases, something that
   is not possible using the old typedef syntax. We’ll show you an example of an
   alias template in Chapter 18 as well.
   */

  LargePositiveNumbers account_balance{400'890'456};
  std::cout << account_balance << std::endl;

  struct Contact {
    std::string name;
    int age;

    Contact(std::string name, int age) : name(std::move(name)), age(age) {}
  };

  using PhoneBook = std::map<std::shared_ptr<Contact>, std::string>;
  PhoneBook phonebook;

  auto alice = std::make_shared<Contact>("Alice", 25);
  auto bob = std::make_shared<Contact>("Bob", 30);

  phonebook[alice] = "+1-555-1234";
  phonebook[bob] = "+1-555-5678";
}
