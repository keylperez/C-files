#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct student
{
    char studentName[40];
    int studentId;
    int studentAge;
    int gradeLevel;
    char studentSex;
    char classSection;
    int hp;
} studentWhole[100];

typedef struct student studentInfo;

int mainAction();
void addStudent(int *lastIndex);
void editStudent(int *lastIndex);
void studentListMain(int *lastIndex);
// void fighting(int *lastIndex);
void enter2Continue();
void clr()
{
    system("cls");
}

int main()
{
    int i = 0, choice, size = 0;
    int *lastIndex;
    lastIndex = &size;
    do
    {
        choice = mainAction();
        switch (choice)
        {
        case 1:
            addStudent(&size);
            break;
        case 2:
            editStudent(&size);
            break;
        case 3:
            studentListMain(&size);
            break;
        // case 4:
        //     fighting(&size);
        //     break;
        case 5:
            i = 1;
            break;
        default:
            clr();
            printf("\n\tPlease input the correct option...\n\n");
            break;
        }
    } while (i == 0);
    return 0;
}

int mainAction()
{
    int mainInput = 0;
    printf(""
           "\n\tGood day! What do you want to do?\n\n"
           "\t1 - add student\n"
           "\t2 - edit student\n"
           "\t3 - get student list\n"
           "\t4 - exit program\n"
           "\n\tInput here: ");
    scanf("%d", &mainInput);
    // fflush(stdin);
    return mainInput;
}

void addStudent(int *lastIndex)
{
    int i;
    printf("\n\n\tInput student name: \t");
    scanf("%s", &studentWhole[*lastIndex].studentName);
    // fgets(studentWhole[*lastIndex].studentName, 30, stdin);
    // for (i = 0; i < 30; i++)
    // {
    //     temp = getche();
    //     studentWhole[*lastIndex].studentName[i] = temp;
    // }
    printf("\n\tInput student id: \t");
    scanf("%d", &studentWhole[*lastIndex].studentId);
    printf("\n\tInput student age: \t");
    scanf("%d", &studentWhole[*lastIndex].studentAge);
    printf("\n\tInput student sex(M/F): ");
    studentWhole[*lastIndex].studentSex = getche();
    // scanf("%c", &studentWhole[*lastIndex].studentSex);
    printf("\n\n\tInput student level: \t");
    scanf("%d", &studentWhole[*lastIndex].gradeLevel);
    printf("\n\tInput student section: \t");
    studentWhole[*lastIndex].classSection = getche();
    // scanf("%c", &studentWhole[*lastIndex].classSection);
    studentWhole[*lastIndex].hp = 10;
    printf("\n\n\tSUCESS! STUDENT ADDED TO LIST.");
    enter2Continue();
    (*lastIndex)++;
}

void editStudent(int *lastIndex)
{
    int studentSelector, editInput;
    int i;
    studentListMain(&lastIndex);
    printf("\n\n\tWhich student would you like to edit?(input by order/index starting from 1): ");
    scanf("%d", &studentSelector);
    studentSelector -= 1;
    if (studentSelector > *lastIndex)
    {
        printf("\n\tError! Please input lower than size");
        editStudent(&lastIndex);
    }
    printf("\n"
           "\tName:\t %s"
           "\n\tID:\t %d"
           "\n\tAge:\t %d"
           "\n\tSex:\t %c"
           "\n\tLevel:\t %d"
           "\n\tSection: %c"
           "\n\tHp:\t %d"
           "",
           studentWhole[studentSelector].studentName,
           studentWhole[studentSelector].studentId,
           studentWhole[studentSelector].studentAge,
           studentWhole[studentSelector].studentSex,
           studentWhole[studentSelector].gradeLevel,
           studentWhole[studentSelector].classSection,
           studentWhole[studentSelector]
               .hp);
    printf("\n\n\tWhich field do you want to edit?\n"
           "\t1 - Student Name\n"
           "\t2 - Student ID\n"
           "\t3 - Student Age\n"
           "\t4 - Student Sex\n"
           "\t5 - Student Level\n"
           "\t6 - Student Section\n"
           "\t7 - Hp:\n"
           "\n\tInput here: ");
    scanf("%d", &editInput);
    // fflush(stdin);
    switch (editInput)
    {
    case 1:
        printf("\n\n\tInput student name: \t");
        scanf("%s", &studentWhole[studentSelector].studentName);
        // fgets(studentWhole[studentSelector].studentName, 30, stdin);
        break;
    case 2:
        printf("\n\tInput student id: \t");
        scanf("%d", &studentWhole[studentSelector].studentId);
        break;
    case 3:
        printf("\n\tInput student age: \t");
        scanf("%d", &studentWhole[studentSelector].studentAge);
        break;
    case 4:
        printf("\n\tInput student sex(M/F): \t");
        studentWhole[studentSelector].studentSex = getche();
        break;
    case 5:
        printf("\n\n\tInput student level: \t");
        scanf("%d", &studentWhole[studentSelector].gradeLevel);
        break;
    case 6:
        printf("\n\tInput student section: \t");
        studentWhole[studentSelector].classSection = getche();
        break;
    case 7:
        printf("\n\tInput student Health: \t");
        scanf("%d", &studentWhole[studentSelector].hp);
        break;
    default:
        printf("\n\tError, please input correct option");
        break;
    }
    printf("\n\n"
           "\tName:\t %s"
           "\n\tID:\t %d"
           "\n\tAge:\t %d"
           "\n\tSex:\t %c"
           "\n\tLevel:\t %d"
           "\n\tSection: %c"
           "\n\tHp: %d"
           "",
           studentWhole[studentSelector].studentName,
           studentWhole[studentSelector].studentId,
           studentWhole[studentSelector].studentAge,
           studentWhole[studentSelector].studentSex,
           studentWhole[studentSelector].gradeLevel,
           studentWhole[studentSelector].classSection,
           studentWhole[studentSelector]
               .hp);
    printf("\n\n\tSUCCESS! EDITED STUDENT.");
    enter2Continue();
}

void studentListMain(int *lastIndex)
{
    int i;
    for (i = 0; i < *lastIndex; i++)
    {
        printf("\n\t%d. Name:\t %s - %d - %d\n", i + 1, studentWhole[i].studentName, studentWhole[i].studentId, studentWhole[i].hp);
    }
    printf("\n\n\t");
    enter2Continue();
}

void enter2Continue()
{
    printf("Press enter to continue...");
    getch();
    clr();
}

// void fighting(int *lastIndex)
// {
//     int indexSelector, fighter1, fighter2;
//     studentListMain(&lastIndex);
//     printf("\n\tInput fighter 1: ");
//     // scanf("%d", &fighter1);
// }