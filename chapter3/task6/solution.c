#include <stdio.h>
#include <stdlib.h>

void swap(char *x, char *y);

char *reverse(char *buffer, int i, int j);

char *itoa(int value, char *buffer, int base);

int main(void) {
    char buffer[33];
    int value[] = {255, 27, 64, 128};
    int base[] = {16, 10, 8, 2};
    for (int i = 0; i < 4; i++) {
        printf("itoa(%d, %d) = %s\n", value[i], base[i], itoa(value[i], buffer, base[i]));
    }
    return 0;
}

void swap(char *x, char *y) {
    char t = *x;
    *x = *y;
    *y = t;
}

char *reverse(char *buffer, int i, int j) {
    while (i < j) {
        swap(&buffer[i++], &buffer[j--]);
    }
    return buffer;
}

char *itoa(int value, char *buffer, int base) {
    if (base < 2 || base > 32) {
        return buffer;
    }
    int n = abs(value);
    int i = 0;
    while (n) {
        int x = n % base;
        buffer[i++] = (char) (x >= 10 ? 65 + (x - 10) : 48 + x);
        n = n / base;
    }
    if (i == 0) {
        buffer[i++] = '0';
    }
    if (value < 0 && base == 10) {
        buffer[i++] = '-';
    }
    buffer[i] = '\0';
    return reverse(buffer, 0, i - 1);
}
