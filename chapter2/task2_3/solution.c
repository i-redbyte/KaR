#include <stdio.h>
#include <ctype.h>

unsigned int htoi(const char s[]) {
    unsigned int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int ch = tolower(s[i]);
        if (ch == '0' && tolower(s[i + 1]) == 'x') i++;
        else if (ch >= '0' && ch <= '9')
            n = 16 * n + (ch - '0');
        else if (ch >= 'a' && ch <= 'f')
            n = 16 * n + (ch - 'a' + 10);
    }
    return n;
}

int main(void) {
    printf("%d\n", htoi("0xFA9C")); //decimal: 64156
    printf("%d\n", htoi("0x0001")); // 1
    printf("%d\n", htoi("0xAAAA")); // 43690
    printf("%d\n", htoi("0xFFFF")); // 65535
    printf("%d\n", htoi("0x1111")); // 4369
    printf("%d\n", htoi("0xBCDA")); // 48346
    printf("%d\n", htoi("0xFF"));   // 255
    printf("%d\n", htoi("0xF"));    // 15
    printf("%d\n", htoi("0x10"));   // 16
    printf("%d\n", htoi("0x16"));   // 22
    return 0;
}