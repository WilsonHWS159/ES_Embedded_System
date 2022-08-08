CROSS-COMPILER = arm-none-eabi-

all: test.elf

test.elf: test.c
	$(CROSS-COMPILER)gcc -O1 -Wall -std=c11 -mcpu=cortex-m4 -mthumb -nostartfiles -T empty.ld test.c -o test.elf
	$(CROSS-COMPILER)objdump -D test.elf

clean:
	rm -f *.o *.elf
