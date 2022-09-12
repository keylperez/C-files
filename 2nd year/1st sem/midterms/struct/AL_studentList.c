#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define SIZE 40

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

typedef struct StudList
{
	Student classList[SIZE];
	int last;
} StudList;

/* Function will receive a full name and return a 
formatted string of the user's Full name in the format Fname Mi. Lname*/
char *getFullName(FullName name)
{
	char temp[100];
	sprintf(temp, "%s %c. %s", name.fName, name.mi, name.lName);
	char *retval = (char *)malloc(strlen(temp) + 1);
	strcpy(retval, temp);
	return retval;
}

/* Function will receive an array of scores and return the sum of those scores to the calling function.*/
int getSumScores(int scores[])
{
	int i, retval = 0;
	for (i = 0; i < 4; i++)
		retval += scores[i];
	return retval;
}

/* Function will receive a grade, and check if it's lesser than or equal to 3.0. Returns 1 if TRUE, 0 if FALSE. */
int hasPassed(float grade)
{
	int i, retval = 0;
	if (grade <= 3.0)
		retval = 1;
	return retval;
}

/* Function is given */
float calculateGrade(float totalScore)
{
	return 5 - (totalScore / 240 * 4);
}

void displayStudentList(StudList list)
{
	int i;
	for (i = 0; i < list.last; i++)
	{
		printf("ID Number: %s", list.classList[i].idNum);
		printf("\nStudent Name: %s", getFullName(list.classList[i].name));
		printf("\nCourse: %s\n\n", list.classList[i].course);
	}
}

/* Function will display the student and all relevant info. This is partially given */
void displayStudent(Student stud)
{
	int i, totScore = getSumScores(stud.scores);
	float grade = calculateGrade(totScore);
	printf("ID Number: %s", stud.idNum);
	printf("\nStudent Name: %s", getFullName(stud.name));
	printf("\nCourse: %s", stud.course);
	printf("\nTotal Score: %d/240", totScore);
	printf("\nGrade: %.1f", grade);
	printf("\nStatus: %s\n\n", (hasPassed(grade) == 1 ? "PASSED" : "FAILED"));
}

/* Function will add a new student into the END of the student list. */
void addStudent(StudList *list, Student newStud)
{
	list->classList[list->last] = newStud;
	list->last++;
}

/* Function is given */
void populateList(StudList *list)
{
	list->last = 0;
	Student stud = {{"Denise", 'E', "Morrison"}, "16104441", "BSCS", {35, 47, 26, 57}};
	Student stud2 = {{"John", 'N', "Doe"}, "18101441", "BSCS", {46, 46, 43, 50}};
	Student stud3 = {{"Alice", 'L', "Marian"}, "16101731", "BSCS", {25, 17, 18, 34}};
	Student stud4 = {{"Jake", 'K', "Valkyrie"}, "17102171", "BSIT", {43, 10, 13, 25}};
	Student stud5 = {{"Hermione", 'F', "Granada"}, "15102017", "BSIT", {23, 31, 15, 32}};
	addStudent(list, stud);
	addStudent(list, stud2);
	addStudent(list, stud3);
	addStudent(list, stud4);
	addStudent(list, stud5);
}

/* Function will go through the StudList and check if the passed idNum exists in the list. If TRUE, return 1, else 0 */
int isPartOfClass(StudList list, char idNum[])
{
	int i, retval = 0;
	for (i = 0; i < list.last && retval == 1; i++)
		if (strcmp(list.classList[i].idNum, idNum))
			retval = 1;
	return retval;
}

/* Function will go through the StudList and return the index of the HIGHEST scoring student in the list. Returns -1 for an empty list */
int getHighestScore(StudList list)
{
	int i, j, retval = -1, highest = 0;
	for (i = 0; i < list.last; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (highest < list.classList[i].scores[j])
			{
				highest = list.classList[i].scores[j];
				retval = i;
			}
		}
	}
	return retval;
}

/* Function initializes a given StudList to empty */
void initStudList(StudList *SL)
{
	SL->last = 0;
}

int main(void)
{
	StudList blockB;
	populateList(&blockB);
	displayStudentList(blockB);

	if (isPartOfClass(blockB, "14101941") == 1)
	{
		puts("Student with ID Number 14101941 is part of the class.");
	}
	else
	{
		puts("Student with ID Number 14101941 is NOT part of the class.");
	}

	printf("\n\nStudent with the highest score is:\n");
	if (getHighestScore(blockB) != -1)
	{
		displayStudent(blockB.classList[getHighestScore(blockB)]);
	}
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include <time.h>
//#define SIZE 40
//
//typedef struct
//{
//	char fName[32];
//	char mi;
//	char lName[16];
//} FullName;
//
//typedef struct Student
//{
//	FullName name;
//	char idNum[9];
//	char course[5];
//	int scores[4];
//} Student;
//
//typedef struct StudList
//{
//	Student classList[SIZE];
//	int last;
//} StudList;
//
///* Function will receive a full name and return a
//formatted string of the user's Full name in the format Fname Mi. Lname*/
//char *getFullName(FullName name);
//
///* Function will receive an array of scores and return the sum of those scores to the calling function.*/
//int getSumScores(int scores[]);
//
///* Function will receive a grade, and check if it's lesser than or equal to 3.0. Returns 1 if TRUE, 0 if FALSE. */
//int hasPassed(float grade);
//
///* Function is given */
//float calculateGrade(float totalScore);
//
///* Function will display the student and all relevant info. This is partially given */
//void displayStudent(Student stud);
//
///* Function will add a new student into the END of the student list. */
//void addStudent(StudList *list, Student newStud);
//
///* Function is given */
//void populateList(StudList *list);
//
///* Function will go through the StudList and check if the passed idNum exists in the list. If TRUE, return 1, else 0 */
//int isPartOfClass(StudList list, char idNum[]);
//
///* Function will go through the StudList and return the index of the HIGHEST scoring student in the list. Returns -1 for an empty list */
//int getHighestScore(StudList list);
//
///* Function initializes a given StudList to empty */
//void initStudList(StudList *SL);
//
///* Function will remove the student with the same idNum passed from the StudList */
//void withdrawStud(StudList *SL, char idNum[]);
//
//int main(void)
//{
//	StudList blockB;
//	populateList(&blockB);
//
//	displayStudentList(blockB);
//
//	/*
//	if(isPartOfClass(blockB, "14101941") == 1){
//		puts("Student with ID Number 14101941 is part of the class.");
//	}else{
//		puts("Student with ID Number 14101941 is NOT part of the class.");
//	}
//
//	printf("\n\nStudent with the highest score is:\n");
//	if(getHighestScore(blockB) != -1){
//		displayStudent(blockB.classList[getHighestScore(blockB)]);
//	}*/
//	return 0;
//}
//
//char *getFullName(FullName name)
//{
//	char buffer[100];
//
//	strcpy(buffer, name.fName);
//	// strcpy(buffer, name.fName);
//	// strcpy(buffer + strlen(name.fName), " ");
//	strncat(buffer, " ", 1);
//	strncat(buffer, &name.mi, 1);
//
//	strncat(buffer, ". ", 1);
//	strcat(buffer, &name.lName);
//
//	int strn = strlen(buffer);
//
//	char *retName = (char *)malloc(strn + 1);
//	strcpy(retName, buffer);
//
//	return retName;
//}
//
//int getSumScores(int scores[])
//{
//	return (scores[0] + scores[1] + scores[2] + scores[3]) / 4;
//}
//
//float calculateGrade(float totalScore)
//{
//	return 5 - (totalScore / 240 * 4);
//}
//
//int hasPassed(float grade)
//{
//	int retVal = 0;
//	if (grade <= 3.0)
//	{
//		retVal = 1;
//	}
//
//	return retVal;
//}
//
//void displayStudent(Student stud)
//{
//
//	int totScore = getSumScores(stud.scores);
//	int grade = caculateGrade(totScore);
//	printf("\n\nID Number: %s", stud.idNum);
//	printf("\nStudent Name: %s", getFullName(stud.name));
//	printf("\nCourse: %s", stud.course);
//	printf("\nTotal Score: %.0f/240", totScore);
//	printf("\nGrade: %.1f", grade);
//	printf("\nStatus: %s\n\n", (hasPassed(grade) == 1 ? "PASSED" : "FAILED"));
//}
//
//void displayStudentList(StudList students)
//{
//	int i;
//	for (i = 0; i < students.last; i++)
//	{
//		displayStudent(students.classList[i]);
//	}
//}
//
//void addStudent(StudList *list, Student newStud)
//{
//	if (list->last < SIZE - 1)
//	{
//		list->classList[list->last + 1] = newStud;
//		list->last++;
//	}
//}
//
//void populateList(StudList *list)
//{
//	Student stud = {{"Denise", 'E', "Morrison"}, "16104441", "BSCS", {35, 47, 26, 57}};
//	Student stud2 = {{"John", 'N', "Doe"}, "18101441", "BSCS", {46, 46, 43, 50}};
//	Student stud3 = {{"Alice", 'L', "Marian"}, "16101731", "BSCS", {25, 17, 18, 34}};
//	Student stud4 = {{"Jake", 'K', "Valkyrie"}, "17102171", "BSIT", {43, 10, 13, 25}};
//	Student stud5 = {{"Hermione", 'F', "Granada"}, "15102017", "BSIT", {23, 31, 15, 32}};
//
//	addStudent(list, stud);
//	addStudent(list, stud2);
//	addStudent(list, stud3);
//	addStudent(list, stud4);
//	addStudent(list, stud5);
//}
//
//int isPartOfClass(StudList list, char idNum[])
//{
//	int i;
//	int count = list.last + 1;
//	int retVal = 0;
//
//	for (i = 0; i < count && strcmp(idNum, list.classList[i].idNum) != 0; i++)
//	{
//	}
//
//	return (i < count) ? 1 : 0;
//}
//
//int getHighestScore(StudList list)
//{
//}
//
//void initStudList(StudList *SL)
//{
//	SL->last = -1;
//}
//
//void withdrawLastStud(StudList *SL)
//{
//	if (SL->last != -1)
//	{
//		SL->last--;
//	}
//}
//
//void withdrawStud(StudList *SL, char idNum[])
//{
//	int i;
//	int count = *SL.last + 1;
//	if (isPartOfClass(*SL, idNum == 1))
//	{
//		for (i = 0; i < count && strcmp(idNum, list.classList[i].idNum) != 0; i++)
//		{
//		}
//		memcpy(SL->classList+i, SL->classList+i+1, sizeof(Student)*SL->last-i));
//		SL->last--;
//	}
//}
//
//void withdrawFirstSTudent(StudList *SL)
//{
//	if (SL->last != -1)
//	{
//		memcpy(SL->classLIst, SL->classList + 1, sizeof(Student) * SL->last);
//		SL->last--;
//	}
//}
