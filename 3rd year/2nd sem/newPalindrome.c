#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

struct node
{
    char letter;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;

void addChar(char data);
void display_node();
void isPalindrome();

int main()
{
    struct node *start;
    start = (struct node *)malloc(sizeof(struct node));

    char input;
    int error = 1;

    printf("press enter to end...");

    printf("\nEnter letter: ");
    while (input != '\r')
    {
        fflush(stdin);
        input = getch();
        // scanf("%c", &input);
        if (isalpha(input) || isspace(input))
        {
            printf("%c", input);
            addChar(input);
        }
        else
        {
            error = 0;
            break;
        }
    }
    // printf("\nerror: %d\n", error);
    if (error)
    {
        isPalindrome();
    }
    else
    {
        printf("Invalid input");
    }

    return 0;
}

void addChar(char data)
{

    struct node *temp, *new_node;
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Out of memory"); // check sucess of malloc
    }
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Out of memory"); // check sucess of malloc
    }

    new_node->letter = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void display_node()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp = start;
    printf("\n");
    while (temp != NULL)
    {
        // printf("display_node function");
        printf("%c", temp->letter);
        temp = temp->next;
    }
}

void isPalindrome()
{
    struct node *trav, *back;
    trav = (struct node *)malloc(sizeof(struct node));
    back = (struct node *)malloc(sizeof(struct node));

    trav = start;
    back = start;

    int result = 1;

    while (back->next != NULL)
    {
        back = back->next;
    }
    while (trav->next != NULL)
    {
        if (isspace(trav->letter))
        {
            printf("\ntrav: %c", trav->letter);
            trav = trav->next;
        }
        if (isspace(back->letter))
        {
            printf("\nback: %c", back->letter);
            back = back->prev;
        }
        if (trav->letter == back->letter)
        {
            trav = trav->next;
            back = back->prev;
        }
        else
        {
            result = 0;
            break;
        }
    }

    if (result)
    {
        display_node();
        printf(" is a Paldindrome");
    }
    else
    {
        display_node();
        printf(" is not a Paldindrome");
    }
}
