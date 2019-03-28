/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include <FreeRTOS.h>

#include "i2c.h"

static void i2c_master_clbk(int result, void *data);

int i2c_master_init(i2c_bus_t bus, uint32_t addr_mode, uint32_t clock_speed)
{
    return 0;
}

void i2c_master_deinit(i2c_bus_t bus)
{   
}

int i2c_master_send(i2c_bus_t bus, uint8_t address, uint8_t *data, size_t length)
{
    return 0;
}

int i2c_master_recv(i2c_bus_t bus, uint8_t address, uint8_t *data, size_t length)
{
    return 0;
}
