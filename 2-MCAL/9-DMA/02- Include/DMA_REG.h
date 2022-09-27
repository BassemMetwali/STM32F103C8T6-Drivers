/*************************************************************************************************
 * [MODULE_NAME]:  DMA_REG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  All Registers of DMA Peripheral
 ************************************************************************************************/


#ifndef DMA_REG_
#define DMA_REG_

typedef struct {
	volatile uint32 CCR    ;
	volatile uint32 CNDTR  ;
	volatile uint32 CPAR   ;
	volatile uint32 CMAR   ;

}DMA_CHANNELS;


typedef struct{
	volatile uint32 ISR       ;
	volatile uint32 IFCR      ;
	DMA_CHANNELS CHANNEL[7]   ;
}DMA;

#define  DMA   ((volatile DMA*) 0x40020000)

#endif
