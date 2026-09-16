/**********************************************************************************
*                                                                                 *
*                                    FUNCTIONS                                    *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>

// Executable statements should be inside of a function
// only initializations and definitions of variables in global scope

void function_add_numbers(int, int, int); //funtion prototype (declaration)
int return_add_numbers(int, int, int); 

int main()
{
	function_add_numbers(10,30,10);
	int valueA = 10;
	function_add_numbers(valueA,-30,10);

	int vA = 10, vB = 5, vC = 7;
	printf("%d + %d + %d = %d\n", vA, vB, vC, return_add_numbers(vA, vB, vC));


	return 0; // 0 means that the program was SUCCESS (non zero ERROR)
}

void function_add_numbers(int a, int b, int c)
{
	int sum;
	sum = a + b + c;
	printf("Sum = %d\n", sum);
}

int return_add_numbers(int a, int b, int c)
{
	return (a + b + c);
}