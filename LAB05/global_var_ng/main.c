#include "blink.h"

int main(void)
{
	blink_count(LED_GREEN, 10);
	blink_count(LED_ORANGE, 10);
	blink_count(LED_RED, 10);
	blink(LED_BLUE);
}
