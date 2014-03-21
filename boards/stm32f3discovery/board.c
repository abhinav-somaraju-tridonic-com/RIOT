/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     board_stm32f3discovery
 * @{
 *
 * @file        board.c
 * @brief       Board specific implementations for the STM32F3Discovery evaluation board
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * @}
 */

#include <stdint.h>
#include <stdio.h>

#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h"

#include "board.h"
#include "cpu.h"
#include "led.h"

#include "periph/uart.h"


extern void SystemInit(void);


void board_init(void)
{
    /* initialize core clocks via STM-lib given function */
    SystemInit();

    /* initialize the CPU */
    cpu_init();

    /* initialize the boards leds */
    gpio_t pins[] = {LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_10};
    led_init(pins, 8);

    /* is this needed? */
    //hwtimer_init();
}
