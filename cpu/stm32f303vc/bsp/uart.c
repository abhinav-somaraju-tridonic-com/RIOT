/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */


/**
 * @ingroup     cpu_stm32f303vc
 * @{
 * @file        uart.c
 * @brief       UART interface implementation using UART5 for the STM32F303VC
 * 
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @}
 */

#include "bsp/uart.h"
#include "irq.h"
#include "thread.h"
#include "sched.h"
#include "mutex.h"
#include "ringbuffer.h"

#include "periphial_conf.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x_usart.h"

/**
 *
 */
#define TX_BUFSIZE  (128U)
#define RX_BUFSIZE  (128U)


inline static void isr_on_entry(void);
inline static void isr_on_return(void);

static ringbuffer_t tx_rb;
static ringbuffer_t rx_rb;

static char tx_buf[TX_BUFSIZE];
static char rx_buf[RX_BUFSIZE];

static mutex_t rx_lock;


void uart_init(void)
{
    // define memory used
    USART_InitTypeDef uart_init;
    GPIO_InitTypeDef gpio_init;
    NVIC_InitTypeDef nvic_init;

    // initialize and lock the receive mutex (as initially there is no data available)
    mutex_init(&rx_lock);
    mutex_lock(&rx_lock);

    // initialize used ringbuffer
    ringbuffer_init(&tx_rb, tx_buf, TX_BUFSIZE);
    ringbuffer_init(&rx_rb, rx_buf, RX_BUFSIZE);

    // enable clocks
    BCONF_STDUART_DEV_CLK();
    BCONF_STDUART_RX_CLK_EN();
    BCONF_STDUART_TX_CLK_EN();

    // configure pins
    gpio_init.GPIO_Pin = BCONF_STDUART_RX_PIN;
    gpio_init.GPIO_Mode = GPIO_Mode_AF;
    gpio_init.GPIO_OType = GPIO_OType_PP;
    gpio_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
    gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BCONF_STDUART_RX_PORT, &gpio_init);
    GPIO_PinAFConfig(BCONF_STDUART_RX_PORT, BCONF_STDUART_RX_PINSRC, BCONF_STDUART_RX_AF);

    gpio_init.GPIO_Pin = BCONF_STDUART_TX_PIN;
    GPIO_Init(BCONF_STDUART_TX_PORT, &gpio_init);
    GPIO_PinAFConfig(BCONF_STDUART_TX_PORT, BCONF_STDUART_TX_PINSRC, BCONF_STDUART_TX_AF);

    // configure uart device
    uart_init.USART_BaudRate = BCONF_STDUART_DEV_BAUDRATE;
    uart_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    uart_init.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    uart_init.USART_Parity = USART_Parity_No;
    uart_init.USART_StopBits = USART_StopBits_1;
    uart_init.USART_WordLength = USART_WordLength_8b;
    USART_Init(BCONF_STDUART_DEVICE, &uart_init);

    USART_ITConfig(BCONF_STDUART_DEVICE, USART_IT_RXNE, ENABLE); // enable the USART2 receive interrupt
    USART_Cmd(BCONF_STDUART_DEVICE, ENABLE);

    // init the interrupt
    nvic_init.NVIC_IRQChannel = UART5_IRQn; // we want to configure the USART1 interrupts
    nvic_init.NVIC_IRQChannelPreemptionPriority = 0x0F; // this sets the priority group of the USART1 interrupts
    nvic_init.NVIC_IRQChannelSubPriority = 0x0F; // this sets the subpriority inside the group
    nvic_init.NVIC_IRQChannelCmd = ENABLE; // the UART5 interrupts are globally enabled
    NVIC_Init(&nvic_init);
}

char uart_readc(void)
{
    mutex_lock(&rx_lock);
    char c = (char)rb_get_element(&rx_rb);
    if (rx_rb.avail > 0) {
        mutex_unlock(&rx_lock);
    }
    return c;
}

void uart_writec(char c)
{
    // block until the transmit register is empty
    while (USART_GetFlagStatus(BCONF_STDUART_DEVICE, USART_FLAG_TXE) == RESET);
    USART_SendData(BCONF_STDUART_DEVICE, (uint16_t)c);
}

void uart_isr(void)
{
    if (USART_GetITStatus(BCONF_STDUART_DEVICE, USART_IT_RXNE) == SET) {
        char c = (char)USART_ReceiveData(BCONF_STDUART_DEVICE);
        rb_add_element(&rx_rb, c);
        mutex_unlock(&rx_lock);
    }
}

// this is the interrupt request handler (IRQ) for ALL USART1 interrupts
__attribute__((naked))
void UART5_IRQHandler(void) {
    isr_on_entry();
    uart_isr();
    if (sched_context_switch_request) {
        thread_yield(); // trigger PendSV for context switch
    }
    isr_on_return();
}


__attribute__( ( always_inline ) ) static __INLINE void isr_on_entry(void)
{
    /* {r0-r3,r12,LR,PC,xPSR} are saved automatically on exception entry */
    asm("push   {LR}");
    /* save exception return value */
}

__attribute__( ( always_inline ) ) static __INLINE void isr_on_return(void)
{
    asm("pop        {r0}");
    /* restore exception retrun value from stack */
//  asm("pop        {r4}"); /*foo*/
    asm("bx     r0"); /* load exception return value to pc causes end of exception*/
    /* {r0-r3,r12,LR,PC,xPSR} are restored automatically on exception return */
}
