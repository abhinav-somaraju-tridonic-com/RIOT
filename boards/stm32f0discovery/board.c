/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     board_stm32f0discovery
 * @{
 *
 * @file        board.c
 * @brief       Board specific implementations for the STM32F0Discovery evaluation board
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * @}
 */

#include "board.h"


extern void SystemInit(void);
void leds_init(void);


void board_init(void)
{
    /* initialize core clocks via STM-lib given function */
    SystemInit();

    /* initialize the CPU */
    cpu_init();

    /* initialize the boards LEDs */
    leds_init();

    for (int i = 0; i < 10000000; i++) {
        LD3_TOGGLE;
        LD4_TOGGLE;
    }
}


/**
 * @brief Initialize the boards on-board LEDs (LD3 and LD4)
 *
 * The LED initialization is hard-coded in this function. As the LEDs are soldered
 * onto the board they are fixed to their CPU pins.
 *
 * The LEDs are connected to the following pins:
 * - LD3: PC8
 * - LD4: PC9
 */
void leds_init(void)
{
    /* enable clock for port GPIOE */
    RCC->AHBENR |= RCC_AHBENR_GPIOEEN;

    /* set output speed to 50MHz */
    LED_PORT->OSPEEDR |= 0x000f0000;
    /* set output type to push-pull */
    LED_PORT->OTYPER &= ~(0x00000300);
    /* configure pins as general outputs */
    LED_PORT->MODER &= ~(0x000f0000);
    LED_PORT->MODER |= 0x00050000;
    /* disable pull resistors */
    LED_PORT->PUPDR &= ~(0x000f0000);

    /* turn all LEDs off */
    LED_PORT->BRR = 0x0300;
}
