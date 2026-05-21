#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  int c;
  FILE *fd = fopen(argv[0], "r");

  if (fd ==NULL){
      exit(-1);
  }
  while ((c = fgetc(fd)) != EOF) {
    putc(c, stdout);
  }

  return 0;
}
