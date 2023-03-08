#include <stdio.h>
#include <stdlib.h>

void insert(int *set, int y[5]);
void show(int set);
int check(int set, int check);
int removeEl(int *set, int remove);
int intersection(int *set, int *set2);
int unionSet(int *set, int *set2);

int main()
{
    int x = 0, x2 = 0;
    int y[5] = {1, 2, 5, 5, 7};
    int z[5] = {0, 1, 7, 8, 10};
    int *ptr, *ptr2;
    ptr = &x;
    ptr2 = &x2;
    insert(ptr, y);
    show(x);
    if (check(x, 3))
        printf("\nIn the set");
    else
        printf("\nOut of the set");
    if (check(x, 5))
        printf("\nIn the set");
    else
        printf("\nOut of the set");

    int removed = removeEl(ptr, 2);
    show(x);
    insert(ptr2, z);
    show(x2);
    int intersected = intersection(ptr, ptr2);
    show(intersected);
    int unioned = unionSet(ptr, ptr2);
    show(unioned);
    return 0;
}

void insert(int *set, int y[5])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        *set |= 1 << y[i];
        // set = set | 1 << y[i];
    }
}

int removeEl(int *set, int remove)
{
    // 00000100
    // 11111011
    // 10100110
    // 10100010
    *set &= ~(1 << remove);
    return 0;
}

int intersection(int *set, int *set2)
{
    return *set & *set2;
}

int unionSet(int *set, int *set2)
{
    return *set | *set2;
}

void show(int set)
{
    int i;
    printf("\nset: %d\n", set);
    for (i = 0; i < 32; i++)
    {
        if (set % 2 == 1)
            // printf("1");
            printf("%d\n", i);
        // else
        // printf("0");
        set = set >> 1;
    }
}

int check(int set, int check)
{

    // 0000001010011
    int i;
    for (i = 0; i < 32; i++)
    {
        if (set % 2 == 1 && check == i)
        {
            return 1;
        }
        set = set >> 1;
    }
    return 0;
}
