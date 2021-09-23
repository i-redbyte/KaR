#include <stdio.h>

int strend(const char *, char *);

int main() {
    printf("=====\nresult = %d\n=====\n\n", strend("12345111", "111"));
    printf("=====\nresult = %d\n=====\n\n", strend("c++", "c"));
    printf("=====\nresult = %d\n=====\n\n", strend("assembler", "bler"));
    printf("=====\nresult = %d\n=====\n\n", strend("Sokolov Ilya", "Ilya"));
    printf("=====\nresult = %d\n=====\n\n", strend("scala", "python"));
    printf("=====\nresult = %d\n=====\n\n", strend("java", "kotlin"));
    return 0;
}

int strend(const char *s, char *t) {
    char *pt;
    for (pt = t; *s != '\0'; ++s) {
        if (*pt != '\0' && *s == *pt) {
            ++pt;
        } else {
            pt = t;
        }
    }
    if (*s == '\0' && *pt == '\0') return 1;
    return 0;
}