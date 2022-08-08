.syntax unified

.word 0x20000100
.word _start

.global _start
.type _start, %function
_start:
	b	mymain
