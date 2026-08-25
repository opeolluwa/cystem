#include <stdio.h>

int sumOfArray(int A[]) {
  int sum = 0;
  int size = sizeof(A) / sizeof(A[0]);
  for (int i = 0; i < size; i++) {
    sum += A[i];
  }
  return sum;
}

int main() {
  int arrays[5] = {1, 5, 2, 3, 4};

  for (int i = 0; i < 5; i++) {
    printf("the address of %d is %d \n", arrays[i], &arrays[i]);
  }

  int sum = sumOfArray(arrays);
  printf("%d", sum);
}
