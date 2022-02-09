/*
 * set_interval_terminal.c
 *
 *  Created on: Feb 9, 2022
 *      Author: צבי
 */
#include "terminal.h"
#include "Timer.h"
#include "uart.h"

/* USER CODE BEGIN PV */
union special_8bit_buff{
	uint32_t total_value;
	uint8_t buff[NUM_OF_BYTES_IN_UINT32];
};

union special_8bit_buff terminal_input_buff;
UART_HandleTypeDef *p_terminal_huart_handle;



void TERMINAL_start(UART_HandleTypeDef *p_huart)
{
	p_terminal_huart_handle = p_huart;
	UART_Receive_and_call_func_it(p_terminal_huart_handle, terminal_input_buff.buff, NUM_OF_BYTES_IN_UINT32, TERMINAL_processInput);
}

void TERMINAL_processInput()
{
	TIMER_set_interval(terminal_input_buff.total_value);
	UART_Receive_and_call_func_it(p_terminal_huart_handle, terminal_input_buff.buff, NUM_OF_BYTES_IN_UINT32, TERMINAL_processInput);
}
