/*************************************************************************************************
 * [MODULE_NAME]:  LED_MATRIX_Prog.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  LED_MATRIX Program
 ************************************************************************************************/
#include "TYPES.h"
#include "MACROS.h"

#include "GPIO_INTERFACE.h"
#include "DELAY_INTERFACE.h"

#include "LED_MATRIX_INTERFACE.h"
#include "LED_MATRIX_REG.h"
#include "LED_MATRIX_CONFG.h"


void LEDMATRIX_init ( void ){


	GPIO_enablePortClock(LEDMATRIX_ROW_PORT);
	GPIO_enablePortClock(LEDMATRIX_COL_PORT);

    /* Initialize Direction      */
	GPIO_setPortDirection_H_L( LEDMATRIX_ROW_PORT , LEDMATRIX_ROW_PIN ,  OUTPUT_SPEED_2MHZ_PP);
	GPIO_setPortDirection_H_L( LEDMATRIX_COL_PORT , LEDMATRIX_COL_PIN ,  OUTPUT_SPEED_2MHZ_PP);


	/* Disable ALL LEDs */
	for (int i = 0; i < 8; i++) {

		GPIO_setPinValue(LEDMATRIX_COL_PORT, LEDMATRIX_COL_PIN + i, HIGH);
	}

}

void LEDMATRIX_enable ( uint8 * arr ){

	for (int i=0 ;i<8 ;i++){
         /* momken ykon feh moshkla fe awl func  */
		GPIO_setPortValue_H_L(LEDMATRIX_ROW_PORT ,LEDMATRIX_ROW_PIN  , arr[i]);
		GPIO_setPinValue(LEDMATRIX_COL_PORT , LEDMATRIX_COL_START_PIN + i , LOW);
		_delay_ms(2);  /* assume 1 Tick = 1us */
		GPIO_setPinValue(LEDMATRIX_COL_PORT , LEDMATRIX_COL_START_PIN + i , HIGH);
	}


}
