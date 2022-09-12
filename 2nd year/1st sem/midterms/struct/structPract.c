#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char fName[32];
    char mi;
    char lName[16];
} FullName;

typedef struct Student
{
    FullName name;
    char idNum[9];
    char course[5];
    int scores[4];
} Student;

char *getFullName(FullName name)
//Receives as parameter the fullname of a student. Returns a string that contains the FULL NAME of the student.
{
    char buffer[100];

    strcpy(buffer, name.fName);
    // strcpy(buffer, name.fName);
    // strcpy(buffer + strlen(name.fName), " ");
    strncat(buffer, " ", 1);
    strncat(buffer, &name.mi, 1);

    strncat(buffer, ". ", 1);
    strcat(buffer, &name.lName);

    int strn = strlen(buffer);

    char *retName = (char *)malloc(strn + 1);
    strcpy(retName, buffer);

    return retName;
}

int getSumScores(int scores[])
//Receives as parameter the scores of a student. This function returns the sum of those scores.
{
    return (scores[0] + scores[1] + scores[2] + scores[3]) / 4;
}

void displayStudent(Student stud)
//Displays all the info in the Student structure
{
    char sentence[255];
    printf("\n\n===================================================================\n");
    sprintf(sentence, "\nFullName: \t%s %c. %s", stud.name.fName, stud.name.mi, stud.name.lName);
    puts(sentence);
    sprintf(sentence, "\nID Num: \t%s", stud.idNum);
    puts(sentence);
    sprintf(sentence, "\nCourse: \t%s", stud.course);
    puts(sentence);
    sprintf(sentence, "\nScores: [%d, %d, %d, %d]", stud.scores[0], stud.scores[1], stud.scores[2], stud.scores[3]);
    puts(sentence);
}

int isPartOfClass(Student stud, char isCourse[])
//Receives as parameter and a course. It checks if the student belongs to that course. Returns 1 if true, 0 if false.
{
    int retVal = 0;
    if (strcmp(stud.course, isCourse) == 0)
    {
        retVal = 1;
    }

    return retVal;
}

void cheat(Student *stud)
//Receives as parameter a stud ptr. Changes ALL the scores of the student to 100.
{
    int i;
    for (i = 0; i < 4; i++)
    {
        stud->scores[i] = 100;
    }
}

void setVals(Student *stud)
{

    strcpy(stud->name.fName, "William Caleb");
    stud->name.mi = 'A';
    strcpy(stud->name.lName, "Perez");
    strcpy(stud->idNum, "18104944");
    strcpy(stud->course, "BSCS");
    stud->scores[0] = 95;
    stud->scores[1] = 90;
    stud->scores[2] = 93;
    stud->scores[3] = 87;
}

int main(void)
{
    Student student;

    setVals(&student);

    char *nameptr = getFullName(student.name);
    puts(nameptr);

    int score = getSumScores(student.scores);
    printf("\nAverage score: %d", score);

    displayStudent(student);

    int partClass = isPartOfClass(student, "BSCS");
    printf("\npart of class: %d", partClass);

    cheat(&student);
    displayStudent(student);

    // puts(*nameptr);
    free(nameptr);
    //Call each written function once to check if the result is correct.
    return 0;
}
