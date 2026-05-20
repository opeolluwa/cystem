#include <stdio.h>

int main(int argc, char *argv[]) {
  int c;
  FILE *fp = fopen(argv[0], "r");
  
  while ((c = getc(stdin)) != EOF) {
    putc(c, stdout);
  }

  return 0;
}
