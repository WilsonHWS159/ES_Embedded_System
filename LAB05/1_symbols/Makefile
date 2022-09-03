CROSS-COMPILER = arm-none-eabi-

all: symbols.bin

symbols.bin: symbols.c vector_table.s
	$(CROSS-COMPILER)gcc -Wall -std=c11 -mcpu=cortex-m4 -mthumb -nostartfiles -T stm32f4.ld symbols.c vector_table.s -o symbols.elf
	$(CROSS-COMPILER)objcopy -O binary symbols.elf symbols.bin

flash:
	st-flash --reset write symbols.bin 0x8000000

clean:
	rm -f *.o *.elf *.bin
