#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch() {
    return bufp > 0 ? buf[--bufp] : getchar();
}

int getop(char s[]) {
    int i;
    static int c = ' ';
    while (c == ' ' || c == '\t') {
        c = getchar();
    }

    s[0] = (char) c;
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        int res = c;
        c = ' ';
        return res;
    }
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
        while (isdigit(s[++i] = (char) c));
    }
    s[i] = '\0';
    return NUMBER;
}

int main() {
    /* no-op */
    return 0;
}