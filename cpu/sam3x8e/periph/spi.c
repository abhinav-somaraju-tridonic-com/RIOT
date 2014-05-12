



#include "cpu.h"
#include "periph/spi.h"
#include "periph_conf.h"



int spi_init(spi_t dev, uint32_t speed)
{
    if (dev == SPI_UNDEFINED) {
        return -1;
    }

    /* enable SPI clock */
    PMC->PMC_PCER0 = (1 << ID_SPI0);

    /* configure SPI pins */
    PMC->PMC_PCER0 = (1 << ID_PIOA);                                    /* enable port A clock */
    PIOA->PIO_ABSR &= ~(PIO_ABSR_P25 | PIO_ABSR_P26 | PIO_ABSR_P7);     /* configure peripheral function A for pins */

    /* configure SPI as master with disabled internal chip select and disabled error handling */
    SPI_0_DEV->SPI_MR = SPI_MR_MSTR | SPI_MR_PS | SPI_MR_MODFDIS;

    /* enable the SPI module */
    SPI_0_DEV->SPI_CR = SPI_CR_SPIEN;

    return 0;
}

int spi_transfer_byte_blocking(spi_t dev, char out, char *in)
{
    while (!(SPI_0_DEV->SPI_SR & SPI_SR_TDRE));
    SPI_0_DEV->SPI_TDR = (uint32_t)in;

    return -1;
}

int spi_transfer_bytes_blocking(spi_t dev, char *in, char *out, int size)
{
    return -1;
}
