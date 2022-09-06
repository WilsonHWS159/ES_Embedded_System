#include <stdint.h>
#include "reg.h"
#include "blink.h"

int main(void)
{
	//RCC Enable GPIOA
	??????

	//GPIO Configurations
	??????

	//RCC Enable SYSCFG
	??????

	//SYSCFG Configurations
	??????

	//EXTI Configurations
	??????

	//NVIC Configurations
	SET_BIT(NVIC_ISER_BASE + NVIC_ISERn_OFFSET(0), 6); //IRQ6

	blink(LED_BLUE);
}

void exti0_handler(void)
{
	blink_count(LED_ORANGE, 10);

	//clear pending
	SET_BIT(EXTI_BASE + EXTI_PR_OFFSET, 0);
}
