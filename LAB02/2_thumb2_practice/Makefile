CROSS-COMPILER = arm-none-eabi-
QEMU = ./gnu-mcu-eclipse-qemu/bin/qemu-system-gnuarmeclipse

all: thumb2_practice.bin

thumb2_practice.bin: thumb2_practice.s
	$(CROSS-COMPILER)gcc -Wall -mcpu=cortex-m4 -nostartfiles -Ttext=0x0 thumb2_practice.s -o thumb2_practice.elf
	$(CROSS-COMPILER)objcopy -O binary thumb2_practice.elf thumb2_practice.bin
	$(CROSS-COMPILER)objdump -D thumb2_practice.elf

qemu:
	@echo
	@echo "Press Ctrl+A and then press X to exit QEMU"
	@echo
	$(QEMU) -M STM32F4-Discovery -nographic -gdb tcp::1234 -S -kernel thumb2_practice.bin

clean:
	rm -rf *.o *.elf *.bin

