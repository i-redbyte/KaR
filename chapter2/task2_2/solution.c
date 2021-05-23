#include <stdio.h>

#define LIM 1000

int main(void) {
    int i, c;
    char line[LIM];
    for (i = 0; (i < LIM - 1) * ((c = getchar()) != '\n') * (c != EOF); ++i)
        line[i] = (char) c;
    line[i] = (char) c;
    printf("%s\n", line);
    return 0;
}
