/*************************************************************************************************
 * [MODULE_NAME]:  SPI_INTERFACE.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  All # Defines to be used by User & Function's prototype
 ************************************************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


#define SPI_DISABLE                 0
#define SPI_ENABLE                  1

#define SPI_MODE1                   0
#define SPI_MODE2                   1
#define SPI_MODE3                   2
#define SPI_MODE4                   3

#define SPI_MASTER                  0
#define SPI_SLAVE                   1

#define SPI_FPCLK_DIVIDED_BY_2      0b000
#define SPI_FPCLK_DIVIDED_BY_4      0b001
#define SPI_FPCLK_DIVIDED_BY_8      0b010
#define SPI_FPCLK_DIVIDED_BY_16     0b011
#define SPI_FPCLK_DIVIDED_BY_32     0b100
#define SPI_FPCLK_DIVIDED_BY_64     0b101
#define SPI_FPCLK_DIVIDED_BY_128    0b110
#define SPI_FPCLK_DIVIDED_BY_256    0b111

#define SPI_MSB_FIRST               0
#define SPI_LSB_FIRST 				 1

#define HW_SLAVE_MANAGEMENT          0
#define SW_SLAVE_MANAGEMENT          1

#define SPI_8BIT_DATA               0
#define SPI_16BIT_DATA              1

#define SPI_INT_DISABLE             0
#define SPI_TXE_INT_ENABLE          1
#define SPI_RXNE_INT_ENABLE         2

void SPI_init ( void );

void SPI_sendRecieveSynch(uint8 DataToTransmit ,uint8 *DataToReceive);


void SPI1_setCallBack( void (*ptr) (void) );




#endif
