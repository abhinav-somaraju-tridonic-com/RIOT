/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     cpu_stm32f303vg
 * @{
 *
 * @file        hwtimer_arch.c
 * @brief       Implementation of the kernels hwtimer interface
 *
 * The hardware timer implementation uses the Coretex build-in system timer as backend.
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * @}
 */

#include "hwtimer_arch.h"
#include "stm32"

#define TIMER_MAX = 0x00ffffff      /* maximum value of the timer counter before reload */
#define TIMER_SLOTS = 10

void (*timeout_handler)(int);
uint32_t cpu_speed;

typedef struct {
    int id;
    void(*callback)(void);
} slot_t;


/**
 * Initialize architecture dependent kernel timer support.
 */
void hwtimer_arch_init(void (*handler)(int), uint32_t fcpu)
{
    timeout_handler = handler;
    cpu_speed = fcpu;

    // set up sysTick for counting time (without irq)
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
}

/**
 * Enable interrupts of hardware timers.
 */
void hwtimer_arch_enable_interrupt(void)
{
    SysTick->
}

/**
 * Disable interrupts of hardware timers.
 */
void hwtimer_arch_disable_interrupt(void)
{
    // TODO
}

/**
 * Set a kernel timer to raise an interrupt after ::offset kernel timer ticks
 * from now.
 */
void hwtimer_arch_set(unsigned long offset, short timer)
{
    // TODO
}

/**
 * Set a kernel timer to raise an interrupt at specified system time.
 */
void hwtimer_arch_set_absolute(unsigned long value, short timer)
{
    // TODO
}

/**
 * Unset the kernel timer with the given timer ID.
 */
void hwtimer_arch_unset(short timer)
{
    // TODO
}

/**
 * Get the current tick count of the default hardware timer.
 */
unsigned long hwtimer_arch_now(void)
{
    // TODO
    return 0;
}

/**
 * @brief
 */
