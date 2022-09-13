CROSS-COMPILER = arm-none-eabi-

all: unprivileged.bin

unprivileged.bin: main.c newlib_port.c usart.c blink.c startup.c vector_table.s asm_func.s
	$(CROSS-COMPILER)gcc -std=c11 -Wall -mcpu=cortex-m4 -mthumb -nostartfiles -T stm32f4.ld main.c newlib_port.c usart.c blink.c startup.c vector_table.s asm_func.s -o unprivileged.elf
	$(CROSS-COMPILER)objcopy -O binary unprivileged.elf unprivileged.bin

flash:
	st-flash --reset write unprivileged.bin 0x8000000

clean:
	rm -f *.o *.elf *.bin
