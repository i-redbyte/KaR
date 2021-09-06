#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch();

void ungetch(int ch);

void ungets(char *s);

int main() {
    char s[] = "123456789 C - it's goood\n";
    int c;
    ungets(s);
    while ((c = getch()) != EOF) {
        putchar(c);
    }
    return 0;
}

int getch() {
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int ch) {
    if (bufp >= BUFSIZE) {
        printf("error: stack is full, can't execute ungetch()\n");
    } else {
        buf[bufp++] = (char) ch;
    }
}

void ungets(char *s) {
    int i, len;
    len = (int) strlen(s);
    if (BUFSIZE - bufp >= len) {
        for (i = ((int) strlen(s)) - 1; i >= 0; i--) {
            ungetch(s[i]);
        }
    } else {
        printf("error: not enough buffer space, can't execute ungets()\n");
    }
}
