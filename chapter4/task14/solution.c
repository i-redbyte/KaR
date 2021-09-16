#include <stdio.h>

#define swap(t, a, b) { t temp; temp = a, a = b, b = temp; }

int main() {
    double a = 100.5;
    double b = 200.9;

    int x = 42;
    int y = 245;

    char *px = "hello";
    char *py = "world";
    printf("\n<=============================>\n\n");
    printf("a, b BEFORE = %.2f; %.2f;\n", a, b);
    printf("x, y BEFORE = %d; %d;\n", x, y);
    printf("px, py BEFORE = %s; %s;\n", px, py);
    printf("\n<=============================>\n\n");
    swap(int, x, y);
    swap(double, a, b);
    swap(char *, px, py);
    printf("a, b AFTER =%.2f; %.2f;\n", a, b);
    printf("x, y AFTER = %d; %d;\n", x, y);
    printf("px, py AFTER = %s; %s;\n", px, py);
    printf("\n<=============================>\n\n");
    return 0;
}