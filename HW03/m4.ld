SECTIONS
{
	. = 0x0;
	.mytext :
	{
		KEEP(*(.vector_table))
		*(.text)
	}
}