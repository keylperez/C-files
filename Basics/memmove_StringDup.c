#include <stdio.h>
#include <string.h>

void removeDup(char string[]);

int main()
{
	char string[] = "ASDFGHJKLAAASDFGHJKLZXCVBZXCVBNMQWERTYUI";

	puts("Before removing dups: ");
	puts(string);

	removeDup(string);

	puts("After removing dups: ");
	puts(string);

	return 0;
}

void removeDup(char string[])
{
	int n = strlen(string);
	int i, x, y;
	for (i = 0; i < n; i++)
	{
		for (x = (i + 1); x < n; x++)
		{
			if (string[i] == string[x])
			{
				memmove(string + x, string + (x + 1), n - x);
				x--;
				n--;
			}
		}
	}
}
