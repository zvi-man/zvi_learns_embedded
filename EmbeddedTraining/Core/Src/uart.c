/*
 * uart.c
 *
 *  Created on: Feb 9, 2022
 *      Author: צבי
 */

#include "uart.h"
#include <string.h>
#include <task_handler.h>

UART_HandleTypeDef *p_huart_send_handle;
UART_HandleTypeDef *p_huart_receive_it_handle;
void (*p_uart_callbac_func)();


void UART_init(UART_HandleTypeDef *p_huart)
{
	p_huart_send_handle = p_huart;
}

void UART_sendOuch()
{
	UART_sendString(OUCH_MSG);
}

void UART_sendString(char *p_str_to_send)
{
	HAL_UART_Transmit(p_huart_send_handle, p_str_to_send, strlen(p_str_to_send), HAL_MAX_DELAY);
}

void UART_Receive_and_call_func_it(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, void (*func))
{
	p_uart_callbac_func = func;
	p_huart_receive_it_handle = huart;
	HAL_UART_Receive_IT(huart, pData, Size);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == p_huart_receive_it_handle)
	{
		TASK_HANDLER_InsertTask(p_uart_callbac_func);
	}
}
