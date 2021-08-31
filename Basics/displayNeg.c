//Create a C program that will allow the user to enter 5 integers,
//find the negative numbers and display them using the function displayNeg()

#include <stdlib.h>
#include <stdio.h>

void displayNeg(int Array[], int size)
{
    int i;
    printf("\n\n");

    for (i = 0; i < size; i++)
    {
        if (Array[i] < 0)
        {
            printf("%d ", Array[i]);
        }
    }
}

int main()
{
    int n = 5;
    int arr[n];
    int i;

    printf("input 5 integers daw:\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    displayNeg(arr, n);
}