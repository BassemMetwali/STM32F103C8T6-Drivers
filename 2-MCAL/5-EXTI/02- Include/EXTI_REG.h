/*************************************************************************************************
 * [MODULE_NAME]:  EXTI_REG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Registers of External interrupt Peripheral
 ************************************************************************************************/
#ifndef EXTI_REG_H_
#define EXTI_REG_H_



typedef struct {
	volatile uint32 IMR;
	volatile uint32 EMR;
	volatile uint32 RTSR;
	volatile uint32 FTSR;
	volatile uint32 SWIER;
	volatile uint32 PR;

}EXTI;

#define EXTI ((volatile EXTI *) 0x40010400)

#endif
