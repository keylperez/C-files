#include <stdio.h>
#include <stdlib.h>

struct childData
{
    char *name;
    float height;
} children[] = {
    /*0*/ {"Caleb", 182.88},
    /*1*/ {"Jakob", 167.10},
    /*2*/ {"Hannah", 162.56},
    {"Gab", 162.13},
    {"Kyra", 165.45},
    {"Sana", 162.94},
    {"Hans", 157.80},
    {"Jastine", 157.48},
    {"Peter", 172.34},
    {"Saman", 180.34}};

typedef struct childData childdata;
//childdata = struct childData
childdata *sort_height();

childdata *sort_height()
{

    childdata *sortedHeight = malloc(sizeof(struct childData) * 10);

    int i = 0, j = 0;
    int x, y, z;

    childdata temp;
    //i for already sorted
    //x for unsorted
    //z for current unsorted
    //y for current element
    for (x = 1; x < 10; x++, i++)
    { //right-most sorted

        for (y = i, z = x, j = 0; !j; y--, z--)
        { //swapping loop

            j = 1;
            if (children[z].height < children[y].height)
            { //swapping condition
                temp = children[y];
                children[y] = children[z];
                children[z] = temp;
                j = 0;
            }

            sortedHeight[z] = children[z];
        }
    }

    return sortedHeight;
}

int main()
{
    int i;
    childdata *sorted = sort_height();

    for (i = 0; i < 10; i++)
    {
        printf("%-10s %.2f\n", sorted[i].name, sorted[i].height);
    }
    return 0;
}

/*
Write a C function named sort_height()
that receives and sorts the record of ten (10)
children in ascending order.
Do the following:
1. Height should be in centimeter (cm).
2. You may use any sorting algorithm.
3. The function should return a structure of
the sorted record of children.
4. Write a program to show the function
works.
*/
