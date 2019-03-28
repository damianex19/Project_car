TOOLS_SRC_DIR = $(ROOT_DIR)/tools
CFLAGS += -I$(TOOLS_SRC_DIR)
CFLAGS += -I$(TOOLS_SRC_DIR)/portable/soc/$(SOC_FAMILY)

ifeq ($(CONFIG_TOOLS_LIST), 'y')
	TARGET_OBJ += $(TOOLS_SRC_DIR)/list.o
endif

ifeq ($(CONFIG_TOOLS_MAP), 'y')
	TARGET_OBJ += $(TOOLS_SRC_DIR)/map.o
endif

ifeq ($(CONFIG_TOOLS_RINGBUF), 'y')
	TARGET_OBJ += $(TOOLS_SRC_DIR)/ringbuf.o
endif

include $(TOOLS_SRC_DIR)/portable/soc/$(SOC_FAMILY)/soc.mk
