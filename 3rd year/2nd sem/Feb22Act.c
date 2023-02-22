#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char FName[24], MI, LName[16];
    unsigned int ID;
    char course[8];
    int yearLevel;
} studtype;

typedef struct node
{
    studtype stud;
    struct node *link;
} *LinkedList;

#define SIZE 0XFF

typedef struct
{
    studtype stud[SIZE];
    int count;
} ArrayList;

void insertArr(ArrayList *AL, char fn[24], char mn, char ln[16], unsigned int id, char course[8], int year);
void displayArr(ArrayList *AL);
void display(ArrayList *AL, LinkedList *L);
LinkedList *sortCourse(ArrayList *AL, char string[8]);

int main()
{
    ArrayList *AL = (ArrayList *)malloc(sizeof(ArrayList)); // create the arraylist implemetation
    AL->count = 0;
    insertArr(AL, "Matugas", 'A', "Matugas", 18104944, "BSCS", 3);
    insertArr(AL, "Perez", 'B', "Perez", 18104944, "BSCS", 3);
    insertArr(AL, "Izumi", 'C', "Izumi", 18104944, "BSIT", 3);
    insertArr(AL, "Labana", 'D', "Labana", 18104944, "BSBRUH", 3);
    insertArr(AL, "Guzman", 'E', "Guzman", 18104944, "BSCS", 3);
    insertArr(AL, "Leano", 'F', "Leano", 18104944, "BSCS", 3);
    insertArr(AL, "Samson", 'G', "Samson", 18104944, "nop", 3);
    insertArr(AL, "Woogie", 'I', "Woogie", 18104944, "BSCS", 3);
    displayArr(AL);
    LinkedList *L = sortCourse(AL, "BSCS");
    display(AL, &L);
    free(AL);
    return 0;
}

void insertArr(ArrayList *AL, char fn[24], char mn, char ln[16], unsigned int id, char course[8], int year) // populate array
{
    strcpy(AL->stud[AL->count].FName, fn);
    AL->stud[AL->count].MI = mn;
    strcpy(AL->stud[AL->count].LName, ln);
    AL->stud[AL->count].ID = id;
    strcpy(AL->stud[AL->count].course, course);
    AL->stud[AL->count].yearLevel = year;
    AL->count++;
}

LinkedList *sortCourse(ArrayList *AL, char string[8])
{
    LinkedList head = NULL; // create the linked list head
    LinkedList *trav;
    int i = 0;
    while (i < AL->count) // not a for loop so iteration is conditional
    {
        if (strcmp(AL->stud[i].course, string) == 0) // if current index course matches string parameter
        {

            for (trav = &head; *trav != NULL && strcmp((*trav)->stud.LName, AL->stud[i].LName) < 0; trav = &(*trav)->link) // traverse through list and stop when the next node is null or the next node's last name is greater than the current index's last name
            {
                // printf("\n%s", (*trav)->stud.LName);
            }

            LinkedList new_node = malloc(sizeof(struct node)); // create new node

            if (new_node != NULL) // check if node allocation was successful
            {
                new_node->stud = AL->stud[i];                                                     // new node's data is the current array index's data
                new_node->link = *trav;                                                           // new node's link is next node after current node
                *trav = new_node;                                                                 //
                memmove(AL->stud + i, AL->stud + (i + 1), sizeof(AL->stud[0]) * (AL->count - i)); // move the array elements after the current index to the left
                // sizeof AL->stud[0] is the size of the first element of the array which is a node so the size takes a whole node instead of 1 bit of memory
                AL->count--; // since an element has been removed, the count is decremented
                i--;         // checks current index (was i = 0 but decrement makes code more effecient)
            }
        }
        else
        {
            i++; // increment i if current index course does not match string parameter
        }
    }
    return head; // return address of first node
}

void displayArr(ArrayList *AL)
{
    int i;
    printf("Initial Array List:");
    for (i = 0; i < AL->count; i++)
    {
        printf("\n%u - %s %c. %s, %s", AL->stud[i].ID, AL->stud[i].FName, AL->stud[i].MI, AL->stud[i].LName, AL->stud[i].course);
    }
    printf("\n===============================================================");
}

void display(ArrayList *AL, LinkedList *L)
// void display(ArrayList *AL)
{
    int i;
    LinkedList trav;
    printf("\nMutated Array List:");
    for (i = 0; i < AL->count; i++)
    {
        printf("\n%u - %s %c. %s, %s", AL->stud[i].ID, AL->stud[i].FName, AL->stud[i].MI, AL->stud[i].LName, AL->stud[i].course);
    }
    printf("\n\nCourse Linked List:");
    for (trav = *L; trav != NULL; trav = trav->link)
    {
        printf("\n%u - %s %c. %s, %s", trav->stud.ID, trav->stud.FName, trav->stud.MI, trav->stud.LName, trav->stud.course);
    }
}
