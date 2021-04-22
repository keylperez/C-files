#include <stdio.h>
#include <stdlib.h>

struct date
{
    int month;
    int day;
    int year;
};

struct date date1 = {5, 27, 2001};
struct date date2 = {8, 11, 2001};

int diff_days()
{
    int days;
    int daysYear;
    daysYear = abs(360 * (date1.year - date2.year));
    days = abs((30 - date1.day) + (date2.day - 1));
    days += 30 * (abs(date1.month - date2.month) - 1);
    days = abs(daysYear - days);
    return days;
}

int main()
{
    int days;
    days = diff_days();
    printf("\n\tThe number of days between %d/%d/%d and %d/%d/%d is %d days", date1.month, date1.day, date1.year, date2.month, date2.day, date2.year, days);
}

/*
    Write a C function named diff_days() that determines the number of days between two dates. Do the following: 
    1. Each month is 30 days, which means 360 days each year. 
    2. The function should return the number of days as their difference. 
    3. Write a program to show the function works. 
    4. Write a version of the program using pointers to the dates as the function parameters. Show a side by side code screenshot to show the equivalence. 
*/