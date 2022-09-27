/*************************************************************************************************
 * [MODULE_NAME]:  DELAY_Prog.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  DELAY Program
 ************************************************************************************************/
#include "TYPES.h"
#include "MACROS.h"

#include "DELAY_INTERFACE.h"

#include "SYSTICK_INTERFACE.h"


void _delay_ms( uint32 Time ){

	//STK_init();
	STK_setBusyWait(Time * 1000);
}


/* Suppose That The Clock System (AHB) = 8MHZ EXT & The Systick Clock Is = AHB/8 */
void _delay_us( uint32 Time ){

	//STK_init();
	STK_setBusyWait(Time );
}


