CROSS-COMPILER = arm-none-eabi-

all: mpu.bin

mpu.bin: main.c newlib_port.c usart.c blink.c startup.c vector_table.s asm_func.s
	$(CROSS-COMPILER)gcc -std=c11 -Wall -mcpu=cortex-m4 -mthumb -nostartfiles -T stm32f4.ld main.c newlib_port.c usart.c blink.c startup.c vector_table.s asm_func.s -o mpu.elf
	$(CROSS-COMPILER)objcopy -O binary mpu.elf mpu.bin

flash:
	st-flash --reset write mpu.bin 0x8000000

clean:
	rm -f *.o *.elf *.bin
