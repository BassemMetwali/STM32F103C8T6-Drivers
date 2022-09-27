/************************************************************************************************
 * [MODULE_NAME]:  DAC_PROG.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  DAC Program
 **********************************************************************************************/
/*********************************** LIB Includes *********************************************/

#include "TYPES.h"
#include "MACROS.h"

/*********************************** MCAL Includes *********************************************/
#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"

/*********************************** Peripheral Includes ***************************************/
#include "DAC_INTERFACE.h"
#include "DAC_CONFG.h"
#include "DAC_PRIVATE.h"

#include "song.h"

uint16 Song_Counter = 0;

void DAC_CALLBACK( void ){

	GPIO_setPortValue_H_L( DAC_PORT , DAC_L_H ,Song_Array[ Song_Counter ]);
	Song_Counter++;

		if( Song_Counter == Song_Length ){
			Song_Counter = 0;
		}

}




void DAC_Init( void ){


     /************************** IO Pins Initialization ********************************/
	GPIO_setPortDirection_H_L( DAC_PORT, DAC_L_H, OUTPUT_SPEED_2MHZ_PP);

	/****************************** SysTick Init **************************************/

	STK_init(); /* Enable SysTick AHB/8 = 1MHZ */

}

void DAC_Play( void ){

	STK_setIntervalPeriodic ( NO_OF_SAMPLES_PER_SEC , DAC_CALLBACK);

}

void DAC_Stop( void ){

	Song_Counter = 0;
	STK_stopInterval();
}

