#include <stdio.h>
#include <string.h>

int strrindex(char[], char[]);

int main() {
    char *s = "Kernighan and Ritchie";
    char *findText = "and";
    char *findText2 = "Ke";
    printf("'%s' matches '%s' at index %d\n", findText, s, strrindex(s, findText));
    printf("'%s' matches '%s' at index %d\n", findText2, s, strrindex(s, findText2));
    printf("'%s' matches '%s' at index %d\n", "000", s, strrindex(s, "000"));
    return 0;
}

int strrindex(char s[], char t[]) {
    int ls, lt, is, is2, it, match;
    ls = strlen(s);
    lt = strlen(t);
    match = -1;
    for (is = ls - 1; is >= 0; is--) {
        for (it = 0, is2 = is; it < lt; it++, is2++) {
            if (t[it] != s[is2]) {
                match = -1;
                break;
            }
            match = is;
        }
        if (it >= lt)return match;
    }
    return match;
}