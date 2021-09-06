#include <stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch();

void ungetch(int ch);

int main() {
    char c;
    ungetch(EOF);
    while ((c = (char) getch()) != EOF) {
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
    } else if (ch != EOF) {
        buf[bufp++] = (char) ch;
    }
}
