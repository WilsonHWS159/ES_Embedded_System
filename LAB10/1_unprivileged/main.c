#include <stdint.h>
#include <stdio.h>
#include "reg.h"
#include "blink.h"
#include "usart.h"
#include "asm_func.h"

void user_task(void);

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

	printf("[Kernel] Switch to unprivileged thread mode & start user task (psp_init = 0x%x).\r\n\n", (unsigned int)psp_init);

	//start user task
	??????

	while (1) //should not go here
		;
}

void user_task(void)
{
	printf("[User] Start in unprivileged thread mode.\r\n\n");

	printf("[User] Control: 0x%x \r\n", (unsigned int)read_ctrl());
	printf("[User] SP: 0x%x \r\n", (unsigned int)read_sp());
	printf("[User] MSP: 0x%x \r\n", (unsigned int)read_msp());
	printf("[User] PSP: 0x%x \r\n\n", (unsigned int)read_psp());

	printf("[User] Switch to privileged thread mode by writing the control register directly. (forbidden)\r\n\n");

	sw_priv();

	printf("[User] Control: 0x%x \r\n", (unsigned int)read_ctrl());
	printf("[User] SP: 0x%x \r\n", (unsigned int)read_sp());
	printf("[User] MSP: 0x%x \r\n", (unsigned int)read_msp());
	printf("[User] PSP: 0x%x \r\n\n", (unsigned int)read_psp());

	blink(LED_BLUE); //should not return
}
