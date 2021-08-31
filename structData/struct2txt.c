#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef struct studentList
{
    char studentName[40];
    int studentId;
    int studentAge;
    int gradeLevel;
    char studentSex;
    char classSection;
} studentInfo;

int main()
{
    FILE *fptr;
    fptr = fopen("./structData/");
}