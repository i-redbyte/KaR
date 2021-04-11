#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_COUNT_TAB 8
#define SPACE ' '

int main(int argc, char *argv[]) {
    unsigned int tab = DEFAULT_COUNT_TAB;
    unsigned int position = 1;
    int input_char;

    if (argc > 1) tab = strtoul(argv[1], NULL, 10);

    while ((input_char = getchar()) != EOF) {
        if (input_char == '\t') {
            input_char = SPACE;
            while (position++ < tab) putchar(input_char);
            position = 0;
        }
        if (input_char == SPACE) position = 0;
        putchar(input_char);
        if (position == tab) position = 1;
        else position++;
    }
    return 0;
}