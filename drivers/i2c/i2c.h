/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __I2C_H__
#define __I2C_H__

#include "i2c_soc.h"

/* I2C master interface */
int i2c_master_init(i2c_bus_t bus, uint32_t addr_mode, uint32_t clock_speed);
void i2c_master_deinit(i2c_bus_t bus);

int i2c_master_send(i2c_bus_t bus, uint8_t address, uint8_t *data, size_t length);
int i2c_master_recv(i2c_bus_t bus, uint8_t address, uint8_t *data, size_t length);

/* I2C slave interface */
int i2c_slave_init(i2c_bus_t bus);
void i2c_slave_deinit(i2c_bus_t bus);

int i2c_slave_send(i2c_bus_t bus, uint8_t *data, size_t length);
size_t i2c_slave_recv(i2c_bus_t bus, uint8_t *data, size_t lenght);

#endif /* __I2C_H__ */
