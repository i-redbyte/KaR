#include <stdio.h>

#define MAXLENGTH 20

int get_line(char [], int);

void copy(char [], char []);

int main() {
    int len, max = 0;
    char line[MAXLENGTH], longest[MAXLENGTH];
    while ((len = get_line(line, MAXLENGTH)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    printf("\n===================\nMax string length : %d", max);
    printf("\n");
    return 0;
}

int get_line(char line[], int limit) {
    int i, c;
    for (i = 0; i < limit - 1 && (((c = getchar()) != EOF) && (c != '\n')); i++)
        line[i] = c;
    if (i == (limit - 1)) {
        while ((c = getchar()) != '\n') {
            ++i;
        }
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}
