#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calendar();
void printWeather();

int main()
{
    srand(time(0));
    calendar();
    return 0;
}

void calendar()
{
    int week, days, dayStart, wthDays, x;
    int dayNum = 1, space = 0, wth = 1;
    char weatherStat[6];
    printf("\n\n");
    printf("||\tSun\t||\tMon\t||\tTues\t||\tWed\t||\tThurs\t||\tFri\t||\tSat");
    printf("\n||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\n");
    /* returns random number between 1 to 7 to determine which day of the week the month will start*/
    dayStart = (rand() % 7) + 1;
    /* prints first row with consideration on which day the month will start*/
    for (days = 1; days <= 7; days++)
    {
        if (days >= dayStart)
        {
            printf("||\t%d\t", dayNum);
            dayNum++;
            wth++;
        }
        /*Prints space if month does not start yet*/
        else
        {
            printf("||\t \t");
            space++;
        }
    }
    printf("\n");
    /*Prints the weather status on the next row below the number dates*/
    for (wthDays = 1; wthDays <= 7; wthDays++)
    {
        if (wthDays <= space)
        {
            printf("||\t \t");
        }
        else
        {
            printWeather();
        }
    }
    printf("\n||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\n");
    /*Pick random last day between 28 to 31*/
    int lastDay = (rand() % 4 + 28);
    /*loop per week*/
    for (week = 1; dayNum <= lastDay; week++)
    {
        /*Loop to print per day*/
        for (days = 1, x = 1; days <= 7 && dayNum <= lastDay; days++)
        {
            printf("||\t%d\t", dayNum);
            dayNum++;
            x++;
        }
        /*Loop to print space after all the days are printed*/
        while (dayNum > lastDay && days <= 7)
        {
            printf("||\t \t");
            days++;
        }
        printf("\n");
        /*Loop to print weather 1 row under the number dates*/
        for (wthDays = 1; wthDays <= 7; wthDays++)
        {
            if (wthDays < x)
            {
                printWeather();
            }
            else
            {
                printf("||\t \t");
            }
        }

        printf("\n||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\n");
    }
}

/*Prints random weather status*/
void printWeather()
{
    switch (rand() % 3)
    {
    case 0:
        printf("||\tSunny\t");
        break;
    case 1:
        printf("||\tRainy\t");
        break;
    case 2:
        printf("||\tCloudy\t");
        break;
    }
}
