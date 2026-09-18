/**********************************************************************************
*                                                                                 *
*                                   LOOPING                                       *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// in C we have while, for and do while loops

int main()
{
	//examples of the loops:
	// while loop
	printf("while: ");
	uint8_t contador = 0;
	while (contador < 10)
	{
		contador++;
		printf("%d ", contador);
	}
	printf("\n");
	

	// for loop
	printf("for: ");
	for(int8_t i = 0; i < 10; i++)
	{
		printf("%d ", i + 1);
	}
	printf("\n");


	// do while loop
	printf("do while: ");
	contador = 0;
	do{
		contador++;
		printf("%d ", contador);
	}while(contador < 10);
	printf("\n");

	return 0;
}
