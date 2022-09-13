#include <stdint.h>
#include <stdio.h>
#include "reg.h"
#include "blink.h"
#include "usart.h"
#include "asm_func.h"

void user_task(void);
void set_mpu(void);

int main(void)
{
	extern uint32_t _msp_init;

	uint32_t *msp_init = &_msp_init;
	uint32_t *psp_init = msp_init - 8 * 1024;

	init_usart1();

	printf("[Kernel] Start in privileged thread mode (msp_init = 0x%x).\r\n\n", (unsigned int)msp_init);

	printf("[Kernel] Control: 0x%x \r\n", (unsigned int)read_ctrl());
	printf("[Kernel] SP: 0x%x \r\n", (unsigned int)read_sp());
	printf("[Kernel] MSP: 0x%x \r\n", (unsigned int)read_msp());
	printf("[Kernel] PSP: 0x%x \r\n\n", (unsigned int)read_psp());

	set_mpu();

	printf("[Kernel] Switch to unprivileged thread mode & start user task (psp_init = 0x%x).\r\n\n", (unsigned int)psp_init);

	//start user task
	??????

	while (1) //should not go here
		;
}

void user_task(void)
{
	printf("[User] Try to print something.\r\n\n");
	blink(LED_BLUE); //should not return
}

void set_mpu(void)
{
	//set region 0: flash (0x00000000), 1MB, allow execution, full access, enable all subregion
	??????

	//set region 1: sram (0x20000000), 128KB, forbid execution, full access, enable all subregion
	??????

	//set region 2: RCC_AHB1ENR, 32B, forbid execution, full access, enable all subregion
	??????

	//set region 3: GPIOD, 32B, forbid execution, full access, enable all subregion
	??????

	//disable region 4 ~ 7
	for (??????)
	{
		??????
	}

	//enable the default memory map as a background region for privileged access (PRIVDEFENA)
	??????

	//enable mpu
	??????
}
