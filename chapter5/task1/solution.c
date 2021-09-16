#include <stdio.h>
#include <ctype.h>

int buff = EOF;

int getint(int *pn);

int main() {
    int number;
    getint(&number);
    printf("%d\n", number);
    return 0;
}

int getch() {
    int temp;
    if (buff != EOF) {
        temp = buff;
        buff = EOF;
    } else {
        temp = getchar();
    }
    return temp;
}

void ungetch(int c) {
    if (buff != EOF) {
        fputs("ungetch: Too many characters", stderr);
    } else {
        buff = c;
    }
}

int getint(int *pn) {
    int c, sign;
    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    while (!isdigit(c)) {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}