#include <stdio.h>

unsigned rotright(unsigned x, int n) {
    while (n > 0) {
        x = (x >> 1) | ~(~0U >> (x & 1));
        n--;
    }
    return x;
}

int main(void) {
    printf("%d\n", rotright(254, 1));
    printf("%d\n", rotright(1, 1));
    printf("%d\n", rotright(-2147483648, 31));
    printf("%d\n", rotright(10, 1));
    printf("0x%X\n", rotright(0xFF, 8));
    printf("0x%X\n", rotright(0x0A, 4));
    printf("0x%X\n", rotright(0xED, 8));
    return 0;
}
