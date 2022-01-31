/*
 * button.h
 *
 *  Created on: Jan 31, 2022
 *      Author: zvi
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "stm32f4xx_hal.h"


#define BUTTON_DEBOUNCE_TIME_MSEC 50

GPIO_PinState BUTTON_ReadButtonDebouncer(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);




#endif /* INC_BUTTON_H_ */
