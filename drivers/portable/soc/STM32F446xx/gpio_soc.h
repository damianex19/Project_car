/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __GPIO_SOC_H__
#define __GPIO_SOC_H__

#include "stm32f4xx_hal_conf.h"
#include "gpio_bsp_con.h"

typedef enum gpio_mode_e
{
	G_MODE_INVALID = 0,
	G_MODE_INPUT = GPIO_MODE_INPUT,
	G_MODE_OUTPUT_PP = GPIO_MODE_OUTPUT_PP,
	G_MODE_OUTPUT_OD = GPIO_MODE_OUTPUT_OD,
	G_MODE_ALTERNATE_PP = GPIO_MODE_AF_PP,
	G_MODE_ALTERNATE_OD = GPIO_MODE_AF_OD,
	G_MODE_END
} gpio_mode_t;

typedef enum gpio_pull_e
{
	G_PULL_INVALID = 0,
	G_PULL_NONE = GPIO_NOPULL,
	G_PULL_PULL_UP = GPIO_PULLUP,
	G_PULL_PULL_DOWN = GPIO_PULLDOWN,
	G_PULL_END
} gpio_pull_t;

typedef enum gpio_irq_mode_e
{
	G_IRQ_NONE = 0,
	G_IRQ_RISING = GPIO_MODE_IT_RISING,
	G_IRQ_FALLING = GPIO_MODE_IT_FALLING,
	G_IRQ_RISING_FALLING = GPIO_MODE_IT_RISING_FALLING,
	G_IRQ_END
} gpio_irq_t;

typedef void (*gpio_irq_callback_f)(void *data);

int gpio_soc_init(size_t pin, gpio_mode_t mode, gpio_pull_t pull, gpio_irq_t irq, gpio_irq_callback_f irq_callback, void *data);
int gpio_soc_init_alternate(size_t pin, gpio_mode_t mode, gpio_pull_t pull, gpio_irq_t irq, gpio_irq_callback_f irq_callback, void *data, uint32_t alternate);
void gpio_soc_deinit(size_t pin);

uint32_t gpio_soc_read_pin(size_t pin); /* ToDo replace return type with enum or define */
void gpio_soc_write_pin(size_t pin, uint32_t state);	/* ToDo replace state with enum or define */
void gpio_soc_toggle_pin(size_t pin);

void gpio_irq_handler(uint16_t pin);

#endif // __GPIO_SOC_H__