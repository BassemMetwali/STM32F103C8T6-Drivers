/*************************************************************************************************
 * [MODULE_NAME]:  STP_Prog.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Serial To Parallel Program
 ************************************************************************************************/
#include "TYPES.h"
#include "MACROS.h"

#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"

#include "STP_INTERFACE.h"
#include "STP_PRIVATE.h"
#include "STP_CONFG.h"



/*
 * Description :
 * Setup modes for Storage pin & Shift pin & Serial Data pin as an OUTPUT.
 * Initialize pins if there have a value before.
 */
void STP_init( void ){

	GPIO_enablePortClock ( STP_DATA_PORT );
	GPIO_enablePortClock ( STP_BIT_LATCH_PORT );
	GPIO_enablePortClock ( STP_BYTE_LATCH_PORT );

	GPIO_setupPinMode( STP_DATA_PORT       , STP_DATA_PIN       , OUTPUT_SPEED_2MHZ_PP );
	GPIO_setupPinMode( STP_BIT_LATCH_PORT  , STP_BIT_LATCH_PIN  , OUTPUT_SPEED_2MHZ_PP );
	GPIO_setupPinMode( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , OUTPUT_SPEED_2MHZ_PP );

	/* initialize of Storage & Shift Clock Pins */
	GPIO_setPinValue(  STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN ,  LOW  );
	GPIO_setPinValue(  STP_BIT_LATCH_PORT  , STP_BIT_LATCH_PIN ,  LOW  );

}


/*
 * Description :
 * Write a Data in form of zeros & ones to Serial Data pin (Data is 8_bit).
 * Give Rising edge to Shift pin after firing Data to shift data in IC.
 * Give Rising edge to Storage pin after shifting all Data.
 */
void STP_byteOutput ( uint8 Data ){

	/*  it should be signed integer to be negative when it finishes decrement  */
	for (sint8 counter = 8; counter > 0; counter--) {

		GPIO_setPinValue( STP_DATA_PORT, STP_DATA_PIN,
				(GET_BIT(Data, (counter - 1))));

		/* Rising Edge to shift data in register */
		GPIO_setPinValue( STP_BIT_LATCH_PORT, STP_BIT_LATCH_PIN, HIGH);
		STK_setBusyWait(10);
		GPIO_setPinValue( STP_BIT_LATCH_PORT, STP_BIT_LATCH_PIN, LOW);

	}
	/* Rising Edge to store data in storage register  */
	GPIO_setPinValue(  STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , HIGH);
	STK_setBusyWait(10);
	GPIO_setPinValue(  STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , LOW);

}


/*
 * Description :
 * Write a Data in form of zeros & ones to Serial Data pin (Data is 16_bit).
 * Give Rising edge to Shift pin after firing Data to shift data in IC.
 * Give Rising edge to Storage pin after shifting all Data.
 */
void STP_halfWordOutput ( uint16 Data ){

	/*  it should be signed integer to be negative when it finishes decrement  */
	for (sint16 counter = 16; counter > 0; counter--) {

		GPIO_setPinValue( STP_DATA_PORT, STP_DATA_PIN,
				(GET_BIT(Data, (counter - 1))));

		/* Rising Edge to shift data in register */
		GPIO_setPinValue( STP_BIT_LATCH_PORT, STP_BIT_LATCH_PIN, HIGH);
		STK_setBusyWait(10);
		GPIO_setPinValue( STP_BIT_LATCH_PORT, STP_BIT_LATCH_PIN, LOW);

	}
	/* Rising Edge to store data in storage register  */
	GPIO_setPinValue(  STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , HIGH);
	STK_setBusyWait(10);
	GPIO_setPinValue(  STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , LOW);

}
