#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int key;
    char[100] value;
};

struct list
{
    struct node arr[100];
    int start;
    int avail;
};

void insertEl(struct list *l, char string[100]);
void deleteEl(struct list *l, char string[100]);
void displayArr(struct list *l);

int main()
{

    struct list *L = (struct L *)malloc(sizeof(struct list));
    if (L == NULL)
    {
        printf("failed malloc");
        return 1;
    }
    L->start = 0;
    L->avail = 0;

    printf("Success initialize\n");

    insertEl(L, 'beautiful');

    return 0;
}