#include <stdio.h>

static char daytab[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

void month_day(int, int, int*, int*);
int day_of_year(int, int, int);

int main() {
    int month, day;

    printf("%d\n", day_of_year(1993, 11, 20));
    month_day(1988, 60, &month, &day);
    printf("%d %d\n", month, day);
    return 0;
}

void month_day(int year, int day, int *pmonth, int *pday) {
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
    for(i = 0; day > daytab[leap][i]; i++) {
        day -= daytab[leap][i];
    }

    *pmonth = i + 1;
    *pday = day;
}

int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = (year % 4 == 0 && year % 100 == 0 || year % 400 == 0);
    for(i = 0; i < month - 1; i++) {
        day += daytab[leap][i];
    }

    return day;
}
