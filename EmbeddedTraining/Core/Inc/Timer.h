/*
 * Timer.h
 *
 *  Created on: 30 בינו׳ 2022
 *      Author: צבי
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include <stdbool.h>


void TIMER_init(TIM_HandleTypeDef *p_htim);
void TIMER_start(TIM_HandleTypeDef *p_htim, void (*func), bool is_one_time);
void TIMER_stop(TIM_HandleTypeDef *p_htim);



#endif /* INC_TIMER_H_ */
