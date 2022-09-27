/*************************************************************************************************
 * [MODULE_NAME]:  SPI_CONFG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Configuration of SPI Peripheral
 ************************************************************************************************/
#ifndef SPI_CONFG_H_
#define SPI_CONFG_H



#define SP1_STATUS          SPI_ENABLE

#define SPI1_CLOCK_MODE     SPI_MODE4

#define SPI1_MASTER_SLAVE   SPI_MASTER

#define SPI1_PRESCALLER     SPI_FPCLK_DIVIDED_BY_4

#define SPI1_DATA_ORDER     SPI_MSB_FIRST

#define SPI1_SS_MANAGE      SW_SLAVE_MANAGEMENT

#define SPI1_DATA_SIZE      SPI_8BIT_DATA

#define SPI1_INT_STATUS     SPI_INT_DISABLE

#define SPI_SLAVE_PIN   		GPIOA_ID,PIN0   /* SLAVE SELECT PIN */

#define MOSI_PIN        PIN7

#define MISO_PIN        PIN6

#define SCK_PIN         PIN5

#define SPI1_PORT     GPIOA_ID

#endif


