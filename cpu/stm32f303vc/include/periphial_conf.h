/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */


/**
 * @ingroup     cpu_stm32f303vc
 * @{
 *
 * @file        periphial_conf.h
 * @brief       Definitions of pins and periphials.
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */
#ifndef __PERIPHIAL_CONF_H_
#define __PERIPHIAL_CONF_H_

#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h"

/**
 * @brief Standard UART (used by puts, printf...) configuration
 *
 * Standard UART is configured to use UART5 on pins PC12 (TX) and PD2 (RX).
 * @{
 */
#define BCONF_STDUART_DEVICE        UART5
#define BCONF_STDUART_DEV_IRQ       UART5_IRQn
#define BCONF_STDUART_DEV_CLK()     RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE)
#define BCONF_STDUART_DEV_BAUDRATE  115200

#define BCONF_STDUART_RX_PORT       GPIOD
#define BCONF_STDUART_RX_PIN        GPIO_Pin_2
#define BCONF_STDUART_RX_CLK_EN()   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE)
#define BCONF_STDUART_RX_PINSRC     GPIO_PinSource2
#define BCONF_STDUART_RX_AF         GPIO_AF_5

#define BCONF_STDUART_TX_PORT       GPIOC
#define BCONF_STDUART_TX_PIN        GPIO_Pin_12
#define BCONF_STDUART_TX_CLK_EN()   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define BCONF_STDUART_TX_PINSRC     GPIO_PinSource12
#define BCONF_STDUART_TX_AF         GPIO_AF_5
/** @} */

/** @} */
#endif /* __PERIPHIAL_CONF_H_ */
