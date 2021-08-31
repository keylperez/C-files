/*
Create a C program that will allow the users to input 3 numbers. 
The numbers will then be passed to the function getLargest() to find largest element in an array and 
display it using a function displayLarge()
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void getLargest(int Array[], int size);
void displayLarge(int largeNum);

int main()
{
    int i, arr[3];
    printf("Input 3 numbers daw:\n");
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);
    }
    getLargest(arr, 3);
    return 0;
}

void getLargest(int Array[], int size)
{
    int i = 0, y, largest;
    for (y = i + 1; y < 3; y++)
    {
        if (Array[y] > Array[i])
        {
            largest = Array[y];
        }
        if (Array[i] > Array[y])
        {
            largest = Array[i];
        }
    }
    displayLarge(largest);
}

void displayLarge(int largeNum)
{
    printf("\n\nLargest number in array: %d", largeNum);
}