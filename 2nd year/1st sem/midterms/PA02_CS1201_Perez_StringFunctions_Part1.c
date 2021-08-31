#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRING_SIZE 100

// Write the code for the following functions.

// char* trimLead(char* str)
// -This function removes all the leading white spaces in the passed string and returns it to the calling function.
//  Leading white spaces are any spaces before the first non-space character in the string.
// -This function will NOT update the original string value.
// -Does not need to take into account the '\t' and '\n' characters.
// -You are encouraged to use the string functions for this.
// -The allocated memory for the return value should be EQUAL to the size of the original string minus all the leading white spaces.

// char* rmvBlanks(char* str)
// -This function removes any extra spaces in between words in the string.
// -It does not necessarily need to remove the leading white spaces, nor the trailing white spaces. The function is only concerned with spaces in between words.
// -This function will NOT update the original string value.
// -Does not need to take into account the '\t' and '\n characters.
// -You are encouraged to use the string functions for this.
// -The allocated memory for the return value should be EQUAL to the size of the original string minus all the leading white spaces.

// char* formatString(char* str)
// -This function removes all the leading white spaces and extra spaces in between words in the string.
// -You may call the previous functions for this.

// Options :
// # String functions:
// - strcpy    char*strcpy(char* dest, char* src)
//     [String copy or strcpy, is a function thatreceives 2 parameters, dest and src. It copies into destall the elements in src INCLUDINGthe ‘\0’character.]

// - strcmp    char*strcpy(char* dest, char* src)
//     [Stringcompare or strcmp, is a function that compares the string str1 with the string str2.]

// - strlen    int strlen(const char* string)
//     [String length or strlen, is a function that returns the lengthof the parameter string.]

// - strcat    char*strcat(char* dest, char* src)
//     [String concatenate orstrcat, is a function that appends to the end of the string destthe value of string src.]

// - puts      puts(string)
//     [Put string or puts is a function that basically displays a string. A newline character‘\n’is always appended to the output]

// - gets      gets(string)
//     [Getstring or gets is a function thatstores into the parameter string the string inputted by the user.]

char *trimLead(char *str)
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
    }
}

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