/*
 * LED.h
 *
 *  Created on: 30 בינו׳ 2022
 *      Author: צבי
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

#define NUM_TIMES_TOGGLE_LED_FOR_MSG 5
#define TOGGLE_LED_SERIAL_MSG "Toggle Led %d times"

void LED_init(GPIO_TypeDef* gpio_type, uint16_t gpio_pin);
void LED_ledToggledXTimesMsg();
void LED_toggleLed();

#endif /* INC_LED_H_ */
