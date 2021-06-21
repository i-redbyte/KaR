#include <stdio.h>

unsigned setbits(const int x, const int p, const int n, const int y) {
    return ((x & ~(~(~0 << n) << (p + 1 - n))) | ((~(~0 << n) & y) << (p + 1 - n)));
}

int main(void) {
    printf("0x%X\n", setbits(0x0FFF, 4, 4, 0xA));
    printf("0x%X\n", setbits(0x0, 4, 4, 0xA));
    printf("0x%X\n", setbits(0x0, 8, 16, 0xF));
    printf("0x%X\n", setbits(0x0, 5, 3, 0xF));
    return 0;
}
