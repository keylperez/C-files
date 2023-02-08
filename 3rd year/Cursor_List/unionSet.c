#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100;
typedef struct node
{
    char data;
    struct node *link;
} * SET;

typedef struct
{
    SET *Node;
    int size;
} * SET_ARRAY;

SET_ARRAY unionSet(SET_ARRAY A, SET_ARRAY B);
void initSet(SET_ARRAY *setArray, char data);

int main()
{
    SET_ARRAY A, B, C;
    A = (SET_ARRAY)malloc(sizeof(SET_ARRAY));
    B = (SET_ARRAY)malloc(sizeof(SET_ARRAY));
    C = (SET_ARRAY)malloc(sizeof(SET_ARRAY));
    char setA[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char setB[5] = {'B', 'D', 'F', 'H', 'H'};
    int i;
    for (i = 0; i < 10; i++)
    {
        insertSet(A, setA[i]);
    }
    for (i = 0; i < 5; i++)
    {
        insertSet(B, setB[i]);
    }
}

void initSet(SET_ARRAY *setArray, char data)
{
    SET *temp = (SET *)malloc(sizeof(SET));
    (*temp)->data = data;
    (*temp)->link = NULL;
    if ((*setArray)->size == 0)
    {
        (*setArray)->Node[(*setArray)->size] = temp;
        (*setArray)->size++;
    }
    else
    {
        for (int i = 0; i < (*setArray)->size; i++)
        {
            if ((*setArray)->Node[i]->data == data)
            {
                return;
            }
        }
        (*setArray)->Node[(*setArray)->size] = temp;
        (*setArray)->size++;
    }
}

SET_ARRAY unionSet(SET_ARRAY A, SET_ARRAY B)
{
    SET_ARRAY C, *trav;
    C = NULL;

    trav = &C;

    // while not reached last node
    while (A != NULL && B != NULL)
    {
        *trav = (SET)malloc(sizeof(struct node));
        // check if malloc is succesfull
        if (*trav != NULL)
        {
            if (A->data < B->data)
            {
                (*trav)->data = A->data;
                A = A->link;
            }
            else
            {
                if (A->data == B->data)
                {
                    A = A->link;
                }
                (*trav)->data = B->data;
                B = B->link;
            }
            trav = &(*trav)->link;
        }
    }
    if (A == NULL && B != NULL)
    {
        A = B;
    }
    while (A != NULL)
    {
        *trav = (SET)malloc(sizeof(struct node));
        if (*trav != NULL)
        {
            (*trav)->data = A->data;
            trav = &(*trav)->link;
            A = A->link;
        }
    }
    *trav = NULL;
    return C;
}