#include <stdio.h>
#include <string.h>

#define MAX_STR 1000

void itoa(int, char [], int);

void reverse(char []);

int main() {
    int testValue = 256;
    char s[MAX_STR];
    s[0] = '\0';
    printf("Integer: %d\n", testValue);
    itoa(testValue, s, 0);
    printf("String: %s\n", s);
    return 0;
}

void itoa(int num, char s[], int pos) {
    int abs = 0;
    if (num < 0) {
        num *= -1;
        abs = EOF;
    }
    int buf = num % 10;
    if (buf > 0) {
        buf += '0';
        s[pos++] = (char) buf;
        if ((num / 10) > 0) {
            if (abs == EOF) {
                num *= -1;
            }
            num /= 10;
            itoa(num, s, pos);
        } else {
            if (abs == EOF) {
                s[pos++] = '-';
            }
            s[pos] = '\0';
        }
    }
    if (pos == 1) {
        reverse(s);
    }
}

void reverse(char s[]) {
    char c;
    int i, j;
    for (i = 0, j = (int) strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}