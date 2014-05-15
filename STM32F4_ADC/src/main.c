/**
 * @file: 	main.c
 * @brief:
 * @date: 	9 kwi 2014
 * @author: Michal Ksiezopolski
 * 
 *
 * @verbatim
 * Copyright (c) 2014 Michal Ksiezopolski.
 * All rights reserved. This program and the 
 * accompanying materials are made available 
 * under the terms of the GNU Public License 
 * v3.0 which accompanies this distribution, 
 * and is available at 
 * http://www.gnu.org/licenses/gpl.html
 * @endverbatim
 */

#include <stm32f4xx.h>
#include <stdio.h>

#include "timers.h"
#include "led.h"
#include "uart.h"
#include "adc.h"

#define SYSTICK_FREQ 1000 ///< Frequency of the SysTick.

void softTimerCallback(void);

/**
 * Main function
 * @return Nothing
 */
int main(void) {

	UART2_Init(); // Initialize USART2 (for printf)
	TIMER_Init(SYSTICK_FREQ); // Initialize timer

	LED_TypeDef led;
	led.nr=LED0;
	led.gpio=GPIOD;
	led.pin=12;
	led.clk=RCC_AHB1Periph_GPIOD;

	LED_Add(&led); // Add an LED

	printf("Starting program\r\n"); // Print a string to UART2

	int8_t timerID = TIMER_AddSoftTimer(1000, softTimerCallback);
	TIMER_StartSoftTimer(timerID);

	ADC3_Init();
	ADC_SoftwareStartConv(ADC3);

	while (1) {

		TIMER_SoftTimersUpdate();
	}

	return 0;
}

void softTimerCallback(void) {

	LED_Toggle(LED0); // Toggle LED
	printf("Test string sent from STM32F4!!!\r\n"); // Print test string
	printf("ADC ch1 = %d, ch2 = %d, ch3 = %d\r\n", ACD3_GetResult(0), ACD3_GetResult(1), ACD3_GetResult(2));

}




