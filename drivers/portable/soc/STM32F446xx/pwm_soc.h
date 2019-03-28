/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __PWM_SOC_H__
#define __PWM_SOC_H__

#include "stm32f4xx_hal_conf.h"

#include "pwm_bsp.h"


#define TIMER_IRQ_PRORITY 7

typedef struct pwm_handle_s {
	TIM_HandleTypeDef pwm_hal_handle;
	TIM_OC_InitTypeDef pwm_hal_config;

	uint32_t channel;
    IRQn_Type irq;
} pwm_handle_t;

int pwm_soc_init(pwm_timer_t timer, uint32_t p_freq, uint32_t res);
void pwm_soc_deinit(pwm_timer_t timer);

uint32_t pwm_soc_get_timer_clock(pwm_timer_t timer);

int pwm_soc_set_duty_cycle(pwm_timer_t timer, uint16_t dc);
int pwm_soc_get_duty_cycle(pwm_timer_t timer, uint16_t *dc);
void pwm_soc_set_timer_for_dma(pwm_timer_t timer);
void pwm_soc_timer_start(pwm_timer_t timer);
void pwm_soc_timer_stop(pwm_timer_t timer);

#endif
