#include <stdio.h>

#define SPACE_POSITION 1
#define TAB_POSITION 0
#define TAB '\t'
#define SPACE ' '

int main(void) {
    int space_symbols[2];
    space_symbols[SPACE_POSITION] = space_symbols[TAB_POSITION] = 0;
    int input_symbols = 0;
    int last = '\n';
    while ((input_symbols = getchar()) != EOF) {
        if (input_symbols == ' ') space_symbols[SPACE_POSITION]++;
        else if (input_symbols == '\t') space_symbols[TAB_POSITION]++;
        else {
            if (input_symbols != '\n' && (space_symbols[TAB_POSITION] + space_symbols[SPACE_POSITION]) > 0) {
                if (space_symbols[TAB_POSITION] > 0) {
                    space_symbols[TAB_POSITION]--;
                    putchar(TAB);
                }
                if (space_symbols[SPACE_POSITION] > 0) {
                    space_symbols[SPACE_POSITION]--;
                    putchar(SPACE);
                }
                putchar(input_symbols);
            } else if (input_symbols == '\n' && last == '\n')/*no-op*/;
            else putchar(input_symbols);

            if (space_symbols[TAB_POSITION] > 0) space_symbols[TAB_POSITION] = 0;
            if (space_symbols[SPACE_POSITION] > 0) space_symbols[SPACE_POSITION] = 0;

            last = input_symbols;
        }
    }

    return 0;
}