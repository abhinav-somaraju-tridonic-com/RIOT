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

#include <stdint.h>
#include <stddef.h>

#include "thread.h"
#include "hwtimer_arch.h"
#include "stm32f30x.h"

#define TIMER_MAX           0x00ffffff      /* maximum value of the timer counter before reload */
#define TIMER_SLOTS         (10U)

#define IRQ_ENABLE()        (SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk)
#define IRQ_DISABLE()       (SysTick->CTRL &= ~(SysTick_CTRL_TICKINT_Msk))

#define COUNT_ENABLE()      (SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk)
#define COUNT_DISABLE()     (SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk))

#define CRIT_START()        {
#define CRIT_END()          }

typedef struct slot slot_t;
struct slot {
    slot_t *next;
    int32_t offset;
    uint8_t timer;
};

void (*timeout_handler)(int);
uint32_t cpu_speed;

// memory holding the timer slots
slot_t slots[TIMER_SLOTS];

// currently active timer slot
slot_t *head = NULL;
uint8_t current_timer = -1;




/**
 * @brief Initialize architecture dependent kernel timer support
 *
 * The timer starts in disabled state with disabled interrupts.
 *
 * @param[in] handler   Function pointer to the multiplexer that handles the timers timeout
 * @param[in] fcpu      The current CPU frequency in Hz
 */
void hwtimer_arch_init(void (*handler)(int), uint32_t fcpu)
{
    timeout_handler = handler;
    cpu_speed = fcpu;

    for (uint8_t i = 0; i < TIMER_SLOTS; i++) {
        slots[i].next = NULL;
        slots[i].offset = -1;
        slots[i].timer = i;
    }

    // set up sysTick for counting time (without irq)
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    IRQ_ENABLE();
}

/**
 * Enable interrupts of hardware timers.
 */
void hwtimer_arch_enable_interrupt(void)
{
    IRQ_ENABLE();
}

/**
 * Disable interrupts of hardware timers.
 */
void hwtimer_arch_disable_interrupt(void)
{
    IRQ_DISABLE();
}

/**
 * Set a kernel timer to raise an interrupt after ::offset kernel timer ticks
 * from now.
 *
 * CAREFUL: function assumes that timer is not greater than TIMER_SLOTS!
 */
void hwtimer_arch_set(unsigned long offset, short timer)
{
    if (head == NULL) {
        SysTick->LOAD = ((offset - 930) & SysTick_LOAD_RELOAD_Msk);
        SysTick->VAL = 1;
        current_timer = timer;
        COUNT_ENABLE();
    }


//    slot_t *slot = &slots[timer + 1];
//    int32_t index = head;
//
//    // insert empty
//    if (head == -1) {
//        head = timer;
//        slot->offset = offset;
//        slot->prev = -1;
//        slot->next = -1;
//        TIMER_ENBALE();
//    }
//
//
//    // insert normally
//    if (slots[current].offset > offset) {
//        int32_t prev = xx;
//        int32_t next = xx;
//        slots[new].offset = offset - slots[prev].offset;
//        slots[new].next = next;
//        slots[new].prev;
//    }
//
//
//    while (index > -1) {
//        if (offset < slots[index].offset) {
//            if (index == head) {
//                // insert first
//            } else {
//                // insert after
//            }
//            return;
//        }
//        index = slots[index].next;
//    }
//
//    slot_t *slot = (slot_t*)head.next;
//    if (head == NULL) {
//
//    }
}

/**
 * Set a kernel timer to raise an interrupt at specified system time.
 *
 * @deprecated
 */
void hwtimer_arch_set_absolute(unsigned long value, short timer)
{
    // TODO not: will not be implemented
}

/**
 * Unset the kernel timer with the given timer ID.
 */
void hwtimer_arch_unset(short timer)
{
//    if (head == timer) {
//        // handle it
//    }
//    if (slots[i].prev > -1) {
//        ((slot_t *)slots[i].prev)->next = slots[i].next;
//    }
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
 * @brief SysTick timer interrupt
 */
void SysTick_Handler(void)
{
    // 1. has next timeout?
    // yes:
    //      set next timeout
    //      reload timer
    // no:
    //      disable timer
    //
    // 2. update list data

    if (head != NULL) {
        SysTick->LOAD = head->offset;       // set reload value to next timer slot value
        SysTick->VAL = 1;                   // load the new value into the timer by writing anything into the value register
        head->offset = -1;                  // cleanup used offset
        head = head->next;                  // advance the current head, will be NULL in case no slot is active
    } else {
        COUNT_DISABLE();                    // disable timer because nothing to do
    }
    timeout_handler(current_timer);

    thread_yield();                         // trigger the scheduler
}
