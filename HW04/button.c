#ifndef REG_H

#include <stdint.h>
#include "reg.h"

#endif

void button_init(uint8_t button)
{
    SET_BIT(RCC_BASE + RCC_AHB1ENR_OFFSET, GPIO_EN_BIT(GPIO_PORTA));

    //MODER button pin = 00 => General purpose input mode
    CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_MODER_OFFSET, MODERy_1_BIT(button));
    CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_MODER_OFFSET, MODERy_0_BIT(button));

    //OT button pin = x => don't care

    //OSPEEDR button pin = xx => don't care

    //PUPDR button pin = 10 => pull-down
    SET_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_PUPDR_OFFSET, PUPDRy_1_BIT(button));
    CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_PUPDR_OFFSET, PUPDRy_0_BIT(button));
}

_Bool button_status(uint8_t button)
{
    return READ_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_IDR_OFFSET, IDRy_BIT(button));
}
