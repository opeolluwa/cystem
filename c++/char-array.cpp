#include <iostream>

int main() {
  char vowels[5]{'a', 'e', 'i', 'o', 'u'};
  std::cout << vowels << std::endl;

  char names[]{"adefemi"};

  std::cout << names << std::endl;

  char stars[][80]{"Robert Redford", "Hopalong Cassidy", "Lassie",
                   "Slim Pickens",   "Boris Karloff",    "Oliver Hardy"};
}
