ENCODER_TEST_DIR = $(PWD)
ENCODER_TEST_OBJ = $(ENCODER_TEST_DIR)/main.o \
				   $(ENCODER_TEST_DIR)/encoder_test.o \

CFLAGS += -I$(ENCODER_TEST_DIR)

$(ENCODER_TEST_DIR)/encoder_test.elf: $(TARGET_OBJ) $(ENCODER_TEST_OBJ)
	$(CC) -mthumb -mcpu=$(CPU) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T$(ROOT_DIR)/$(LNK_SCRIPT) -Wl,--gc-sections -o $@ $^
	$(OBJCOPY) -Oihex $(ENCODER_TEST_DIR)/encoder_test.elf $(ENCODER_TEST_DIR)/encoder_test.hex

test/Encoder: $(ENCODER_TEST_DIR)/encoder_test.elf

test/Encoder_clean:
	rm -rf $(ENCODER_TEST_OBJ)
	rm -rf $(ENCODER_TEST_DIR)/encoder_test.elf $(ENCODER_TEST_DIR)/encoder_test.hex
	rm -rf soc
	rm -rf bsp
	rm -rf hal