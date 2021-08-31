#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calendar(int start, int end)
{

	int day = 1, x;

	for (x = start - 1; x > 0; x--)
	{
		printf("\t");
	}

	for (x = 1; x <= 6; x++)
	{	//changes the rows after the limit
		//placed 6 rows if start of day is saturday and end of month is 31
		printf("\t");
		for (; start <= 7; start++)
		{

			if (day <= end)
			{
				printf("%d-", day++);

				switch (rand() % 3)
				{ //random weather
				case 0:
					printf("S\t");
					break;
				case 1:
					printf("R\t");
					break;
				case 2:
					printf("C\t");
				}
			}
		}
		start = 1; //placed it outside the loop initilization for the start of the day
		puts("\n");
	}
}

void initPrint()
{
	printf("\tLegend:\tS - Sunny\n\t\tC - Cloudy\n\t\tR - Rainy\n\n");
	printf("\tMon\tTue\tWed\tThur\tFri\tSat\tSun\n\n\n");
}

int main()
{
	srand(time(0)); //using a time seed for actual randomizing
	int start = (rand() % 6) + 1, end = (rand() % 4) + 28;

	initPrint();
	calendar(start, end);
	return 0;
}