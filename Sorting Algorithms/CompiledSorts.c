#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int InsertionSort(int A[], int n);
int BubbleSort(int A[], int n);
int SelectionSort(int A[], int n);
void clr()
{
    system("cls");
}

int main()
{

    int a[] = {17, 14, 18, 30, 31, 5, 25, 19, 99, 97};
    int size = sizeof(a) / 4;
//    printf("%d", size);
    int i = 0, choice = NULL, moves = 0;
    printf("\n\nArray: ");
    for (i = 0; i < size; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n\n"
           "\n\t1 - Insertions algorithm"
           "\n\t2 - Bubble algorithm"
           "\n\t3 - Selection algorithm"
           "\n\t0 - exit"
           "\n\n\tChoose which sorting algorithm to use: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
    	return 0;
        exit(1);
        break;
    case 1:
        moves = InsertionSort(a, size);
        break;

    case 2:
        moves = BubbleSort(a, size);
        break;

    case 3:
        moves = SelectionSort(a, size);
        break;

    default:
        printf("\n\tError please select a valid choice");
        printf("\n\tPress any key to continue...");
        getch();
        clr();
        main();
        break;
    }
    // InsertionSort(a, size);
    printf("\nNew Array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n\tNumber of moves: %d", moves);
    getche();
    main();
}

int InsertionSort(int A[], int n)
{
    int i = 0, j = 0, count = 0;
    int x, y, z, c, temp;
    //i for already sorted
    //x for unsorted
    //z for current unsorted
    //y for current element
    for (x = 1; x < n; x++, i++)
    { //right-most sorted

        for (y = i, z = x, j = 0; !j; y--, z--)
        { //swapping loop

            j = 1;
            if (A[z] < A[y])
            { //swapping condition

                temp = A[y];
                A[y] = A[z];
                A[z] = temp;
                j = 0;
            }
        }
        
                printf("\n%d Array: ", ++count);
                for (c = 0; c < n; c++)
                {
                    printf("%d, ", A[c]);
                }
    }
    return count;
}

int BubbleSort(int A[], int n)
{
    int i, x, y, temp, count = 0;
    printf("\n");
    for (i = 0; i < n - 1; i++)//outer loop
    {

        for (x = 0; x < n - i - 1; x++)
        {
            if (A[x] > A[x + 1])
            {
                temp = A[x];
                A[x] = A[x + 1];
                A[x + 1] = temp;
            }
        }
        
                printf("\n%d Array: ", ++count);

                for (y = 0; y < n; y++)
                {
                    printf("%d, ", A[y]);
                }
    }
    return count;
}

int SelectionSort(int A[], int n)
{
    int i, x, y, c, temp, count = 0;

    for (y = 0; y < n; y++)
    {
        i = y;

        for (x = i + 1; x < n; x++)
        {

            if (A[i] > A[x])
            {
                i = x;
            }
        }
        temp = A[y];
        A[y] = A[i];
        A[i] = temp;
                printf("\n%d Array: ", ++count);

        for (c = 0; c < n; c++)
        {
            printf("%d, ", A[c]);
        }
    }
    return count;
}
