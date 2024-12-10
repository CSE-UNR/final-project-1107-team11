//Authors:1007-Team #11 - Kace Alejandro, Taylor Steelman, Donald Welch
//Date:12-1-2024
//Purpose: CS 135 Final Project

#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100
#define MAX_WORDS 50

//Function declarations
void loadGame(char game[][MAX_LENGTH], int *lineCount); // KACE
void userInput(char user_inputs[MAX_WORDS][MAX_LENGTH], int lineCount, char game[][MAX_LENGTH]); // DON
void replaceIndex(char game[][MAX_LENGTH], char user_inputs[MAX_WORDS][MAX_LENGTH], int lineCount); // TAYLOR
void printGame(char game [][MAX_LENGTH], int lineCount); // KACE
void initialize_arr(char arr[][MAX_LENGTH], int size); // DON
void initialize_user_inputs(char user_inputs [MAX_WORDS][MAX_LENGTH], int size); // TAYLOR
void playGame(char game[][MAX_LENGTH], char userInput[MAX_WORDS][MAX_LENGTH]); // TAYLOR

int main(){ //KACE
	char game[MAX_WORDS][MAX_LENGTH];
	char user_inputs[MAX_WORDS][MAX_LENGTH];
	int lineCount = 0;

// Load the Mad Libs game from the file
	loadGame(game, &lineCount);
	initialize_user_inputs(user_inputs, MAX_WORDS);
	playGame(game, user_inputs);
	

return 0;
}

// Function to load the Mad Libs game template into memory
void loadGame(char game[][MAX_LENGTH], int *lineCount) { // KACE
	FILE *file = fopen("madlib2.txt", "r"); // Open the file for reading
		if (file == NULL) {
			printf("Error opening madlib2.txt.\n");
			*lineCount = 0; // No lines to process
		return;
		}

int count = 0;
	while (fgets(game[count], MAX_LENGTH, file) != NULL) {
		count++; // Increment line count for each successfully read line
	if (count >= MAX_WORDS) {
		printf("Warning: Maximum number of lines exceeded.\n");
		break;
		}
	}
fclose(file);
*lineCount = count; // Update the line count
}
             

//Function to get user input for Mad Libs game
void userInput(char user_inputs[MAX_WORDS][MAX_LENGTH], int lineCount, char game[][MAX_LENGTH]){
	char placeholder;
	for(int i = 0; i < lineCount; i++){
	//Checks for placeholders and prompts the user
		for(int j = 0; game[i][j] != '\0'; j++){
			placeholder = game[i][j];
			if(placeholder == 'A' || placeholder == 'N' || placeholder == 'V'){
			   if(placeholder == 'A'){
			   	printf("Enter an adjective: ");
			   }else if(placeholder == 'N'){
			   	printf("Enter a noun: ");
			   }else if(placeholder == 'V'){
			   	printf("Enter a verb: ");
			   }
			   fgets(user_inputs[i], MAX_LENGTH, stdin);
			   for(int k = 0; k < MAX_LENGTH; k++){
			   	if(user_inputs[i][k] == '\n'){
			   	   user_inputs[i][k] = '\0';
			   	   break;
			   	   }
		   	  } 			
	   	 }
	}
   }
} 

// Function to replace placeholder
void replaceIndex(char game[][MAX_LENGTH], char user_inputs[MAX_WORDS][MAX_LENGTH], int lineCount){	
	for(int i = 0; i < lineCount; i++){
		for(int j = 0; game[i][j] != '\0'; j++){
			if(game[i][j] == 'A' || game[i][j] == 'N' || game[i][j] =='V'){
			  char *input = user_inputs[i];
			  int inputLength = 0;
			  while(input[inputLength] != '\0'){
			       inputLength++;
			  }
			  game[i][j] = '\0';
			  for(int k = 0; k < inputLength; k++){
			  	game[i][j + k] = input[k];
			  }
			  j += inputLength;
			  }	     	
			 }
			}
		}	
// Function to print the Mad Libs game template
void printGame(char game[][MAX_LENGTH], int lineCount) { // KACE
	for (int i = 0; i < lineCount; i++) {
		printf("%s ", game[i]); // Print each line
	}
}
//Function to initialize 2d Array
void initialize_arr(char arr[][MAX_LENGTH], int size){
	for(int i = 0; i < size; i++){
		arr[i][0] = '\0';// Initializes an empty string	
               }
}             
           
void initialize_user_inputs(char user_inputs [MAX_WORDS][MAX_LENGTH], int size){
	for(int i = 0; i < size; i++){
		user_inputs[i][0] = '\0';
		}
	}
void playGame(char game[][MAX_LENGTH], char user_inputs[MAX_WORDS][MAX_LENGTH]){
	int lineCount = 0;
	for(int i = 0; game[i][0] != '\0'; i++){
		lineCount++;
	}
	userInput(user_inputs, lineCount, game);
	replaceIndex(game, user_inputs, lineCount);
	printGame(game, lineCount);
}		 




