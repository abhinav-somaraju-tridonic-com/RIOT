

#define WEAK_ALIAS(x) __attribute__ ((weak, alias(#x)))

extern int _stack_end;

/* Cortex M3 core interrupt handlers */
void reset_handler(void);
void nmi_handler(void) WEAK_ALIAS(default_handler);
void hard_fault_handler(void) WEAK_ALIAS(default_handler);
void mem_manage_handler(void) WEAK_ALIAS(default_handler);
void bus_fault_handler(void) WEAK_ALIAS(default_handler);
void usage_fault_handler(void) WEAK_ALIAS(default_handler);
void svc_isr(void) WEAK_ALIAS(default_handler);
void debug_mon_handler(void) WEAK_ALIAS(default_handler);
void pendsv_isr(void) WEAK_ALIAS(default_handler);
void systick_isr(void) WEAK_ALIAS(default_handler);

/* LPC13xx specific interrupt handlers */
void WAKEUP_Handler(void) WEAK_ALIAS(default_handler);
void I2C_Handler(void) WEAK_ALIAS(default_handler);
void TIMER_16_0_Handler(void) WEAK_ALIAS(default_handler);
void TIMER_16_1_Handler(void) WEAK_ALIAS(default_handler);
void TIMER_32_0_Handler(void) WEAK_ALIAS(default_handler);
void TIMER_32_1_Handler(void) WEAK_ALIAS(default_handler);
void SSP_Handler(void) WEAK_ALIAS(default_handler);
void UART_Handler(void) WEAK_ALIAS(default_handler);
void USB_IRQ_Handler(void) WEAK_ALIAS(default_handler);
void USB_FIQ_Handler(void) WEAK_ALIAS(default_handler);
void ADC_Handler(void) WEAK_ALIAS(default_handler);
void WDT_Handler(void) WEAK_ALIAS(default_handler);
void BOD_Handler(void) WEAK_ALIAS(default_handler);
void EINT3_Handler(void) WEAK_ALIAS(default_handler);
void EINT2_Handler(void) WEAK_ALIAS(default_handler);
void EINT1_Handler(void) WEAK_ALIAS(default_handler);
void EINT0_Handler(void) WEAK_ALIAS(default_handler);

void default_handler(void);



/* Stack top and vector handler table */
void *vector_table[] __attribute__ ((section(".text.isr_vector"))) = {
    &_stack_end,
    reset_handler,
    nmi_handler,
    hard_fault_handler,
    mem_manage_handler,
    bus_fault_handler,
    usage_fault_handler,
    0,
    0,
    0,
    0,
    svc_isr,
    debug_mon_handler,
    0,
    pendsv_isr,
    systick_isr,

    /* LPC13xx specific interrupt vectors */
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    I2C_Handler,
    TIMER_16_0_Handler,
    TIMER_16_1_Handler,
    TIMER_32_0_Handler,
    TIMER_32_1_Handler,
    SSP_Handler,
    UART_Handler,
    USB_IRQ_Handler,
    USB_FIQ_Handler,
    ADC_Handler,
    WDT_Handler,
    BOD_Handler,
    EINT3_Handler,
    EINT2_Handler,
    EINT1_Handler,
    EINT0_Handler,
};




void default_handler(void)
{
    while (1) {asm ("nop");}
}
