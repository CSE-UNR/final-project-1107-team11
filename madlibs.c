//Authors:1007-Team #11-Kace Alejandro, Taylor Steelman, Donald Welch
//Date:12-1-2024
//Purpose: CS 135 Final Project

#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100
#define MAX_WORDS 50

//Function declarations
void loadGame(char game[][MAX_LENGTH], int *lineCount);
void userInput(char userInput[MAX_WORDS][MAX_LENGTH], int lineCount);
void replaceIndex(char game[][MAX_LENGTH], char userInput[MAX_WORDS][MAX_LENGTH], int lineCount);
void printGame(char game [][MAX_LENGTH], int lineCount);
void initialize_arr(char arr[][MAX_LENGTH], int size);
void initialize_userInput(char userInput [MAX_WORDS][MAX_LENGTH], int size);
void playGame(char game[][MAX_LENGTH], char userInput[MAX_WORDS][MAX_LENGTH]);

int main(){
	char game[MAX_WORDS][MAX_LENGTH];
	char userInput[MAX_WORDS][MAX_LENGTH];
	int lineCount;
	
	//creates the madlibs.txt file-- writing it
	FILE *file = fopen("madlib3.txt", "w"); // opens the file for writing
	
	if(file == NULL){
		printf("Error.\n");
		return 1; // Exit if not able to open file
	}
	//writes the madlib template to the file
	fprintf(file, "It was a A, cold November day. I woke up to the A smell of N roasting in the A downstairs.\n");
	fprintf(file, "I V down the stairs to see if I could help V the dinner.\n");
	
	fclose(file);	
	

	return 0;
}	

