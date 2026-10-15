.syntax unified
.cpu cortex-m0plus
.thumb
.text
.balign 4

.global gp2_high
.type gp2_high, %function
.thumb_func
gp2_high:
    ldr  r0, =0xD0000014    @ GPIO_OUT_SET address
    movs r1, #4             @ Bit 2 mask: 1 << 2
    str  r1, [r0]           @ Write the mask to GPIO_OUT_SET
    bx   lr                 @ Return to the caller
.size gp2_high, .-gp2_high

.global gp2_low
.type gp2_low, %function
.thumb_func
gp2_low:
    ldr  r0, =0xD0000018    @ GPIO_OUT_CLR address
    movs r1, #4             @ Same bit 2 mask
    str  r1, [r0]           @ Write the mask to GPIO_OUT_CLR
    bx   lr
.size gp2_low, .-gp2_low

.global gp2_enable_output
.type gp2_enable_output, %function
.thumb_func
gp2_enable_output:
    ldr  r0, =0xD0000024    @ GPIO_OE_SET address
    movs r1, #4             @ GP2 bit mask
    str  r1, [r0]           @ Enable GP2 output
    bx   lr                 @ Return to C
.size gp2_enable_output, .-gp2_enable_output

.global gp2_init_low
.type gp2_init_low, %function
.thumb_func
gp2_init_low:
    ldr  r0, =0xD0000018    @ GPIO_OUT_CLR address
    movs r1, #4             @ GP2 bit mask
    str  r1, [r0]           @ Set GP2 output latch LOW
    bx   lr                 @ Return to C
.size gp2_init_low, .-gp2_init_low

.global gp2_select_sio
.type gp2_select_sio, %function
.thumb_func
gp2_select_sio:
    ldr  r0, =0x40014014    @ IO_BANK0_GPIO2_CTRL
    movs r1, #5             @ FUNCSEL = SIO (00101)
    str  r1, [r0]           @ Select SIO for GP2
    bx   lr
.size gp2_select_sio, .-gp2_select_sio

.ltorg