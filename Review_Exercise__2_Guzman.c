/*Function findEven() will accept as parameters an array of positive integers and its size. 
It will find all the even numbers and put them in another array which is to be returned to 
the calling function. In addition, put negative 1 at the end of the array containing the even numbers. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *findEven(int arrA[], int sizeA);

void main()
{
    int arrA[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sizeA = sizeof(arrA);
    int *p = findEven(arrA, 10);
    int i;
    for (i = 0; i < 6; i++)
    {
        printf("%d ", p[i]);
    }
    free(p);
}

int *findEven(int arrA[], int sizeA)
{
    int x, ctr;
    int *evenArr = (int *)malloc(sizeof(int) * sizeA + 1);
    for (ctr = x = 0; x < sizeA; x++)
    {
        if (arrA[x] % 2 == 0)
        {
            evenArr[ctr] = arrA[x];
            ctr++;
        }
    }
    evenArr[ctr] = -1;
    return evenArr;
}
