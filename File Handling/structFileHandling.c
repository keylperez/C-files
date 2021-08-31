#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct studentList
{
    char studentName[40];
    int studentId;
    int studentAge;
    int gradeLevel;
    char studentSex;
    char classSection;
} studentInfo;

typedef struct linkedList
{
    studentInfo sList;
    struct linked_list *next;
} node;
node *head = NULL, *last = NULL;

FILE *fptr;
int mainAction();
void addStudent();
void deleteStudent();
void studentListMain();
void insertLast();
void clr()
{
    system("cls");
}

int main()
{
    int i = 0, choice, size = 0;
    do
    {
        choice = mainAction();
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            studentListMain();
            printf("\n\n\tPress enter to continue...");
            getch();
            clr();
            break;
        case 4:
            i = 1;
            break;
        default:
            clr();
            printf("\n\tPlease input the correct option...\n\n");
            break;
        }
    } while (i == 0);
    fclose(fptr);
    return 0;
}

int mainAction()
{
    int mainInput = 0;
    printf(""
           "\n\tGood day! What do you want to do?\n\n"
           "\t1 - add student\n"
           "\t2 - delete student\n"
           "\t3 - print student list\n"
           "\t4 - exit program\n"
           "\n\tInput here: ");
    scanf("%d", &mainInput);
    // fflush(stdin);
    return mainInput;
}

void addStudent()
{
    int val, count = 0;
    printf("\n\n\tHow many students will you add? ");
    scanf("%d", &val);
    while (count < val)
    {
        insertLast();
        count++;
    }

    printf("\n\n\tSUCESS! STUDENT(s) ADDED TO LIST. Press enter to continue...");
    getch();
    clr();
}

void insertLast()
{
    char name[40], sex, section;
    int id, age, level;
    printf("\n\n\tInput student name: \t");
    scanf("%s", &name);
    printf("\n\tInput student id: \t");
    scanf("%d", &id);
    printf("\n\tInput student age: \t");
    scanf("%d", &age);
    printf("\n\tInput student sex(M/F): ");
    sex = getche();
    printf("\n\n\tInput student level: \t");
    scanf("%d", &level);
    printf("\n\tInput student section: \t");
    section = getche();

    node *temp_node;
    temp_node = (node *)malloc(sizeof(node));

    strncpy(temp_node->sList.studentName, name, strlen(name) + 1);
    temp_node->sList.studentId = id;
    temp_node->sList.studentAge = age;
    temp_node->sList.studentSex = sex;
    temp_node->sList.gradeLevel = level;
    temp_node->sList.classSection = section;
    temp_node->next = NULL;

    if (head == NULL)
    {
        head = temp_node;
        last = temp_node;
    }
    else
    {
        last->next = temp_node;
        last = temp_node;
    }
    printf("\n\n\tStudent Added!\n");
}

void deleteStudent()
{
    printf("Delete Function");
}

void studentListMain()
{
    printf("\n\tYour full linked list is\n");

    node *myList;
    myList = head;
    int i = 0;

    while (myList != NULL)
    {
        printf("\n\t%d.\t%s\n", i, myList->sList.studentName);

        myList = myList->next;
        i++;
    }
    puts("");
}
