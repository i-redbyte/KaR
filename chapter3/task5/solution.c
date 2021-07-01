#include <stdio.h>

#define NUMBER  180
#define MAX_SIZE  256

void itob(int n, char s[], int b);

void reverse(char s[]);

int main(void) {
    char s[MAX_SIZE];
    for (int i = 2; i <= 26; i++) {
        itob(NUMBER, s, i);
        printf("Number %d in base %d : %s\n", NUMBER, i, s);
    }
    return 0;
}

void itob(int n, char s[], int b) {
    int i, sign, tmp_res;
    sign = n;
    i = 0;
    do {
        tmp_res = n % b;
        if (sign < 0) {
            tmp_res = -tmp_res;
        }
        if (tmp_res > 9) {
            s[i++] = (char) (tmp_res - 10 + 'A');
        } else {
            s[i++] = (char) (tmp_res + '0');
        }
    } while (n /= b);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';

    reverse(s);
}

void reverse(char s[]) {
    int i, j;
    i = j = 0;
    while (s[j] != '\0') j++;
    int tmp;
    for (--j; j > i; i++, j--) {
        tmp = (int) s[j];
        s[j] = s[i];
        s[i] = (char) tmp;
    }
}