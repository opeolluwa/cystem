#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {

  FILE *fd[argc];
  if (argc <= 1) {
    fd[0] = stdin;
  } else {
      for (int i = 0; i < argc; i++) {
        fd[i] = fopen(argv[i], "r"); 
        if (fd[i] == NULL) {
          exit(-1);
        }
      }
  }

  int c; 
  for (int i = 0; i < argc; i++) {
    while ((c = fgetc(fd[i])) != EOF) {
      putc(c, stdout);
    }
  }

  return 0;
}
