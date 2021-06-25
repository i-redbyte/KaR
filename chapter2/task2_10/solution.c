#include <stdio.h>

void lower(char *s);

int main() {
    char lower_text[] = "HelLo C! HOW ARE YOU?";
    lower(lower_text);
    printf("RESULT:\n%s\n", lower_text);
    return 0;
}

void lower(char *s) {
    int i = 0;
    char c;
    while ((c = s[i]) != '\0') {
        c >= 'A' && c <= 'Z' ? s[i++] += 'a' - 'A' : i++;
    }
}