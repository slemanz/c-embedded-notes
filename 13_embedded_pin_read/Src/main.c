#include <stdio.h>
#include <stdint.h>

// use a button (pa0) to turn on a led (pc13)

int main(void) {
	// enabling the peripheral clock to GPIOA and GPIOC
	// RCC address -> 0x40023800
	// AHB1EN address -> 0x40023800 + 0x30
	// bit 0 to enable GPIOA clock, bit 2 to enable GPIOC clock
	uint32_t *RCC_AHB1ENR = (uint32_t *)(0x40023800 + 0x30); // have to typecast that is a pointer
	*RCC_AHB1ENR = *RCC_AHB1ENR  | (1 << 0) | (1 << 2);


	// GPIOA address -> 0x40020000
	// GPIO port mode register -> 0x40020000 + 0x00
	// pin 0 -> bit 1 and 0 : value 00 to input
	uint32_t *GPIOA_mode = (uint32_t *)(0x40020000 + 0x00);
	*GPIOA_mode &= ~(3 << 0);


	// GPIOA port pull-up/pull-down register ->  0x40020000 + 0x0C
	// set pull up to pa0 -> bit 1 and 0 -> 01
	uint32_t *GPIOA_port_pull = (uint32_t *)(0x40020000 + 0x0C);
	*GPIOA_port_pull &= ~(1 << 1);
	*GPIOA_port_pull |=  (1 << 0);


	// GPIOA port input data register -> 0x40020000 + 0x10
	// bit 0 -> read-only
	uint32_t *GPIOA_input = (uint32_t *)(0x40020000 + 0x10);


	// GPIOC address -> 0x40020800
	// GPIO port mode register -> 0x40020800 + 0x00
	// pin 13 -> bit 27 and 26 : value 01 to output
	uint32_t *GPIOC_mode = (uint32_t *)(0x40020800 + 0x00);
	*GPIOC_mode &= ~(1 << 27); // clear
	*GPIOC_mode |=  (1 << 26);  // set


	// GPIOC port output data register -> 0x40020800 + 0x14
	// pin 13 -> bit 13
	uint32_t *GPIOC_output = (uint32_t *)(0x40020800 + 0x14);
	*GPIOC_output |= (1 << 13);


	while(1){

		uint8_t pinStatus = *GPIOA_input & (1<<0);
		if(!pinStatus){
			*GPIOC_output &= ~(1 << 13); // PC13 is active-low, so clear it to turn the led on
		}else{
			*GPIOC_output |= (1 << 13);
		}

	}

	return 0;
}