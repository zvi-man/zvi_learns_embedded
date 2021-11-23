/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>

#define RCC_AHB1ENR_ADDR 0x40023830
#define RCC_AHB1_TURNON_GPIOC 0x00000004
#define GPIOC_MODER_ADDR 0x40020800
#define MODER_PIN13_GPO 0x04000000
#define GPIOC_ODR_ADDR 0x40020814
#define ODR_PIN_HIGH 0x00002000
#define ODR_PIN_LOW 0x00000000

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	uint32_t *p_gpio_rcc_ahb1_en_addr = (uint32_t*) RCC_AHB1ENR_ADDR;
	uint32_t *p_gpioc_odr = (uint32_t*) GPIOC_ODR_ADDR;
	uint32_t *p_gpioc_moder = (uint32_t*) GPIOC_MODER_ADDR;
	*p_gpio_rcc_ahb1_en_addr = (uint32_t) RCC_AHB1_TURNON_GPIOC;
	*p_gpioc_moder = (uint32_t) MODER_PIN13_GPO;
    /* Loop forever */
	while(1)
	{
		*p_gpioc_odr = (uint32_t) ODR_PIN_HIGH;
		*p_gpioc_odr = (uint32_t) ODR_PIN_LOW;
	}
}
