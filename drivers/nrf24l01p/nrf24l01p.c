/*
 * Copyright (C) 2014 Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * This source code is licensed under the LGPLv2 license,
 * See the file LICENSE for more details.
 *
 */

/**
 * @ingroup     drivers_nrf24l01p
 * @{
 * 
 * @file        nrf24l01p.c
 * @brief       Implementation of the nrf24l01p driver
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * 
 * @}
 */

#include "nrf24l01p.h"
#include "periph/gpio.h"
#include "periph/spi.h"

int nrf24l01p_init_auto(void);

int nrf24l01p_init(nrf24l01p_t *dev, spi_t spi, gpio_t ce, gpio_t csn, gpio_t irq)
{



    // set power up bit in CONFIG
    // set to receive mode by setting PRIM_RX bit in CONFIG
    // 
}

int nrf24l01p_send(nrf24l01p_t *dev, char *data, int length);

int nrf24l01p_register(nrf24l01p_t *dev, int pid)
{
    dev->listener = pid;
    return 0;
}

int nrf24l01p_unregister(nrf24l01p_t *dev, int pid)
{
    if (dev != NULL && dev->pid == pid) {
        dev->pid = 0;
        return 0;
    } else {
        return -1;
    }
}

int nrf24l01p_start(nrf24l01p_t *dev)
{
    if (dev == NULL) {
        return -1;
    }
    gpio_set(dev->ce);
    return 0;
}

int nrf24l01p_stop(nrf24l01p_t *dev)
{
    if (dev == NULL) {
        return -1;
    }
    gpio_clear(dev->ce);
    return 0;
}

int nrf24l01p_preload(nrf24l01p_t *dev, char *data, int size)
{
    gpio_clear(dev->cs);
    spi_write_byte(dev->spi, CMD_W_TX_PAYLOAD);
    size = (size <= 32) ? size : 32;
    spie_write(dev->spi, data, size);
    gpio_set(dev->cs);
    return size;
}

int nrf24l01p_transmit(nrf24l01p_t *dev, uint16_t saddr)
{
    gpio_clear(dev->cs);
    spi_write(dev->spi, CMD_W_REGISTER & REG_)
    gpio_set(dev->cs);
}

int nrf24l01p_set_channel(void *f, uint8_t channel)
{
    nrf24l01p_t *dev = (nrf24l01p_t*)f;
    gpio_clear(cs->cs);
    uint8_t cmd[] = {CMD_W_REGISTER & REG_RF_CH, channel};
    spi_write(dev->spi, cmd, 2);
    gpio_set(dev->cs);
}

int nrf24l01p_set_address_width(nrf24l01p_t *dev, nrf24l01p_aw_t aw)
{
    gpio_clear(dev->cs);
    spi_write_reg(dev->spi, CMD_W_REGISTER | REG_SETUP_AW, 0x00 | aw);
    gpio_set(dev->cs);
}

int nrf24l01p_set_datarate(nrf24l01p_t *dev, nrf24l01p_dr_t dr)
{
    gpio_clear(dev->cs);
    uint8_t rf_setup = spi_read_byte(dev->spi, CMD_R_REGISTER | REG_SETUP_RF);
    gpio_set(dev->cs);
    switch (dr) {
        case NRF24L01P_DR_500KBS:
            rf_setup |= RF_SETUP_RF_DR_LOW;
            break;
        case NRF24L01P_DR_1MBS:
            rf_setup &= ~(RF_SETUP_RF_DR_LOW | RF_SETUP_RF_DR_HIGH);
            break;
        case NRF24L01P_DR_2MBS:
            rf_setup &= ~RF_SETUP_RF_DR_LOW;
            rf_setup |= RF_SETUP_RF_DR_HIGH;
            break;
    }
    gpio_clear(dev->cs);
    spi_write_reg(dev->spi, CMD_W_REGISTER | REG_SETUP_RF, rf_setup);
    gpio_set(dev->cs);
    return 0;
}

int nrf24l01p_get_status(nrf24l01p_t *dev)
{
    uint8_t status;
    gpio_clear(dev->cs);
    status = spi_read_byte(0x00);
    gpio_set(dev->cs);
    return status;
}

int nrf24l01p_set_power(nrf24l01p_t *dev, nrf24l01p_pwr_t pwr)
{
    uint8_t rf_setup = spi_read_byte(dev->spi, CMD_R_REGISTER | REG_SETUP_RF);
    rf_setup &= &RF_SETUP_RF_PWR;
    rf_setup |= (pwr << 1);
    spi_write_reg(dev->spi, CMD_W_REGISTER | REG_SETUP_RF, rf_setup);
}

void spi_rx_cb(uint8_t data)
{

}

void exti_cb(void *f)
{
    nrf24l01p_t *dev = (nrf24l01p_t*)f;
    dev->state = INT;

}
