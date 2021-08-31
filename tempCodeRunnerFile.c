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
    int array[5] = {1, 3, 0, 4, 2};
    int *iPtr;
    iPtr = array + 2;
    // printf("%x\n", iPtr);
    // printf("%d", *(iPtr + 1));
    printf("%d", array[*iPtr] + *(iPtr + 2));
    return 0;
}