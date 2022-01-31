/*
 * Timer.c
 *
 *  Created on: 30 בינו׳ 2022
 *      Author: צבי
 */

#include "Timer.h"


void (*p_timer_callbac_func)();
bool run_iterrupt_once;


/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
void TIMER_init(TIM_HandleTypeDef *p_htim)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  p_htim->Instance = TIM2;
  p_htim->Init.Prescaler = 25000-1;
  p_htim->Init.CounterMode = TIM_COUNTERMODE_UP;
  p_htim->Init.Period = 500 - 1;
  p_htim->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  p_htim->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(p_htim) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(p_htim, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(p_htim, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

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
	if (p_htim->Instance == TIM2)
	{
		p_timer_callbac_func();
	}
	if (run_iterrupt_once)
	{
		HAL_TIM_Base_Stop_IT(p_htim);
	}
}
