/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __ENCODER_H__
#define __ENCODER_H__

#include "encoder_soc.h"

typedef void (*encoder_measure_done_clbk)(int32_t count, uint32_t time_ms);

int encoder_init(encoder_timer_t timer, encoder_type_t type);
void encoder_deinit(encoder_timer_t timer);

encoder_dir_t encoder_get_direction(encoder_timer_t timer);
int32_t encoder_get_value(encoder_timer_t timer);

int32_t encoder_measure_speed_block(encoder_timer_t timer, uint32_t time_ms);
int encoder_measure_speed_no_block(encoder_timer_t timer, uint32_t time_ms, encoder_measure_done_clbk clbk);

#endif //__ENCODER_H__
