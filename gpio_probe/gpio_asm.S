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

.ltorg