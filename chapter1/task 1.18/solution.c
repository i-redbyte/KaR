#include <stdio.h>

#define SPACE_POSITION 1
#define TAB_POSITION 0
#define TAB '\t'
#define SPACE ' '

int main(void) {
    int input_symbols[2], space_symbols[2];
    space_symbols[SPACE_POSITION] = space_symbols[TAB_POSITION] = 0;
    input_symbols[0] = '\n';

    while ((input_symbols[1] = getchar()) != EOF) {
        if (input_symbols[1] == ' ') space_symbols[SPACE_POSITION]++;
        else if (input_symbols[1] == '\t') space_symbols[TAB_POSITION]++;
        else {
            if (input_symbols[1] != '\n' && (space_symbols[TAB_POSITION] + space_symbols[SPACE_POSITION]) > 0) {
                if (space_symbols[TAB_POSITION] > 0) {
                    space_symbols[TAB_POSITION]--;
                    putchar(TAB);
                }
                if (space_symbols[SPACE_POSITION] > 0) {
                    space_symbols[SPACE_POSITION]--;
                    putchar(SPACE);
                }
                putchar(input_symbols[1]);
            } else if (input_symbols[1] == '\n' && input_symbols[0] == '\n')/*no-op*/;
            else putchar(input_symbols[1]);

            if (space_symbols[TAB_POSITION] > 0) space_symbols[TAB_POSITION] = 0;
            if (space_symbols[SPACE_POSITION] > 0) space_symbols[SPACE_POSITION] = 0;

            input_symbols[0] = input_symbols[1];
        }
    }

    return 0;
}