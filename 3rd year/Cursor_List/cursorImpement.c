#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 30;

typedef struct
{
    char data[100];
    int group;
    int link;
} NodeType;

typedef struct VHnode
{
    NodeType heap[SIZE];
    int avail;
} * VHeap;

typedef struct
{
    int elemPtr;
    VHeap VH;
} cursorList;

void display(cursorList L);
void display2(cursorList *L);
void insertFirst(cursorList *L, char str[]);
void deleteFirst(cursorList *L, char str[]);

int main()
{
    cursorList L;
    L.VH = (VHeap)malloc(sizeof(struct VHnode));
    L.elemPtr = -1;
    L.VH->avail = 0;
    for (int i = 0; i < SIZE - 1; i++)
    {
        L.VH->heap[i].link = i + 1;
    }
    L.VH->heap[SIZE - 1].link = -1;
    insertFirst(&L, "Hello");
    insertFirst(&L, "World");
    insertFirst(&L, "!");
    display(L);
    display2(&L);
    return 0;
}

void display(cursorList L)
{
    int trav;
    for (trav = L.elemPtr; trave != -1; trav = L.VH->heap[trav].link)
    {
        printf("\n%s", L.VH->heap[trav].data);
    }
}

void display2(cursorList *L)
{
    int *trav;
    // trav initialize to point to the first element of the list
    // trav will point to the link field of the current node
    for (trav = &L->elemPtr; *trav != -1; trav = &L->VH->heap[*trav].link)
    {
        printf("\n%s", L->VH->heap[*trav].data);
    }
}

void insertFirst(cursorList *L, char str[])
{
    int temp;
    temp = L->VH->heap[temp].link;
    strcopy(L->VH->heap[temp].data, str);
    L->VH->heap;
    [temp].link = L->elemPtr;
    L->elemPtr = temp;
}

void deleteFirst(cursorList *L, char str[])
{
    int temp;
    temp = L->elemPtr;
    L->elemPtr = L->VH->heap[temp].link;
    L->VH->heap[temp].link = L->VH->avail;
    L->VH->avail = temp;
}

cursorList getGroup(cursorList *L, int group)
{
    cursorList new = {-1, L->VH};
    int *trav, temp;
    for (trav = &L->elemPtr; *trav != -1;)
    {
        if (L->VH->heap[*trav].group == group)
        {
            temp = *trav;
            *trav = L->VH->heap[temp].link;
            L->VH->heap[temp].link = new.elemPtr;
            new.elemPtr = temp;
        }
        else
        {
            trav = &L->VH->heap[*trav].link;
        }
    }
    return new;
}