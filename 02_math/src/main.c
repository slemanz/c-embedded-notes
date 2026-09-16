/**********************************************************************************
*                                                                                 *
*                                       MATH                                      *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include "math.h"

int main()
{
	// only intengers values and answers!!!
	printf("MATH!\n");
	int valueA = 0x0A;
	int valueB = 2;

	printf("a = %d b = %d\n", valueA, valueB);
	printf("add: %d\n", math_add(valueA, valueB));
	printf("sub: %d\n", math_sub(valueA, valueB));
	printf("mpy: %d\n", math_mpy(valueA, valueB));
	printf("div: %d\n", math_div(valueA, valueB));
}
