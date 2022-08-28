#include "blink.h"
#include "button.h"

/* initial configuration of leds and button GPIO */
void init()
{
    led_init(LED_BLUE);
    button_init(BUTTON_USR);
}

int main(void)
{
	init();
    while (!button_status(BUTTON_USR));
    blink(LED_BLUE);
}
