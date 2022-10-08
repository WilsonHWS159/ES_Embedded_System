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

	printf("[Kernel] Start in privileged thread mode.\r\n\n");

	printf("[Kernel] Control: 0x%X \r\n", (unsigned int)read_ctrl());
	printf("[Kernel] SP: 0x%X \r\n", (unsigned int)read_sp());
	printf("[Kernel] MSP: 0x%X \r\n", (unsigned int)read_msp());
	printf("[Kernel] PSP: 0x%X \r\n\n", (unsigned int)read_psp());

	printf("[Kernel] SVC.\r\n\n");
	sys_call();
	printf("[Kernel] SVC return.\r\n\n");

	printf("[Kernel] Switch to unprivileged thread mode & start user task with psp.\r\n\n");

	//start user task
	start_user((uint32_t *)user_task, psp_init);

	while (1) //should not go here
		;
}

void user_task(void)
{
	printf("[User] Start in unprivileged thread mode.\r\n\n");

	printf("[User] Control: 0x%X \r\n", (unsigned int)read_ctrl());
	printf("[User] SP: 0x%X \r\n", (unsigned int)read_sp());
	printf("[User] MSP: 0x%X \r\n", (unsigned int)read_msp());
	printf("[User] PSP: 0x%X \r\n\n", (unsigned int)read_psp());

	printf("[User] SVC.\r\n\n");
	sys_call();
	printf("[User] SVC return.\r\n\n");

	blink(LED_BLUE); //should not return
}

void svc_handler_c(??????)
{
	printf("[SVC Handler] LR: 0x%X\r\n", (unsigned int)??????);
	printf("[SVC Handler] Control: 0x%X\r\n", (unsigned int)read_ctrl());
	printf("[SVC Handler] SP: 0x%X \r\n", (unsigned int)read_sp());
	printf("[SVC Handler] MSP: 0x%X \r\n", (unsigned int)read_msp());
	printf("[SVC Handler] PSP: 0x%X \r\n\n", (unsigned int)read_psp());
}
