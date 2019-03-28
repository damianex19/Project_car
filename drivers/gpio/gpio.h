/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __GPIO_H__
#define __GPIO_H__

#include <FreeRTOS.h>
#include <gpio_soc.h>

#define GPIO_INVALID_PIN (size_t)(-1)

int gpio_init(size_t pin, gpio_mode_t mode, gpio_pull_t pull, gpio_irq_t irq, gpio_irq_callback_f irq_callback, void *data);
void gpio_deinit(size_t pin);

uint32_t gpio_read_pin(size_t pin);
void gpio_write_pin(size_t pin, uint32_t state);
void gpio_toggle_pin(size_t pin);

#endif
