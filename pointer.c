#include <stdio.h>
void swap(int *a, int *b);

int main(){
    int num = 10;
    int *ptr = &num;
    printf("Value: %d\n", *ptr);
    *ptr = 20;
    printf("New value: %d\n", *ptr);

    int a = 5, b = 10;
    printf("a: %d, b: %d\n", a, b);
    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);
    
}



void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

