#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
Activities: 
1. Input a number for a recursion factorial function and store the returned variables in a text file
2. Given a name and id in a Linked List, create a program to store it in a binary file
3. Create a program to sort the given matrix
matrix[][3] = {4, 2, 3, 9, 3, 4, 8, 5, 3};
4. Make a program that stores the returned fibonacci variables of the given number (8) into a dynamically allocated array
*/

// int main()
// {
//     char A[] = "no more secrets";
//     char B[] = "yes no more secrets";
//     // int size = strcpy(B, A);
//     int i = strcmp(A, B);
//     printf("%d", i);

//     return 0;
// }

int main()
{
    char word[100];
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