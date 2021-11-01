#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSIZE    100

int main(int argc, char *argv[]) {
    double data[MAXSIZE];
    double *point_data = data;

    while (--argc) {
        if (isdigit(**++argv))
            *point_data++ = atof(*argv);
        else if (*argv[0] == '-') {
            point_data -= 2;
            *point_data = *point_data - *(point_data + 1);
            ++point_data;
        } else if (*argv[0] == '/') {
            point_data -= 2;
            *point_data = *point_data / *(point_data + 1);
            ++point_data;
        } else if (*argv[0] == '*') {
            point_data -= 2;
            *point_data = (*point_data) * (*(point_data + 1));
            ++point_data;
        } else if (*argv[0] == '+') {
            point_data -= 2;
            *point_data = *point_data + *(point_data + 1);
            ++point_data;
        } else {
            argc = 1;
        }
    }
    printf("%.2f\n", *--point_data);
    return 0;
}