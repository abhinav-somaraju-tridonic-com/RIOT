/*
 * Copyright (C) 2014 Hauke Petersen <mail@haukepetersen.de>
 *
 * This file is subject to the terms and conditions of the GPLv2 License. 
 * See the file LICENSE in the top level directory for more details.
 */

/**
 * @ingroup     driver_periph
 * @{
 * 
 * @file        gpio.c
 * @brief       Low-level GPIO driver implementation
 *
 * @author      Hauke Petersen <mail@haukepetersen.de>
 * 
 * @}
 */

#include "cpu.h"
#include "periph/gpio.h"
#include "periph_conf.h"

typedef struct {
    void (*cb)(void);
} gpio_state_t;

static inline void irq_handler(gpio_t dev);

static gpio_state_t config[GPIO_NUMOF];


void gpio_init_out(gpio_t dev, gpio_pp_t pushpull)
{
    GPIO_TypeDef *port;
    uint32_t pin;

    switch (dev) {
        case GPIO_0:
            GPIO_0_CLKEN();
            port = GPIO_0_PORT;
            pin = GPIO_0_PIN;
        case GPIO_1:
            GPIO_1_CLKEN();
            port = GPIO_1_PORT;
            pin = GPIO_1_PIN;
        case GPIO_2:
            GPIO_2_CLKEN();
            port = GPIO_2_PORT;
            pin = GPIO_2_PIN;
        case GPIO_3:
            GPIO_3_CLKEN();
            port = GPIO_3_PORT;
            pin = GPIO_3_PIN;
        case GPIO_4:
            GPIO_4_CLKEN();
            port = GPIO_4_PORT;
            pin = GPIO_4_PIN;
        case GPIO_5:
            GPIO_5_CLKEN();
            port = GPIO_5_PORT;
            pin = GPIO_5_PIN;
        case GPIO_6:
            GPIO_6_CLKEN();
            port = GPIO_6_PORT;
            pin = GPIO_6_PIN;
        case GPIO_7:
            GPIO_7_CLKEN();
            port = GPIO_7_PORT;
            pin = GPIO_7_PIN;
        case GPIO_8:
            GPIO_8_CLKEN();
            port = GPIO_8_PORT;
            pin = GPIO_8_PIN;
        case GPIO_9:
            GPIO_9_CLKEN();
            port = GPIO_9_PORT;
            pin = GPIO_9_PIN;
        case GPIO_10:
            GPIO_10_CLKEN();
            port = GPIO_10_PORT;
            pin = GPIO_10_PIN;
        case GPIO_11:
            GPIO_11_CLKEN();
            port = GPIO_11_PORT;
            pin = GPIO_11_PIN;
        case GPIO_UNDEFINED:
        default:
            return -1;
    }

    port->MODER &= ~(2 << (2 * pin));           /* set pin to output mode */
    port->MODER |= (1 << (2 * pin));
    port->OTYPER &= ~(1 << pin);                /* set to push-pull configuration */
    port->OSPEEDR |= (3 << (2 * pin));          /* set to high speed */
    port->PUPDR &= ~(3 << (2 * pin));           /* configure push-pull resistors */
    port->PUPDR |= (pushpull << (2 * pin));
    port->ODR &= ~(1 << pin);                   /* set pin to low signal */

    return 0; /* all OK */
}

void gpio_init_in(gpio_t dev, gpio_pp_t pushpull)
{
    GPIO_TypeDef *port;
    uint32_t pin;

    switch (dev) {
        case GPIO_0:
            GPIO_0_CLKEN();
            port = GPIO_0_PORT;
            pin = GPIO_0_PIN;
        case GPIO_1:
            GPIO_1_CLKEN();
            port = GPIO_1_PORT;
            pin = GPIO_1_PIN;
        case GPIO_2:
            GPIO_2_CLKEN();
            port = GPIO_2_PORT;
            pin = GPIO_2_PIN;
        case GPIO_3:
            GPIO_3_CLKEN();
            port = GPIO_3_PORT;
            pin = GPIO_3_PIN;
        case GPIO_4:
            GPIO_4_CLKEN();
            port = GPIO_4_PORT;
            pin = GPIO_4_PIN;
        case GPIO_5:
            GPIO_5_CLKEN();
            port = GPIO_5_PORT;
            pin = GPIO_5_PIN;
        case GPIO_6:
            GPIO_6_CLKEN();
            port = GPIO_6_PORT;
            pin = GPIO_6_PIN;
        case GPIO_7:
            GPIO_7_CLKEN();
            port = GPIO_7_PORT;
            pin = GPIO_7_PIN;
        case GPIO_8:
            GPIO_8_CLKEN();
            port = GPIO_8_PORT;
            pin = GPIO_8_PIN;
        case GPIO_9:
            GPIO_9_CLKEN();
            port = GPIO_9_PORT;
            pin = GPIO_9_PIN;
        case GPIO_10:
            GPIO_10_CLKEN();
            port = GPIO_10_PORT;
            pin = GPIO_10_PIN;
        case GPIO_11:
            GPIO_11_CLKEN();
            port = GPIO_11_PORT;
            pin = GPIO_11_PIN;
        case GPIO_UNDEFINED:
        default:
            return -1;
    }

    port->MODER &= ~(3 << (2 * pin));           /* configure pin as input */
    port->PUPDR &= ~(3 << (2 * pin));           /* configure push-pull resistors */
    port->PUPDR |= (pushpull << (2 * pin));

    return 0; /* everything alright here */
}

void gpio_init_int(gpio_t dev, gpio_pp_t pushpull, gpio_flank_t flank, void (*cb)(void))
{
    // set callback
    config[dev].cb = cb;

    gpio_init_in(dev, pushpull);

    EXTI_InitTypeDef exti;
    NVIC_InitTypeDef nvic;

    // config the exti mode
    exti.EXTI_Mode = EXTI_Mode_Interrupt;
    switch (flank) {
        case GPIO_RISING:
            exti.EXTI_Trigger = EXTI_Trigger_Rising;
            break;
        case GPIO_FALLING:
            exti.EXTI_Trigger = EXTI_Trigger_Falling;
            break;
        case GPIO_BOTH:
            exti.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
            break;
    }
    exti.EXTI_LineCmd = ENABLE;

    // nvic setup
    nvic.NVIC_IRQChannelPreemptionPriority = GPIO_IRQ_PRIO;
    nvic.NVIC_IRQChannelSubPriority = 0;
    nvic.NVIC_IRQChannelCmd = ENABLE;

    // define pin spedific options
    switch (dev) {
        case GPIO_0:
            GPIO_0_EXTI_MAP();
            exti.EXTI_Line = GPIO_0_LINE;
            nvic.NVIC_IRQChannel = GPIO_0_IRQ;
            break;
        case GPIO_1:
            GPIO_1_EXTI_MAP();
            exti.EXTI_Line = GPIO_1_LINE;
            nvic.NVIC_IRQChannel = GPIO_1_IRQ;
            break;
        case GPIO_2:
            GPIO_2_EXTI_MAP();
            exti.EXTI_Line = GPIO_2_LINE;
            nvic.NVIC_IRQChannel = GPIO_2_IRQ;
            break;
        case GPIO_3:
            GPIO_3_EXTI_MAP();
            exti.EXTI_Line = GPIO_3_LINE;
            nvic.NVIC_IRQChannel = GPIO_3_IRQ;
            break;
        case GPIO_4:
            GPIO_4_EXTI_MAP();
            exti.EXTI_Line = GPIO_4_LINE;
            nvic.NVIC_IRQChannel = GPIO_4_IRQ;
            break;
        case GPIO_5:
            GPIO_5_EXTI_MAP();
            exti.EXTI_Line = GPIO_5_LINE;
            nvic.NVIC_IRQChannel = GPIO_5_IRQ;
            break;
        case GPIO_6:
            GPIO_6_EXTI_MAP();
            exti.EXTI_Line = GPIO_6_LINE;
            nvic.NVIC_IRQChannel = GPIO_6_IRQ;
            break;
        case GPIO_7:
            GPIO_7_EXTI_MAP();
            exti.EXTI_Line = GPIO_7_LINE;
            nvic.NVIC_IRQChannel = GPIO_7_IRQ;
            break;
        case GPIO_8:
            GPIO_8_EXTI_MAP();
            exti.EXTI_Line = GPIO_8_LINE;
            nvic.NVIC_IRQChannel = GPIO_8_IRQ;
            break;
        case GPIO_9:
            GPIO_9_EXTI_MAP();
            exti.EXTI_Line = GPIO_9_LINE;
            nvic.NVIC_IRQChannel = GPIO_9_IRQ;
            break;
        case GPIO_10:
            GPIO_10_EXTI_MAP();
            exti.EXTI_Line = GPIO_10_LINE;
            nvic.NVIC_IRQChannel = GPIO_10_IRQ;
            break;
        case GPIO_11:
            GPIO_11_EXTI_MAP();
            exti.EXTI_Line = GPIO_11_LINE;
            nvic.NVIC_IRQChannel = GPIO_11_IRQ;
            break;
    }

    EXTI_Init(&exti);
    NVIC_Init(&nvic);
}

int gpio_read(gpio_t dev)
{
    GPIO_TypeDef *port;
    uint32_t pin;

    switch (dev) {
        case GPIO_0:
            port = GPIO_0_PORT;
            pin = GPIO_0_PIN;
        case GPIO_1:
            port = GPIO_1_PORT;
            pin = GPIO_1_PIN;
        case GPIO_2:
            port = GPIO_2_PORT;
            pin = GPIO_2_PIN;
        case GPIO_3:
            port = GPIO_3_PORT;
            pin = GPIO_3_PIN;
        case GPIO_4:
            port = GPIO_4_PORT;
            pin = GPIO_4_PIN;
        case GPIO_5:
            port = GPIO_5_PORT;
            pin = GPIO_5_PIN;
        case GPIO_6:
            port = GPIO_6_PORT;
            pin = GPIO_6_PIN;
        case GPIO_7:
            port = GPIO_7_PORT;
            pin = GPIO_7_PIN;
        case GPIO_8:
            port = GPIO_8_PORT;
            pin = GPIO_8_PIN;
        case GPIO_9:
            port = GPIO_9_PORT;
            pin = GPIO_9_PIN;
        case GPIO_10:
            port = GPIO_10_PORT;
            pin = GPIO_10_PIN;
        case GPIO_11:
            port = GPIO_11_PORT;
            pin = GPIO_11_PIN;
    }

    if (port->MODER & (3 << (pin * 2))) {       /* if configured as output */
        return port->ODR & (1 << pin);          /* read output data register */
    } else {
        return port->IDR & (1 << pin);          /* else read input data register */
    }
}

void gpio_set(gpio_t dev)
{
    switch (dev) {
        case GPIO_0:
            GPIO_0_PORT->ODR |= (1 << GPIO_0_PIN);
            break;
        case GPIO_1:
            GPIO_1_PORT->ODR |= (1 << GPIO_1_PIN);
            break;
        case GPIO_2:
            GPIO_2_PORT->ODR |= (1 << GPIO_2_PIN);
            break;
        case GPIO_3:
            GPIO_3_PORT->ODR |= (1 << GPIO_3_PIN);
            break;
        case GPIO_4:
            GPIO_4_PORT->ODR |= (1 << GPIO_4_PIN);
            break;
        case GPIO_5:
            GPIO_5_PORT->ODR |= (1 << GPIO_5_PIN);
            break;
        case GPIO_6:
            GPIO_6_PORT->ODR |= (1 << GPIO_6_PIN);
            break;
        case GPIO_7:
            GPIO_7_PORT->ODR |= (1 << GPIO_7_PIN);
            break;
        case GPIO_8:
            GPIO_8_PORT->ODR |= (1 << GPIO_8_PIN);
            break;
        case GPIO_9:
            GPIO_9_PORT->ODR |= (1 << GPIO_9_PIN);
            break;
        case GPIO_10:
            GPIO_10_PORT->ODR |= (1 << GPIO_10_PIN);
            break;
        case GPIO_11:
            GPIO_11_PORT->ODR |= (1 << GPIO_11_PIN);
            break;
    }
}

void gpio_clear(gpio_t dev)
{
    switch (dev) {
        case GPIO_0:
            GPIO_0_PORT->ODR &= ~(1 << GPIO_0_PIN);
            break;
        case GPIO_1:
            GPIO_1_PORT->ODR &= ~(1 << GPIO_1_PIN);
            break;
        case GPIO_2:
            GPIO_2_PORT->ODR &= ~(1 << GPIO_2_PIN);
            break;
        case GPIO_3:
            GPIO_3_PORT->ODR &= ~(1 << GPIO_3_PIN);
            break;
        case GPIO_4:
            GPIO_4_PORT->ODR &= ~(1 << GPIO_4_PIN);
            break;
        case GPIO_5:
            GPIO_5_PORT->ODR &= ~(1 << GPIO_5_PIN);
            break;
        case GPIO_6:
            GPIO_6_PORT->ODR &= ~(1 << GPIO_6_PIN);
            break;
        case GPIO_7:
            GPIO_7_PORT->ODR &= ~(1 << GPIO_7_PIN);
            break;
        case GPIO_8:
            GPIO_8_PORT->ODR &= ~(1 << GPIO_8_PIN);
            break;
        case GPIO_9:
            GPIO_9_PORT->ODR &= ~(1 << GPIO_9_PIN);
            break;
        case GPIO_10:
            GPIO_10_PORT->ODR &= ~(1 << GPIO_10_PIN);
            break;
        case GPIO_11:
            GPIO_11_PORT->ODR &= ~(1 << GPIO_11_PIN);
            break;
    }
}


void gpio_toggle(gpio_t dev)
{
    if (gpio_read(dev)) {
        gpio_clear(dev);
    } else {
        gpio_set(dev);
    }
}

void gpio_write(gpio_t dev, int value)
{
    if (value) {
        gpio_set(dev);
    } else {
        gpio_clear(dev);
    }
}


static inline void irq_handler(gpio_t dev) 
{
    config[dev].cb();
}

__attribute__((naked))
void isr_exti0_1(void)
{
    ISR_ENTER();
    if (EXTI->PR & EXTI_PR_PR0) {
        EXTI->PR |= EXTI_PR_PR0;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_0);
    }
    else if (EXTI->PR & EXTI_PR_PR1) {
        EXTI->PR |= EXTI_PR_PR1;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_1);
    }
    ISR_EXIT();
}

__attribute__((naked))
void isr_exti2_3(void)
{
    ISR_ENTER();
    if (EXTI->PR & EXTI_PR_PR2) {
        EXTI->PR |= EXTI_PR_PR2;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_2);
    }
    else if (EXTI->PR & EXTI_PR_PR3) {
        EXTI->PR |= EXTI_PR_PR3;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_3);
    }
    ISR_EXIT();
}

__attribute__((naked))
void isr_exti4_15(void)
{
    ISR_ENTER();
    if (EXTI->PR & EXTI_PR_PR4) {
        EXTI->PR |= EXTI_PR_PR4;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_4);
    }
    else if (EXTI->PR & EXTI_PR_PR5) {
        EXTI->PR |= EXTI_PR_PR5;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_5);
    }
    else if (EXTI->PR & EXTI_PR_PR6) {
        EXTI->PR |= EXTI_PR_PR6;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_6);
    }
    else if (EXTI->PR & EXTI_PR_PR7) {
        EXTI->PR |= EXTI_PR_PR7;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_7);
    }
    else if (EXTI->PR & EXTI_PR_PR8) {
        EXTI->PR |= EXTI_PR_PR8;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_8);
    }
    else if (EXTI->PR & EXTI_PR_PR9) {
        EXTI->PR |= EXTI_PR_PR9;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_9);
    }
    else if (EXTI->PR & EXTI_PR_PR10) {
        EXTI->PR |= EXTI_PR_PR10;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_10);
    }
    else if (EXTI->PR & EXTI_PR_PR11) {
        EXTI->PR |= EXTI_PR_PR11;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_11);
    }
    else if (EXTI->PR & EXTI_PR_PR12) {
        EXTI->PR |= EXTI_PR_PR12;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_12);
    }
    else if (EXTI->PR & EXTI_PR_PR13) {
        EXTI->PR |= EXTI_PR_PR13;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_13);
    }
    else if (EXTI->PR & EXTI_PR_PR14) {
        EXTI->PR |= EXTI_PR_PR14;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_14);
    }
    else if (EXTI->PR & EXTI_PR_PR15) {
        EXTI->PR |= EXTI_PR_PR15;        /* clear status bit by writing a 1 to it */
        irq_handler(GPIO_IRQ_15);
    }
    ISR_EXIT();
}
