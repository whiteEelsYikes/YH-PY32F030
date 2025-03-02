





.equ stack_size, 0x00001000
.global stack_size
    .section .stack
    .align 3
__stack_mem:
    .global __stack_mem
    .align 3
    .zero stack_size
__initial_sp:
    .align 3
    .global __initial_sp




    .section .isr_vector
    .align 2
__vectors:
    .global __vectors
                .long     __initial_sp              @ Top of Stack
                .long     Reset_Handler+1             @ Reset Handler
                .long     NMI_Handler+1               @ NMI Handler
                .long     HardFault_Handler+1         @ Hard Fault Handler
                .long     0                         @ Reserved
                .long     0                         @ Reserved
                .long     0                         @ Reserved
                .long     0                         @ Reserved
                .long     0                         @ Reserved
                .long     0                         @ Reserved
                .long     0                         @ Reserved
                .long     SVC_Handler               @ SVCall Handler
                .long     0                         @ Reserved
                .long     0                         @ Reserved
                .long     PendSV_Handler            @ PendSV Handler
                .long     SysTick_Handler           @ SysTick Handler



    .section .data
    .align 2
                .equ GPIOA_BASE, 0x50000000UL   // GPIOA ?????
                .global GPIOA_BASE
                .equ RCC_BASE, 0x40021000UL     // RCC ?????
                .equ RCC_IOPENR_OFFSET, 0x34  // RCC IOPENR ????????
                .equ GPIO_MODER_OFFSET, 0x00  // GPIO ??????????
                .equ GPIO_OTYPER_OFFSET, 0x04 // GPIO ??????????????
                .equ GPIO_OSPEEDR_OFFSET, 0x08 // GPIO ?????????????
                .equ GPIO_PUPDR_OFFSET, 0x0C  // GPIO ????/????????????
                .equ GPIO_IDR_OFFSET, 0x10  // GPIO ???????????????
                .equ GPIO_ODR_OFFSET, 0x14  // GPIO ??????????????
                .global GPIO_ODR_OFFSET
                .equ GPIO_BSRR_OFFSET, 0x18   // GPIO ???��????/??��?????
                .equ GPIO_LCKR_OFFSET, 0x1C   // GPIO ????????????????
                .equ GPIO_AFRL_LOW_OFFSET, 0x20  // GPIO ???��???????(low)
                .equ GPIO_AFRL_HIGH_OFFSET, 0x24  // GPIO ???��???????(high)
                .equ GPIO_BRR_OFFSET, 0x28   // GPIO ???��??��?????



    .thumb


    .section .text
    .thumb
    .align 2

Reset_Handler:  @ Reset Handler
    .global  Reset_Handler
    .weak Reset_Handler
    .align 2
                // bkpt #0
                CPSID I // ???????��??????��?
                add r0, r0, #1
                mov r0, #10
                add r1, r0, r0
                ldr r0, =_start+1
                bx R0
                //bkpt #0


.global _start

_start:
    // ??? GPIOA ???
    fail_loop:
    //bkpt #0
    ldr r0, =RCC_BASE + RCC_IOPENR_OFFSET  // RCC IOPENR ????????
    ldr r1, [r0]
    ldr r2, =0x1                // ??????????????? GPIOA ???
    orr r1, r1, r2              // ????��
    str r1, [r0]

    // ?????????
    ldr r1, [r0]
    //ldr r2, =0x1
    tst r1, r2
    beq fail_loop               // ??????��??????????????

    // ???? GPIOA2 ?????????
    ldr r0, =GPIOA_BASE + GPIO_MODER_OFFSET
    ldr r1, [r0]
    ldr r2, =0xEBFFFD5F         // ??????????
    and r1, r1, r2              // ?????��
    ldr r2, =0x10               // ??????????
    orr r1, r1, r2              // ??????????
    str r1, [r0]

    // ???? GPIOA2 ????????
    ldr r0, =GPIOA_BASE + GPIO_OTYPER_OFFSET
    ldr r1, [r0]
    ldr r2, =0x0         // ??????????
    and r1, r1, r2              // ????????????
    str r1, [r0]

    // ???? GPIOA2 ?????????
    ldr r0, =GPIOA_BASE + GPIO_OSPEEDR_OFFSET
    ldr r1, [r0]
    ldr r2, =0x0C0002A0         // ??????????
    str r1, [r0]
    
    
    // ???? GPIOA2 ???????
    ldr r0, =GPIOA_BASE + GPIO_PUPDR_OFFSET
    ldr r1, [r0]
    ldr r2, =0x24000150         // ??????????
    and r1, r1, r2              // ???????/????????
    ldr r2, =0x10               // ??????????
    orr r1, r1, r2              // ?????????
    str r1, [r0]

    // ???? GPIOA2 ??????? (???? LED)
    ldr r0, =GPIOA_BASE + GPIO_BRR_OFFSET
    ldr r1, =0x40000            // ???????????????? GPIOA2 ??��?????
    str r1, [r0]
    .extern main
    //bkpt #0
    ldr r0, =main
    //b main
    //bkpt #0
    // ???????
    mov r0, #0
    .equ count, 1000000
    ldr r2, =count
loop:
    cmp r2, r0
    bcc not_led
    add r0, r0, #1
    b loop
not_led:
    mov r0, #0
    // ???? GPIOA2 ?????? not bi
    ldr r3, =GPIOA_BASE + GPIO_ODR_OFFSET
    ldr r1, [r3]
    mvn r1, r1
    str r1, [r3]
    b loop


@ Dummy Exception Handlers (infinite loops which can be modified)
NMI_Handler:
    .global  NMI_Handler
    .weak NMI_Handler
    .align 2
                bkpt #0
                bx lr

HardFault_Handler:
    .global  HardFault_Handler
    .weak HardFault_Handler
    .align 2
                bkpt #0
                bx lr

SVC_Handler:
    .global  SVC_Handler
    .weak SVC_Handler
    .align 2
                bkpt #0
                bx lr

PendSV_Handler:
    .global  PendSV_Handler
    .weak PendSV_Handler
    .align 2
                bx lr

SysTick_Handler:
    .global  SysTick_Handler
    .weak SysTick_Handler
    .align 2
                bx lr
