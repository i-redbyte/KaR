#include <stdio.h>

#define MINLEN 81

int main() {
    int symbol, pos = 0;
    char line_part[MINLEN + 1];
    while ((symbol = getchar()) != EOF) {
        if (pos < MINLEN) {
            line_part[pos] = (char) symbol;
        } else if (pos == MINLEN) {
            line_part[MINLEN] = '\0';
            printf("%s", line_part);
            putchar(symbol);
        } else {
            putchar(symbol);
        }

        if (symbol == '\n') pos = 0;
        else ++pos;
    }
    return 0;
}