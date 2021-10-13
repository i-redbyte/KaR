#include <stdio.h>

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int day_of_year(int, int, int);

void month_day(int, int, int *, int *);

int main() {
    int m, d;

    printf("day_of_year: %d\n", day_of_year(2021, 8, 6));
    printf("day_of_year: %d\n", day_of_year(2021, 6, 14));
    printf("day_of_year: %d\n", day_of_year(2021, 1, 1));

    month_day(2021, 32, &m, &d);
    printf("month_day: %d %d\n", m, d);
    month_day(2021, 255, &m, &d);
    printf("month_day: %d %d\n", m, d);
    month_day(2021, 365, &m, &d);
    printf("month_day: %d %d\n", m, d);

    return 0;
}

int day_of_year(int year, int month, int day) {
    int leap;
    char *p;

    leap = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
    p = &daytab[leap][1];
    while (--month > 0) {
        day += *p++;
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap;
    char *p;

    leap = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
    p = &daytab[leap][1];
    while (yearday > *p) {
        yearday -= *p++;
    }
    *pmonth = 1 + p - &daytab[leap][1];
    *pday = yearday;
}