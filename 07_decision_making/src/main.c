/**********************************************************************************
*                                                                                 *
*                            DECISION MAKING                                      *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// executes one set of statements or other:
// 1. if statement
// 2. if-else statement
// 3. if-else-if ladder
// 4. conditional operators
// 5. switch/case statement

int main()
{
	//e.g
	float num1, num2;
	int32_t n1, n2;
	printf("Digit first number (integer): ");
	if(scanf("%f", &num1) == 0)
	{
		printf("Sorry, invalid input!\n");
		return 0;
	}

	printf("Digit second number (integer): ");
	if(scanf("%f", &num2) == 0)
	{
		printf("Sorry, invalid input!\n");
		return 0;
	}

	// store only the integer part
	n1 = num1;
	n2 = num2;

	if((n1 != num1) || (n2 != num2)) printf("Warning: only comparing the integer part.\n");

	if(n1 == n2){
		printf("The numbers are equal.\n");
	}else if(n1 > n2){
		printf("%d is the biggest.\n", n1);
	}else{
		printf("%d is the biggest.\n", n2);
	}

	// conditional operator
	// expression1 ? expression2 : expression3;
	uint8_t n1_biggest = (n1 >= n2) ? 1 : 0;
	
	
	//switch case
	switch (n1_biggest)
	{
	case 0:
		printf("Second number was equal or bigger. \n");
		break;
	default:
		printf("First number was equal or bigger. \n");
		break;
	}


	return 0;
}
