#include <iostream>

int main() {
  long dimension{56'000'000};
  long *pnum{&dimension};

  std::string name{"Alex"};
  auto *some_pointer{&name};
  std::cout << "the address of" << "name is " << some_pointer
            << " the dereferenced value is " << *some_pointer << std::endl;

  const char *proverbs{"Many mickle makes a muckle"};
  std::cout << proverbs;

    const char* const my_favorite_star{ "Lassie" };
    // my_favorite_star[0] ='w';
    // my_favorite_star = "alex";
  return 0;
}
