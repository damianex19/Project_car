DRIVERS_DIR = $(ROOT_DIR)/drivers

ifeq ($(CONFIG_ENCODER),'y')
    CONFIG_GPIO ='y'
    CONFIG_SOC_ENCODER = 'y'
    TARGET_OBJ += $(DRIVERS_DIR)/encoder/encoder.o
    CFLAGS += -I$(DRIVERS_DIR)/encoder
endif   

ifeq ($(CONFIG_DRV8835), 'y')
  CONFIG_GPIO ='y'
  CONFIG_SOC_PWM ='y'
  TARGET_OBJ += $(DRIVERS_DIR)/DRV8835/drv8835.o
  CFLAGS += -I$(DRIVERS_DIR)/DRV8835
endif 

ifeq ($(CONFIG_LSM303D), 'y')
    CONFIG_I2C = 'y'
    TARGET_OBJ += $(DRIVERS_DIR)/LSM303D/acc_mag_LSM303D.o
    CFLAGS += -I$(DRIVERS_DIR)/LSM303D
endif

ifeq ($(CONFIG_I2C),'y')
    CONFIG_GPIO ='y'
    CONFIG_SOC_I2C = 'y'
    TARGET_OBJ += $(DRIVERS_DIR)/i2c/i2c_master.o
    CFLAGS += -I$(DRIVERS_DIR)/i2c
endif

ifeq ($(CONFIG_USART),'y')
    CONFIG_GPIO ='y'
    CONFIG_SOC_USART = 'y'
    CONFIG_TOOLS_RINGBUF = 'y'
    TARGET_OBJ += $(DRIVERS_DIR)/usart/usart.o
    CFLAGS += -I$(DRIVERS_DIR)/usart
endif

ifeq ($(CONFIG_GPIO),'y')
    CONFIG_SOC_GPIO = 'y'
    TARGET_OBJ += $(DRIVERS_DIR)/gpio/gpio.o
    CFLAGS += -I$(DRIVERS_DIR)/gpio
endif

include $(ROOT_DIR)/drivers/portable/soc/$(SOC_FAMILY)/soc.mk
include $(ROOT_DIR)/drivers/portable/bsp/$(BOARD_TYPE)/bsp.mk
