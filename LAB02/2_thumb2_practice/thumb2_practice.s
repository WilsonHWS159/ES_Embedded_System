.syntax unified

.word 0x20000100
.word _start

.global _start
.type _start, %function
_start:
	//
	//mov # to reg
	//
	movs	r0,	#100
	movs	r1,	#0x11000000
	mov	r2,	#102
	movw	r3,	#103

	//
	//mov reg to reg
	//
	movs	r4,	r0
	mov	r5,	r1

	//
	//add
	//
	adds	r4,	r1,	#1
	add	r5,	r4,	#5

	//
	//push
	//
	push	{r0}
	push	{r1, r2, r3, r4}


	//
	//pop
	//
	pop	{r4, r5, r6, r7}
	pop	{r3}


	//
	//ldr
	//
	movs	r0,	#0x0
	ldr	r1,	[r0]
	ldr	r2,	[r0, #4]

	//
	//str
	//
	movs	r0,	#0x20000000
	str	r1,	[r0]
	str	r2,	[r0, #4]

	//
	//b bl
	//
	bl	label01

sleep:
	b	sleep

label01:
	nop
	nop
	bx	lr
