#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 1
char buf[BUFSIZE];
int bufp = 0;

int getch();

void ungetch(int ch);

int main() {
    char c;
    while ((c = (char) getch()) != EOF) {
        if (isdigit(c)) {
            putchar(c);
            while (isdigit(c = (char) getch())) {
                putchar(c);
            }
            if (c != EOF) {
                ungetch(c);
            }
        } else {
            putchar(c);
        }
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
