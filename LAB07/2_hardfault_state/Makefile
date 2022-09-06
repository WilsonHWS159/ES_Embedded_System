CROSS-COMPILER = arm-none-eabi-

all: hardfault.bin

hardfault.bin: hardfault.s
	$(CROSS-COMPILER)gcc -std=c11 -Wall -mcpu=cortex-m4 -mthumb -nostartfiles -T stm32f4.ld hardfault.s -o hardfault.elf
	$(CROSS-COMPILER)objcopy -O binary hardfault.elf hardfault.bin

flash:
	st-flash --reset write hardfault.bin 0x8000000

clean:
	rm -f *.o *.elf *.bin
