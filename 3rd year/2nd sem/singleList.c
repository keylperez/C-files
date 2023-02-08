#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}

struct node *head = NULL;

int main()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
}