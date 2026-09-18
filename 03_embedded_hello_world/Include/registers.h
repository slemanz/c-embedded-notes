#ifndef INC_REGISTERS_H
#define INC_REGISTERS_H

#define RCC_BASE        0x40023800
#define GPIOA_BASE      0x40020000
#define USART2_BASE     0x40004400

#define RCC_AHB1ENR     (*(volatile unsigned int *)(RCC_BASE    + 0x30))
#define RCC_APB1ENR     (*(volatile unsigned int *)(RCC_BASE    + 0x40))
#define GPIOA_MODER     (*(volatile unsigned int *)(GPIOA_BASE  + 0x00))
#define GPIOA_AFRL      (*(volatile unsigned int *)(GPIOA_BASE  + 0x20))
#define USART2_SR       (*(volatile unsigned int *)(USART2_BASE + 0x00))
#define USART2_DR       (*(volatile unsigned int *)(USART2_BASE + 0x04))
#define USART2_BRR      (*(volatile unsigned int *)(USART2_BASE + 0x08))
#define USART2_CR1      (*(volatile unsigned int *)(USART2_BASE + 0x0C))

#endif /* INC_REGISTERS_H */