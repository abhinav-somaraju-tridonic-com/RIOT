/*
 * Linker script for ST STM32F303VC 
 */



/* define the entry point for the controller (calling the start-up code) */
ENTRY (reset_handler)

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
    /* definition of the text section */
    .text :
    {
        KEEP(*(.text.isr_vector))
        . = ALIGN(4);
        *(.text)
        *(.text*)
        *(.rodata)
        *(.rodata*)
        *(.glue_7)              /* ARM thumb helper code */
        *(.glue_7t)             /* ARM 32 helper code */
        *(.eh_frame)            /* gcc exception stack unwind information */
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
        . = ALIGN(4);
        _bss_begin = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _bss_end = .;
    } > ram

    /* definition of the stack memory */

    _stack_end = ORIGIN(ram) + LENGTH(ram);

}