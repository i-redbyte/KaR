#include <stdio.h>

int my_any(const char s[], const char t[]) {
    int i, j;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; t[j] != '\0'; j++) {
            if (s[i] == t[j]) return i;
        }
    }
    return -1;
}

int main(void) {
    printf("position: %d\n", my_any("Haskell", "Scala"));
    printf("position: %d\n", my_any("Assembler", "x86"));
    printf("position: %d\n", my_any("C++", "C"));
    printf("position: %d\n", my_any("C", "Java"));
    printf("position: %d\n", my_any("Stack", "Heap"));
    printf("position: %d\n", my_any("Ilya", "Ada"));
    printf("position: %d\n", my_any("Kernighan", "Ritchie"));
    return 0;
}
