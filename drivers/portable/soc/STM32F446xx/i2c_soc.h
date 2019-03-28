/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __I2C_SOC_H__
#define __I2C_SOC_H__

#include "stm32f4xx_hal_conf.h"

#include "i2c_bsp.h"

#define I2C_ERROR_NONE 				HAL_I2C_ERROR_NONE
#define I2C_ERROR_BERR				HAL_I2C_ERROR_BERR
#define I2C_ERROR_ARLO				HAL_I2C_ERROR_ARLO
#define I2C_ERROR_AF				HAL_I2C_ERROR_AF
#define I2C_ERROR_OVR				HAL_I2C_ERROR_OVR
#define I2C_ERROR_DMA				HAL_I2C_ERROR_DMA
#define I2C_ERROR_TIMEOUT			HAL_I2C_ERROR_TIMEOUT

#define I2C_ADDRESSING_MODE_7BIT	I2C_ADDRESSINGMODE_7BIT
#define I2C_ADDRESSING_MODE_10BIT	I2C_ADDRESSINGMODE_10BIT

typedef void (*i2c_op_clbk_t)(int result, void *data);

/* I2C master interface */
int i2c_master_soc_init(i2c_bus_t i2c_bus, uint32_t addr_mode, uint32_t clock_speed);
void i2c_master_soc_deinit(i2c_bus_t i2c_bus);
int i2c_master_soc_send(i2c_bus_t bus, uint8_t address, uint8_t *data, size_t length, i2c_op_clbk_t clbk, void *user);
int i2c_master_soc_recv(i2c_bus_t bus, uint8_t address, uint8_t *data, size_t length, i2c_op_clbk_t clbk, void *user);

/* I2C slave interface */
/* TODO */

#endif /* __I2C_SOC_H__ */