//Authors:1007-Team #11-Kace Alejandro, Taylor Steelman, Donald Welch
//Date:12-1-2024
//Purpose: CS 135 Final Project

#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100
#define MAX_WORDS 50

//Function declarations
void loadGame(char game[][MAX_LENGTH], int *lineCount); //Kace
void userInput(char userInput[MAX_WORDS][MAX_LENGTH], int lineCount); //Don
void replaceIndex(char *madlib); //Me
void printGame(char game [][MAX_LENGTH], int lineCount); //Kace
void initialize_arr(char arr[][MAX_LENGTH], int size); //Don
void initialize_userInput(char userInput [MAX_WORDS][MAX_LENGTH], int size); //Me
void playGame(char game[][MAX_LENGTH], char userInput[MAX_WORDS][MAX_LENGTH]); //Me

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

void replaceIndex(char *madlib) {
    char input[100]; 
    char *placeholder = madlib; 
    char type[10]; 

    while (*placeholder) {
        if (*placeholder == 'N' || *placeholder == 'A' || *placeholder == 'V') {
        
            if (*placeholder == 'N') {
                type[0] = 'n'; type[1] = 'o'; type[2] = 'u'; type[3] = 'n'; type[4] = '\0';
            } else if (*placeholder == 'A') {
                type[0] = 'a'; type[1] = 'd'; type[2] = 'j'; type[3] = 'e'; type[4] = 'c'; 
                type[5] = 't'; type[6] = 'i'; type[7] = 'v'; type[8] = 'e'; type[9] = '\0';
            } else if (*placeholder == 'V') {
                type[0] = 'v'; type[1] = 'e'; type[2] = 'r'; type[3] = 'b'; type[4] = '\0';
            }

           
            printf("Enter a %s: ", type);
            scanf("%99s", input);

            
            int inputLength = 0;
            while (input[inputLength] != '\0') {
                inputLength++;
            }

            
            char *temp = placeholder + 1;
            int remainingLength = 0;
            while (*temp != '\0') {
                remainingLength++;
                temp++;
            }

           
            for (int i = remainingLength; i >= 0; i--) {
                placeholder[inputLength + i] = placeholder[i + 1];
            }

            // Insert the user input into the placeholder position
            for (int i = 0; i < inputLength; i++) {
                placeholder[i] = input[i];
            }

            // Advance the pointer
            placeholder += inputLength;
        } else {
            placeholder++; // Move to the next character
        }
    }
}

