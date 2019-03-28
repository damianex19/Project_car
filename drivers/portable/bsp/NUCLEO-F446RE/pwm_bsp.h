/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __PWM_BSP_H__
#define __PWM_BSP_H__

typedef enum pwm_timer_e {
	PWM_TIMER_1,
	PWM_TIMER_2,
	PWM_TIMER_3,
	PWM_TIMER_4,
	PWM_TIMER_5,
	PWM_TIMER_8,
	PWM_TIMER_9,
	PWM_TIMER_10,
	PWM_TIMER_11,
	PWM_TIMER_12,
	PWM_TIMER_13,
	PWM_TIMER_14,
	PWM_TIMER_END
} pwm_timer_t;

#endif