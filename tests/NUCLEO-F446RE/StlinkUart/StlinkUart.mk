STLINK_UART_TEST_DIR = $(PWD)
STLINK_UART_TEST_OBJ = $(STLINK_UART_TEST_DIR)/main.o \
					   $(STLINK_UART_TEST_DIR)/stlink_uart_test.o

CFLAGS += -I$(STLINK_UART_TEST_DIR)

$(STLINK_UART_TEST_DIR)/stlink_uart_test.elf: $(TARGET_OBJ) $(STLINK_UART_TEST_OBJ)
	$(CC) -mthumb -mcpu=$(CPU) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T$(ROOT_DIR)/$(LNK_SCRIPT) -Wl,--gc-sections -o $@ $^
	$(OBJCOPY) -Oihex $(STLINK_UART_TEST_DIR)/stlink_uart_test.elf $(STLINK_UART_TEST_DIR)/stlink_uart_test.hex

test/StlinkUart: $(STLINK_UART_TEST_DIR)/stlink_uart_test.elf

test/StlinkUart_clean:
	rm -rf $(STLINK_UART_TEST_OBJ)
	rm -rf $(STLINK_UART_TEST_DIR)/stlink_uart_test.elf $(STLINK_UART_TEST_DIR)/stlink_uart_test.hex
	rm -rf soc
	rm -rf bsp
	rm -rf hal