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
    if (VH)
    {
        printf("Success malloc");
    }
    else
    {
        return 0;
    }
    VH->start = 0;
    VH->avail = 0;

    printf("\nSuccess initialize");

    insertEl(VH, 1);
    displayArr(VH);
    insertEl(VH, 56);
    displayArr(VH);
    insertEl(VH, 3);
    displayArr(VH);
    insertEl(VH, 2);

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
    // struct node *new_node = (struct node *)malloc(sizeof(struct node));
    int i, j;
    for (i = VH->start; VH->arr[i].next != -1; i = VH->arr[i].next)
    {
    }
    VH->arr[i].next = VH->avail;
    VH->arr[VH->avail].data = num;
    VH->arr[VH->avail].next = -1;
    //    VH->arr[VH->avail] = *new_node;

    for (i = 0; VH->arr[i].data >= -1; i++)
    {
    }
    VH->avail = i;
}

void delEl(struct VHeap *VH, int num)
{
    int i;

    for (i = VH->start; VH->arr[VH->arr[i].next].data != num; i = VH->arr[i].next)
    {
    }
    int j = VH->arr[VH->arr[i].next].next; // 3
    VH->start = VH->arr[i].next;
    VH->arr[i].next = j;
}

void displayArr(struct VHeap *VH)
{
    int i;
    printf("\n\n");

    for (i = VH->start; VH->arr[i].next != -1; i = VH->arr[i].next)
    {
        printf("\ndata: %d, \nnext: %d", VH->arr[i].data, VH->arr[i].next);
    }
}

int isEmpty(struct VHeap *VH)
{
    return (VH->avail == VH->start);
}