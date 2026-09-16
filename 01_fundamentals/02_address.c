/**********************************************************************************
*                                                                                 *
*                            ADDRESS OF A VARIABLE                                *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>

void main()
{
	// & -> gives you memory location address of a variable, e.g:
	
	char c1 = 'A';
	char c2 = 'p';
	char c3 = 'p';
	char c4 = 'l';
	char c5 = 'e';
	char c6 = ':';
	char c7 = ')';

	// %p will be the format specifier for address
	printf("Address of c1 = %p\n", &c1); // also called as pointer
	printf("Address of c2 = %p\n", &c2);
	printf("Address of c3 = %p\n", &c3);
	printf("Address of c4 = %p\n", &c4);
	printf("Address of c5 = %p\n", &c5);
	printf("Address of c6 = %p\n", &c6);
	printf("Address of c7 = %p\n", &c7);

	// the address can be store into a variable
	// number vs pointer
	// use typecasting
	unsigned long long int addressOfc1 = (unsigned long long int)&c1; //convert the addres to a number
	printf("Address of c1 = %llu (in number dec)\n", addressOfc1);
	printf("Address of c1 = %llx (in number hex)\n", addressOfc1);

	
}