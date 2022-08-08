CROSS-COMPILER = arm-none-eabi-

all: main.bin

main.bin: main.c blink.c vector_table.s
	$(CROSS-COMPILER)gcc -Wall -std=c11 -mcpu=cortex-m4 -mthumb -nostartfiles -T stm32f4.ld main.c blink.c vector_table.s -o main.elf
	$(CROSS-COMPILER)objcopy -O binary main.elf main.bin

flash:
	st-flash --reset write main.bin 0x8000000

clean:
	rm -f *.o *.elf *.bin
