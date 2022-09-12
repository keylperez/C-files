#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// typedef struct Item
// {
//     int data;
// } Item, *Item;

typedef struct node
{
    int data;
    struct node *next;

} node, *LL;

int main()
{
    // head contains address of head of list
    LL list;
    initLL(&list);
}
// display traverse list
// for(trav = head; trav != NULL; trav = trav->next){}

// perform insert delete sort
// for(trav = head; *trav != NULL; trav = &(*trav)->next){}

// Member
int member(LL head, int data)
{
    LL trav;
    for (trav = head; trav != NULL && trav->data != data; trav = trav->next)
    {
    }
    return trav == NULL ? 0 : 1;
}

void insertSorted(LL *head, int data)
{
    LL temp, *trav;

    for (trav = head; *trav != NULL && (*trav)->data < data; &(*trav)->next)
    {
    }
    temp = (LL)malloc(sizeof(node));
    if (temp != NULL)
    {
        temp->data = data;
        temp->next = *trav;
        temp->*trave = temp
    }
    free(temp);
}

void deleteMem(LL *head, int data)
{
    LL temp, *trav;
    for (trav = head; *trav != NULL && *trav->data != data; &(*trav)->next)
    {
    }
    if (*trav != NULL)
    {
        temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

// *trav = next = &node;
// trav  = &node;
