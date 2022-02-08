/*
 * Timer.c
 *
 *  Created on: 30 בינו׳ 2022
 *      Author: צבי
 */

#include "Timer.h"


void (*p_timer_callbac_func)();
bool run_iterrupt_once;



void TIMER_start(TIM_HandleTypeDef *p_htim, void (*func), bool is_one_time)
{
	p_timer_callbac_func = func;
	run_iterrupt_once = is_one_time;
	HAL_TIM_Base_Start_IT(p_htim);
}

void TIMER_stop(TIM_HandleTypeDef *p_htim)
{
	HAL_TIM_Base_Stop_IT(p_htim);
}


/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *p_htim)
{
	// Check wich timer triggered the interrupt
	if (p_htim->Instance == TIMER_NUM)
	{
		p_timer_callbac_func();
	}
	if (run_iterrupt_once)
	{
		HAL_TIM_Base_Stop_IT(p_htim);
	}
}
