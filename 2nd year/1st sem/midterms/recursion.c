#include <stdio.h>
#include <stdlib.h>

int annoyingRecursion(int num)
{
    if (num >= 1)
    {
        return num * annoyingRecursion(num - 1);
    }
    if (num < 1)
    {
        return 1;
    }
}

int main()
{
    int theNum, returned;
    printf("Give me num: ");
    scanf("%d", &theNum);
    returned = annoyingRecursion(theNum);
    printf("\nThe return: %d", returned);
    return 0;
}