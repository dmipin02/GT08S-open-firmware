#pragma once
#include <systypes.h>
#include <mt6261.h>

#define SPI_PORTX PORTB
#define SPI_DDRX  DDRB

#define SPI_SCLK 0
#define SPI_MOSI 0
#define SPI_MISO 0
#define SPI_CS   0

#define SPI_CONF0_REG   (*(volatile uint32_t *)(SPI_base + 0x0))
#define SPI_CONF1_REG   (*(volatile uint32_t *)(SPI_base + 0x4))
#define SPI_TX_ADDR_REG (*(volatile uint32_t *)(SPI_base + 0x8))
#define SPI_TX_FIFO_REG (*(volatile uint32_t *)(SPI_base + 0x10))
#define SPI_RX_ADDR_REG (*(volatile uint32_t *)(SPI_base + 0xC))
#define SPI_RX_FIFO_REG (*(volatile uint32_t *)(SPI_base + 0x14))

// Command register
#define SPI_COMM_REG    (*(volatile uint32_t *)(SPI_base + 0x18))
#define SPI_STATUS1_REG (*(volatile uint32_t *)(SPI_base + 0x1C))
#define SPI_STATUS2_REG (*(volatile uint32_t *)(SPI_base + 0x20))


void SPI_Init(void);

void SPI_Read(uint8_t *data, uint8_t length);
void SPI_Write(uint8_t *data, uint8_t length);