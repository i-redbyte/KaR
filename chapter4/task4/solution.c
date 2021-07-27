#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getop(char []);

void push(double);

double pop(void);

int getch(void);

void ungetch(int);

void viewStack();

void showTop();

void swap();

void duplicate();

void clearStack();

int main() {
    int type, ignoreNewline = 0;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: division by zero!\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2) {
                    push(fmod(pop(), op2));
                } else {
                    printf("\nerror: division by zero!");
                }
                break;
            case '$':
                ignoreNewline = 1;
                viewStack();
                break;
            case 'c':
                ignoreNewline = 1;
                clearStack();
                break;
            case 't':
                ignoreNewline = 1;
                showTop();
                break;
            case 's':
                ignoreNewline = 1;
                swap();
                break;
            case 'd':
                ignoreNewline = 1;
                duplicate();
                break;
            case '\n':
                if (ignoreNewline) {
                    ignoreNewline = 0;
                } else {
                    printf("\t%.8g\n", pop());
                }
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error:stack full \n");
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    i = 0;
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                ungetch(c);
            }
            return '-';
        }
    }
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()));
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: buffer overflow \n");
    } else {
        buf[bufp++] = c;
    }
}

void viewStack() {
    int i;
    printf("\nstack:\n");
    for (i = sp - 1; i >= 0; i--) {
        printf("%lf\n", val[i]);
    }
}

void showTop() {
    if (sp > 0) {
        printf("\t%.8g\n", val[sp - 1]);
    } else {
        printf("error: stack is empty\n");
    }

}

void swap() {
    double tmp;
    if (sp < 1) {
        printf("error: stack has less than 2 elements, can't swap\n");
    } else {
        tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    }
}

void duplicate() {
    if (sp > MAXVAL - 1) {
        printf("error: stack is full, can't duplicate\n");
    } else {
        double temp = pop();
        push(temp);
        push(temp);
    }
}

void clearStack() {
    sp = 0;
}