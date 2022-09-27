/*************************************************************************************************
 * [MODULE_NAME]:  SYSTICK_Prog.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  SYSTICK Program
 ************************************************************************************************/
#include "TYPES.h"
#include "MACROS.h"

#include "SYSTICK_INTERFACE.h"
#include "SYSTICK_REG.h"
#include "SYSTICK_CONFG.h"

static uint8 STK_modeOfInterval=0;
static void(*STK_callBack)(void);


void STK_init (void){

# if STK_CLK_SRC==STK_SRC_AHB

	SYSTICK->CTRL= (1<< CLKSOURCE); /* To Clear all register and Define its CLK Source */

#elif STK_CLK_SRC==STK_SRC_AHB_8

	SYSTICK->CTRL= 0 ;


#endif
}

void STK_stopInterval        (void){

	/* Disable STK Interrupt */
	CLEAR_BIT(SYSTICK->CTRL, TICKINT);
	/* Stop Timer */
	CLEAR_BIT(SYSTICK->CTRL, ENABLE0);
	SYSTICK->LOAD = 0;
	SYSTICK->VAL = 0;
}

uint32 STK_getElapsedTime(void) {

	uint32 ElapsedTime;
	ElapsedTime = SYSTICK->LOAD - SYSTICK->VAL;
	return ElapsedTime;
}
uint32 STK_getRemainingTime(void) {

	uint32 RemainTime;
	RemainTime = SYSTICK->VAL;
	return RemainTime;
}

void STK_setBusyWait( uint32 Ticks )
{
	CLEAR_BIT(SYSTICK->CTRL, ENABLE0);
	/* Disable STK Interrupt */
	CLEAR_BIT(SYSTICK->CTRL, TICKINT); /* added by me */
	SYSTICK->LOAD = Ticks;
	/* may not Enable interrupt due to flag is fired when underflow is caused but it didn't enter ISR unless interrupt is enabled */
	SET_BIT(SYSTICK->CTRL, ENABLE0);
	while ((BIT_IS_CLEAR(SYSTICK->CTRL, COUNTFLAG)) && (BIT_IS_SET(SYSTICK->CTRL, ENABLE0)));
	CLEAR_BIT(SYSTICK->CTRL, ENABLE0);
	SYSTICK->LOAD = 0;
	SYSTICK->VAL = 0;
}

void STK_setIntervalSingle   ( uint32 Ticks, void (*ptr)(void) ){


     SYSTICK->LOAD = Ticks;

	SET_BIT(SYSTICK->CTRL, ENABLE0);
	STK_callBack = ptr;
	STK_modeOfInterval = STK_SINGLE_INTERVAL;
	SET_BIT(SYSTICK->CTRL, TICKINT);

}
void STK_setIntervalPeriodic ( uint32 Ticks, void (*ptr)(void) ){


    SYSTICK->LOAD=Ticks;

    SET_BIT(SYSTICK->CTRL,ENABLE0);
    STK_callBack=ptr;
	STK_modeOfInterval= STK_PERIOD_INTERVAL;
	SET_BIT(SYSTICK->CTRL,TICKINT);

}

void SysTick_Handler (void) {

	if (STK_modeOfInterval == STK_SINGLE_INTERVAL) {
		STK_stopInterval();
	}

	/* Callback notification */
	STK_callBack();

	/* Clear interrupt flag */
	(void) GET_BIT(SYSTICK->CTRL,COUNTFLAG);
}
