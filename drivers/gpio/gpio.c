/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include "gpio.h"

int gpio_init(size_t pin, gpio_mode_t mode, gpio_pull_t pull, gpio_irq_t irq, gpio_irq_callback_f irq_callback, void *data)
{
	return gpio_soc_init(pin, mode, pull, irq, irq_callback, data);
}

void gpio_deinit(size_t pin)
{
	gpio_soc_deinit(pin);
}

uint32_t gpio_read_pin(size_t pin)
{
	return gpio_soc_read_pin(pin);
}

void gpio_write_pin(size_t pin, uint32_t state)
{
	gpio_soc_write_pin(pin, state);
}

void gpio_toggle_pin(size_t pin)
{
	gpio_soc_toggle_pin(pin);
}
