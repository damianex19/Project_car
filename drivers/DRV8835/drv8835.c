/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include <FreeRTOS.h>
#include "task.h"

#include "gpio.h"
#include "pwm_soc.h"

#include "drv8835.h"

#define	FREQUENCY_HZ 10000
#define RESOLUTION	256

#define DUTY_CYCLE_MIN 0
#define DUTY_CYCLE_MAX RESOLUTION

drv8835_handle_t drv8835_init(const drv8835_init_t *init)
{
	return NULL;
}

void drv8835_deinit(drv8835_handle_t handle) {
	configASSERT(handle != NULL);
}

int drv8835_set_speed(drv8835_handle_t handle, int percent) {
	configASSERT(handle != NULL);

	return -1;
}

int drv8835_set_direction(drv8835_handle_t handle, drv8835_dir_t dir) {
	configASSERT(handle != NULL);
	return -1;
}
