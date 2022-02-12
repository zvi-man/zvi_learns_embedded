/*
 * LED.c
 *
 *  Created on: 30 בינו׳ 2022
 *      Author: צבי
 */
#include "LED.h"
#include "task_handler.h"
#include "uart.h"
#include "string.h"
#include "stdio.h"

GPIO_TypeDef* led_gpio_type;
uint16_t led_gpio_pin;
uint32_t toggle_led_count = 0;

void LED_toggleLed()
{
	HAL_GPIO_TogglePin(led_gpio_type, led_gpio_pin);
	toggle_led_count++;
	if(toggle_led_count == NUM_TIMES_TOGGLE_LED_FOR_MSG)
	{
		TASK_HANDLER_InsertTask(LED_ledToggledXTimesMsg);
		toggle_led_count = 0;
	}

}

void LED_ledToggledXTimesMsg()
{
	char output_msg[strlen(TOGGLE_LED_SERIAL_MSG)];
	sprintf(output_msg, TOGGLE_LED_SERIAL_MSG, NUM_TIMES_TOGGLE_LED_FOR_MSG);
	UART_sendString(output_msg);
}

void LED_init(GPIO_TypeDef* gpio_type, uint16_t gpio_pin)
{
	led_gpio_type = gpio_type;
	led_gpio_pin = gpio_pin;
}

