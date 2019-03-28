CFLAGS += -I$(ROOT_DIR)/init

ifeq ($(SOC_FAMILY),STM32F446xx)
	INIT_DIR = $(ROOT_DIR)/init
	INIT_OBJ = $(INIT_DIR)/stm32f4xx_it.o \
		   $(INIT_DIR)/system_stm32f4xx.o \
		   $(INIT_DIR)/startup_stm32f446xx.o \
		   $(INIT_DIR)/clock_stm32f446xx.o \
		   $(INIT_DIR)/syscalls.o
endif

TARGET_OBJ += $(INIT_OBJ)
