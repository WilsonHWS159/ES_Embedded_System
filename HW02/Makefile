CROSS-COMPILER = arm-none-eabi-
QEMU = ./gnu-mcu-eclipse-qemu/bin/qemu-system-gnuarmeclipse

all: main.bin

main.bin: main.s
	$(CROSS-COMPILER)gcc -Wall -mcpu=cortex-m4 -nostartfiles -Ttext=0x0 main.s -o main.elf
	$(CROSS-COMPILER)objcopy -O binary main.elf main.bin

qemu:
	@echo
	@echo "Press Ctrl+A and then press X to exit QEMU"
	@echo
	$(QEMU) -M STM32F4-Discovery -nographic -gdb tcp::1234 -S -kernel main.bin

clean:
	rm -rf *.o *.elf *.bin

