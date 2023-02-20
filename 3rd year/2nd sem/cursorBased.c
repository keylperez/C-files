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

    // initialize avail and start to 0 index
    VH->start = 0;
    VH->avail = 0;

    printf("Success initialize\n");

    // pass on VH which is a pointer to the struct
    insertEl(VH, 1);
    insertEl(VH, 56);
    insertEl(VH, 3);
    insertEl(VH, 2);
    displayArr(VH);

    delEl(VH, 56);
    delEl(VH, 3);
    printf("\n\n\n");
    displayArr(VH);

    free(VH);
    return 0;
}

void insertEl(struct VHeap *VH, int num)
{
    // 1st insert
    if (isEmpty(VH))
    {
        VH->arr[0].data = num;
        VH->arr[0].next = -1;
        VH->avail = 1;
        return;
    }
    else
    {
        int i;
        // find end of list
        for (i = VH->start; VH->arr[i].next != -1; i = VH->arr[i].next)
        {
        }

        VH->arr[i].next = VH->avail; // set next of last element to avail
        VH->arr[VH->avail].data = num;
        VH->arr[VH->avail].next = -1; // set last of list

        // set avail to next index after the last element (works if avail is lower index)
        for (i = 0; VH->arr[i].next != -1; i++)
        {
        }
        VH->avail = i + 1;
    }
}

void delEl(struct VHeap *VH, int num) // num 56
{
    int i, j;
    // deletion of start element in list
    if (num == VH->arr[VH->start].data)
    {
        VH->avail = VH->start;
        VH->start = VH->arr[VH->start].next;
    }
    else
    {
        // traverses list and finds and compares num to the data of the next of current element, this is in order to edit next when data is found
        for (i = VH->start, j = VH->arr[i].next; VH->arr[j].data != num && j != -1; i = VH->arr[i].next, j = VH->arr[i].next) //
        {
        }
        // if not end of the list
        if (j != -1)
        {
            VH->arr[i].next = VH->arr[j].next; // element after deleted data is next
            if (VH->avail >= j)                // this condition is to check if avail index is after end of list or not, if not then avail remains at the lower index available.
            {

                VH->avail = j;
            }
        }
    }
}

void displayArr(struct VHeap *VH)
{
    int i = VH->start;

    do
    {
        printf("\nindex: %d \ndata: %d \nnext: %d\n", i, VH->arr[i].data, VH->arr[i].next);
        i = VH->arr[i].next;
    } while (i != -1);

    printf("\nStart: %d\nAvail: %d", VH->start, VH->avail);
}

int isEmpty(struct VHeap *VH)
{
    return (VH->avail == VH->start);
}
