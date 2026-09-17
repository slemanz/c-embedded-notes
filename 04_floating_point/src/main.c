/**********************************************************************************
*                                                                                 *
*                              FLOATING POINT                                     *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>

// only store sgnificand!
// Float - 32 bit => %f
// Double - 64 bit (double precision) => %lf

int main()
{
	float number = 45.6785421;
	printf("Number = %f\n", number);
	printf("Number = %0.9f\n", number);

	// preciser
	double number2 = 45.6785421;
	printf("Number = %f\n", number2);
	printf("Number = %0.9f\n", number2);
	printf("Number = %0.2e\n", number2);

	// storing number with scientific notation
	float chargeE = -1.60217662e-19; // will have precision lost
	printf("Charge of an electron:\n");
	printf("%f\n", chargeE);
	printf("%e\n", chargeE); // if double, can be used %le as format specifier

	return 0;
}
