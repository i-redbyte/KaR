
#include <stdio.h>

#define LIMIT 10

void show_array(char *line, int n);

int main(void) {
    int c, line_len, word_len, space_size, in_word_flag;
    char word_buf[100], space_buf[100];
    in_word_flag = line_len = word_len = space_size = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            if (line_len + word_len > LIMIT) putchar('\n');
            show_array(word_buf, word_len);
            putchar('\n');
            in_word_flag = line_len = word_len = space_size = 0;
        } else if (c == ' ' || c == '\t') {
            if (in_word_flag) {
                in_word_flag = 0;
                if (line_len + word_len > LIMIT) {
                    putchar('\n');
                    show_array(word_buf, word_len);
                    line_len = word_len;
                    word_len = 0;
                } else {
                    show_array(word_buf, word_len);
                    line_len += word_len;
                    word_len = 0;
                }
            }
            space_buf[space_size++] = c;
        } else {
            if (!in_word_flag) {
                in_word_flag = 1;
                show_array(space_buf, space_size);
                line_len += space_size;
                space_size = 0;
            }
            word_buf[word_len++] = c;
        }
    }
    return 0;
}

void show_array(char *line, int n) {
    int i;
    for (i = 0; i < n; i++) putchar(line[i]);
}