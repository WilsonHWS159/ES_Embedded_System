.section .vector_table

.word _msp_init
.word reset_handler
.word nmi_handler
.word hardfault_handler
