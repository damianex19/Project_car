/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __ENCODER_SOC_H__
#define __ENCODER_SOC_H__

#include "stm32f4xx_hal_conf.h"

#include "encoder_bsp.h"

typedef enum ecooder_config_e {
	ENCODER_CHANNEL_CFG_1,
	ENCODER_CHANNEL_CFG_2,
	ENCODER_CHANNEL_CFG_12,
	ENCODER_CHANNEL_CFG_INVALID
} encoder_config_t;

typedef enum encoder_dir_e {
	ENCODER_DIR_INVALID = 0,
	ENCODER_DIR_UP,
	ENCODER_DIR_DOWN
} encoder_dir_t;

typedef enum encoder_type_e {
	ENCODER_TYPE_INVALID = 0,
	ENCODER_TYPE_SINGLE,
	ENCODER_TYPE_DUAL,
} encoder_type_t;

typedef struct encoder_handle_s {
	TIM_HandleTypeDef encoder_hal_handle;
	TIM_Encoder_InitTypeDef encoder_hal_config;
	encoder_type_t encoder_type;
	int32_t overflow_cnt;
} encoder_handle_t;

int encoder_soc_init(encoder_timer_t timer, encoder_type_t type);
void encoder_soc_deinit(encoder_timer_t timer);

encoder_dir_t encoder_soc_get_direction(encoder_timer_t timer);
int32_t encoder_soc_get_value(encoder_timer_t timer);

void encoder_soc_handle_irq(encoder_timer_t timer);

#endif
