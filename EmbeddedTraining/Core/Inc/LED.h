/*
 * LED.h
 *
 *  Created on: 30 בינו׳ 2022
 *      Author: צבי
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

#define BLUE_LED_GPIO GPIOC
#define BLUE_LED_GPIO_PIN GPIO_PIN_13

void LED_init();
void LED_toggleLed();

#endif /* INC_LED_H_ */
