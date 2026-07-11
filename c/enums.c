#include <stdio.h>

enum Month {
  January,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December
};

int main() {
  enum Month month = January;
  printf("%d\n", month);
  return 0;
}
