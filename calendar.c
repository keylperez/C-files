#include <stdio.h>
#include <stdlib.h>

const char *weatherRandomizer();
int dayRandomizer();

struct Weather
{
    char sun[] = "Sunny";
    char cloudy[] = "Cloudy";
    char rainy[] = "Rainy";
} weatherStat[6];

int main()
{
    int d, w;
    int dayRes;
    char dailyWeath;
    for (w = 0; w < 5; w++)
    {
        firstDay = dayRandomizer();
        for (d = 0; d < 7; i++)
        {
            printf("||\t%d\t\t", );
        }
        printf("\n");
        for (d = 0; d < 7; i++)
        {
            const char *dailyWeath = weatherRandomizer();
            printf("||\t%s\t\t", weather);
        }
    }

    return 0;
}

const char *weatherRandomizer()
{
    int weatherNum = rand() % 3;
    char weather[6];
    switch (weatherNum)
    {
    case 0:
        weather = weatherStat[].sun;
        break;
    case 1:
        weather = weatherStat[].cloudy;
        break;
    case 2:
        weather = weatherStat[].rainy;
        break;

    default:
        break;
    }
    return weather;
}