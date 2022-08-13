HW02
===
This is the hw02 sample. Please follow the steps below.

# Build the Sample Program

1. Fork this repo to your own github account.

2. Clone the repo that you just forked.

3. Under the hw02 dir, use:

	* `make` to build.

	* `make clean` to clean the ouput files.

4. Extract `gnu-mcu-eclipse-qemu.zip` into hw02 dir. Under the path of hw02, start emulation with `make qemu`.

	See [Lecture 02 ─ Emulation with QEMU] for more details.

5. The sample is designed to help you to distinguish the main difference between the `b` and the `bl` instructions.  

	See [ESEmbedded_HW02_Example] for knowing how to do the observation and how to use markdown for taking notes.

# Build Your Own Program

1. Edit main.s.

2. Make and run like the steps above.

# HW02 Requirements

1. Please modify main.s to observe the `push` and the `pop` instructions:  

	Does the order of the registers in the `push` and the `pop` instructions affect the excution results?  

	For example, will `push {r0, r1, r2}` and `push {r2, r0, r1}` act in the same way?  

	Which register will be pushed into the stack first?

2. You have to state how you designed the observation (code), and how you performed it.  

	Just like how [ESEmbedded_HW02_Example] did.

3. If there are any official data that define the rules, you can also use them as references.

4. Push your repo to your github. (Use .gitignore to exclude the output files like object files or executable files and the qemu bin folder)

[Lecture 02 ─ Emulation with QEMU]: http://www.nc.es.ncku.edu.tw/course/embedded/02/#Emulation-with-QEMU
[ESEmbedded_HW02_Example]: https://github.com/vwxyzjimmy/ESEmbedded_HW02_Example

--------------------

- [x] **If you volunteer to give the presentation next week, check this.**

--------------------

# HW02_Example performed and observation
## Emulation by qemu
`qemu` is defined in `Makefile` that will create a qemu server with port `1234`.
```cmake
qemu:
    @echo
    @echo "Press Ctrl+A and then press X to exit QEMU"
    @echo
    $(QEMU) -M STM32F4-Discovery -nographic -gdb tcp::1234 -S -kernel main.bin
```
1. Use command `make qemu` to start emulation.
```bash
$    make qemu
```
![](https://i.imgur.com/DZ7lRzs.png)

2. Start GNU Debugger with command `arm-none-eabi-gdb`
```bash
$    arm-none-eabi-gdb
```
![](https://i.imgur.com/lOJoTZN.png)

3. Connect to the qemu server by localhost
```bash
(gdb)    target remote 127.0.0.1:1234
```
![](https://i.imgur.com/M6vJXaJ.png)

4. Press `Ctrl + X` two times and show registers with command `layout regs`
```bash
(gdb)    layout regs
```
![](https://i.imgur.com/ZgJ4psd.png)

5. Use `si` or `stepi` to execute one instruction.

## observation
`main.s` is the sample that can help us to distinguish the main difference between the `b` and the `bl` instructions.
```thumb2
.syntax unified

.word 0x20000100
.word _start

.global _start
.type _start, %function
_start:
	nop

	//
	//branch w/o link
	//
	b	label01

label01:
	nop

	//
	//branch w/ link
	//
	bl	sleep

sleep:
	nop
	b	.
```

|label|address|
|:-:|:-:|
|`_start`|`0x8`|
|`label01`|`0xe`|
|`sleep`|`0x12`|

GDB will show the disassembly instructions and the address of these instructions.
![](https://i.imgur.com/zuuILui.png)

When the second instruction (`b    label01`) executed, the `lr` register is still `0`
![](https://i.imgur.com/0gcsUvV.png)

Until the forth instruction (`bl    sleep`) executed, the `lr` register stored `0x13` which is the address of the next instruction of the branch.

The reason of the address is `0x13` instead of `0x12` is the LSB contains the information that the next instrction is a `Thumb-2` instruction.

![](https://i.imgur.com/fjtIRTp.png)

After the sixth instruction (`b    .`) executed, the `lr` register is still `0x13`.
![](https://i.imgur.com/6O96ioG.png)

# HW02 performed and observation

*    Edit `main.s` for observe `push` and `pop` instructions
```Thumb-2
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

```

*    Store `1, 2, 3` into `r0, r1, r2` respectively.

![](https://i.imgur.com/UOkJacH.png)

*    Push the value of `r0, r1, r2` by the order `{r0, r1, r2}` into stack.
        *    Stack pointer `sp` `0x20000100` $\rightarrow$ `0x200000f4`

![](https://i.imgur.com/vS0Ot4n.png)

*    Pop these values out of stack
        *    Stack pointer `sp` `0x200000f4` $\rightarrow$ `0x20000100`
        *    `r3` is `1`
        *    `r4` is `2`
        *    `r5` is `3`

![](https://i.imgur.com/b2mAdwg.png)

*    Push the value of `r0, r1, r2` by the order `{r2, r1, r0}` into stack
In GDB, it shows that the assembler change the order of these registers .automatically.
        *    Stack pointer `sp` `0x20000100` $\rightarrow$ `0x200000f4`

![](https://i.imgur.com/bzZpMfQ.png)

*    Pop these values out of stack
        *    Stack pointer `sp` `0x200000f4` $\rightarrow$ `0x20000100`
        *    `r3` is `1`
        *    `r4` is `2`
        *    `r5` is `3`

![](https://i.imgur.com/TfAV4tc.png)

*    Push the value of `r0, r1, r2` by the order `{r0, r1, r2}`, but only push one value in one instruction
        *    Stack pointer `sp` `0x20000100` $\rightarrow$ `0x200000f4`

![](https://i.imgur.com/QB27Jfs.png)

*    Pop these values out of stack
        *    Stack pointer `sp` `0x200000f4` $\rightarrow$ `0x20000100`
        *    `r3` is `3`
        *    `r4` is `2`
        *    `r5` is `1`

![](https://i.imgur.com/OTVbX2i.png)

*    Push the value of `r0, r1, r2` by the order `{r2, r1, r0}`, but only push one value in one instruction
        *    Stack pointer `sp` `0x20000100` $\rightarrow$ `0x200000f4`

![](https://i.imgur.com/rMK0tP2.png)

*    Pop these values out of stack
        *    Stack pointer `sp` `0x200000f4` $\rightarrow$ `0x20000100`
        *    `r3` is `1`
        *    `r4` is `2`
        *    `r5` is `3`

![](https://i.imgur.com/q7zHLhx.png)

## Conclusion
Let make a sheet to clarify these operations.
||`push {r0, r1, r2}`|`pop`|`push {r2, r1, r0}`|`pop`|`push {r0}, {r1}, {r2}`|`pop`|`push {r2}, {r1}, {r0}`|`pop`|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|**`r3`**||1||1||3||1|
|**`r4`**||2||2||2||2|
|**`r5`**||3||3||1||3|

According to the sheet, it can tells that no matter which registers you put in the brackets, assembler will reorder the sequence to descending order.


