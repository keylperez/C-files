#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    int next;
};

struct VHeap
{
    struct node arr[100];
    int start;
    int avail;
};

void insertEl(struct VHeap *VH, int num);
void delEl(struct VHeap *VH, int num);
void displayArr(struct VHeap *VH);
int isEmpty(struct VHeap *VH);

int main()
{
    struct VHeap *VH;
    VH = (struct VHeap *)malloc(sizeof(struct VHeap));
    if (VH == NULL)
    {
        printf("failed malloc");
        return 1;
    }
    VH->start = 0;
    VH->avail = 0;

    printf("Success initialize\n");

    insertEl(VH, 1);
    insertEl(VH, 56);
    insertEl(VH, 3);
    insertEl(VH, 2);
    displayArr(VH);

    delEl(VH, 56);
    displayArr(VH);
    delEl(VH, 3);
    displayArr(VH);

    free(VH);
    return 0;
}

void insertEl(struct VHeap *VH, int num)
{
    if (isEmpty(VH))
    {
        VH->arr[0].data = num;
        VH->arr[0].next = -1;
        VH->avail = 1;
        return;
    }
    else
    {
        int i = VH->start;
        while (VH->arr[i].next != -1)
        {
            i = VH->arr[i].next;
        }
        VH->arr[i].next = VH->avail;
        VH->arr[VH->avail].data = num;
        VH->arr[VH->avail].next = -1;

        for (i = 0; VH->arr[i].next != -1; i++)
        {
        }
        VH->avail = i + 1;
    }
}

void delEl(struct VHeap *VH, int num) // num 56
{
    int i, j;

    if (num == VH->arr[VH->start].data)
    {
        VH->avail = VH->start;
        VH->start = VH->arr[VH->start].next;
    }
    else
    {

        for (i = VH->start; VH->arr[VH->arr[i].next].data != num && i != -1; i = VH->arr[i].next) //
        {
        }
        j = VH->arr[i].next; // j = 1

        VH->arr[i].next = VH->arr[j].next;
        VH->avail = j;
    }

    //    free(VH->arr[VH->arr[i].next]);
}

void displayArr(struct VHeap *VH)
{
    int i = VH->start;

    do
    {
        printf("\ndata: %d, \nnext: %d\n", VH->arr[i].data, VH->arr[i].next);
        i = VH->arr[i].next;
    } while (i != -1);
}

int isEmpty(struct VHeap *VH)
{
    return (VH->avail == VH->start);
}
