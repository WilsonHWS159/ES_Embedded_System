#include <stdint.h>

int test_volatile(void)
{
	volatile uint32_t *reg_a = (uint32_t *)0x40023800;

	uint32_t val1;
	uint32_t val2;

	val1 = *reg_a;

	val2 = *reg_a;

	if (val1 == val2)
		return 0;

	return 1;
}