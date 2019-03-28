CFLAGS += -I$(ROOT_DIR)/kernel/Source/include/
CFLAGS += -I$(ROOT_DIR)/kernel/Source/portable/GCC/ARM_CM4F/

KERNEL_DIR = $(ROOT_DIR)/kernel
KERNEL_OBJ = $(KERNEL_DIR)/Source/event_groups.o \
			 $(KERNEL_DIR)/Source/queue.o \
			 $(KERNEL_DIR)/Source/timers.o \
			 $(KERNEL_DIR)/Source/portable/MemMang/heap_3.o \
			 $(KERNEL_DIR)/Source/portable/GCC/ARM_CM4F/port.o \
			 $(KERNEL_DIR)/Source/portable/Common/mpu_wrappers.o \
			 $(KERNEL_DIR)/Source/list.o \
			 $(KERNEL_DIR)/Source/tasks.o \
			 $(KERNEL_DIR)/Source/croutine.o

TARGET_OBJ += $(KERNEL_OBJ)