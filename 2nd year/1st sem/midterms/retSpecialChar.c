#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STRING_SIZE 50

// Write the code for the function retSpecialChar.
// Given a string, the function will remove all the non-alphanumeric characters in the passed string (Not including spaces).
// The removed characters are then stored into a new string and returned to the calling function.

// 1) Write the function prototype for the function retSpecialChar
// 2) Write the appropriate function call, assuming the function is called in main. Declare all the necessary variables to be passed to the calling function.
// 3) Write the body of the function retSpecialChar
// 4) Draw the execution stack.

char *retSpecialChar(char *string)
{
    int i = 0, x = 0;
    char buffer[STRING_SIZE];
    int n = strlen(string);

    for (i = 0; i < n; i++)
    {
        //        printf("\nString[%d]: %c", i, string[i]);
//        int z = isalnum(string[i]);
//        printf("\nz: %d", z);
        
        if (isalnum(string[i]) == 0 && isspace(string[i]) == 0)
        {
//            printf("\nString[%d]: %s", i, string);
//            printf("\nBuffer: %s", buffer);
            // }
            // else
            // {
            strncpy(buffer + x, string + i, 1);
            memmove(string + i, string + (i + 1), n - i);
            //            puts(buffer);
            x++;
            n--;
            i--;
        }
    }

    char *retVal = (char *)malloc(strlen(buffer) + 1);
    strcpy(retVal, buffer);

    return retVal;
}

int main()
{
    char string[STRING_SIZE] = "t#1s 1s @ $tr1ng";
    char sentence[200];
    char *specialChar;
    sprintf(sentence, "Original: %s", string);
    puts(sentence);
    specialChar = retSpecialChar(string);
    sprintf(sentence, "\nString: %s", string);
    puts(sentence);
    sprintf(sentence, "\nString: %s", specialChar);
    puts(sentence);
    free(specialChar);
    return 0;
}
