#include <stdio.h>
#include <limits.h>

void itoa(int n, char s[]);

void reverse(char *s);

int main(void) {
    char buffer[100];
    printf("Min: %d\n", INT_MIN);
    itoa(INT_MIN, buffer);
    printf("Buffer : %s\n", buffer);
    return 0;
}

void itoa(int n, char s[]) {
    int i, sign;
    i = 0;
    sign = n;
    if (n < 0) {
        s[i++] = (char) ((((-(n + 1)) % 10) + 1) % 10 + '0');
        n /= 10;
        n = -n;
    } else {
        s[i++] = (char) (n % 10 + '0');
        n /= 10;
    }
    while (n > 0) {
        s[i++] = (char) (n % 10 + '0');
        n /= 10;
    }
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char *s) {
    int c, i, j;
    int n = sizeof(s) / sizeof(*s);
    for (i = 0, j = n - 1; i < j; i++, j--) {
        c = (int) s[i];
        s[i] = s[j];
        s[j] = (char) c;
    }
}
