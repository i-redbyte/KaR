#include<stdio.h>

#define MAX_LINE 100000

int main() {
    char line[MAX_LINE], ch;
    int i = 0;
    while ((ch = getchar()) != EOF) {
        line[i] = ch;
        i++;
    }
    printf("\n Output result:\n");
    for (int k = 0; k < i; k++) {
        if (line[k] == '/' && line[k + 1] == '/') {
            k += 2;
            while (line[k + 1] != '\n') k++;
        } else if (line[k] == '/' && line[k + 1] == '*' && line[k + 2] != '"') {
            k += 2;
            while ((line[k] == '/' && line[k + 1] == '/') || line[k] != '/') {
                k++;
            }
        } else {
            printf("%c", line[k]);
        }
    }
    return 0;
}