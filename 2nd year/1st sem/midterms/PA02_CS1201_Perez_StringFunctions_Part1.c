#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define STRING_SIZE 100

char *trimLead(char *str);
char *rmvBlanks(char *str);
char *formatString(char *str);

int main(void)
{
    char word[STRING_SIZE];
    char sentence[300];
    char *word2;

    puts("Enter any string:");
    gets(word); //inputs string

    system("cls"); //clears terminal
    word2 = formatString(word);
    sprintf(sentence, "Original string : %s", word);
    puts(sentence);
    sprintf(sentence, "Formatted string: %s", word2);
    puts(sentence);

    free(word2);
    return 0;
}

char *trimLead(char *str)
{

    char buffer[STRING_SIZE];
    int i, leadWhite, loopBreak = 1; //leadWhite counts the amount of leading white space

    for (i = 0, leadWhite = 0; loopBreak == 1 && str[i] == ' '; i++)
    {
    }
    strncpy(buffer, str + i, strlen(str) - i); //copies portion of string to buffer
    loopBreak = 0;                             //terminates loop

    char *retVal = (char *)malloc(strlen(buffer) + 1); //allocate memory for return
    strcpy(retVal, buffer);

    return retVal;
}

char *rmvBlanks(char *str)
{

    char buffer[STRING_SIZE];
    strcpy(buffer, str); //copy str to buffer initially for memmove
    int n = strlen(str); //gets size of string
    int i, x;

    for (i = 0; buffer[i] != '\0'; i++, x = i - 1) //Main index that goes through whole string
    {
        //for comparing index behind main index
        if (buffer[i] == ' ' && buffer[x] == ' ') //if main index and previous index are both space
        {
            memmove(buffer + x, buffer + (x + 1), n - x); //move rest of string backwards
            // strncpy(buffer + x, str + (x + 1), n - x);

            x--;
            i--;
            n--;
        }
    }

    char *retVal = (char *)malloc(strlen(buffer) + 1); //allocate memory
    strcpy(retVal, buffer);
    return retVal;
}

char *formatString(char *str)
{
    return rmvBlanks(trimLead(str));
}