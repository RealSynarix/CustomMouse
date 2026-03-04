CC = arm-none-eabi-g++
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Ofast -nostdlib -fno-rtti -fno-exceptions -fno-builtin -fno-tree-loop-distribute-patterns -Tstm32g431.ld

all: cobalt.bin

cobalt.bin: src/main.cpp src/drivers.cpp src/usb_stack.cpp
	$(CC) $(CFLAGS) -Iinclude $^ -o cobalt.elf
	$(OBJCOPY) -O binary cobalt.elf cobalt.bin
