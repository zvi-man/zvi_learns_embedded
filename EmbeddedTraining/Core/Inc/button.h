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

void BUTTON_init(GPIO_TypeDef* gpio_type, uint16_t gpio_pin, void (*func));
void BUTTON_setButtonState(GPIO_PinState new_button_state);
void BUTTON_updateButtonState();

#endif /* INC_BUTTON_H_ */
