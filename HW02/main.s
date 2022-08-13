.syntax unified

.word 0x20000100
.word _start

.global _start
.type _start, %function

_start:
    
    movs    r0, #1
    movs    r1, #2
    movs    r2, #3

    push    {r0, r1, r2}
    pop     {r3, r4, r5}

    push    {r2, r1, r0}
    pop     {r3, r4, r5}
    
    push    {r0}
    push    {r1}
    push    {r2}
    pop     {r3, r4, r5}
    
    push    {r2}
    push    {r1}
    push    {r0}
    pop     {r3, r4, r5}
    
    b       sleep

sleep:
    b       .
