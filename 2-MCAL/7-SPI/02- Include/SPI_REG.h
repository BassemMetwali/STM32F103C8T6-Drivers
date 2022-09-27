/*************************************************************************************************
 * [MODULE_NAME]:  SPI_REG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Registers of SPI Peripheral
 ************************************************************************************************/
#ifndef SPI_REG_H_
#define SPI_REG_H_

typedef struct {

	volatile uint32 CR1        ;
	volatile uint32 CR2        ;
	volatile uint32 SR         ;
	volatile uint32 DR         ;
	volatile uint32 CRCPR      ;
	volatile uint32 RXCRCR     ;
	volatile uint32 TXCRCR     ;
	volatile uint32 I2SCFGR    ;
	volatile uint32 I2SPR      ;

}SPI_T;

#define SPI1  ((volatile SPI_T*)0x40013000)


typedef enum {
	CPHA       ,
	CPOL       ,
	MSTR       ,
	BR0        ,
	BR1        ,
	BR2        ,
	SPE        ,
	LSBFIRST   ,
	SSI        ,
	SSM        ,
	RXONLY     ,
	DFF        ,
	CRCNEXT    ,
	CRCEN      ,
	BIDIOE     ,
	BIDIMODE   ,

}CR1_T;

typedef enum {
	RXDMAEN       ,
	TXDMAEN       ,
	SSOE          ,
	RES1          ,
	RES2          ,
	ERRIE         ,
	RXNEIE        ,
	TXEIE         ,

}CR2_T;


typedef enum {
	RXNE       ,
	TXE        ,
	CHSIDE     ,
	UDR        ,
	CRCERR     ,
	MODF       ,
	OVF        ,
	BSY        ,

}SR_T;


#endif
