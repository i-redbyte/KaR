//Simple solution. Supplement in the future.
#include <stdio.h>

#define MAX_LINE 1000
char line[MAX_LINE];

int get_line(void);

int
main() {
    int len;
    int index;
    int brace, parenthesis;
    int s_quote = 1, d_quote = 1;
    index = len = brace = parenthesis = 0;

    while ((len = get_line()) > 0) {
        index = 0;
        while (index < len) {
            if (line[index] == '[') brace++;
            if (line[index] == ']') brace--;
            if (line[index] == '(') parenthesis++;
            if (line[index] == ')') parenthesis--;
            if (line[index] == '\'') s_quote *= -1;
            if (line[index] == '"') d_quote *= -1;
            index++;
        }
    }
    if (d_quote != 1) printf("Fail: double quote mark\n");
    if (s_quote != 1) printf("Fail: single quote mark\n");
    if (parenthesis != 0) printf("Fail: parenthesis\n");
    if (brace != 0) printf("Fail: brace mark\n");

    if (s_quote == 1 && d_quote == 1 && brace == 0 && parenthesis == 0)
        printf("Syntax OK.\n");
    return 0;
}

int get_line(void) {
    int c, i;
    extern char line[];
    for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;

}