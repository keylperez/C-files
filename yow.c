#include <stdio.h>

typedef struct Student
{
    int yearLevel;
} student;

typedef struct Node
{
    student myStudent;
    struct Node *next;
} node, *Head;

void add(Head head);
void edit(Head head);
void display(Head head);

int main()
{
    node n1 = {1};
    node n2 = {2};
    node n3 = {3};

    Head head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    add(head);
    display(head);
    edit(head);
    display(head);
    return 0;
}

void add(Head head)
{
    Head temp, temp2;
    Head new;
    int test, i;
    printf("Input value of new node: ");
    scanf("%d", &(new->myStudent.yearLevel));
    new->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    printf("\n%d", temp->myStudent.yearLevel);
    // for (temp = head; temp != NULL; temp = temp->next)
    // {
    //     scanf("%d", &(temp->myStudent.yearLevel));
    // }
    getch();
}

void edit(Head head)
{
    int nodeIndex, i, new;
    Head temp;
    system("cls");
    printf("\n\nedit which node?: ");
    scanf("%d", &nodeIndex);
    nodeIndex--;
    for (i = 0, temp = head; i < nodeIndex; i++)
    {
        temp = temp->next;
    }
    printf("\nYear Level to edit: %d", temp->myStudent.yearLevel);
    printf("\nNew value: ");
    scanf("%d", &(temp->myStudent.yearLevel));
    printf("\nNew Year Level value: %d", temp->myStudent.yearLevel);
}

void display(Head head)
{
    Head temp2;

    for (temp2 = head; temp2 != NULL; temp2 = temp2->next)
    {
        printf("\n%d", temp2->myStudent.yearLevel);
    }
    getch();
}