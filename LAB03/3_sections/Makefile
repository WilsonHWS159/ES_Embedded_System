CROSS-COMPILER = arm-none-eabi-

all: sections.elf

sections.elf: sections.c
	$(CROSS-COMPILER)gcc -std=c11 -mcpu=cortex-m4 -mthumb -nostartfiles -T empty.ld sections.c -o sections.elf
	$(CROSS-COMPILER)objdump -D sections.elf

clean:
	rm -rf *.o *.elf

