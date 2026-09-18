/**********************************************************************************
*                                                                                 *
*                                     CONST                                       *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// CONST TYPE QUALIFIER
// used to enforce read-only feature on variables

// compiler can't change a const variable direcectly
// both declaration are allowed:
const uint8_t data1 = 42;
uint8_t const data2 = 43; // but this is prefered

// WARNING: you still change the variable using its pointer for example,
// the const just a safety feature to ensure the programmer shouldn't try to
// modify the value. (but if its a global const generally wont have effect or the program 
// can crash!)

// placement of "const" variables in memory:
// are stored in ROM or FLASH (of course depends on linker script rules)
// in STM32 all GLOBAL const variables live in FLASH and flash memory is write
// protected


// 1- CONSTANT DATA
// use cases: to define mathematical constants in the program
float const pi = 3.1415;
float const radius = 4;


// 2- MODIFIABLE POINTER AND CONSTANT DATA
// the the pointer can be modificable, but the data dont
uint8_t const *pData = (uint8_t *)0xFF000040000000;

// 3- MODIFIABLE DATA AND CONSTANT POINTER
// use cases: improve the readability and guard the pointer variables
uint8_t dataTest = 20;
uint8_t *const pDataTest = (uint8_t*)&dataTest;

// 4- CONST DATA AND CONST POINTER
// use cases: read status register (SR) content from hardware
uint8_t const *const pDataExample = 0x40000000;

int main()
{
	printf("%d\n",dataTest);
	*pDataTest = 40;
	printf("%d\n",dataTest);
	return 0;
}
