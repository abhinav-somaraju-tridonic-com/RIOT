/*
 * Copyright (C) 2013 Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * This source code is licensed under the LGPLv2 license,
 * See the file LICENSE for more details.
 */

/**
 * @defgroup    drivers_nrf24l01p NRF24L01+
 * @ingroup     drivers
 * @brief       NRF24L01+ radio driver
 *
 * @{
 *
 * @file        nrf24l01p.h
 * @brief       Driver interface for the NRF24L01+ radio driver
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef __NRF24L01P_H

typedef struct {
    spi_t spi;
    gpio_t ce;
    gpio_t csn;
    gpio_t irq:
    int listener;
} nrf24l01p_t;

typedef enum {
    NRF24L01P_AW_3BYTE,
    NRF24L01P_AW_4BYTE,
    NRF24L01P_AW_5BYTE
} nrf24l01p_aw_t;

typedef enum {
    NRF24L01P_DR_500KBS,
    NRF24L01P_DR_1MBS,
    NRF24L01P_DR_2MBS
} nrf24l01p_dr_t;

typedef enum {
    NRF24L01_PWR_N18DBM = 0,
    NRF24L01_PWR_N12DBM = 1,
    NRF24L01_PWR_N9DBM = 2,
    NRF24L01_PWM_0DBM = 3
} nrf24l01p_pwr_t;



int nrf24l01p_init_auto(void);

int nrf24l01p_init(nrf24l01p_t dev, spi_t spi, gpio_t ce, gpio_t csn, gpio_t irq);

int nrf24l01p_send(nrf24l01p_t dev, char *data, int length);

int nrf24l01p_register(nrf24l01p_t dev, int pid);

int nrf24l01p_start(nrf24l01p_t dev);

int nrf24l01p_stop(nrf24l01p_t dev);





#endif
/** @} */
