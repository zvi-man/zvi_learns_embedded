/*
 * uart.c
 *
 *  Created on: Feb 9, 2022
 *      Author: צבי
 */

#include "uart.h"
#include <string.h>

UART_HandleTypeDef *p_huart_handle;

void UART_init(UART_HandleTypeDef *p_huart)
{
	p_huart_handle = p_huart;
}

void UART_sendOuch()
{
	HAL_UART_Transmit(p_huart_handle, (uint8_t *)OUCH_MSG, strlen(OUCH_MSG), HAL_MAX_DELAY);
}
