/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */


/**
 * @ingroup     UNGROUPED
 * @{
 * @file        cpu.c
 * @brief       Kernel mutex implementation
 * 
 * This is a detailed description of this .c-file contents.
 * 
 * @author      First Last <email>
 * @}
 */

#include <stdio.h>

#include "cpu.h"
#include "stm32f30x.h"

/**
 * @brief Initialize the CPU, set IRQ priorities and other stuff
 */
void cpu_init(void)
{
    // assign the PendSV interrupt to have the lowest possible priority
    NVIC_SetPriority(PendSV_IRQn, 0xff);
    NVIC_SetPriority(SVCall_IRQn, 0x00);
}
