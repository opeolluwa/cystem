#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}


int power(int base, int exp) {
    if (base == 0) return 0;
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}