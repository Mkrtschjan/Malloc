/*
 * userInput.c
 * This program is designed to get a string input from a user and save it in
 * a char array then copy it to a pointer using heap memory
 *
 *  Created on: Sep 22, 2020
 *      Author: mkrtschjan using code from Dr. Liu's lecture
 *      Due: Sep 30, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LENGTH 32			//To define the maximum length of the string

int main() {
	char input[MAX_CHAR_LENGTH];	//To define the char string
	char *p;						//To define the pointer
	int counter;					//To hold the count of indices


	//To ask the user for an input
	printf("Please input a string: ");

	//To store the first 31 characters of the user input into the char array
	//counting spaces as characters too
	scanf("%31[^\n]s", input);

	//To print the input string held in the char array
	printf("%s\n",input);

	//To use for the maximum length needed for the pointer
	counter = strlen(input)/2;


	// To allocate memory in the heap for the pointer p to hold only odd indices
	// of the char array and accounting for the last \0 character
	p = (char *)malloc(sizeof(char) * (counter + 1));

	//In case allocation failed
	if (p == NULL) {
		printf("malloc() failed!\n");
		return 1;
	}

	//To copy every odd index of the char array into the pointer p
	for (int i = 0; i < strlen(input); ++i) {
		p[i] = input[i+(i+1)];
	}

	//Assigning the last index character of the pointer
	p[counter] = '\0';

	//To print every character of the pointer array
	for (int i = 0; i < strlen(p); ++i) {
		printf("%c", p[i]);
	}

	printf("\n");

	//To print the whole pointer array
	printf("%s\n", p);

	//To free the heap memory
	free(p);

	return 0;

}





