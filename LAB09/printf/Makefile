CROSS-COMPILER = arm-none-eabi-

all: printf.bin

printf.bin: main.c blink.c startup.c vector_table.s
	$(CROSS-COMPILER)gcc -std=c11 -Wall -mcpu=cortex-m4 -mthumb -nostartfiles -T stm32f4.ld main.c blink.c startup.c vector_table.s -o printf.elf
	$(CROSS-COMPILER)objcopy -O binary printf.elf printf.bin

flash:
	st-flash --reset write printf.bin 0x8000000

clean:
	rm -f *.o *.elf *.bin
