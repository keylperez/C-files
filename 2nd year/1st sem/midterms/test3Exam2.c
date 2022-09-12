#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *fintMagicWord(char string[]);

int main(){
	
	return 0;
}

char *fintMagicWord(char string[]){
//	Write the code for the function findMagicWord. The function receives as parameter a string containing characters from ‘A-Z’, ‘a-z’, ‘0-9’. The function goes through the string and extracts the Magic Word. It checks the entire string for any vowel (v) + single digit prime (sdp). Whenever it finds this character pair, the next character is considered part of the magic word. Store all of these magic characters into a new string, which will be returned to the calling function.

//	Write your function only in the space provided.

 
}

void displaySouls(int arr[], int size){
	int i;
	
	printf("{");
	
	for(i = 0; i < size; i++){
		
		printf("%d ", arr[i]);
	}
	
	printf("}\n");
}
