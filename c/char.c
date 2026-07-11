#include <stdio.h>

int main() {
    int c; 

    printf("Enter text: ");
    c = getchar();
    while (c!= EOF) {
        putchar(c);
        c= getchar();
    
    }
    
}