#include <stdio.h>

#define MAX_LINE 1024
#define IGNORE_LAST_SYMBOLS 2

int get_line(char *line);

int main() {
    char input_text[MAX_LINE], reverse_text[MAX_LINE];
    int counter, len;

    while ((len = get_line(input_text)) > 0) {
        counter = 0;

        for (int i = len - IGNORE_LAST_SYMBOLS; i >= 0; i--) {
            reverse_text[counter] = input_text[i];
            counter++;
        }

        reverse_text[counter++] = '\n';
        reverse_text[counter++] = '\0';
        printf("%s", reverse_text);
    }
    return 0;
}

int get_line(char *line) {
    int symbol, i;
    for (i = 0; i < MAX_LINE - 1 && (symbol = getchar()) != EOF && symbol != '\n'; ++i) {
        line[i] = (char) symbol;
    }
    if (symbol == '\n') {
        line[i] = (char) symbol;
        i++;
    }
    line[i] = '\0';
    return i;
}