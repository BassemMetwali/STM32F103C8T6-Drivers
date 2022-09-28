/*************************************************************************************************
 * [MODULE_NAME]:  AFIO_REG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  All AFIO's Registers
 ************************************************************************************************/
#ifndef AFIO_REG_H_
#define AFIO_REG_H_


typedef struct {

	volatile uint32 EVCR;
	volatile uint32 MAPR;
	volatile uint32 EXTICR[4];
	volatile uint32 MAPR2;

}AFIO;

#define AFIO ((volatile AFIO *) 0x40010000) /*Base Address of AFIO */

#endif
