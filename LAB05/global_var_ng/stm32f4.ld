MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 1M
}

SECTIONS
{
	.mytext :
	{
		KEEP(*(.vector_table))
		*(.text)
	} > FLASH
}