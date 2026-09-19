#include <stdio.h>
#include <stdint.h>

// controling IO pin using software
// processor addressable memory regions

// PROCEDURE TO TURN ON THE LED:
// 1) identify the GPIO port(a peripheral) used to connect the LED
// 2) ifentify the GPIO pin where the LED is connected
// 3) activate the GPIO peripheral (enable the clock)
// 4) configure the GPIO pin mode as output
// 5) write to the GPIO pin

int main(void) {

	// will be used the GPIOC -> PIN 13
	// enabling the peripheral clock
	// RCC address -> 0x40023800
	// AHB1EN address -> 0x40023800 + 0x30
	// bit 2 to enable GPIOC clock
	uint32_t *RCC_AHB1ENR = (uint32_t *)(0x40023800 + 0x30); // have to typecast that is a pointer
	//*RCC_AHB1ENR = 0x04; // 0x04 == 0b0100
	*RCC_AHB1ENR = *RCC_AHB1ENR  | (1 << 2);



	// GPIOC address -> 0x40020800
	// GPIO port mode register -> 0x40020800 + 0x00
	// pin 8 -> bit 17 and 16 : value 01 to output
	uint32_t *GPIO_mode = (uint32_t *)(0x40020800 + 0x00);
	//*GPIO_mode = 0x0000 | (1 << 16);
	*GPIO_mode &= ~(1 << 27); // clear
	*GPIO_mode |= (1 << 26);  // set


	// GPIO port output data register -> 0x40020800 + 0x14
	// pin 13 ->
	uint32_t *GPIO_output = (uint32_t *)(0x40020800 + 0x14);
	*GPIO_output &= ~(1 << 13);


	for(;;);
	return 0;
}