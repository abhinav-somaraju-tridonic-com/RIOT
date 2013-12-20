/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @defgroup    board_stm32f3discovery STM32F3Discovery
 * @ingroup     boards
 * @brief       Board specific files for the STM32F3Discovery board.
 * @{
 *
 * @file        board.h
 * @brief       Board specific definitions for the STM32F3Discovery evaluation board.
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef __BOARD_H
#define __BOARD_H

#define F_CPU           (72000000U)

#define HSE_VALUE    ((uint32_t)8000000)
#define RTC_CLOCK_SOURCE_LSI

/**
 * @brief Definitions of available LEDs
 */
typedef enum {
    LED3 = 0x0200,       ///< LED 3
    LED4 = 0x0100,       ///< LED 4
    LED5 = 0x0400,       ///< LED 5
    LED6 = 0x8000,       ///< LED 6
    LED7 = 0x0800,       ///< LED 7
    LED8 = 0x4000,       ///< LED 8
    LED9 = 0x1000,       ///< LED 9
    LED10 = 0x2000       ///< LED 10
} board_leds_t;



void board_init(void);

void sysclock_core_update(void);
void system_init(void);

void board_leds_init(void);
void board_led_on(board_leds_t led);
void board_led_off(board_leds_t led);
void board_led_toggle(board_leds_t led);


/** @} */
#endif /** __BOARD_H */
