/*
 * LED.c
 *
 *  Created on: 30 בינו׳ 2022
 *      Author: צבי
 */
#include "LED.h"

GPIO_TypeDef* led_gpio_type;
uint16_t led_gpio_pin;


void LED_toggleLed()
{
	HAL_GPIO_TogglePin(led_gpio_type, led_gpio_pin);
}

void LED_init(GPIO_TypeDef* gpio_type, uint16_t gpio_pin)
{
	led_gpio_type = gpio_type;
	led_gpio_pin = gpio_pin;
}

