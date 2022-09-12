#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "blink.h"
#include "reg.h"

#undef errno
#define HEAP_MAX (65536) // 64KB

const char *reset_msg = "Hello, world!\r\n";
const char *ore_msg = "Overrun !!!\r\n";

void *_sbrk(int incr)
{
	extern uint8_t _mybss_vma_end;
	static uint8_t *heap_end = NULL;
	uint8_t *prev_heap_end;

	if (heap_end == NULL)
		heap_end = &_mybss_vma_end;

	prev_heap_end = heap_end;
	if (heap_end + incr > &_mybss_vma_end + HEAP_MAX)
		return (void *) -1;
	
	heap_end += incr;
	return (void *) prev_heap_end;
}

void _exit() {}

int _write(int file, char *ptr, int len)
{
	for (uint32_t i = 0; i < len; i++)
		usart1_send_char(*ptr++);
	return len;
}

int _close(int file)
{
	return -1;
}

int _lseek(int file, int ptr, int dir)
{
	return 0;
}

int _read(int file, char *ptr, int len)
{
	return 0;
}

int _fstat(int file, struct stat *st)
{
	st->st_mode = S_IFCHR;
	return 0;
}

int _isatty(int file)
{
	return 1;
}

extern int errno;
int _kill(int pid, int sig)
{
	errno = EINVAL;
	return -1;
}

int _getpid(void)
{
	return 1;
}

void init_usart1(void)
{
	//PB6 PB7

	//RCC EN GPIOB
	SET_BIT(RCC_BASE + RCC_AHB1ENR_OFFSET, GPIO_EN_BIT(GPIO_PORTB));

	//GPIO Configurations
	SET_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_MODER_OFFSET, MODERy_1_BIT(6));
	SET_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_MODER_OFFSET, MODERy_1_BIT(7));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_MODER_OFFSET, MODERy_0_BIT(6));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_MODER_OFFSET, MODERy_0_BIT(7));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_OTYPER_OFFSET, OTy_BIT(6));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_OTYPER_OFFSET, OTy_BIT(7));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_1_BIT(6));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_1_BIT(7));
	SET_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_0_BIT(6));
	SET_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_0_BIT(7));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_PUPDR_OFFSET, PUPDRy_1_BIT(6));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_PUPDR_OFFSET, PUPDRy_1_BIT(7));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_PUPDR_OFFSET, PUPDRy_0_BIT(6));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTB) + GPIOx_PUPDR_OFFSET, PUPDRy_0_BIT(7));
	WRITE_BITS(GPIO_BASE(GPIO_PORTB) + GPIOx_AFRL_OFFSET, AFRLy_3_BIT(6), AFRLy_0_BIT(6), 0x7);
	WRITE_BITS(GPIO_BASE(GPIO_PORTB) + GPIOx_AFRL_OFFSET, AFRLy_3_BIT(7), AFRLy_0_BIT(7), 0x7);
	

	//RCC EN USART1
	SET_BIT(RCC_BASE + RCC_APB2ENR_OFFSET, USART1EN);

	//Baud
	const unsigned int BAUD = 115200;
	const unsigned int SYSCLK_MHZ = 168;
	const double USARTDIV = SYSCLK_MHZ * 1.0e6 / 16 / BAUD;

	const uint32_t DIV_MANTISSA = (uint32_t) USARTDIV;
	const uint32_t DIV_FRACTION = (uint32_t) (((USARTDIV - DIV_MANTISSA) * 16) + 0.5);

	//USART  Configurations
	SET_BIT(USART1_BASE + USART_CR1_OFFSET, UE_BIT);
	WRITE_BITS(USART1_BASE + USART_BRR_OFFSET, DIV_MANTISSA_11_BIT, DIV_MANTISSA_0_BIT, DIV_MANTISSA);
	WRITE_BITS(USART1_BASE + USART_BRR_OFFSET, DIV_FRACTION_3_BIT, DIV_FRACTION_0_BIT, DIV_FRACTION);
	SET_BIT(USART1_BASE + USART_CR1_OFFSET, TE_BIT);
	SET_BIT(USART1_BASE + USART_CR1_OFFSET, RE_BIT);
	SET_BIT(USART1_BASE + USART_CR1_OFFSET, RXNEIE_BIT);
	SET_BIT(NVIC_ISER_BASE + NVIC_ISERn_OFFSET(1), 5);
}

void usart1_send_char(const char ch)
{
	for (; !READ_BIT(USART1_BASE + USART_SR_OFFSET, TXE_BIT););
	WRITE_BITS(USART1_BASE + USART_DR_OFFSET, 0x8, 0x0, ch);
}

char usart1_receive_char(void)
{
	return (char) REG(USART1_BASE + USART_DR_OFFSET);
}

void usart1_handler()
{
	if (READ_BIT(USART1_BASE + USART_SR_OFFSET, ORE_BIT)) {
		for (char *p = ore_msg; *p != '\0';)
			usart1_send_char(*p++);
		blink_count(LED_RED, 1);
	} else if (READ_BIT(USART1_BASE + USART_SR_OFFSET, RXNE_BIT)) {
		char ch = usart1_receive_char();
		if (ch == '\r')
			usart1_send_char('\n');
		usart1_send_char(ch);
		blink_count(LED_BLUE, 1);
	}
}

int main(void)
{
	init_usart1();

	printf("Hello World!!!\r\n");

	int i = 75;
	printf("Decimal : %d, Hexadecimal : 0x%x\r\n", i, i);
	printf("Character : %c\r\n", i);

	blink(LED_GREEN);
}
