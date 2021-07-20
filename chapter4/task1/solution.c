#include <stdio.h>
#include <string.h>

int strrindex(char[], char[]);

void prefixSuffixArray(const char *pat, int m, int *pps);

int KMP(char *text, char *pattern);

int main() {
    char *s = "Kernighan and Ritchie";
    char *findText = "and";
    char *findText2 = "Ke";
    char *findText3 = "C++";
    char *findText4 = "tchi";
    char *findText5 = "rni";
    printf("\n'%s' find at '%s' at index %d\n", findText, s, strrindex(s, findText));
    printf("'%s' find at '%s' at index %d\n", findText2, s, strrindex(s, findText2));
    printf("'%s' find at '%s' at index %d\n", "000", s, strrindex(s, "000"));
    printf("\n================ KMP Algorithm ================\n\n");
    printf("'%s' KMP find at '%s' at index %d\n", findText3, s, KMP(s, findText3));
    printf("'%s' KMP find at '%s' at index %d\n", findText4, s, KMP(s, findText4));
    printf("'%s' KMP find at '%s' at index %d\n", findText5, s, KMP(s, findText5));
    return 0;
}

int strrindex(char s[], char t[]) {
    int ls, lt, is2, it;
    int is, match;
    ls = (int) strlen(s);
    lt = (int) strlen(t);
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

void prefixSuffixArray(const char *pat, int m, int *pps) {
    int length = 0;
    pps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[length]) {
            length++;
            pps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = pps[length - 1];
            } else {
                pps[i] = 0;
                i++;
            }
        }
    }
}

int KMP(char *text, char *pattern) {
    int m = (int) strlen(pattern);
    int n = (int) strlen(text);
    int pps[m];
    prefixSuffixArray(pattern, m, pps);
    int i, j;
    i = j = 0;
    int result = -1;
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == m) {
            return i - j;
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = pps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    return result;
}
