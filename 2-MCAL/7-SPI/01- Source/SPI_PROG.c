/*************************************************************************************************
 * [MODULE_NAME]:  SPI_Prog.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  SPI Program
 ************************************************************************************************/
#include "TYPES.h"
#include "MACROS.h"

#include "GPIO_INTERFACE.h"
#include "RCC_INTERFACE.h"

#include "SPI_INTERFACE.h"
#include "SPI_CONFG.h"
#include "SPI_REG.h"

void (*SPI1_CallBack) (void);

void SPI_init ( void ){

   /* Initialize CR1 Register */
	 SPI1->CR1 = 0x0000;

/************************************ Enable / Disable SPI1 ********************************************/
#if   (  SP1_STATUS  ==  SPI_ENABLE )


/*************************************** SPI1 CLOCK MODE  ************************************************/
#if	   ( SPI1_CLOCK_MODE == SPI_MODE1 )     /* Read then Write & LOW is IDLE state */

	CLEAR_BIT( SPI1 -> CR1 , CPHA ); CLEAR_BIT( SPI1 -> CR1 , CPOL );

#elif	( SPI1_CLOCK_MODE == SPI_MODE2 )     /* Write then Read & LOW is IDLE state */

	SET_BIT( SPI1 -> CR1 , CPHA ); CLEAR_BIT( SPI1 -> CR1 , CPOL );

#elif	( SPI1_CLOCK_MODE == SPI_MODE3 )     /* Read then Write & HIGH is IDLE state */

	CLEAR_BIT( SPI1 -> CR1 , CPHA ); SET_BIT( SPI1 -> CR1 , CPOL );

#elif	( SPI1_CLOCK_MODE == SPI_MODE4 )     /* Write then Read & HIGH is IDLE state */

	SET_BIT( SPI1 -> CR1 , CPHA ); SET_BIT( SPI1 -> CR1 , CPOL );

#endif

/************************************ MASTER / Slave SPI1 ********************************************/
#if    ( SPI1_MASTER_SLAVE == SPI_MASTER )

	SET_BIT( SPI1 -> CR1 , MSTR );

#elif  ( SPI1_MASTER_SLAVE == SPI_SLAVE  )

	CLEAR_BIT( SPI1 -> CR1 , MSTR );

#endif

/************************************ MSB / LSB SPI1 ********************************************/
#if   ( SPI1_DATA_ORDER == SPI_MSB_FIRST )

	CLEAR_BIT( SPI1 -> CR1 , LSBFIRST );

#elif ( SPI1_DATA_ORDER == SPI_LSB_FIRST )

	SET_BIT( SPI1 -> CR1 , LSBFIRST );

#endif

/************************************ SW / HW Slave Select SPI1 ********************************************/
#if   ( SPI1_SS_MANAGE  == HW_SLAVE_MANAGEMENT )

	CLEAR_BIT( SPI1 -> CR1 , SSM );

#elif ( SPI1_SS_MANAGE == SW_SLAVE_MANAGEMENT )

	SET_BIT( SPI1 -> CR1 , SSM );

#endif

/************************************ DFF 8-bit / 16-bit SPI1 ********************************************/
#if   ( SPI1_DATA_SIZE == SPI_8BIT_DATA )

	CLEAR_BIT( SPI1 -> CR1 , DFF );

#elif ( SPI1_DATA_SIZE == SPI_16BIT_DATA )

	SET_BIT( SPI1 -> CR1 , DFF );

#endif

/************************************ Interrupt Enable / Disable SPI1 ********************************************/
#if   ( SPI1_INT_STATUS == SPI_INT_DISABLE )

	 SPI1 -> CR2 = 0 ;

#elif ( SPI1_INT_STATUS == SPI_TXE_INT_ENABLE )

	SET_BIT( SPI1 -> CR2 , 7 );

#elif ( SPI1_INT_STATUS == SPI_RXNE_INT_ENABLE )

	SET_BIT( SPI1 -> CR2 , 6 );

#endif

	    SPI1 -> CR1 &= 0xFFC7 ;
		SPI1 -> CR1 |= ( SPI1_PRESCALLER << BR0 ) ;

		SET_BIT( SPI1 -> CR1 , SPE );

   /******************************** Initialize GPIO Pins *************************************************/
		RCC_enablePeripheral(APB2_BUS ,SPI1_RCC);
		GPIO_enablePortClock(SPI1_PORT);

		GPIO_setupPinMode(SPI_SLAVE_PIN, OUTPUT_SPEED_10MHZ_PP);
		GPIO_setupPinMode( SPI1_PORT , MOSI_PIN  , OUTPUT_SPEED_10MHZ_AFPP );
		GPIO_setupPinMode( SPI1_PORT , MISO_PIN  , INPUT_FLOATING );
		GPIO_setupPinMode( SPI1_PORT , SCK_PIN   , OUTPUT_SPEED_10MHZ_AFPP );

#elif (  SP1_STATUS  ==  SPI_DISABLE )

		CLEAR_BIT( SPI1 -> CR1 , SPE );

#endif

}

void SPI_sendRecieveSynch(uint8 DataToTransmit ,uint8 *DataToReceive)
{

	/* Clear for slave select pin*/
	GPIO_setPinValue(SPI_SLAVE_PIN, LOW);

	/* Put data transmit to SPI data register*/
	SPI1->DR = DataToTransmit;

	/* wait Busy flag finish*/
	while ( GET_BIT(SPI1->SR , BSY) == 1);

	/* return received data*/
	*DataToReceive = SPI1->DR;

	/*set for slave select pin*/
	GPIO_setPinValue(SPI_SLAVE_PIN, HIGH);

}

uint8 SPI1_VidSendDataU8 ( uint8 Data ){

	/* Clear for slave select pin*/
		GPIO_setPinValue(SPI_SLAVE_PIN, LOW);

		/* Put data transmit to SPI data register*/
		SPI1->DR = Data;

		/* wait Busy flag finish*/
		while ( GET_BIT(SPI1->SR , BSY) == 1);

		/*set for slave select pin*/
		GPIO_setPinValue(SPI_SLAVE_PIN, HIGH);

		/* return received data*/
		 return (uint8) (SPI1->DR);

}


void SPI1_setCallBack( void (*ptr) (void) ){

	SPI1_CallBack = ptr;

}

void SPI1_IRQHandler(void){

	SPI1_CallBack();

}


