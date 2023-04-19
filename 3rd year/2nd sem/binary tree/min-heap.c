#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 9

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} *TREE;

int insertData(TREE *head, int data);
void swap(TREE *root, TREE *node);
void displayPostOrder(TREE head, int value);

int main()
{
    TREE head = NULL;
    int arr[] = {21, 56, 45, 1, 7, 22, 36, 48, 50};
    int i;
    for (i = 0; i < SIZE; i++)
        insertData(&head, arr[i]);
    displayPostOrder(head, 0);
    free(head);
    return 0;
}

int insertData(TREE *node, int data)
{
    if (*node == NULL)
    {
        *node = (TREE)malloc(sizeof(struct node));
        (*node)->data = data;
        (*node)->left = NULL;
        (*node)->right = NULL;
        return;
    }
    if ((*node)->left == NULL)
    {

        insertData(&(*node)->left, data);
        if ((*node)->data > (*node)->left->data)
            swap(&(*node), &(*node)->left);
        return;
    }
    if ((*node)->right == NULL)
    {
        insertData(&(*node)->right, data);

        if ((*node)->data > (*node)->right->data)
            swap(&(*node), &(*node)->right);
        return;
    }
    insertData(&(*node)->left, data);
    if ((*node)->data > (*node)->left->data)
        swap(&(*node), &(*node)->left);
    return;
}

void swap(TREE *root, TREE *node)
{
    int data = (*root)->data;
    (*root)->data = (*node)->data;
    (*node)->data = data;
}

void displayPostOrder(TREE head, int value)
{
    value++;
    printf("-%d\t", value);
    if (head == NULL)
        return;
    displayPostOrder(head->left, value);
    printf("^%d/%d\t", value, head->data);
    displayPostOrder(head->right, value);
    printf("*%d/%d\t", value, head->data);
    printf("%d\n", head->data);
}

// ----------------------------------------------------------------