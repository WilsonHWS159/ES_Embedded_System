#include <stdint.h>
#include "reg.h"

void init_usart1(void)
{
	//PB6 PB7

	//RCC EN GPIOB
	??????

	//GPIO Configurations
	??????

	//RCC EN USART1
	??????

	//Baud
	const unsigned int BAUD = 115200;
	const unsigned int SYSCLK_MHZ = 168;
	const double USARTDIV = SYSCLK_MHZ * 1.0e6 / 16 / BAUD;

	const uint32_t DIV_MANTISSA = ??????
	const uint32_t DIV_FRACTION = ??????

	//USART  Configurations
	??????

}

void usart1_send_char(const char ch)
{
	??????
}

char usart1_receive_char(void)
{
	??????
}

int main(void)
{
	init_usart1();

	char *hello = "Hello world!\r\n";

	//send Hello world
	while (*hello != '\0')
		usart1_send_char(*hello++);


	//receive char and resend it
	char ch;
	while (1)
	{
		ch = usart1_receive_char();

		if (ch == '\r')
			usart1_send_char('\n');

		usart1_send_char(ch);
	}
}
