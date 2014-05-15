/**
 * @file: 	adc.h
 * @brief:	   
 * @date: 	15 maj 2014
 * @author: Michal Ksiezopolski
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

#ifndef ADC_H_
#define ADC_H_

#include <stm32f4xx.h>

uint16_t ACD3_GetResult(uint8_t num);
void ADC3_Init(void);

#endif /* ADC_H_ */
