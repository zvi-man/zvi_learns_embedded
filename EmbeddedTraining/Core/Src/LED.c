/*
 * LED.c
 *
 *  Created on: 30 בינו׳ 2022
 *      Author: צבי
 */
#include "LED.h"

void LED_toggleLed()
{
	HAL_GPIO_TogglePin(BLUE_LED_GPIO, BLUE_LED_GPIO_PIN);
}



/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void LED_init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}
