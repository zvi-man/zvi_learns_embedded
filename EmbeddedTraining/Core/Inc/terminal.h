/*
 * terminal.c
 *
 *  Created on: Feb 9, 2022
 *      Author: צבי
 */

#ifndef TERMINAL_C_
#define TERMINAL_C_

#include "main.h"

#define NUM_OF_BYTES_IN_UINT32 4


void TERMINAL_start(UART_HandleTypeDef *p_huart);
void TERMINAL_processInput();

#endif /* INC_TERMINAL_C_ */
