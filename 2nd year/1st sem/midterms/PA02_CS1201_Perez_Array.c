// Write the code for the function retSubsetIndex.
// The function will receive as parameters 2 arrays and their respective sizes.
// The 1st array will act as a dataset to be searched,
// while the 2nd array will serve as the querying action.
// The function will check the 1st array for each element in the 2nd array.
// If the element is found, store in a 3rd array the first index where the element was found.
// If the element was not found, store a -1 instead.
// Return the 3rd array to the calling function.

// 1) Write the function prototype for function retSubsetIndex.
// 2) Write the appropriate function call, assuming the function is called in main.
//    Declare all the necessary variables to be passed to the calling function.
// 3) Write the body of the function retSubsetIndex.
// 4) Draw the execution stack.

// Example:
// A[] = {1, 2, 3, 4, 5};
// B[] = {2, 8, 3};
// C[] = {1, -1, 2};

// A[] = {31, 15, 2, 1, 15};
// B[] = {15, 33, 17, 2, 1};
// C[] = {1, -1, -1, 2, 3};

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *reSubsetIndex(int arr1[], int size1, int arr2[], int size2);

int main()
{
    int A[] = {31, 15, 2, 1, 15};
    int B[] = {15, 33, 17, 2, 1};
    int *C;
    int Asize = sizeof(A) / sizeof(int);
    int Bsize = sizeof(B) / sizeof(int);
    char arr[3] = {'A', 'B', 'C'};

    C = reSubsetIndex(A, Asize, B, Bsize);

    int x, y;
    for (x = 0; x < 3; x++)
    {
        printf("%c[]:\t[", arr[x]);

        switch (arr[x])
        {
        case 'A':
            for (y = 0; y < Asize; y++)
            {
                printf("%d", A[y]);
                y < Asize - 1 ? printf(", ") : printf("]");
            }
            break;
        case 'B':
            for (y = 0; y < Bsize; y++)
            {
                printf("%d", B[y]);
                y < Bsize - 1 ? printf(", ") : printf("]");
            }
            break;
        case 'C':
            for (y = 0; y < Bsize; y++)
            {
                printf("%d", *(C + y));
                y < Bsize - 1 ? printf(", ") : printf("]");
            }
            break;
        }
        printf("\n");
    }

    free(C);
    return 0;
}

int *reSubsetIndex(int arr1[], int size1, int arr2[], int size2)
{
    int *resultArr = (int *)malloc(sizeof(int) * size2);
    int i, x, positive;
    for (i = 0; i < size2; i++, resultArr[i] = -1)
    {
        for (x = 0; x < size1; x++)
        {
            if (arr2[i] == arr1[x])
            {
                resultArr[i] = x;
                x = size1;
            }
        }
    }

    return resultArr;
}
