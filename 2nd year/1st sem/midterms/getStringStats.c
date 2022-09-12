#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Write the code for the function getStringStats.
// It will receive as parameter a string, and return an array of 3 integers.
// Each index in the integer array represents 1 string stat, as represented below:

// A[0] - Holds the number of words
// A[1] - Holds the number of vowels
// A[2] - Holds the number of consonants

// Assume that the string to be passed will only have characters that are from A-Z, a-z, and spaces.

int *getStringStats(char str[])
{
    int i;
    int size = strlen(str) + 1;
    int *retVal = (int *)malloc(sizeof(int) * 3);
    for (i = 0; str[i] != '\0' && str[i] == ' '; i++)
    {
    }
    memmove(str, str + i, size - i);
    for (i = 0; str[i] != '\0'; i++)
    {
    }
    printf("%s\n%d", str, size);
    return retVal;
}

int main()
{
    char string[] = "heres a string";
    int *stats;
    stats = getStringStats(string);
    return 0;
}