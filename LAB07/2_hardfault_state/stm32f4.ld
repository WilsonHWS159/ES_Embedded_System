MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 1M
	SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
	.mytext :
	{
		KEEP(*(.vecter_table))
		*(.text)
	} > FLASH

	_msp_init = ORIGIN(SRAM) + LENGTH(SRAM);
}