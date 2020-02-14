#include <spi.h>

void SPI_Init(void)
{
    // /* IO ports setup,
    //    all ports exclude MISO outputs */
    // SPI_DDRX = (1 << SPI_MOSI) | (1 << SPI_SCK) | (1 << SPI_CS) | (0 << SPI_MISO);
    // SPI_PORTX = (1 << SPI_MOSI) | (1 << SPI_SCK) | (1 << SPI_CS) | (1 << SPI_MISO);

    // /* Bigger bit forward, master, mode 0 */
    // SPCR = (1 << SPE) | (0 << DORD) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA) | (1 << SPR1) | (0 << SPR0);
    // SPSR = (0 << SPI2X);
}

void SPI_Read(uint8_t *data, uint8_t length)
{

}

void SPI_Write(uint8_t *data, uint8_t length)
{

}