#include <stdio.h>

struct point {
  int x;
  int y;
};

int main(){
  struct point origin = {2, 4};
  printf("point is %d %d", origin.x, origin.y);
  return 0;
}
