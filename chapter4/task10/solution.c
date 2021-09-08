/*
 * SEE: https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_4:Exercise_10
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP     100
#define NUMBER    '0'
#define VARIABLE  '1'
#define VARMAX     27
#define BUFSIZE 1000
#define MAXVAL  100

int is_first_input = 0;
double var_array[VARMAX];

int getop(char []);

void push(double);

double pop(void);

double top(void);

int clear(void);

int swap(void);

int elem(void);

int dup(void);

void sprnt(void);

void result(void);

void set_solution(void);

void print_help(void);

int mygetline(char [], int);

int main() {
    int type;
    int i, j;
    int op3;
    double topd;
    double op2;
    char ic[MAXOP];
    char tmp[MAXOP];

    for (i = 0; i < VARMAX; i++) {
        var_array[i] = 0;
    }

    print_help();

    while ((type = getop(ic)) != EOF) {

        op3 = elem();
        if (op3 == 0) {
            is_first_input = 1;
        } else if (op3 > 1) {
            is_first_input = 0;
        }

        j = 0;

        switch (type) {
            case NUMBER:
                push(atof(ic));
                break;
            case VARIABLE:
                for (i = 2; ic[i] != '\0'; i++) {
                    tmp[j++] = ic[i];
                    tmp[j] = '\0';
                }
                var_array[ic[0] - 'A'] = atof(tmp);
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
                    printf("Error: Divide by zero.\n");
                }
                break;
            case '%':
                op3 = (int) pop();
                push((int) pop() % op3);
                break;
            case 'c':
                if (clear()) {
                    printf("Stack Cleared.\n");
                }
                break;
            case 'p':
                if ((topd = top()) != 0) {
                    printf("Top stack element: %g", topd);
                    printf(" of %d elements.\n", elem());
                }
                break;
            case 's':
                if (swap()) {
                    printf("Swap successful.\n");
                }
                break;
            case 'd':
                if (dup()) {
                    printf("Duplication is successful.\n");
                } else {
                    printf("Error: Stack empty.\n");
                }
                break;
            case 'r':
                sprnt();
                break;
            case 'o':
                if (elem() < 2) {
                    printf("Error: pow requires at least two ");
                    printf("items on the stack.\n");
                    break;
                }
                op2 = pop();
                push(pow(op2, pop()));
                break;
            case 'i':
                set_solution();
                push(sin(pop()));
                result();
                break;
            case 'y':
                set_solution();
                push(cos(pop()));
                break;
            case 't':
                set_solution();
                push(tan(pop()));
                break;
            case 'x':
                set_solution();
                push(exp(pop()));
                break;
            case 'q':
                set_solution();
                push(sqrt(pop()));
                break;
            case 'f':
                set_solution();
                push(floor(pop()));
                break;
            case 'l':
                set_solution();
                push(ceil(pop()));
                break;
            case 'v':
                for (i = 0; i < VARMAX; i++) {
                    if (i < VARMAX - 1) {
                        printf("%c: %10.10G\n", 'A' + i, var_array[i]);
                    } else {
                        printf("%c: %10.10G\n", '=', var_array[VARMAX]);
                    }
                }
                break;
            case 'h':
                print_help();
                break;
            case '\n':
                result();
                break;
            default:
                if ((type >= 'A' && type <= 'Z') || type == '=') {
                    if (type != '=') {
                        push(var_array[type - 'A']);
                    } else {
                        push(var_array[VARMAX]);
                    }
                } else {
                    printf("Error: Unknown command \'%s\'\n", ic);
                }
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
        printf("Error: Stack full, cannot push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("Error: Stack empty.\n");
        return 0.0;
    }
}

double top(void) {
    if (sp > 0) {
        return val[sp - 1];
    } else {
        printf("Error: Stack empty.\n");
        return 0.0;
    }
}

int clear(void) {
    if (sp > 0) {
        while (val[--sp] != '\0');
        sp = 0;
        return 1;
    } else {
        printf("Error: Stack empty.\n");
        return 0;
    }
}

int swap(void) {
    double sbuf;
    if (sp > 0) {
        sbuf = val[sp - 2];
        val[sp - 2] = val[sp - 1];
        val[sp - 1] = sbuf;
        return 1;
    } else {
        printf("Error: Stack empty.\n");
        return 0;
    }
}

int elem(void) {
    return sp;
}

int dup(void) {
    if (sp > 0) {
        sp++;
        val[sp] = val[sp - 1];
        return 1;
    } else {
        return 0;
    }
}

void sprnt(void) {
    int count = 0;
    while (count < sp) {
        printf("%d:%10.12g\n", count + 1, val[count]);
        count++;
    }
}

void result(void) {
    if (sp == 1 && is_first_input != 1) {
        printf("Solution: %10.20g\n", val[0]);
        var_array[VARMAX] = val[0];
        is_first_input = 0;
        clear();
    }
}

void set_solution(void) {
    if (elem() >= 1) {
        is_first_input = 0;
    }
}

int mygetline(char s[], int maxline) {
    int i = 0;
    char c;
    while ((c = getchar()) != EOF && c != '\n' && i < maxline) {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i++] = '\0';
    return i;
}

char getopbuf[BUFSIZE];
int getopbufp = 0;
int getopbuflen = 0;

int getop(char s[]) {
    int i = 0, c;
    s[0] = '\0';

    if (getopbuflen == 0 || getopbufp == getopbuflen - 2) {
        getopbufp = 0;
        getopbuflen = mygetline(getopbuf, BUFSIZE);
    }

    if (getopbuf[getopbufp] == '\n') {
        return '\n';
    }

    while (isspace(c = getopbuf[getopbufp++]));
    s[i++] = c;

    if (isalpha(c) && c >= 'A' && c <= 'Z') {
        for (i = 1; getopbuf[getopbufp] != ' ' && getopbuf[getopbufp] != '\n'; s[i++] = getopbuf[getopbufp++]);
        s[i] = '\0';
        if (i > 1) {
            return VARIABLE;
        } else {
            return c;
        }
    } else if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    if (c == '-') {
        if ((c = getopbuf[++getopbufp]) == ' ') {
            return c;
        } else if (isdigit(c)) {
            s[++i] = c;
        }
    }
    if (isdigit(c)) {
        for (; isdigit(c = getopbuf[getopbufp]); i++, getopbufp++) {
            s[i] = c;
        }
    }
    if (c == '.') {
        while (isdigit(s[i++] = c = getopbuf[getopbufp++]));
    }
    s[i] = '\0';
    return NUMBER;
}

void print_help(void) {
    printf("The Polish Calculator\n");
    printf("-----------------------------------------------\n");
    printf("-> Enter equations in the form: \"1 1 + 2 5 + *\"\n");
    printf("-> Use \"A=1 B=2 C=3\" to store variables.\n");
    printf("-> Use \"A B C * *\" to use stored variables.\n");
    printf("-----------------------------------------------\n");
    printf(">>> Command Help:\n");
    printf(">>>     c:      Clear memory.\n");
    printf(">>>     p:      Print last character.\n");
    printf(">>>     s:      Swap last two characters.\n");
    printf(">>>     d:      Duplicate the last input.\n");
    printf(">>>     r:      Print the entire stack.\n");
    printf(">>>     v:      Print variable list.\n");
    printf(">>>     o:      pow(x,y), x^y, x > 0.\n");
    printf(">>>     i:      sin(x), sine of x.\n");
    printf(">>>     y:      cos(x), cosine of x.\n");
    printf(">>>     t:      tan(x), tangent of x.\n");
    printf(">>>     x:      exp(x), e^x, exponential function.\n");
    printf(">>>     q:      sqrt(x), x >= 0, square of x.\n");
    printf(">>>     f:      floor(x), largest integer not greater than x.\n");
    printf(">>>     l:      ceil(x), smallest integer not less than x.\n");
    printf(">>>     =:      Access the last successful solution.\n");
    printf(">>>     h:      Print this help text.\n");
}