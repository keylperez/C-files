#include <stdio.h>
#include <stdlib.h>

struct date
{
    int month;
    int day;
    int year;
};

int diff_days(struct date *ptr1, struct date *ptr2)
{
    int days;
    int daysYear;
    daysYear = abs(360 * ((*ptr1).year - (*ptr2).year));
    days = abs((30 - (*ptr1).day) + ((*ptr2).day - 1));
    days += 30 * (abs((*ptr1).month - (*ptr2).month) - 1);
    days = abs(daysYear - days);
    return days;
}

int diff_days(struct date *ptr1, struct date *ptr2);

int main()
{
    struct date date1 = {5, 27, 2001};
    struct date date2 = {8, 11, 2001};
    struct date *ptr1 = &date1;
    struct date *ptr2 = &date2;
    int days;
    days = diff_days(ptr1, ptr2);
    printf("\n\tThe number of days between %d/%d/%d and %d/%d/%d is %d days", (*ptr1).month, (*ptr1).day, (*ptr1).year, (*ptr2).month, (*ptr2).day, (*ptr2).year, days);
    return 0;
}

/*
    Write a C function named diff_days() that determines the number of days between two dates. Do the following: 
    1. Each month is 30 days, which means 360 days each year. 
    2. The function should return the number of days as their difference. 
    3. Write a program to show the function works. 
    4. Write a version of the program using pointers to the dates as the function parameters. Show a side by side code screenshot to show the equivalence. 
*/
