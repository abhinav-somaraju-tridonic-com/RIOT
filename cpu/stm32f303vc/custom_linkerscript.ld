/*
 * Linker script for ST STM32F303VC 
 */


/*
 * Memory sections for the STM32F303VC:
 * - 256K flash
 * - 48K RAM (of which 8kB are CCM RAM and 40KB are SRAM). 
 */
MEMORY
{
    flash (rx)      : ORIGIN = 0x08000000, LENGTH = 256K
    ram (rwx)       : ORIGIN = 0x20000000, LENGTH = 40K
    ccmram (rwx)    : ORIGIN = 0x10000000, LENGTH = 8K
}


SECTIONS
{
    /* put the isr-vector up front */
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > flash
    
    /* definition of the text section */
    .text :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        *(.text)
        *(.text*)
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
        _data_flash = .;
    } > flash

    /* definition of the data section */
    .data : AT(_data_flash)
    {
        . = ALIGN(4);
        _data_begin = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _data_end = .;
    } > ram

    /* definition of the bss section */
    .bss :
    {
        _bss_begin = .;
        __bss_start__ = _bss_begin;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _bss_end = .;
        __bss_end__ = _bss_end;
    } > ram

    /* definition of the stack memory */
    _stack_size = 10024;                             /* TODO: stack should take all of the remaining memory!!! */
    _stack_end = ORIGIN(ram) + LENGTH(ram);
    _stack_begin = _stack_end - _stack_size;
    . = _stack_begin;
    ._stack :
    {
        . = . + _stack_size;
    } > ram
}

/* define the entry point for the controller (calling the start-up code) */
ENTRY (reset_handler)