/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the LGPLv2 License.
 * See the file LICENSE in the top level directory for more details.
 */

/**
 * @ingroup     driver_periph
 * @brief       Low-level UART peripheral driver
 * @{
 *
 * @file        uart.h
 * @brief       Low-level UART peripheral driver interface definitions
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef __PERIPH_UART_H
#define __PERIPH_UART_H

#include "periph_conf.h"


/**
 * @brief Definition of available UART devices
 */
#ifdef UART_NUMOF
typedef enum {
#ifdef UART_0_EN
    UART_0 = 0,         ///< UART channel 0
#endif
#ifdef UART_1_EN
    UART_1,             ///< UART channel 1
#endif
#ifdef UART_2_EN
    UART_2              ///< UART channel 2
#endif
} uart_t;
#endif


/**
 * @brief Initialize a given UART device
 * 
 * The UART device will be initialized with the following configuration:
 * - 8 data bits
 * - no parity
 * - 1 stop bit
 * - baud-rate as given
 * 
 * @param uart          the UART device to initialize
 * @param baudrate      the desired baud-rate in baud/s
 * @param rx_cb         receive callback is called for every byte the is receive in interrupt context
 * @param tx_db         transmit callback is called when done with sending a byte (tx buffer gets empty)
 * @return              the actually set baud-rate, -1 on error
 */
int uart_init(uart_t uart, int baudrate, void (*rx_cb)(char), void (*tx_cb)(void));

/**
 * @brief Begin a new transmission, on most platforms this function will enable the tx interrupt
 * 
 * @param uart          UART device that will start a transmission
 */
void uart_tx_begin(uart_t uart);

/**
 * @brief End a transmission, on most platforms this will disable the tx interrupt
 * 
 * @param uart          the UART device that is finished with transmitting stuff
 */
void uart_tx_end(uart_t uart);

/**
 * @brief Write a byte into the UART's send register
 * 
 * Writing a byte into while another byte is still waiting to be transferred will override
 * the old byte. This method should be used in the transmit callback routine as in this it
 * is made sure that no old byte is waiting to be transferred.
 * 
 * @param uart          the UART device to use for transmission
 * @param data          the byte to write
 * @return              1 on success, -1 on error
 */
int uart_write(uart_t uart, char data);

int uart_write_blocking(uart_t uart, char data);

int uart_read_blocking(uart_t uart, char *data);

#endif /* __PERIPH_UART_H */
/** @} */
