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
    ArrayList *AL = (ArrayList *)malloc(sizeof(ArrayList));
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
    //    display(AL);
    display(AL, &L);
    free(AL);
    return 0;
}

void insertArr(ArrayList *AL, char fn[24], char mn, char ln[16], unsigned int id, char course[8], int year)
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
    LinkedList head = NULL;
    LinkedList *trav;
    int i = 0;
    while (i < AL->count)
    {
        if (strcmp(AL->stud[i].course, string) == 0)
        {

            for (trav = &head; *trav != NULL && strcmp((*trav)->stud.LName, AL->stud[i].LName) < 0; trav = &(*trav)->link)
            {
            }

            LinkedList new_node = malloc(sizeof(struct node));

            if (new_node != NULL)
            {
                new_node->stud = AL->stud[i];
                new_node->link = *trav;
                *trav = new_node;
                //                 new_node->link = (*trav)->link;
                //                 (*trav)->link = new_node;
                memmove(AL->stud + i, AL->stud + (i + 1), sizeof(AL->stud[0]) * (AL->count - i));
                AL->count--;
                i = 0;
            }
        }
        else
        {
            i++;
        }
    }
    return head;
}

void displayArr(ArrayList *AL)
{
    int i;
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
    for (i = 0; i < AL->count; i++)
    {
        printf("\n%u - %s %c. %s, %s", AL->stud[i].ID, AL->stud[i].FName, AL->stud[i].MI, AL->stud[i].LName, AL->stud[i].course);
    }
    printf("\n\n\n");
    for (trav = *L; trav != NULL; trav = trav->link)
    {
        printf("\n%u - %s %c. %s, %s", trav->stud.ID, trav->stud.FName, trav->stud.MI, trav->stud.LName, trav->stud.course);
    }
}
