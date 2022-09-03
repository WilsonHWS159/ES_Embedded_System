#include <stdint.h>

uint32_t global_var = 0x1234;

extern uint32_t _mydata_lma_start;
extern uint32_t _mydata_vma_start;

void symbols(void)
{
	uint32_t *sram_debug = (uint32_t *)0x20000200;

	sram_debug[0] = 0xAAAA;

	sram_debug[1] = global_var;
	sram_debug[2] = (uint32_t)&global_var;

	sram_debug[3] = _mydata_lma_start;
	sram_debug[4] = (uint32_t)&_mydata_lma_start;

	sram_debug[5] = _mydata_vma_start;
	sram_debug[6] = (uint32_t)&_mydata_vma_start;

	while (1)
		;
}
