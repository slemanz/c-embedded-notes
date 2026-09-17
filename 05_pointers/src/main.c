/**********************************************************************************
*                                                                                 *
*                              POINTERS                                           *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>

// pointer == memory location
// * defines a pointer variable declaration

int main()
{
	// example: pointer variable of type char
	char *address1 = (char *) 0x00007FFF6E3C3824;

	// in the computer (64 bits), always reserve 8 bytes for the pointer variable.

	// the pointer data type decides the behavior of the operations carried out
	// on the pointer variable (read, write, increment, decrement).

	// char* -> read yelds 1 byte of data
	// int*  -> read yelds 4 bytes of data


	// Operators:
	// * = value at Address
	// & = Address of

	// reading data from pointer:
	char data1 = 42; 
	char *address2 = &data1; // just to get a valid pointer address
	char data = *address2; // derefering a pointer
	printf("Pointer data value: %d - 0x%llX \n", data, (long long int) address2);

	// write a data in pointer
	*address2 = 72;
	printf("New data1: %d\n", data1);

	// complete example to change the initial value with pointer
	char data_example = 100;
	char *pdata_example = &data_example;
	printf("\n\nInitial data: %d\n", *pdata_example);
	*pdata_example = 65;
	printf("End data: %d\n", data_example);

	// TAKE CARE: aritmatical in pointer will depend of the typecast of the variable
	// e.g: char will add just 1 to address and short will add 2 to address!!!
	// this also called "bytes offset"

	return 0;
}
