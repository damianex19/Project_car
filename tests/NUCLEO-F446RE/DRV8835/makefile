PROJECT_DIR = $(PWD)
ROOT_DIR = $(PWD)/../../..

CROSS_COMPILE = arm-none-eabi-

CC = $(CROSS_COMPILE)gcc
AS = $(CROSS_COMPILE)as
OBJCOPY = $(CROSS_COMPILE)objcopy

CPU = cortex-m4
SOC_FAMILY = STM32F446xx
BOARD_TYPE = NUCLEO-F446RE
LNK_SCRIPT = STM32F446RETx_FLASH.ld

CFLAGS += --std=gnu99 -Wall
CFLAGS += -g -ggdb -O0
CFLAGS += -D$(SOC_FAMILY)
CFLAGS += -mcpu=$(CPU) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -I$(ROOT_DIR)/

CONFIG_DRV8835 = 'y'
CONFIG_ENCODER = 'y'
CONFIG_USART = 'y'
CONFIG_TOOLS_LIST = 'y'
CONFIG_TOOLS_RINGBUF = 'y'
CONFIG_BSP_LEDS = 'y'

TARGET_OBJ=
include $(ROOT_DIR)/drivers/drivers.mk
include $(ROOT_DIR)/hal/hal.mk
include $(ROOT_DIR)/init/init.mk
include $(ROOT_DIR)/kernel/kernel.mk
include $(ROOT_DIR)/tools/tools.mk

DEPFLAGS = -MT $@ -MMD -MP -MF $(patsubst %.o,%.d,$@)

%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

%.o: %.s
	$(AS) -c $^ -o $@ -mthumb -mcpu=$(CPU) -mfloat-abi=hard -mfpu=fpv4-sp-d16

all: test/DRV8835
include DRV8835.mk

clean:	test/DRV8835_clean
		rm -f `find $(ROOT_DIR) -name "*.d"`
		rm -f `find -name "*.d"`
		rm -f $(TARGET_OBJ)

include $(wildcard $(patsubst %,%.d,$(basename $(TARGET_OBJ))))
