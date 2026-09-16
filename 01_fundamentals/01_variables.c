/**********************************************************************************
*                                                                                 *
*                            DATA TYPES AND VARIABLES                             *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>

void myFun(void);
int myScore2; // Global

void main()
{
	// In C we have TWO signicant data types:
	//   |----Integer and Float

	char var_char = 'C'; // consumes 1 byte of memory always
	unsigned char var_char2; // exemple of initialization
	var_char2 = 67;

	printf("Char Format: %c \n", var_char2);
	printf("Intenger Format: %d \n", var_char2); // Could be also %u for unsigned

	// sizeof operator (compiler dependent)
	printf("\nSize of char data type: %ld\n", sizeof(char));
	printf("Size of short data type: %ld\n", sizeof(short));
	printf("Size of int data type: %ld\n", sizeof(int));
	printf("Size of long data type: %ld\n", sizeof(long));
	printf("Size of long long data type: %ld\n\n", sizeof(long long));

	// variables names will be replace by an adress when compile

	// Declaration vs Definition
	int myScore; // Definition
	// extern int myScore; // Declaration (defined in other file)

	// Scope: can be Local and Global
	myScore = 200; // Local
	printf("1- My Score: %d\n", myScore);
	myFun();

}

void myFun(void)
{
	myScore2 = 500;
	printf("2- My Score: %d\n", myScore2);

}