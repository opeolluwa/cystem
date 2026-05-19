#include <stdio.h>
#include <string.h>
int main() {
  char name[] = "ales";

  int length = strlen(name);
  int counter = 0;

  printf("Length: %d\n", length);

  while (name[counter] != '\0') {
    counter++;
  }
  printf("Counter: %d\n", counter);
}
