.syntax unified

.global	read_sp
read_sp:
	mov		r0, sp
	bx		lr

.global	read_msp
read_msp:
	mrs		r0, msp
	bx		lr

.global	read_psp
read_psp:
	mrs		r0, psp
	bx		lr

.global	read_ctrl
read_ctrl:
	mrs		r0, control
	bx		lr

.global	start_user
start_user:
	movs	lr,	r0
	msr	psp,	r1

	movs	r3,	#0x3
	msr	control,	r3
	isb

	bx	lr

.global	sw_priv
sw_priv:
	mov		r0, 0x2
	msr		control, r0
	ISB
	bx		lr
