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
		*(.text.*)
		*(.rodata)
		*(.rodata.*)
	} > FLASH

	.eh_frame :
	{
		*(.eh_frame)
	} > FLASH

	.ARM.exidx :
	{
		*(.ARM.exidx)
		_mydata_lma_start = .; /* LMA is equivalent to VMA in this section */
	} > FLASH

	.mydata : AT(_mydata_lma_start) /* tell linker whrere (LMA) this section should be put at */
	{
		_mydata_vma_start = .;
		*(.data)
		*(.data.*)
		_mydata_vma_end = .;
	} > SRAM

	.mybss :
	{
		_mybss_vma_start = .;
		*(.bss)
		*(.bss.*)
		*(COMMON)
		_mybss_vma_end = .;
	} > SRAM
	
	_msp_init = ORIGIN(SRAM) + LENGTH(SRAM);
}