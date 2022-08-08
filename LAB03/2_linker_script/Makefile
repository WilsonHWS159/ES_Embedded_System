CROSS-COMPILER = arm-none-eabi-

all: simple.elf

simple.elf: simple.c vector_table.s
	$(CROSS-COMPILER)gcc -Wall -std=c11 -mcpu=cortex-m4 -mthumb -nostartfiles -T m4.ld simple.c vector_table.s -o simple.elf
	$(CROSS-COMPILER)objdump -D simple.elf

clean:
	rm -rf *.o *.elf

