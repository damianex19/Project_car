/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include <FreeRTOS.h>

#include "gpio.h"

#include "leds.h"

void leds_init(uint32_t leds)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef gpio;
	gpio.Pin=GPIO_PIN_5;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull=GPIO_NOPULL;
	gpio.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA,&gpio);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
}

void leds_deinit(uint32_t leds)
{

HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);

}

void leds_set(uint32_t leds, led_state_t state)
{
}

led_state_t leds_get(uint32_t leds)
{
    return LED_OFF;
}

void leds_toggle( uint32_t leds )
{

}

void leds_on( uint32_t leds )
{
}

void leds_off( uint32_t leds )
{
}

