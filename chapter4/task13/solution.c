#include<stdio.h>
#include<string.h>

void reverse(char[], int, int);

int main(void) {
    char s[] = "My friend C language!";
    int n = (int) strlen(s) - 1;
    reverse(s, 0, n);
    printf("%s\n", s);
    return 0;
}

void reverse(char s[], int left, int right) {
    char c;
    if (left < right) {
        reverse(s, left + 1, right - 1);
        c = s[left];
        s[left] = s[right];
        s[right] = c;
    }
}