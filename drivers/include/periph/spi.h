/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the LGPLv2 License.
 * See the file LICENSE in the top level directory for more details.
 */

/**
 * @ingroup     driver_periph
 * @brief       Low-level SPI peripheral driver
 * @{
 *
 * @file        spi.h
 * @brief       Low-level SPI peripheral driver interface definitions
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef __SPI_H
#define __SPI_H

#include <stdint.h>

#include "periph_conf.h"


/**
 * @brief Definition available SPI devices
 */
typedef enum {
#if SPI_0_EN
    SPI_0,              /*< SPI device 0 */
#endif
#if SPI_1_EN
    SPI_1,              /*< SPI device 1 */
#endif
#if SPI_2_EN
    SPI_2,               /*< SPI device 2 */
#endif
#if SPI_3_EN
    SPI_3,               /*< SPI device 3 */
#endif
    SPI_UNDEFINED
} spi_t;


int spi_init(spi_t dev, uint32_t speed);

int spi_transfer_byte_blocking(spi_t dev, char in, char *out);
int spi_transfer_bytes_blocking(spi_t dev, char *in, char *out, int size);


#endif /* __SPI_H */
/** @} */
