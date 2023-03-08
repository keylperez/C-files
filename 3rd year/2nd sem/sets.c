#include <stdio.h>
#include <stdlib.h>

void insert(int *x, int y[5]);
void show(int x);
int check(int x, int check);
int removeEl(int *x, int remove);

int main()
{
    int x = 0;
    int y[5] = {1, 2, 5, 5, 7};
    int *ptr;
    ptr = &x;
    insert(ptr, y);
    show(x);
    if (check(x, 3))
        printf("\nIn the set");
    else
        printf("\nOut of the set");

    int removed = removeEl(ptr, 2);
    show(x);
    return 0;
}

void insert(int *x, int y[5])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        *x |= 1 << y[i];
        // x = x | 1 << y[i];
    }
}

int removeEl(int *x, int remove)
{
    *x &= ~(1 << remove);
    return 0;
}

void show(int x)
{
    int i;
    printf("\nx: %d\n", x);
    for (i = 0; i < 32; i++)
    {
        if (x % 2 == 1)
            printf("1");
        // printf("%d\n", i);
        else
            printf("0");
        x = x >> 1;
    }
}

int check(int x, int check)
{

    // 0000001010011
    int i;
    for (i = 0; i < 32; i++)
    {
        if (x % 2 == 1 && check == i)
        {
            return 1;
        }
        x = x >> 1;
    }
    return 0;
}
