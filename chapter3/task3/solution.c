#include <stdio.h>

#define MAX_LEN 1024
#define END_LINE '\0'

void expand(const char s1[], char s2[]);

int main() {
    char text[] = "-1-2 2-3 4-5 1-7";
    char result[MAX_LEN];
    expand(text, result);
    printf("%s\n", result);
    return 0;
}

void expand(const char s1[], char s2[]) {
    int i, j;
    char c, d;
    i = j = 0;
    while ((c = s1[i]) != END_LINE) {
        i++;
        if (c != ' ' && s1[i] == '-' && s1[i + 1] != END_LINE) {
            i++;
            d = s1[i];
            if (d < c) {
                while (d < c) {
                    s2[j] = c--;
                    j++;
                }
            } else {
                while (d > c) {
                    s2[j] = c++;
                    j++;
                }
            }
        } else {
            s2[j] = c;
            j++;
        }
    }
    s2[j] = END_LINE;
}
