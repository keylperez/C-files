#include <stdio.h>
#include <stdlib.h>

void countEvenOdd(int *Array, int size);

int main()
{
    int *ptra;
    int i, n;
    printf("Input size of array you will input: ");
    scanf("%d", &n);

    ptra = (int *)calloc(n, sizeof(int));
    if (ptra == NULL)
    {
        fprintf(stderr, "Error alocating memory!");
        exit(1);
    }

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptra[i]);
    }

    countEvenOdd(ptra, n);

    free(ptra);
    return 0;
}

void countEvenOdd(int *Array, int size)
{
    int i, even = 0, odd = 0;
    for (i = 0; i < size; i++)
    {
        if (Array[i] % 2 == 0)
        {
            even++;
        }
        if (Array[i] % 2 != 0)
        {
            odd++;
        }
    }

    printf("\n\neven:\t%d", even);
    printf("\n\nodd:\t%d", odd);
}