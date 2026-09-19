/**********************************************************************************
*                                                                                 *
*                                  VOLATILE                                       *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// volatile is a type qualifier in c used with variables to instruct the compiler
// no to invoke any optimization on the variable operation

int main()
{
	uint8_t volatile data1;
	uint8_t volatile data2; 

	data1 = 50;

	// the volatile enforce the compiler not to do any optimization on the variables
	// operations (read/write)
	data2 = data1; 
	data2 = data1; // so, this would not be optimized


	// when to use 'volatile' qualifier?
	// - there is a possibility of unexpected changes in the variable value
	// within the code or fromoutside the code (hardware)	


	// use volatile when your code is dealing with below scenarios:
	// 1- memory mapped peripheral registers (microcontroller)
	// 2- multiple tasks accessing global variables in an RTOS multithreaded application
	// 3- when a global variable is used to share data between the main code and an ISR code

	// the syntax to use volotile in the data of a pointer:
	uint32_t volatile *exampleRegister = (uint32_t*)0x40023830;
	
	// WARNING: in a empty loop (for) the variable to count should be make a volatile or the 
	// compiler should optimize the loop

	return 0;
}
