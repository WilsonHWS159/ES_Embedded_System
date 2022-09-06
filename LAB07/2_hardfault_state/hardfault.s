.section .vecter_table

.word _msp_init
.word reset_handler
.word nmi_handler
.word hardfault_handler

.section .text

.syntax unified


loop:
	b	.;


init_regs:
	movs	R0,	#0xA0;
	movs	R1,	#0xA1;
	movs	R2,	#0xA2;
	movs	R3,	#0xA3;
	movs	R4,	#0xA4;
	movs	R5,	#0xA5;
	movs	R6,	#0xA6;
	movs	R7,	#0xA7;
	movs	R8,	#0xA8;
	movs	R8,	#0xA8;
	movs	R9,	#0xA9;
	movs	R10,	#0xAA;
	movs	R11,	#0xAB;
	movs	R12,	#0xAC;
	blx	loop;

.type	reset_handler, %function
reset_handler:
	b	init_regs;


.type	nmi_handler, %function
nmi_handler:
	b	.


.type	hardfault_handler, %function
hardfault_handler:
	movs	R0,	#0;
	movs	R1,	#0;
	movs	R2,	#0;
	movs	R3,	#0;
	movs	R4,	#0;
	movs	R5,	#0;
	movs	R6,	#0;
	movs	R7,	#0;
	movs	R8,	#0;
	movs	R8,	#0;
	movs	R9,	#0;
	movs	R10,	#0;
	movs	R11,	#0;
	movs	R12,	#0;
	bx	lr;
