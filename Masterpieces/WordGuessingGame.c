#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clr(){
	system("cls");
}

void instructions(){
	printf("Word Guessing Game\n\n\n\nPress Enter to continue\n");
	getchar();clr();
	printf("Hello there player\n\nYou up for some guessing game?");
	getchar();clr();
	printf("\nOh yah?\n");
	getchar();clr();
	printf("Yea! But first let me give you the instructions\n\n");
	printf("You only have 3 lives,\nInput only a non caps letter,");
	printf("\nAnd have fun guessing!");
	getchar();clr();
}

void init(char *ptr){
	int num=0;
	for(;num<=4;num++){
		ptr[num]='*';
	}
}

void endScreen(){
	clr();
	printf("Congrats!!! You have guessed the entire word!!!\n\n");
	printf("You are so good at this... maybe you looked into the code?\n\n");
	printf("hmhmhmhmhm...\n\nWell thats fine if you knew the answer all along!\n\n");
	printf("You had fun right?");
}

void wrongEnd(char presetWord[]){
	clr();
	printf("Aww... You have lost all your lives\n\n");
	printf("The answer was %s", presetWord);
}

int final(char presetWord[], char *hiddenWord){
	int temp, correct=0;
	for(temp=0;temp<=4;temp++){
		if(presetWord[temp]==hiddenWord[temp]){
			correct++;
		}
	}
	if(correct==5)	return 1;
	else return 0;
}

int letterCheck(char presetWord[], char inputLetter, char *hiddenWord){
	int temp;
	for(temp=0;temp<=4;temp++) //go through into all the letters in the preset word
	{
		//checks if it matches with a part in the preset word
		if(presetWord[temp]==inputLetter){
			memcpy(hiddenWord+temp,presetWord+temp,1*sizeof(char));
			temp=6;
			return 1;
		}
	}
	if(temp==5){
	return 0;
	}
}




char inputCheck(){
	char letter;
	
	printf("\nInput a letter: ");
	scanf("%c", &letter);
	getchar();
	if(letter>='a' && letter<='z'){
		return letter;
	}
	else{
		printf("Incorrect input\n\n");
		return inputCheck();
	}
}


int main(){
	int lives=3, correct=1, end=0;
	char presetWord[] = {'w', 'o', 'r', 'l', 'd'};
	char *hiddenWord = (char *) malloc(5*sizeof(char));
	char inputLetter;
	
	init(hiddenWord);
	instructions();
	
	
	while(lives>0){
		
		printf("\n\nLives Remaining: %d\n\n", lives);
		printf("%s\n",hiddenWord);
		
		if(correct!=1){
		printf("Wrong!");
		lives--;
		}
		correct = 0;
		
		inputLetter=inputCheck();
		correct=letterCheck(presetWord, inputLetter, hiddenWord);
		
		
		
		end=final(presetWord, hiddenWord);
		if(end==1){
			lives=0;
		}
		clr();
	}
	if(end==1){
		endScreen();
	}
	else wrongEnd(presetWord);
	free(hiddenWord);
	return 0;
}

