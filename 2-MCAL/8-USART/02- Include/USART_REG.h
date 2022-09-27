/*************************************************************************************************
 * [MODULE_NAME]:  USART_REG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Registers of USART Peripheral
 ************************************************************************************************/
#ifndef USART_REG_H_
#define USART_REG_H_


typedef struct {
	volatile uint32 SR     ;
	volatile uint32 DR     ;
	volatile uint32 BRR    ;
	volatile uint32 CR1    ;
	volatile uint32 CR2    ;
	volatile uint32 CR3    ;
	volatile uint32 GTPR   ;

}USART_T;


#define USART1    ((volatile USART_T*)0x40013800)

typedef enum {
	PE   ,
	FE   ,
	NE   ,
	ORE  ,
	IDLE ,
	RXNE_USART1 ,
	TC_USART1   ,
	TXE  ,
	LBD  ,
	CTS  ,
}SR_T;

typedef enum{
	SBK            ,
	RWU            ,
	RE             ,
	TE             ,
	IDLEIE         ,
	RXNEIE_USART1  ,
	TCIE_USART1    ,
	TXEIE_USART1   ,
	PEIE           ,
	PS             ,
	PCE            ,
	WAKE           ,
	M              ,
	UE             ,

}CR1;

typedef enum{
	ADD0,
	ADD1,
	ADD2,
	ADD3,
	Res4,
    LBDL,
	LBDIE,
	Res7,
	LBCL,
	CPHA,
	CPOL,
	CLKEN,
	STOP0,
	STOP1,
	LINEN,
}CR2;


#endif
