/**********************************************************************************
*                                                                                 *
*                            OPERATORS                                            *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// Is a symbol that tells the compiler to perform a certain mathematical or
// logical manipulation on the operands.

int main()
{
	// ARITHMETIC OPERATORS -> (+, -, *, / and %)
	int32_t a = 10, b = 2;
	printf("Example: %d + %d = %d\n", a, b, a+b);
	

	// PRECEDENCE OPERATOR -> determine which mathematical operation takes place
	// first -> parentheses ().
	printf("Example: %d*(%d + %d) = %d\n", a, a, b, a*(a+b));
	

	// UNARY OPERATORS -> (++ and --)
	// can be pre or post!
	int32_t c = a;
	printf("Example: %d++ = %d\n", a, ++c);
	// can be use in pointers too
	// in a 32 bits will increment for, e.g
	int32_t *pA = &a;
	int32_t *pA_inc = pA;
	printf("In pointers: %p++ = %p\n", pA, ++pA_inc);


	// RELATIONAL OPERATORS -> (==, >, <, >=, <= and !=)
	// 0 is false, and everything not equals 0 is true
	printf("Example: %d == %d is %d \n", a, b, a==b);


	// LOGICAL OPERATORS -> (&&, || and !)
	int32_t logical = 20;
	printf("Example: !%d = %d\n", logical, !logical);
	

	return 0;
}
