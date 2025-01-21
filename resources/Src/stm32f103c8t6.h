/*
 * stm32f103c8t6.h
 *
 *  Created on: Nov 14, 2024
 *      Author: gilbes
 */

#ifndef STM32F103C8T6_H_
#define STM32F103C8T6_H_


#endif /* STM32F103C8T6_H_ */

#include <stdint.h>

//-------------------------------------------------------//
//---------------- Base Addresses -----------------------//
//-------------------------------------------------------//

#define RCC_BASE        (0x40021000U)  // RCC base address
#define GPIOA_BASE      (0x40010800U)  // GPIOA base address
#define GPIOB_BASE      (0x40010C00U)  // GPIOB base address
#define GPIOC_BASE      (0x40011000U)  // GPIOC base address
#define GPIOD_BASE      (0x40011400U)  // GPIOD base address
#define GPIOE_BASE      (0x40011800U)  // GPIOE base address
#define AFIO_BASE       (0x40010000U)  // Alternate Function I/O base address
#define USART1_BASE     (0x40013800U)  // USART1 base address
#define USART2_BASE     (0x40004400U)  // USART2 base address
#define USART3_BASE     (0x40004800U)  // USART3 base address
#define SPI1_BASE       (0x40013000U)  // SPI1 base address
#define SPI2_BASE       (0x40003800U)  // SPI2 base address
#define I2C1_BASE       (0x40005400U)  // I2C1 base address
#define I2C2_BASE       (0x40005800U)  // I2C2 base address
#define TIM1_BASE       (0x40012C00U)  // TIM1 base address
#define TIM2_BASE       (0x40000000U)  // TIM2 base address
#define TIM3_BASE       (0x40000400U)  // TIM3 base address
#define TIM4_BASE		(0x40000800U)	//TIM4 base address
#define TIM5_BASE		(0x40000C00U)	//TIM4 base address
#define NVIC_BASE       (0xE000E100U)  // Nested Vector Interrupt Controller base

#define DMA1_BASE		(0x40020000U)	//DMA1 base address

//-------------------------------------------------------//
//---------------------- DMA ----------------------------//
//-------------------------------------------------------//
typedef struct{
	volatile uint32_t ISR;
	volatile uint32_t IFCR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CNDTR1;
	volatile uint32_t CNDTR2;
	volatile uint32_t CPAR1;
	volatile uint32_t CPAR2;
	volatile uint32_t CMAR1;
	volatile uint32_t CMAR2;
	volatile uint32_t CCR3;     // Channel 3 Control Register
	volatile uint32_t CNDTR3;
    volatile uint32_t CPAR3;
    volatile uint32_t CMAR3;
    volatile uint32_t CCR4;     // Channel 4 Control Register
    volatile uint32_t CNDTR4;
    volatile uint32_t CPAR4;
    volatile uint32_t CMAR4;
    volatile uint32_t CCR5;     // Channel 5 Control Register
    volatile uint32_t CNDTR5;
    volatile uint32_t CPAR5;
    volatile uint32_t CMAR5;
    volatile uint32_t CCR6;     // Channel 6 Control Register (TIM3_CH1 Uses This!)
    volatile uint32_t CNDTR6;
    volatile uint32_t CPAR6;
    volatile uint32_t CMAR6;
    volatile uint32_t CCR7;     // Channel 7 Control Register
    volatile uint32_t CNDTR7;
    volatile uint32_t CPAR7;
    volatile uint32_t CMAR7;

}DMA1_TypeDef;

#define DMA ((DMA1_TypeDef*)DMA1_BASE)
//-------------------------------------------------------//
//--------------------- RCC -----------------------------//
//-------------------------------------------------------//

typedef struct {
    volatile uint32_t CR;       // Clock Control Register
    volatile uint32_t CFGR;     // Clock Configuration Register
    volatile uint32_t CIR;      // Clock Interrupt Register
    volatile uint32_t APB2RSTR; // APB2 Peripheral Reset Register
    volatile uint32_t APB1RSTR; // APB1 Peripheral Reset Register
    volatile uint32_t AHBENR;   // AHB Peripheral Clock Enable Register
    volatile uint32_t APB2ENR;  // APB2 Peripheral Clock Enable Register
    volatile uint32_t APB1ENR;  // APB1 Peripheral Clock Enable Register
    volatile uint32_t BDCR;     // Backup Domain Control Register
    volatile uint32_t CSR;      // Control/Status Register
} RCC_TypeDef;

#define RCC ((RCC_TypeDef*)RCC_BASE)

//-------------------------------------------------------//
//--------------------- GPIO ----------------------------//
//-------------------------------------------------------//

typedef struct {
    volatile uint32_t CRL;   // Configuration register low
    volatile uint32_t CRH;   // Configuration register high
    volatile uint32_t IDR;   // Input data register
    volatile uint32_t ODR;   // Output data register
    volatile uint32_t BSRR;  // Bit set/reset register
    volatile uint32_t BRR;   // Bit reset register
    volatile uint32_t LCKR;  // Lock register
} GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef*)GPIOE_BASE)

//-------------------------------------------------------//
//--------------------- USART ---------------------------//
//-------------------------------------------------------//

typedef struct {
    volatile uint32_t SR;    // Status register
    volatile uint32_t DR;    // Data register
    volatile uint32_t BRR;   // Baud rate register
    volatile uint32_t CR1;   // Control register 1
    volatile uint32_t CR2;   // Control register 2
    volatile uint32_t CR3;   // Control register 3
    volatile uint32_t GTPR;  // Guard time and prescaler register
} USART_TypeDef;

#define USART1 ((USART_TypeDef*)USART1_BASE)
#define USART2 ((USART_TypeDef*)USART2_BASE)
#define USART3 ((USART_TypeDef*)USART3_BASE)

//-------------------------------------------------------//
//--------------------- SPI -----------------------------//
//-------------------------------------------------------//

typedef struct {
    volatile uint32_t CR1;   // Control register 1
    volatile uint32_t CR2;   // Control register 2
    volatile uint32_t SR;    // Status register
    volatile uint32_t DR;    // Data register
    volatile uint32_t CRCPR; // CRC polynomial register
    volatile uint32_t RXCRCR;// RX CRC register
    volatile uint32_t TXCRCR;// TX CRC register
    volatile uint32_t I2SCFGR;// I2S configuration register
    volatile uint32_t I2SPR; // I2S prescaler register
} SPI_TypeDef;

#define SPI1 ((SPI_TypeDef*)SPI1_BASE)
#define SPI2 ((SPI_TypeDef*)SPI2_BASE)

//-------------------------------------------------------//
//--------------------- I2C -----------------------------//
//-------------------------------------------------------//

typedef struct {
    volatile uint32_t CR1;    // Control register 1
    volatile uint32_t CR2;    // Control register 2
    volatile uint32_t OAR1;   // Own address register 1
    volatile uint32_t OAR2;   // Own address register 2
    volatile uint32_t DR;     // Data register
    volatile uint32_t SR1;    // Status register 1
    volatile uint32_t SR2;    // Status register 2
    volatile uint32_t CCR;    // Clock control register
    volatile uint32_t TRISE;  // TRISE register
} I2C_TypeDef;

#define I2C1 ((I2C_TypeDef*)I2C1_BASE)
#define I2C2 ((I2C_TypeDef*)I2C2_BASE)

//-------------------------------------------------------//
//--------------------- TIM -----------------------------//
//-------------------------------------------------------//

typedef struct {
    volatile uint32_t CR1;    // Control register 1
    volatile uint32_t CR2;    // Control register 2
    volatile uint32_t SMCR;   // Slave mode control register
    volatile uint32_t DIER;   // DMA/Interrupt enable register
    volatile uint32_t SR;     // Status register
    volatile uint32_t EGR;    // Event generation register
    volatile uint32_t CCMR1;  // Capture/Compare mode register 1
    volatile uint32_t CCMR2;  // Capture/Compare mode register 2
    volatile uint32_t CCER;   // Capture/Compare enable register
    volatile uint32_t CNT;    // Counter
    volatile uint32_t PSC;    // Prescaler
    volatile uint32_t ARR;    // Auto-reload register
    volatile uint32_t RESERVED1;
    volatile uint32_t CCR1;   // Capture/Compare register 1
    volatile uint32_t CCR2;   // Capture/Compare register 2
    volatile uint32_t CCR3;   // Capture/Compare register 3
    volatile uint32_t CCR4;   // Capture/Compare register 4
    volatile uint32_t RESERVED2;
    volatile uint32_t DCR;    // DMA control register
    volatile uint32_t DMAR;   // DMA address for full transfer
} TIM_TypeDef;

#define TIM1 ((TIM_TypeDef*)TIM1_BASE)
#define TIM2 ((TIM_TypeDef*)TIM2_BASE)
#define TIM3 ((TIM_TypeDef*)TIM3_BASE)
#define TIM4 ((TIM_TypeDef*)TIM4_BASE)
#define TIM5 ((TIM_TypeDef*)TIM5_BASE)
#define NVIC_ISER0  *((volatile uint32_t *)0xE000E100U)  // Interrupt Set Enable Register 0
#define TIM3_IRQn 29  // IRQ number for TIM3
#define NVIC_EnableIRQ(IRQn) (NVIC_ISER0 |= (1 << (IRQn)))
#define TIM1_IRQN 27
