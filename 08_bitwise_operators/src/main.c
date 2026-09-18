/**********************************************************************************
*                                                                                 *
*                          BITWISE OPERATORS                                      *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// the operators in c:
// &  = AND
// |  = OR
// << = LEFT SHIFT
// >> = RIGHT SHIFT
// ~  = NOT
// ^  = XOR

// the operation goes bit by bit

int main()
{
	int32_t a = 40, b = 20, c = 0;	
	c = ~a; // -41
	printf("%d\n", c);

	// applicability:
	// testing of bits (&)
	// setting of bits (|)
	// clearing of bits (~ and &)
	// toggling of bits (^)

	// --testing of bit example:
	// bit-masking
	int32_t number = 0;
	printf("Number is odd or even? Insert an integer: ");
	scanf("%d", &number);
	// mask 1, if AND operation is equal 1 == number odd
	(number & 1) ? printf("Number is odd.\n") : printf("Number is even.\n");


	int32_t num = 20, output;
	// --setting of bit example:

	// num | mask
	output = num | 0x08;
	printf("[input] [output]: 0x%x 0x%x\n", num, output);


	// --clearing of bit example:

	// num & ~(mask)
	output = num & ~(0xFF);
	printf("[input] [output]: 0x%x 0x%x\n", num, output);


	// --toggling of bit example:

	// num ^  mask 
	output = num ^ 0xFF;
	printf("[input] [output]: 0x%x 0x%x\n", num, output);

	return 0;
}
