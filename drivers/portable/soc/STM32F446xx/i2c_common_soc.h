/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __I2C_COMMON_SOC_H__
#define __I2C_COMMON_SOC_H__

#include "stm32f4xx_hal_conf.h"

#include "i2c_soc.h"
#include "i2c_bsp.h"

typedef struct i2c_handle_s
{
	I2C_HandleTypeDef i2c_hal_handle;
	i2c_op_clbk_t clbk;
	void *user;
} i2c_handle_t;

int i2c_common_periph_init(i2c_bus_t bus, uint32_t addr_mode, uint32_t clock_speed, uint32_t own_address);
void i2c_common_periph_deinit(i2c_bus_t bus);
i2c_handle_t * i2c_common_get_handle(i2c_bus_t bus);

#endif /* __I2C_COMMON_SOC_H__ */