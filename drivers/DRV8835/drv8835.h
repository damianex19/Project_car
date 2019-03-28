/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __DRV_8835_H__
#define __DRV_8835_H__

#include "pwm_soc.h"

typedef enum drv8835_dir_e {
	NON_INVERTED,
	INVERTED
} drv8835_dir_t;

typedef enum drv8835_state_e {
	DISABLED,
	ENABLED
} drv8835_state_t;

typedef struct drv8835_init_s {
	size_t dir_pin;
	pwm_timer_t pwm;
} drv8835_init_t;

typedef const void * drv8835_handle_t; 

drv8835_handle_t drv8835_init(const drv8835_init_t *init);
void drv8835_deinit(drv8835_handle_t handle);

int drv8835_set_speed(drv8835_handle_t handle, int percent);
int drv8835_set_direction(drv8835_handle_t handle, drv8835_dir_t dir);

#endif //__DRV_8835_H__