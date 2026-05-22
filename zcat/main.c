#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {

  FILE *fd;
  if (argc <= 1) {
    fd = stdin;
  } else {
    fd = fopen(argv[0], "r");
  }

  int c;

  if (fd == NULL) {
    exit(-1);
  }
  while ((c = fgetc(fd)) != EOF) {
    putc(c, stdout);
  }

  return 0;
}
