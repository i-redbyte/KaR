#include <stdio.h>
#include <ctype.h>

double my_atof(char *s);

int main(void) {
    printf("%f\n", my_atof("123.45e-6"));
    printf("%f\n", my_atof("123.45e6"));
    printf("%f\n", my_atof("666.88e+2"));
    printf("%f\n", my_atof("666.88e-5"));
}

double my_atof(char *s) {
    double value, power, base, p;
    int i, sign, exp;

    for (i = 0; isspace(s[i]); i++);
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
        i++;
    }
    for (value = 0.0; isdigit(s[i]); i++) {
        value = 10.0 * value + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        value = 10.0 * value + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
    } else {
        return sign * value / power;
    }
    base = (s[i] == '-') ? 0.1 : 10.0;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (exp = 0; isdigit(s[i]); i++) {
        exp = 10 * exp + (s[i] - '0');
    }
    for (p = 1; exp > 0; --exp) {
        p = p * base;
    }
    return (sign * (value / power)) * p;
}