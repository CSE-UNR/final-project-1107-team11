//Authors:1007-Team #11 - Kace Alejandro, Taylor Steelman, Donald Welch
//Date:12-1-2024
//Purpose: CS 135 Final Project

#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100
#define MAX_WORDS 50

//Function declarations
void loadGame(char game[][MAX_LENGTH], int *lineCount); // KACE
void userInput(char userInput[MAX_WORDS][MAX_LENGTH], int lineCount); // DON
void replaceIndex(char game[][MAX_LENGTH], char userInput[MAX_WORDS][MAX_LENGTH], int lineCount); // TAYLOR
void printGame(char game [][MAX_LENGTH], int lineCount); // KACE
void initialize_arr(char arr[][MAX_LENGTH], int size); // DON
void initialize_userInput(char userInput [MAX_WORDS][MAX_LENGTH], int size); // TAYLOR
void playGame(char game[][MAX_LENGTH], char userInput[MAX_WORDS][MAX_LENGTH]); // TAYLOR

int main() { // KACE
	char game[MAX_WORDS][MAX_LENGTH];
	int lineCount = 0;

// Create the madlibs.txt file and write the initial Mad Libs template
FILE *file = fopen("madlib2.txt", "w"); // Open the file for writing
	if (file == NULL) {
		printf("Error creating madlib2.txt.\n");
		return 0; // Exit if unable to open file
	}

// Write the Mad Libs template to the file
	fprintf(file, "Today, every student has a computer\n");
	fprintf(file, "A\n");
	fprintf(file, "enough to fit into their\n");
	fprintf(file, "N\n");
	fprintf(file, ". They can solve any math problem by simply pushing the computer's\n");
	fprintf(file, "A\n");
	fprintf(file, "buttons. Computers can add, subtract, multiply, and\n");
	fprintf(file, "V\n");
	fprintf(file, ". They can also\n");
	fprintf(file, "V\n");
	fprintf(file, "better than a human. They have a\n");
	fprintf(file, "A\n");
	fprintf(file, "screen that shows all kinds of\n");
	fprintf(file, "N\n");
	fprintf(file, "and\n");
	fprintf(file, "A\n");
	fprintf(file, "figures.\n");
	fprintf(file, "I V down the stairs to see if I could help V the dinner.\n\n");
	fclose(file);

// Load the Mad Libs game from the file
	loadGame(game, &lineCount);

// Print the game content
	printf("Loaded Mad Libs Template:\n");
	printGame(game, lineCount);

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

// Function to print the Mad Libs game template
void printGame(char game[][MAX_LENGTH], int lineCount) { // KACE
	for (int i = 0; i < lineCount; i++) {
		printf("%s", game[i]); // Print each line
	}
}

