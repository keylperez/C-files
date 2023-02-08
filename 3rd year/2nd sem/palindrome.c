#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char letter;
    struct node *before;
    struct node *after;
};

struct node *addChar(struct node *L, char inputChar);
int isPalindrome(struct node *l);

int main()
{
    struct node *head = NULL, *temp = NULL;

    char input;
    head = (struct node *)malloc(sizeof(struct node));
    head->letter = NULL;
    head->before = NULL;
    head->after = NULL;

    temp = head;

    printf("input 0 to end...");
    while (input != '0')
    {
        printf("\nEnter letter: ");
        input = getchar();
        // fflush(stdin);
        // scanf("%c", &input);
        if (input == '0')
        {
            break;
        }
        temp = addChar(temp, input);
    }

    int boolean = isPalindrome(head);

    if (boolean == 1)
    {
        printf("\nThe List is a Palindrome");
    }
    if (boolean == 0)
    {
        printf("\nThe List is not a Palindrome");
    }

    return 0;
}

struct node *addChar(struct node *L, char inputChar)
{
    struct node *item;
    item = (struct node *)malloc(sizeof(struct node));

    item->letter = inputChar;
    item->before = L;
    item->after = NULL;
    L->after = item;

    printf("\nLetter: %c", item->letter);

    L = L->after;

    printf("\nafterLetter: %c", item->letter);
    return L;
};

int isPalindrome(struct node *L)
{
    struct node *trav = NULL, *back = NULL;

    int result = 0;
    back = L;
    trav = head;

    char a, b;

    do
    {
        a = trav->letter;
        b = back->letter;

        if (a == b)
        {
            result = 1;
        }
        else
        {
            result = 0;
            break;
        }

        trav = trav->after;
        back = back->before;
    } while (a == b);

    printf("%c", L->letter);
    return result;
}
