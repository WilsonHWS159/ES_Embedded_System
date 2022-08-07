CROSS-COMPILER = arm-none-eabi-
QEMU = ./gnu-mcu-eclipse-qemu/bin/qemu-system-gnuarmeclipse

all: main.bin

main.bin: main.c vector_table.s
	$(CROSS-COMPILER)gcc -Wall -std=c11 -mcpu=cortex-m4 -mthumb -nostartfiles -T m4.ld main.c vector_table.s -o main.elf
	$(CROSS-COMPILER)objcopy -O binary main.elf main.bin
	$(CROSS-COMPILER)objdump -D main.elf

qemu:
	@echo
	@echo "Press Ctrl+A and then press X to exit QEMU"
	@echo
	$(QEMU) -M STM32F4-Discovery -nographic -gdb tcp::1234 -S -kernel main.bin

clean:
	rm -rf *.o *.elf

