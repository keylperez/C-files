#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void welcomeScreen();													//shows welcome screen
char startGame(int lives, char placeholder[]);							//guess screen that shows every time the player needs to input a letter
int winTest(char word[], char placeholder[], int size);					//to test if the player has won already or not
int letterTest(char letter, char word[], char placeholder[], int size); //checks if the inputed letter is correct or not
void congratulations(char word[]);										//shows congratulations screen
void gameOver(char word[]);												//shows loser scene
void clr();																//clears the screen

int main()
{
	char word[] = "programming";	//preset word
	char letter = '\0';				//varaible for inputed letter
	int lives = 3, YoN, win, i = 0; // number of lives; value determines if input letter is correct or not; value determines if user has won yet or not
	int size = sizeof(word) - 1;
	char placeholder[size]; //word hidden in asterisks
	do
	{
		placeholder[i] = '*';
		++i;
	} while (i < size);
	// printf("%d", size);
	welcomeScreen();
	do
	{				   //execute loop while lives is greater than 0
		letter = '\0'; //resets value of letter to null
					   //			printf("\nvalue of word & placholder: %s & %s", word, placeholder); //debug purposes
		clr();
		letter = startGame(lives, placeholder);
		YoN = letterTest(letter, word, placeholder, size); //return value either 1(correct) or 0(wrong)
		if (YoN == 0)
		{ //if YoN is wrong, minues 1 life, else continue
			--lives;
		}
		//			printf("\nvalue of YoN: %d\n", YoN);	//debug purposes
		win = winTest(word, placeholder, size); //return value either 1(wint) or 0(not yet)
		if (win == 1)
		{ //if user has won, go to congratulations screen
			congratulations(word);
		}
	} while (lives > 0); //if lives is equal to 0, gameover
	gameOver(word);
}

void welcomeScreen()
{
	printf("\n"
		   "\t===================================================================\n"
		   "\t||                                                               ||\n"
		   "\t||                                                               ||\n"
		   "\t||              Welcome Player to the GUESSING GAME!             ||\n"
		   "\t||                                                               ||\n"
		   "\t||                         How to play:                          ||\n"
		   "\t||                                                               ||\n"
		   "\t||      Just like Hangman, guess the word before running out     ||\n"
		   "\t||      of your 3 lives to win. The quantity of letters will     ||\n"
		   "\t||      be displayed and you have to guess the word starting     ||\n"
		   "\t||      with letters one by one. You lose a life if inputed      ||\n"
		   "\t||      letter is not part of the word.                          ||\n"
		   "\t||                                                               ||\n"
		   "\t||                           Have Fun!                           ||\n"
		   "\t||                                                               ||\n"
		   "\t===================================================================\n");

	printf("\n\n\n\n\tPress any key to continue...");
	getch(); //lets user input any key to continue
}

char startGame(int lives, char placeholder[])
{
	char letter; //inputed letter
	int x;
	printf("\n\n"
		   "\t===================================================================\n"
		   "\t||                                                               ||\n"
		   "\t||                         Lives:  %d                             ||\n"
		   "\t||                                                               ||\n"
		   "\t||                   GUESS THE WORD BELOW:                       ||\n"
		   "\t||                                                               ||\n"
		   "\t||                        %s                            ||\n"
		   "\t||                                                               ||\n"
		   "\t||                           Hint:                               ||\n"
		   "\t||                                                               ||\n"
		   "\t||                      It's what we do                          ||\n"
		   "\t||                                                               ||\n"
		   "\t===================================================================\n",
		   lives, placeholder //displayes actual number of lives and actual letters guessed
	);
	//	printf("\nValue of character: %c", letter);
	printf("\n\n\tInput a letter: ");
	do
	{ //tests if input is small capital letter
		letter = getche();
		if (letter >= 'a' && letter <= 'z')
		{
			x++;
		}
		else
		{
			printf("\n\tPlease input small capital letters only: ");
		}
	} while (x == 0);
	return letter; //returns value of leltter to main
}

int letterTest(char letter, char word[], char placeholder[], int size)
{ //replaces the correct inputed letter to placeholder array
	int i = 0, y = 0;
	do
	{
		if (word[i] == letter)
		{													 //checks if inputed letter matches any element if arrat
															 //			printf("\narray index: %d", i);	//debug purposes
			memcpy(placeholder + i, word + i, sizeof(char)); //copies elements from word array to placeholder array
			y = 1;
		}
		i++;
	} while (i < size);
	//	printf("\n value of y: %d", y);	//debug purposes
	return y; //returns either 1 or 0 depending on user input of letter
}

void clr()
{
	system("cls");
}

int winTest(char word[], char placeholder[], int size)
{ //tests if user has guessed all the letters/elements of array
	int i, correct = 0;
	for (i = 0; i < size; i++)
	{
		if (word[i] == placeholder[i])
		{ //checks every element of both arrays
			//			printf("%d", correct);	//debug purposes
			correct++;
		}
	}
	//	printf("\n%d", correct);	//debug purposes
	if (correct == size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void congratulations(char word[])
{
	clr();
	printf("\n"
		   "\t===================================================================\n"
		   "\t||                                                               ||\n"
		   "\t||                                                               ||\n"
		   "\t||               Congratualtions! You guess the word:            ||\n"
		   "\t||                                                               ||\n"
		   "\t||                         %s                           ||\n"
		   "\t||                                                               ||\n"
		   "\t||              Good job and for that you get nothing            ||\n"
		   "\t||                             hehe                              ||\n"
		   "\t||                                                               ||\n"
		   "\t||                                                               ||\n"
		   "\t===================================================================\n",
		   word);
	exit(1);
}
void gameOver(char word[])
{
	clr();
	printf("\n"
		   "\t===================================================================\n"
		   "\t||                                                               ||\n"
		   "\t||                                                               ||\n"
		   "\t||            Sorry! You weren't able to guess the word:         ||\n"
		   "\t||                                                               ||\n"
		   "\t||                         %s                           ||\n"
		   "\t||                                                               ||\n"
		   "\t||              Good job and for that you get nothing            ||\n"
		   "\t||                             hehe                              ||\n"
		   "\t||                                                               ||\n"
		   "\t||                                                               ||\n"
		   "\t===================================================================\n",
		   word);
	exit(1);
}
