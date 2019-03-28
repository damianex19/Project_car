/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include <string.h>

#include "pwm_soc.h"

static pwm_handle_t pwm_handles[PWM_TIMER_END];

int pwm_soc_init(pwm_timer_t timer, uint32_t p_freq, uint32_t res)
{
	return -1;
}

uint32_t pwm_soc_get_timer_clock(pwm_timer_t timer)
{
	return 0;
}

void pwm_soc_deinit(pwm_timer_t timer)
{
	return;
}

int pwm_soc_set_duty_cycle(pwm_timer_t timer, uint16_t dc)
{
	return -1;
}

int pwm_soc_get_duty_cycle(pwm_timer_t timer, uint16_t *dc)
{
	return -1;
}
