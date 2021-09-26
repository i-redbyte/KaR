#include <stdio.h>
#include <string.h>

#define SIZE 100

char *strncpyNew(char *s, char *t, unsigned int n);

char *strncatNew(char *s, char *t, unsigned int n);

int strncmpNew(char *s, char *t, unsigned int n);

int main() {
    char s[SIZE] = "Rust Kotlin", t[SIZE] = "Ruby C";
    char *ps = "Java Kotlin", *pt = "Rust C";
    printf("strncmpNew(%s, %s, %d) = %d\n", ps, pt, 6, strncmpNew(s, t, 6));
    printf("strncatNew(%s, %s, %d) = %s\n", ps, pt, 8, strncatNew(s, t, 8));
    printf("strncpyNew(%s, %s, %d) = %s\n", ps, pt, 3, strncpyNew(s, t, 3));
    return 0;
}

char *strncpyNew(char *s, char *t, unsigned int n) {
    int i, tlen = strlen(t);
    for (i = 0; i < n; i++) {
        if (i < tlen) {
            s[i] = t[i];
        } else {
            s[i] = 0;
        }
    }
    s[i] = 0;
    return s;
}

char *strncatNew(char *s, char *t, unsigned int n) {
    int i, tlen = strlen(t), slen = strlen(s);
    for (i = 0; i < n; i++) {
        if (i < tlen) {
            s[slen + i] = t[i];
        } else {
            break;
        }
    }
    s[slen + i] = '\0';
    return s;
}

int strncmpNew(char *s, char *t, unsigned int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (s[i] != t[i] || s[i] == 0 || t[i] == 0) return s[i] - t[i];
    }
    return 0;
}