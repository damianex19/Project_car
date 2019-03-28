/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include "gpio_soc.h"
#include "gpio_bsp_pin.h"

#define EXTI_LINES_CNT	16

int gpio_soc_init(size_t pin, gpio_mode_t mode, gpio_pull_t pull, gpio_irq_t irq, gpio_irq_callback_f irq_callback, void *data)
{
	return 0;
}

int gpio_soc_init_alternate(size_t pin, gpio_mode_t mode, gpio_pull_t pull, gpio_irq_t irq, gpio_irq_callback_f irq_callback, void *data, uint32_t alternate)
{
	return 0;
}

void gpio_soc_deinit(size_t pin)
{
}

uint32_t gpio_soc_read_pin(size_t pin)
{
	return 0;
}

void gpio_soc_write_pin(size_t pin, uint32_t state)
{
}

void gpio_soc_toggle_pin(size_t pin)
{
}
