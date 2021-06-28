#include <stdio.h>

void escape(char *s, char *t);

void unescape(char *s, char *t);

int main(void) {
    char text[] = "\t\rKAR!\n\n\aC++,\n\tWorld! C\b the best \"language 'YES'\"!!!!!!\n";
    int len = sizeof(text) / sizeof(*text);
    char unescapeText[len];
    printf("\n======================================================\n");
    printf("First text:\n%s\n", text);
    escape(unescapeText, text);
    printf("Escaped text:\n%s\n", unescapeText);
    unescape(text, unescapeText);
    printf("Unescaped text:\n%s\n", text);
    printf("\n======================================================\n");
    return 0;
}

void escape(char *s, char *t) {
    int i, j;
    i = j = 0;
    while (t[i]) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            case '\a':
                s[j++] = '\\';
                s[j] = 'a';
                break;
            case '\b':
                s[j++] = '\\';
                s[j] = 'b';
                break;
            case '\f':
                s[j++] = '\\';
                s[j] = 'f';
                break;
            case '\r':
                s[j++] = '\\';
                s[j] = 'r';
                break;
            case '\v':
                s[j++] = '\\';
                s[j] = 'v';
                break;
            case '\\':
                s[j++] = '\\';
                s[j] = '\\';
                break;
            case '\"':
                s[j++] = '\\';
                s[j] = '\"';
                break;
            default:
                s[j] = t[i];
                break;
        }
        i++;
        j++;
    }
    s[j] = t[i];
}

void unescape(char *s, char *t) {
    int i, j;
    i = j = 0;
    while (t[i]) {
        switch (t[i]) {
            case '\\':
                switch (t[++i]) {
                    case 'n':
                        s[j] = '\n';
                        break;
                    case 't':
                        s[j] = '\t';
                        break;
                    case 'a':
                        s[j] = '\a';
                        break;
                    case 'b':
                        s[j] = '\b';
                        break;
                    case 'f':
                        s[j] = '\f';
                        break;
                    case 'r':
                        s[j] = '\r';
                        break;
                    case 'v':
                        s[j] = '\v';
                        break;
                    case '\\':
                        s[j] = '\\';
                        break;
                    case '\"':
                        s[j] = '\"';
                        break;
                    default:
                        s[j++] = '\\';
                        s[j] = t[i];
                }
                break;
            default:
                s[j] = t[i];
        }
        i++;
        j++;
    }
    s[j] = t[i];
}

