/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include <string.h>

#include "i2c_common_soc.h"

static i2c_handle_t i2c_handles[I2C_BUS_END];

int i2c_common_periph_init(i2c_bus_t bus, uint32_t addr_mode, uint32_t clock_speed, uint32_t own_address)
{
    return 1;
}

void i2c_common_periph_deinit(i2c_bus_t bus)
{
	return;
}

i2c_handle_t * i2c_common_get_handle(i2c_bus_t bus)
{
    return NULL;
}
