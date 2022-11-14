#include <stdio.h>


int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    int m, d;
    month_day(1988,60,&m,&d);
    printf("month: %d, day: %d\n", m, d);
    return 0;
}


static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    /* Error check 1: if month is out of bounds */
    if (month < 1 || month > 12) {
        printf("Month out of bounds\n");
        return -1;
    }

    /* Error check 2: if day is out of bounds */
    if (day < 0 || day > daytab[month]) {
        printf("Day out of bounds\n");
        return -2;
    }

    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 0; i < month; ++i)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (year < 0 || yearday < 0) {
        printf("Incorrect input.\n");
        *pmonth = *pday = -1;
        return;
    }

    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    /* Error check: If yearday is out of bounds */
    if (leap && yearday > 366) {
        yearday %= 366;
        year++;
    } else if (yearday > 365) {
        yearday %= 365;
        year++;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
    return;
}


