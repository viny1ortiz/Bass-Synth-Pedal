/*
 * bassSynthetizerCode.c
 *
 *  Created on: Nov 14, 2024
 *      Author: Gilberto Guerrero Carrillo
 *      		Vinicius Ortiz Ourcilleon
*/
#include <stdint.h>
#include "stm32f103c8t6.h"


volatile uint16_t frequency = 0;  // Measured frequency
volatile uint32_t value1 = 0, value2 = 0;
#define FILTER_SIZE 8
volatile uint16_t frequency_buffer[FILTER_SIZE] = {0};
volatile uint8_t index = 0;
volatile uint16_t avg_frequency = 0;
// Initialize GPIO for Input Capture (TIM3 on PA6)
void GPIO_Init_Input() {
    RCC->APB2ENR |= (1 << 2);  // Enable GPIOA clock
    GPIOA->CRL &= ~(0xF << 24);  // Clear PA6 configuration
    GPIOA->CRL |= (0x4 << 24);   // PA6 as input floating
}

// Initialize TIM3 for Input Capture on PA6
void TIM3_InputCapture_Init() {
    RCC->APB1ENR |= (1 << 1);  // Enable TIM3 clock

    TIM3->PSC = 10 - 1;  //  8MHz/9 timer clock
    TIM3->ARR = 0xFFFF;  // Max auto-reload value
    TIM3->CCMR1 |= (1 << 0);  // Capture input on TI1 (CC1S = 01)
    TIM3->CCER |= (1 << 0);   // Enable capture on CH1
    TIM3->DIER |= (1 << 1);   // Enable CC1 interrupt
    TIM3->CR1 |= (1 << 0);    // Enable TIM3 counter

    NVIC_EnableIRQ(TIM3_IRQn);  // Enable TIM3 interrupt
}

// Initialize GPIO for PWM Outputs
void GPIO_Init_Output() {
    RCC->APB2ENR |= (1 << 2);  // Enable GPIOA clock
    GPIOA->CRL &= ~(0xFF << 0);  // Clear PA0 and PA1 configuration
    GPIOA->CRL |= (0xB << 0);//   // PA0 and  as alternate function push-pull

    RCC->APB2ENR |= (1 << 3);	//Enable GPIOB clock
    GPIOB->CRL &= ~(0xF << 24);  // Clear PB6 configuration
    GPIOB->CRL |= (0xB << 24);   // Set PB6 to AF push-pull, 50 MHz output
}

// Initialize TIM2 for 2x Frequency PWM (PA0)
void TIM2_PWM_Init() {
    RCC->APB1ENR |= (1 << 0);  // Enable TIM2 clock
    TIM2->PSC =10 - 1;  // 8MHz/9 timer clock
    TIM2->ARR = 800 - 1;  // Default frequency
    TIM2->CCR1 = 400;  // 50% duty cycle

    TIM2->CCMR1 |= (6 << 4);  // PWM mode 1 on CH1
    TIM2->CCER |= (1 << 0);   // Enable CH1 output
    TIM2->CR1 |= (1 << 0);    // Enable TIM2 counter
    TIM2->CR1 |= (1<<7);
}

// Initialize TIM4 for 4x Frequency PWM (PA1)
void TIM4_PWM_Init() {
    RCC->APB1ENR |= (1 << 2);  // Enable TIM4 clock
    TIM4->PSC = 10 - 1;  // 8MHz/9  timer clock
    TIM4->ARR = 400 - 1;  // Default frequency
    TIM4->CCR1 = (TIM4->ARR + 1)/2;  // 50% duty cycle

    TIM4->CCMR1 &= ~(0xFF << 0);
    TIM4->CCMR1 |= (6 << 4);  // PWM mode 1 on CH1
    TIM4->CCER |= (1 << 0);   // Enable CH1 output
    TIM4->CR1 |=(1<<7);
    TIM4->CR1 |= (1 << 0);    // Enable TIM4 counter
}

// TIM3 Interrupt Handler for Frequency Measurement
void TIM3_IRQHandler() {
    if (TIM3->SR & (1 << 1)) {  // Check for capture flag
        TIM3->SR &= ~(1 << 1);  // Clear flag
        value2 = TIM3->CCR1;

        if (value2 > value1) {
            frequency = 1000000 / (value2 - value1);  // Calculate frequency
        } else {
            frequency = 0;  // Handle timer overflow
        }

        value1 = value2;  // Update last capture value
    }
}

// Update PWM Frequencies
void Update_PWM_Frequencies() {
	// Store frequency in buffer for averaging
	frequency_buffer[index] = frequency;
	index = (index + 1) % FILTER_SIZE;
	// Compute the average frequency
	uint32_t sum = 0;
	for (uint8_t i = 0; i < FILTER_SIZE; i++) {
       sum += frequency_buffer[i];
	}
	avg_frequency = sum / FILTER_SIZE;

    if (frequency > 20) {
        TIM2->ARR = (1000000 / ( 2*avg_frequency)) - 1;
        TIM2->CCR1 = (TIM2->ARR + 1) / 2;

        TIM4->ARR = (1000000 / (4 * avg_frequency
        		)) - 1;
        TIM4->CCR1 = (TIM4->ARR + 1) / 2;
    }else{
    	frequency=0;
    }
}
void RCC_Init() {
    // Enable HSE
    RCC->CR |= (1<<16);;  // Turn on HSE oscillator
    while ((RCC->CR & (1<<17)) == 0);  // Wait for HSE to be ready

    // Select HSE as the system clock
    RCC->CFGR |= (1 << 0);  // Set HSE as system clock
    while ((RCC->CFGR & (3 << 2)) != (1 << 2));
}
int main(void) {
	RCC_Init();
    GPIO_Init_Input();
    TIM3_InputCapture_Init();
    GPIO_Init_Output();
    TIM2_PWM_Init();
    TIM4_PWM_Init();

    while (1) {
        Update_PWM_Frequencies();
    }
}
