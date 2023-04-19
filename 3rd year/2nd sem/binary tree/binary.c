#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 7

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} *TREE;

int traverseTree(TREE *head, int data);
void isEmpty(TREE *head);
void insertData(TREE *head, int data);
void displayTree(TREE head, int value);
void displayInOrder(TREE head, int value);
void displayPreOrder(TREE head, int value);
void displayPostOrder(TREE head, int value);

int main()
{
    TREE head = NULL;
    int arr[] = {5, 7, 1, 8, 6, 2, 4};
    int i;
    displayTree(head, 0);
    for (i = 0; i < SIZE; i++)
        traverseTree(&head, arr[i]);
    displayTree(head, 0);
    free(head);
    return 0;
}

int traverseTree(TREE *node, int data)
{
    if (*node == NULL)
    {
        insertData(node, data);
        return;
    }
    if (data < (*node)->data)
        traverseTree(&(*node)->left, data);
    if (data > (*node)->data)
        traverseTree(&(*node)->right, data);
}

void insertData(TREE *node, int data)
{
    *node = (TREE)malloc(sizeof(struct node));
    (*node)->data = data;
    (*node)->left = NULL;
    (*node)->right = NULL;
}

void displayTree(TREE head, int value)
{
    if (head == NULL)
        return;
    int tempvalue = value;
    printf("\nIn Order: \n");
    displayInOrder(head, tempvalue);
    printf("\nPre Order: \n");
    tempvalue = value;
    displayPreOrder(head, tempvalue);
    printf("\nPost Order: \n");
    tempvalue = value;
    displayPostOrder(head, tempvalue);
}

void displayInOrder(TREE head, int value)
{
    value++;
    printf("-%d\t", value);
    if (head == NULL)
        return;

    displayInOrder(head->left, value);
    printf("^%d/%d\t", value, head->data);
    printf("%d\n", head->data);
    displayInOrder(head->right, value);
    printf("*%d/%d\t", value, head->data);
}

void displayPreOrder(TREE head, int value)
{
    value++;
    printf("-%d\t", value);
    if (head == NULL)
        return;
    printf("%d\n", head->data);
    displayPreOrder(head->left, value);
    printf("^%d/%d\t", value, head->data);
    displayPreOrder(head->right, value);
    printf("*%d/%d\t", value, head->data);
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

// in order = L N R
// pre-order = N L R
// post-order = L R N
