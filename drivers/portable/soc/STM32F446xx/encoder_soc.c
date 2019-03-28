/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include <string.h>

#include "stm32f4xx_hal_conf.h"
#include "encoder_soc.h"

#include <tools/container_of.h>

static encoder_handle_t encoder_handles[ENCODER_TIMER_END];

int encoder_soc_init_single(encoder_timer_t timer) 
{
	return -1;
}

int encoder_soc_init_dual(encoder_timer_t timer) 
{
	return -1;
}

int encoder_soc_init(encoder_timer_t timer, encoder_type_t type)
{
	return -1;
}

void encoder_soc_deinit(encoder_timer_t timer)
{
}

encoder_dir_t encoder_soc_get_direction(encoder_timer_t timer) {
	return ENCODER_DIR_INVALID;
}

int32_t encoder_soc_get_value(encoder_timer_t timer) {
	return -1;
}
