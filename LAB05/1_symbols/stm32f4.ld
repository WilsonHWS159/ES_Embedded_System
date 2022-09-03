MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 1M
	SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
	.mytext :
	{
		KEEP(*(.vector_table))
		*(.text)
		_mydata_lma_start = .;
	} > FLASH

	.mydata : AT(_mydata_lma_start)
	{
		_mydata_vma_start = .;
		*(.data)
	} > SRAM

}
