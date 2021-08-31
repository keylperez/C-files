#include <stdio.h>
#include <stdlib.h>

/*
Write a C program that will allow the user to input N integers. 
They will then be passed to the function getEvenNums() which will return all even numbers to be displayed.
*/

int *getEvenNums(int Array[], int size);

int main()
{
    int *arr;
    int n, i;

    printf("How many do you want to input? ");
    scanf("%d", &n);
    arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL)
    {
        fprintf(stderr, "Error alocating memory!");
        exit(1);
    }

    printf("okay put %d numbers cuz you want. If you put 100 that's your loss HAHHAHA", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    free(arr);
    return 0;
}

int *getEvenNums(int Arrau[], int size)
{
    int i;
}