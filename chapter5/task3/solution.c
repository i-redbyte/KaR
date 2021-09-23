#include <printf.h>

void strCat(char *,  char *);

int main(int argc, char *argv[]) {
    char string1[] = "Hello, ";
    char string2[] = "my love language!";

    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);
    strCat(string1, string2);
    printf("\n====\nResult: %s\n====\n", string1);
    return 0;
}

void strCat(char *s,  char *t) {
    while(*s++);
    s--;
    while((*s++ = *t++));
}