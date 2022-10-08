#ifndef REG_H
#define REG_H

//REG OPERATIONS
#define UINT32_1 ((uint32_t)1)

#define REG(addr) (*((volatile uint32_t *)(addr)))

#define CLEAR_MASK(highest_bit, lowest_bit) (((highest_bit) - (lowest_bit)) >= 31 ? (uint32_t)0xFFFFFFFF : ~(((UINT32_1 << ((highest_bit) - (lowest_bit) + 1)) - 1) << (lowest_bit)))
#define WRITE_BITS(addr, highest_bit, lowest_bit, data) (REG(addr) = (REG(addr) & CLEAR_MASK(highest_bit, lowest_bit)) | ((uint32_t)(data) << (lowest_bit)))

#define SET_BIT(addr, bit) (REG(addr) |= UINT32_1 << (bit))
#define CLEAR_BIT(addr, bit) (REG(addr) &= ~(UINT32_1 << (bit)))

#define READ_BIT(addr, bit) ((REG(addr) >> (bit)) & UINT32_1)

//FLASH
#define FLASH_BASE 0x40023C00

#define FLASH_ACR_OFFSET 0x00
#define PRFTEN_BIT 8
#define LATENCY_2_BIT 2
#define LATENCY_0_BIT 0

//RCC
#define RCC_BASE 0x40023800

#define RCC_CR_OFFSET 0x00
#define PLLRDY_BIT 25
#define PLLON_BIT 24
#define HSERDY_BIT 17
#define HSEON_BIT 16

#define RCC_PLLCFGR_OFFSET 0x04

#define PLLSRC_BIT 22

#define PLLP_1_BIT 17
#define PLLP_0_BIT 16

#define PLLN_8_BIT 14
#define PLLN_0_BIT 6

#define PLLM_5_BIT 5
#define PLLM_0_BIT 0

#define RCC_CFGR_OFFSET 0x08
#define MCO2_1_BIT 31
#define MCO2_0_BIT 30

#define MCO2PRE_2_BIT 29
#define MCO2PRE_0_BIT 27

#define SWS_1_BIT 3
#define SWS_0_BIT 2

#define SW_1_BIT 1
#define SW_0_BIT 0

#define RCC_AHB1ENR_OFFSET 0x30
#define GPIO_EN_BIT(port) (port)

#define RCC_APB2ENR_OFFSET 0x44
#define SYSCFGEN_BIT 14
#define USART1EN 4

//GPIO
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3

#define GPIO_BASE(port) (0x40020000 + 0x400 * (port))

#define GPIOx_MODER_OFFSET 0x00
#define MODERy_1_BIT(y) ((y)*2 + 1)
#define MODERy_0_BIT(y) ((y)*2)

#define GPIOx_OTYPER_OFFSET 0x04
#define OTy_BIT(y) (y)

#define GPIOx_OSPEEDR_OFFSET 0x08
#define OSPEEDRy_1_BIT(y) ((y)*2 + 1)
#define OSPEEDRy_0_BIT(y) ((y)*2)

#define GPIOx_PUPDR_OFFSET 0x0C
#define PUPDRy_1_BIT(y) ((y)*2 + 1)
#define PUPDRy_0_BIT(y) ((y)*2)

#define GPIOx_BSRR_OFFSET 0x18
#define BRy_BIT(y) ((y) + 16)
#define BSy_BIT(y) (y)

#define GPIOx_AFRL_OFFSET 0x20
#define AFRLy_3_BIT(y) ((y)*4 + 3)
#define AFRLy_0_BIT(y) ((y)*4)

//EXTI
#define EXTI_BASE 0x40013C00

#define EXTI_IMR_OFFSET 0x00

#define EXTI_RTSR_OFFSET 0x08

#define EXTI_FTSR_OFFSET 0x0C

#define EXTI_PR_OFFSET 0x14

//SYSCFG
#define SYSCFG_BASE 0x40013800

#define SYSCFG_EXTICR1_OFFSET 0x08

#define EXTI0_3_BIT 3
#define EXTI0_0_BIT 0

//USART1
#define USART1_BASE 0x40011000

#define USART_SR_OFFSET 0x00
#define TXE_BIT 7
#define TC_BIT 6
#define RXNE_BIT 5
#define ORE_BIT 3

#define USART_DR_OFFSET 0x04

#define USART_BRR_OFFSET 0x08
#define DIV_MANTISSA_11_BIT 15
#define DIV_MANTISSA_0_BIT 4
#define DIV_FRACTION_3_BIT 3
#define DIV_FRACTION_0_BIT 0

#define USART_CR1_OFFSET 0x0C
#define UE_BIT 13
#define RXNEIE_BIT 5
#define TE_BIT 3
#define RE_BIT 2

//NVIC
#define NVIC_ISER_BASE 0xE000E100

#define NVIC_ISERn_OFFSET(n) (0x00 + 4 * (n))

#endif