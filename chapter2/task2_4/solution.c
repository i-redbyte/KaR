#include <stdio.h>

void my_squeeze(char s[], const char chars[]);

int main(void) {
    char s[] = "C++";
    my_squeeze(s, "+");
    printf("%s\n", s);
    return 0;
}

void my_squeeze(char s[], const char chars[]) {
    int i, j, k;
    for (k = 0; chars[k] != '\0'; k++) {
        for (i = j = 0; s[i] != '\0'; i++) {
            if (s[i] != chars[k]) s[j++] = s[i];
        }
        s[j] = '\0';
    }
}