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

#include "GPIO_INTERFACE.h"
#include "EXTI_INTERFACE.h"
#include "NVIC_INTERFACE.h"
#include "AFIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"


#include "IR_INTERFACE.h"
#include "IR_CONFG.h"

#define SIZE_OF_ARRAY   50

/* Using volatile due to all of these variables are used in ISR */
volatile uint8 FLAG = 0;
volatile uint8 Counter = 0;
volatile uint8 DATA = 0;
volatile uint32 CodeSample[SIZE_OF_ARRAY] = { 0 } ;

void Timer_ResetCallBack ( void ){

	STK_stopInterval();
	FLAG  = 0 ;
	Counter = 0 ;
	DATA    = 0 ;

}


void Read_CodeCallBack(void)
{
	if (FLAG == 0)
	{
		/*  Clear Timer Value */
		STK_stopInterval ();
		/* Start Timer */
		STK_setIntervalPeriodic ( 1000000, Timer_ResetCallBack ); /* 1 Tick = 1us */
		FLAG=1;
	}

	else if (FLAG == 1)
	{
		CodeSample[Counter] = STK_getElapsedTime();
		Counter++;
		/*  Clear Timer Value */
		STK_stopInterval();
		/* Start Timer */
		STK_setIntervalPeriodic(1000000, Timer_ResetCallBack); /* 1 Tick = 1us */
	}

   if (Counter == END_OF_CODE)
   {
	   for (int i=DATA_COMMEND_START_EDGE ; i< DATA_COMMEND_END_EDGE ; i++)
	   {
		   if (CodeSample[i] > LOGIC1_RANGE)
		   {
			   SET_BIT( DATA ,(i-DATA_COMMEND_START_EDGE));
		   }
		   else
		   {
			   CLEAR_BIT(DATA ,(i-DATA_COMMEND_START_EDGE));
		   }
	   }

	   STK_stopInterval(); /* Stop Timer */   /* ADDED BY me */
	   NVIC_disablePeripheral( NVIC_EXTI0 ); /* Disable EXTI0 Interrupts */
	   FLAG=2;

   }

}

void IR_init( void ){

	STK_init();

	NVIC_setPriority(NVIC_EXTI0, NVIC_GROUP_PRIORITY_0,
			NVIC_SUBGROUP_PRIORITY_0, GROUP4);
	NVIC_enablePeripheral(NVIC_EXTI0);

	AFIO_enableClock();
	AFIO_setEXTIConfiguration(AFIO_EXTI_LINE0, IR_PORT);

	EXTI_setCallBack(EXTI_LINE0,  Read_CodeCallBack );
	EXTI_init(EXTI_LINE0, FALLING_EDGE);

	GPIO_enablePortClock(GPIOA_ID);

	GPIO_setupPinMode(IR_PORT, IR_PIN , INPUT_FLOATING);

}


uint8 IR_getData (void)
{
	uint8 value;
    while (FLAG != 2);
    value=DATA;
    FLAG = 0;
    Counter = 0;
    DATA=0;
    NVIC_enablePeripheral   ( NVIC_EXTI0 );
	return value;
}



