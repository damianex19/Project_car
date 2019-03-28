LEDS_BLINK_TEST_DIR = $(PWD)
LEDS_BLINK_TEST_OBJ = $(LEDS_BLINK_TEST_DIR)/main.o \
					   $(LEDS_BLINK_TEST_DIR)/leds_blink.o

CFLAGS += -I$(LEDS_BLINK_TEST_DIR)

$(LEDS_BLINK_TEST_DIR)/leds_blink_test.elf: $(TARGET_OBJ) $(LEDS_BLINK_TEST_OBJ)
	$(CC) -mthumb -mcpu=$(CPU) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T$(ROOT_DIR)/$(LNK_SCRIPT) -Wl,--gc-sections -o $@ $^
	$(OBJCOPY) -Oihex $(LEDS_BLINK_TEST_DIR)/leds_blink_test.elf $(LEDS_BLINK_TEST_DIR)/leds_blink_test.hex

test/LedsBlink: $(LEDS_BLINK_TEST_DIR)/leds_blink_test.elf

test/LedsBlink_clean:
	rm -rf $(LEDS_BLINK_TEST_OBJ)
	rm -rf $(LEDS_BLINK_TEST_DIR)/leds_blink_test.elf $(LEDS_BLINK_TEST_DIR)/leds_blink_test.hex
	rm -rf soc
	rm -rf bsp
	rm -rf hal