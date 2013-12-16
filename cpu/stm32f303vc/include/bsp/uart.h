/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */


/**
 * @ingroup     board_stm32f3discovery
 * @brief       STM32F3 specific UART driver *
 * @{
 *
 * @file        uart.h
 * @brief       Interface definitions for the STM32F3 specific UART driver
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */
#ifndef __UART_H_
#define __UART_H_

void uart_init(void);

char uart_readc(void);

void uart_writec(char);


/** @} */
#endif /* __UART_H_ */
