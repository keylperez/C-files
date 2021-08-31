#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// Problem 1:
// -Write the code for the function calcArrC which receives as a paramater 3 arrays:
//     arrA, arrB, arrC. The function will calculate the values of the indeces arrC and return it to the calling function.
// -The value of arrC[i] is half of the product of arrA[i] and arrB[i].
// -Before calculating for arrC, arrB must be copied from arrA using memcpy.

// Problem 2:
// Assume that the code below has been executed. Write down the values of ALL the arrays.

void checkArr(int arrA[], int arrB[], int arrC[])
{
    int i;
    printf("\nArray A:");
    for (i = 0; i < 5; i++)
    {
        printf("\t%d", arrA[i]);
    }
    printf("\nArray B:");
    for (i = 0; i < 5; i++)
    {
        printf("\t%d", arrB[i]);
    }
    printf("\nArray C:");
    for (i = 0; i < 5; i++)
    {
        printf("\t%d", arrC[i]);
    }
}

void calcArrC(int arrA[], int arrB[], int arrC[])
{
    int i;
    memcpy(arrB, arrA, sizeof(int) * 5);
    for (i = 0; i < 5; i++)
    {
        arrC[i] = (arrA[i] * arrB[i]) / 2;
    }
}

int main(void)
{
    int arrA[5] = {17, 21, 28, 14, 18};
    int arrB[5], arrC[5];
    int i;

    calcArrC(arrA, arrB, arrC);

    // recalcAllArr(arrA, arrB, arrC);
    checkArr(arrA, arrB, arrC);
    return 0;
}