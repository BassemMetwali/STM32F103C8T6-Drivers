/*************************************************************************************************
 * [MODULE_NAME]:  USART_Prog.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  USART Program
 ************************************************************************************************/
#include "TYPES.h"
#include "MACROS.h"

#include "RCC_INTERFACE.h"

#include "USART_INTERFACE.h"
#include "USART_CONFG.h"
#include "USART_REG.h"

#define THRESHOLD_VALUE  9000000UL

void USART_init ( void ){


	 /* Setting up baud rate */
	    uint16 Mantissa =  ((F_CPU) / (USART1_BAUD_RATE * 16));
	    uint16 Fraction =  ((F_CPU * 1000 ) / (USART1_BAUD_RATE * 16)) - Mantissa*1000;
	    Fraction = (Fraction * 16) / 1000;
	    USART1 -> BRR = (Mantissa << 4) | Fraction;


	if( Fraction > 1500 ){ Mantissa += 1 ; Fraction  = 0 ; }

	/************************************ Enable / Disable USART ********************************************/
#if ( USART1_STATUS == USART1_ENABLE )

	USART1->SR = 0;

	/************************************** Bit Size USART **************************************************/
#if  ( USART1_WORD_LENGTH == _8BIT_WORD_LENGTH )

	CLEAR_BIT(USART1 -> CR1, M);

#elif ( USART1_WORD_LENGTH == _9BIT_WORD_LENGTH )

	SET_BIT( USART1 -> CR1 , M );

#endif

	/************************************** Parity mode USART ***********************************************/
#if  ( USART1_PARITY == PARITY_DISABLE )

	CLEAR_BIT(USART1 -> CR1, PCE);

#elif ( USART1_PARITY == EVEN_PARITY )

	SET_BIT( USART1 -> CR1 , PCE );
	CLEAR_BIT( USART1 -> CR1 , PS );

#elif ( USART1_PARITY == ODD_PARITY )

	SET_BIT( USART1 -> CR1 , PCE );
	SET_BIT( USART1 -> CR1 , PS );


#endif

	/************************************ Enable / Disable Interrupt ********************************************/
#if  ( USART1_INTERRUPT == INT_DISABLE )

	CLEAR_BIT( USART1 -> CR1 , RXNEIE_USART1);
	CLEAR_BIT( USART1 -> CR1 , TCIE_USART1);
	CLEAR_BIT( USART1 -> CR1 , TXEIE_USART1 );

#elif ( USART1_INTERRUPT == TXE_INT_ENABLE )

	SET_BIT( MUSART1 -> CR1 , TXEIE_USART1 );

#elif ( USART1_INTERRUPT == TCE_INT_ENABLE )

	SET_BIT( MUSART1 -> CR1 , TCIE_USART1 );

#elif ( USART1_INTERRUPT == RXNE_INT_ENABLE )

	SET_BIT( MUSART1 -> CR1 , RXNEIE_USART1 );

#endif

	/************************************ Enable / Disable TX ********************************************/
#if  ( USART1_TRANSMITTER == TRANSMITTER_ENABLE )

	SET_BIT(USART1->CR1, TE);

#elif ( USART1_TRANSMITTER == TRANSMITTER_DISABLE )

	CLEAR_BIT( USART1 -> CR1 , TE );

#endif

	/************************************ Enable / Disable RC ********************************************/
#if   ( USART1_RECEIVER == RECEIVER_ENABLE )

	SET_BIT(USART1->CR1, RE);

#elif ( USART1_RECEIVER == RECEIVER_DISBLE )

	CLEAR_BIT( USART1 -> CR1 , RE );

#endif

	/************************************ Stop Bit Mode ********************************************/
#if   ( USART1_STOP_BITS == ONE_STOP_BIT )

	CLEAR_BIT(USART1->CR2, STOP0);
	CLEAR_BIT(USART1->CR2, STOP1);

#elif ( USART1_STOP_BITS == HALF_STOP_BIT )

	SET_BIT( USART1 -> CR2 , STOP0 ); CLEAR_BIT( USART1 -> CR2 , STOP1 );

#elif ( USART1_STOP_BITS == TWO_STOP_BIT )

	CLEAR_BIT( USART1 -> CR2 , STOP0 ); SET_BIT( USART1 -> CR2 , STOP1 );

#elif ( USART1_STOP_BITS == ONE_AND_HALF_STOP_BIT )

	SET_BIT( USART1 -> CR2 , STOP0 ); SET_BIT( USART1 -> CR2 , STOP1 );

#endif

	SET_BIT( USART1 -> CR1 , UE );

#elif     ( USART1_STATUS == USART1_DISABLE )

	CLEAR_BIT( USART1 -> CR1 , UE );

#endif

}

void MUSART1_SendCharSync ( uint8 Char ){

	USART1 -> DR = Char ;
	while (GET_BIT( USART1 -> SR ,TC_USART1 ) == 0);
	CLEAR_BIT(USART1 -> SR ,TC_USART1);

}

void USART1_SendStringSynch ( uint8 *String ){

	uint8 i=0;

	while (String[i] != '\0')
	{
		MUSART1_SendCharSync (String[i]);
		i++;
	}
}

uint8 USART1_RecCharSynch ( void ){

	uint8  Data = 0;
	uint32 TimeOut = 0 ;
	CLEAR_BIT( USART1 -> SR , RXNE_USART1); /* it can be in line 178 */

	while ( ( GET_BIT( USART1 -> SR ,RXNE_USART1) == 0  ) && ( TimeOut < THRESHOLD_VALUE  ) )
	{
		TimeOut++;
	}

	if (TimeOut == THRESHOLD_VALUE)
	{
		Data = 255;
	}
	else
	{
		Data = USART1->DR;
	}


	return Data;

}

void USART1_EnableClock(void) {
    RCC_enablePeripheral(APB2_BUS, USART1_RCC);
}
