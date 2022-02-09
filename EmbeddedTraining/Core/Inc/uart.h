/*
 * uart.h
 *
 *  Created on: Feb 9, 2022
 *      Author: צבי
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"

#define OUCH_MSG "ouch\n"

void UART_init(UART_HandleTypeDef *p_huart);
void UART_Receive_and_call_func_it(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, void (*func));
void UART_sendOuch();
void UART_sendString(char *p_str_to_send);

#endif /* INC_UART_H_ */
