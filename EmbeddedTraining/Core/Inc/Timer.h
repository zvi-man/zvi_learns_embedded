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


#define TIMER_NUM TIM2

void TIMER_init(TIM_HandleTypeDef *p_htim);
void TIMER_start(void (*func), bool is_one_time);
void TIMER_stop(TIM_HandleTypeDef *p_htim);
void TIMER_set_interval(uint32_t time_delay_msec);



#endif /* INC_TIMER_H_ */
