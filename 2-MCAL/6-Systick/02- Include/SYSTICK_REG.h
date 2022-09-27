/*************************************************************************************************
 * [MODULE_NAME]:  SYSTICK_REG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Registers of SYSTICK
 ************************************************************************************************/
#ifndef SYSTICK_REG_H_
#define SYSTICK_REG_H_

typedef struct {

	volatile uint32 CTRL ;
	volatile uint32 LOAD ;
	volatile uint32 VAL  ;
	volatile uint32 CALIB;

}SYSTICK;

#define SYSTICK ((volatile SYSTICK*) 0xE000E010)

#endif
