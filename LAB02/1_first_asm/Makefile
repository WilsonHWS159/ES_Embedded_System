CROSS-COMPILER = arm-none-eabi-

all: first_asm.elf

first_asm.elf: first_asm.s
	$(CROSS-COMPILER)gcc -mcpu=cortex-m4 -nostartfiles -Ttext=0x0 first_asm.s -o first_asm.elf
	$(CROSS-COMPILER)objdump -D first_asm.elf

clean:
	rm -rf *.o *.elf
