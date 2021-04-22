#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct student
{
    char studentName[40];
    int studentId;
    int studentAge;
    int gradeLevel;
    char studentSex;
    char classSection;
    struct student *next;
} studentInfo, *Head;

int mainAction();
void addStudent();
void editStudent();
void studentListMain();
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
            editStudent();
            break;
        case 3:
            studentListMain();
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

void addStudent()
{
    //    printf("\n\n\tInput student name: \t");
    //    scanf("%s", &studentWhole[*lastIndex].studentName);
    //    printf("\n\tInput student id: \t");
    //    scanf("%d", &studentWhole[*lastIndex].studentId);
    //    printf("\n\tInput student age: \t");
    //    scanf("%d", &studentWhole[*lastIndex].studentAge);
    //    printf("\n\tInput student sex(M/F): ");
    //    studentWhole[*lastIndex].studentSex = getche();
    //    // scanf("%c", &studentWhole[*lastIndex].studentSex);
    //    printf("\n\n\tInput student level: \t");
    //    scanf("%d", &studentWhole[*lastIndex].gradeLevel);
    //    printf("\n\tInput student section: \t");
    //    studentWhole[*lastIndex].classSection = getche();
    //    // scanf("%c", &studentWhole[*lastIndex].classSection);
    printf("\n\n\tSUCESS! STUDENT ADDED TO LIST. Press enter to continue...");
    (*lastIndex)++;
    getch();
    clr();
}

void editStudent(int *lastIndex)
{
    int studentSelector, editInput;
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
           "",
           studentWhole[studentSelector].studentName,
           studentWhole[studentSelector].studentId,
           studentWhole[studentSelector].studentAge,
           studentWhole[studentSelector].studentSex,
           studentWhole[studentSelector].gradeLevel,
           studentWhole[studentSelector].classSection);
    printf("\n\n\tWhich field do you want to edit?\n"
           "\t1 - Student Name\n"
           "\t2 - Student ID\n"
           "\t3 - Student Age\n"
           "\t4 - Student Sex\n"
           "\t5 - Student Level\n"
           "\t6 - Student Section\n"
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
           "",
           studentWhole[studentSelector].studentName,
           studentWhole[studentSelector].studentId,
           studentWhole[studentSelector].studentAge,
           studentWhole[studentSelector].studentSex,
           studentWhole[studentSelector].gradeLevel,
           studentWhole[studentSelector].classSection);
    printf("\n\n\tSUCCESS! EDITED STUDENT. Press enter to continue...");
    getch();
    clr();
}

void studentListMain(int *lastIndex)
{
    int i;

    for (i = 0;; i++)
    {
        studentInfo *one = (studentInfo *)malloc(sizeof(studentInfo));
        addStudent(1);
        studentInfo **head = one;
    }

    //	studentInfo *one = NULL;
    //	studentInfo *two = NULL;
    //	studentInfo *three = NULL;
    //	studentInfo *four = NULL;
    //	studentInfo *five = NULL;

    //	one = malloc(sizeof(struct student));
    //	two = malloc(sizeof(struct student));
    //	three = malloc(sizeof(struct student));
    //	four = malloc(sizeof(struct student));
    //	five = malloc(sizeof(struct student));
    //
    //	head->studentName = studentWhole[i].studentName;
    //	head->next = one;
    //	one->studentName = studentWhole[i].studentName;
    //	one->next = two;
    //	two->studentName = studentWhole[i].studentName;

    //    int i;
    //    for (i = 0; i < *lastIndex; i++)
    //    {
    //        printf("\n\t%d. Name:\t %s - %d\n", i + 1, studentWhole[i].studentName, studentWhole[i].studentId);
    //    }
    printf("\n\n\tPress enter to continue...");
    getch();
    clr();
}
