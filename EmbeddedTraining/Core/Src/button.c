/*
 * button.c
 *
 *  Created on: Jan 31, 2022
 *      Author: zvi
 */

#include "button.h"
#include <stdbool.h>



GPIO_PinState BUTTON_ReadButtonDebouncer(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	GPIO_PinState current_button_status = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
	GPIO_PinState new_button_status;
	while(true)
	{
		HAL_Delay(BUTTON_DEBOUNCE_TIME_MSEC);
		new_button_status = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
		if (new_button_status == current_button_status) // Button press consistent
		{
			return current_button_status;
		} // experiencing button bouncing
		current_button_status = new_button_status;
	}
}


