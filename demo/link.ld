/* 定义内存区域 */
MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 32k  /* 32K闪存 */
  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 8k    /* 8K内存 */
}

ENTRY(__vectors)    /* 定义程序入口点 */

SECTIONS  /* 定义段 */
{
  .text :  /* 代码段 */
  {
    KEEP(*(.isr_vector))   /* 中断向量表 */
    *(.text*)              /* 代码段 */
    *(.rodata*)            /* 只读数据段 */
    KEEP(*(.init))         /* 初始化代码 */
    KEEP(*(.fini))         /* 终止代码 */
  } > FLASH AT > FLASH

  /* 初始化数据段 */
  .data : 
  {
    . = ALIGN(3); 
    _sdata = .;            /* 数据段开始 */
    *(.data*)              /* 数据段内容 */
    . = ALIGN(3);          /* 对齐到4字节边界 */
    _edata = .;            /* 数据段结束 */
  } > FLASH AT > FLASH

  /* 未初始化数据段 */
  .bss :
  {
    _sbss = .;             /* BSS段开始 */
    *(.bss*)
    *(COMMON)
    . = ALIGN(3);
    _ebss = .;             /* BSS段结束 */
  } > RAM AT > FLASH

  /* 堆栈段 */
  .stack :
  {
    . = ORIGIN(RAM) + LENGTH(RAM) - stack_size;    /* 将当前位置设置为RAM末尾 */
    . = ALIGN(8);                                  /* 对齐到8字节边界 */
    __stack_mem = .;                               /* 设置栈内存区域开始地址 */
    *(.stack);                 /*. += stack_size;  /* 为栈段分配内存 */*/
    __initial_sp = .;                              /* 设置栈顶指针 */
    . = ALIGN(8);                                  /* 对齐到8字节边界 */
  } > RAM AT > RAM
}
