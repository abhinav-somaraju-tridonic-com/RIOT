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

/**
 * Define the nominal CPU core clock in this board
 */
#define F_CPU               (72000000UL)


/**
 * Assign the hardware timer
 */
#define HW_TIMER            TIMER_0

/**
 * Configure connected devices
 */
#define STD_IO              UART_0
#define STD_IO_BAUDRATE     115200

/**
 * Configure NRF24L01+ devices
 */
#define NRF24L01P_NUMOF     (1U)
#define NRF24L01P_SPI       SPI_0
#define NRF24L01P_CE        GPIO_0
#define NRF24L01P_CSN       GPIO_1
#define NRF24L01P_INT       GPIO_2

/**
 * Assign LEDs
 */
#define LED_ON              (1U)
#define LED_OFF             (0U)
#define LED_3               GPIO_8
#define LED_4               GPIO_9
#define LED_5               GPIO_10
#define LED_6               GPIO_11
#define LED_7               GPIO_12
#define LED_8               GPIO_13
#define LED_9               GPIO_14
#define LED_10              GPIO_15
// for compatability to other boards
#define RED_LED             LED_3
#define GREEN_LED           LED_10


/**
 * @brief Initialize board specific hardware, including clock, LEDs and std-IO
 */
void board_init(void);


/** @} */
#endif /** __BOARD_H */
