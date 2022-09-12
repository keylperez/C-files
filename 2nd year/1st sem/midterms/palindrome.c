#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
/*
Function isSet(). The function accepts an array of integers and its size as parameters. 
It will return one (1) if the given array of integers is a set; or zero (0) if it is not a set.
A collection is identified as a set if all of its elements are UNIQUE. (9 points)

Function getEvenNumbers(). The function accepts an array of integers and its size as parameters. 
This function will copy all the even numbers from the given array and place them in another array which will be returned to the calling function. (9 points)

Function isPalindrome(). The function which accepts a string as its parameter. 
This function will return one (1) if the given string is a palindrome; or, zero (0) if it is not a palindrome. 
A string is considered a palindrome if the order of the characters are the same even if it is read backwards. 
Restriction: The only string function that can be used is the strlen() function. All other string functions should not be used. 
ctype Functions can be used. Space is not considered in the comparison. The phrases “race car”, “Sir Kris” and “Do g eese se e G od” are palindromes. (12 points)
*/

int isSet(int arr[], int size);
int *getEvenNumber(int arr[], int size);
int isPalindrome(char string[]);

int main(){
	int arr[] = {1, 6, 9, 3, 5, 10, 4};
	char palin[] = "Do g eese se e G od";
	char sentence[100];
	int arrsize = sizeof(arr)/sizeof(int);
	int set, palindrome, i;
	int *evenArr;
	
	set = isSet(arr, arrsize);
	evenArr = getEvenNumber(arr, arrsize);
	palindrome = isPalindrome(palin);
	
	sprintf(sentence, "isSet value: %d\n", set);
	puts(sentence);
	
//	printf("some size: %d", sizeof(evenArr)/sizeof(int));
	printf("Even number array: ");
	for(i = 0; i < (sizeof(evenArr)/sizeof(int));i ++){
		printf("%d, ", *(evenArr + i));
	}
	
	sprintf(sentence, "\nPalindrome value: %d", palindrome);
	puts(sentence);
	
	free(evenArr);
	return 0;
}

int isSet(int arr[], int size){
	int i, x;
	for(i = 0; i < (size-1); i++){
		for(x = i + 1; x < size; x++){
			if(arr[i] == arr[x]) return 0;
		}
	}
	return 1;
}

int *getEvenNumber(int arr[], int size){
	int buffer[size];
//	printf("somesize: %d", sizeof(buffer)/4);
	int i, x;
	for(i = 0, x= 0; i < size; i++){
		if(arr[i]%2 == 0){
			memcpy(buffer + x, arr + i, 1);
			x++;
		}
	}
	
	printf("somesize: %d", sizeof(buffer)/4);
	int *retVal = (int *)malloc(sizeof(buffer)/sizeof(int));
	memcpy(retVal, buffer, sizeof(buffer)/sizeof(int));
	return retVal;
	
}

int isPalindrome(char string[]){
	int i, size;
	size = strlen(string);
	for(i=0;i < size ;i++){
		if(string[i] == ' '){
			memmove(string + i, string + (i + 1), size - i );
		}
	}
//	printf("%s", string);
	size = strlen(string);
	for(i=0;i < size ;i++){
		char arg1 = tolower(string[i]);
		char arg2 = tolower(string[size-i-1]);
//		printf("arg1: %c, arg2: %c", arg1, arg2);
        if(arg1 != arg2){
            return 0;
        }
    }
    return 1;
}


