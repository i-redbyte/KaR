#include <stdio.h>

#define TAB_LEN 4

int main() {
    int c, spaces = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaces++;
            if (spaces == TAB_LEN) {
                spaces = 0;
                putchar('\t');
            }
        } else {
            for (int i = 0; i < spaces; ++i) putchar(' ');
            spaces = 0;
            putchar(c);
        }
    }
    return 0;
}