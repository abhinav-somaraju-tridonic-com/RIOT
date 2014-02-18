
extern void board_init(void);
extern void kernel_init(void);

extern unsigned int _data_flash;
extern unsigned int _data_begin;
extern unsigned int _data_end;
extern unsigned int _bss_begin;
extern unsigned int _bss_end;
extern unsigned int _stack_end;


void reset_handler(void)
{
    unsigned int *src;
    unsigned int *dst;

    src = &_data_flash;

    // load data section from flash to ram
    for (dst = &_data_begin; dst < &_data_end; ) {
        *(dst++) = *(src++);
    }
    
    // default bss section in ram to zero
    for (dst = &_bss_begin; dst < &_bss_end; ) {
        *(dst++) = 0;
    }

    board_init();
    kernel_init();
}

void nmi_handler(void)
{
    while (1) {asm ("nop");}
}

void mem_manage_handler(void)
{
    while (1) {asm ("nop");}
}

void debug_mon_handler(void)
{
    while (1) {asm ("nop");}
}

void hard_fault_handler(void)
{
    while (1) {asm ("nop");}
}

void bus_fault_handler(void)
{
    while (1) {asm ("nop");}
}

void usage_fault_handler(void)
{
    while (1) {asm ("nop");}
}
