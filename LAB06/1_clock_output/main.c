#include <stdint.h>
#include "reg.h"
#include "blink.h"

void op_sysclk(unsigned int div);

int main(void)
{
	op_sysclk(1);
	blink(LED_BLUE);
}

/**
 * 
 * output sysclk (PC9)
 * 
 */
void op_sysclk(unsigned int div)
{
	//RCC
	CLEAR_BIT(RCC_BASE + RCC_CFGR_OFFSET, MCO2_1_BIT);
	CLEAR_BIT(RCC_BASE + RCC_CFGR_OFFSET, MCO2_0_BIT);

	if (div == 1)
		CLEAR_BIT(RCC_BASE + RCC_CFGR_OFFSET, MCO2PRE_2_BIT);

	else if (div >= 2 && div <= 5)
	{
		SET_BIT(RCC_BASE + RCC_CFGR_OFFSET, MCO2PRE_2_BIT);
		REG(RCC_BASE + RCC_CFGR_OFFSET) &= ~(((uint32_t)0b11) << (MCO2PRE_0_BIT)) | ((uint32_t)(div - 2) << (MCO2PRE_0_BIT));
	}
	else
		while(1)
			;

	SET_BIT(RCC_BASE + RCC_AHB1ENR_OFFSET, GPIO_EN_BIT(GPIO_PORTC));

	//GPIO MODER
	SET_BIT(GPIO_BASE(GPIO_PORTC) + GPIOx_MODER_OFFSET, MODERy_1_BIT(9));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTC) + GPIOx_MODER_OFFSET, MODERy_0_BIT(9));
	
	//Output push-pull
	CLEAR_BIT(GPIO_BASE(GPIO_PORTC) + GPIOx_OTYPER_OFFSET, OTy_BIT(9));

	//OSPEEDR9 = 11 => Very high speed
	SET_BIT(GPIO_BASE(GPIO_PORTC) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_1_BIT(9));
	SET_BIT(GPIO_BASE(GPIO_PORTC) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_0_BIT(9));

	//PUPDR9 = 00 => No pull-up, pull-down
	CLEAR_BIT(GPIO_BASE(GPIO_PORTC) + GPIOx_PUPDR_OFFSET, PUPDRy_1_BIT(9));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTC) + GPIOx_PUPDR_OFFSET, PUPDRy_0_BIT(9));
}
