#include <stdint.h>
#include <stdio.h>

#include "registers.h"

void config_pins(void);
void config_uart(void);
void uart_send_char(uint8_t ch);

int main(void)
{
    config_pins();
    config_uart();

    printf("Hello World\r\n");

    while(1)
    {

    }
}

/*************************************
 *         IMPLEMENTATIONS
 *************************************/

extern int __io_putchar(int ch)
{
    uart_send_char((uint8_t)ch);

    return ch;
}

void config_pins(void)
{
    // enable clock for GPIOA
    RCC_AHB1ENR |= (1 << 0);

    // set PA2 to alternate function mode
    GPIOA_MODER &= ~(3 << 4);
    GPIOA_MODER |=  (2 << 4);

    // select AF7 (USART2) on PA2
    GPIOA_AFRL &= ~(0xF << 8);
    GPIOA_AFRL |=  (7   << 8);
}

void config_uart(void)
{
    // enable clock for USART2
    RCC_APB1ENR |= (1 << 17);

    // baud rate 115200 with APB1 at 16 MHz (HSI, reset default)
    USART2_BRR = (8 << 4) | 11;

    // enable transmitter
    USART2_CR1 |= (1 << 3);

    // enable the USART
    USART2_CR1 |= (1 << 13);
}

void uart_send_char(uint8_t ch)
{
    // wait until the data register is empty
    while(!(USART2_SR & (1 << 7)));
    USART2_DR = ch;
}