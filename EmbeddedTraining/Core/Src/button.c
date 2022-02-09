/*
 * button.c
 *
 *  Created on: Jan 31, 2022
 *      Author: zvi
 */

#include "button.h"
#include "Timer.h"
#include <stdbool.h>

GPIO_PinState button_state = GPIO_PIN_RESET;
void (*p_button_press_func)();
GPIO_TypeDef* button_gpio_type;
uint16_t button_gpio_pin;



void BUTTON_init(GPIO_TypeDef* gpio_type, uint16_t gpio_pin, void (*func))
{
	p_button_press_func = func;
	button_gpio_type = gpio_type;
	button_gpio_pin = gpio_pin;
}

void BUTTON_setButtonState(GPIO_PinState new_button_state)
{

	if(button_state == GPIO_PIN_RESET && new_button_state == GPIO_PIN_SET) // button pressed
	{
		p_button_press_func();
	}
	button_state = new_button_state;
}

void BUTTON_updateButtonState()
{
	GPIO_PinState current_button_state = HAL_GPIO_ReadPin(button_gpio_type, button_gpio_pin);
	GPIO_PinState new_button_state;
	while(true)
	{
		HAL_Delay(BUTTON_DEBOUNCE_TIME_MSEC);
		new_button_state = HAL_GPIO_ReadPin(button_gpio_type, button_gpio_pin);
		if (new_button_state == current_button_state) // Button press consistent
		{
			BUTTON_setButtonState(current_button_state);
			break;
		} // experiencing button bouncing
		current_button_state = new_button_state;
	}
}


