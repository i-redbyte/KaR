#include <stdio.h>

unsigned  invert(unsigned x, int p, int n){
    unsigned mask = (~(~0 << p)) ^ ~(~0 << (p-n));
    return ((x & ~mask) | (~x & mask));
}
int main(void) {
    printf("%d\n", invert(255, 8, 8));
    printf("%d\n", invert(84, 3, 4));
    printf("%d\n", invert(10, 4, 4));
    printf("0x%X\n", invert(0xFF, 8, 6));
    printf("0x%X\n", invert(0x0A, 4, 2));
    printf("0x%X\n", invert(0xED, 8, 6));
    return 0;
}
