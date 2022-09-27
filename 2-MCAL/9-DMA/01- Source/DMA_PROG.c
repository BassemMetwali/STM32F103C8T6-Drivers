/*************************************************************************************************
 * [MODULE_NAME]:  DMA_PROG.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  DMA Program
 ************************************************************************************************/

#include "TYPES.h"
#include "MACROS.h"

#include "RCC_INTERFACE.h"

#include "DMA_INTERFACE.h"
#include "DMA_CONFG.h"
#include "DMA_PRIVATE.h"
#include "DMA_REG.h"

static void(*DMA_callback[7])(void);

void DMA_setConfiguration( uint8 Channel , uint8 Direction ,uint8 CircMode , uint8 MEM2MEMmode , uint8 PeripheralINC ,
		uint8 MemoryINC , uint8 memorysize , uint8 peripheralsize , uint8 ChannelPriority , uint32 * PeripheralAddress , uint32 * MemoryAddress ,
		uint16 NDT  )
{
     /* To Configure DMA you should Disable it */
	CLEAR_BIT(DMA->CHANNEL[Channel].CCR, EN);

	/************************************* Configuration of DMA Direction **********************************************/
	switch (Direction) {

	case PREI_TO_MEM:
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, DIR);
		break;

	case MEM_TO_PREI:
		SET_BIT(DMA->CHANNEL[Channel].CCR, DIR);
		break;
	}

	/************************************* Configuration of DMA MEM2MEM Mode ********************************************/
	    switch (MEM2MEMmode)
	    {
         /*  If You want to Transfer Data from RAM to RAM */
	    case MEM_TO_MEM_ENABLE:
	    	SET_BIT(DMA->CHANNEL[Channel].CCR,MEM2MEM);
	    	break;

	    case MEM_TO_MEM_DISABLE:
	    	CLEAR_BIT(DMA->CHANNEL[Channel].CCR,MEM2MEM);
	    	break;
	    }


	/************************************* Configuration of DMA Modes **********************************************/
    switch (CircMode)
    {
    /*  If You want to Transfer Data without waiting any trigger, it still transferring always */
    case DMA_ENABLE_CIRCULAR:
    	SET_BIT(DMA->CHANNEL[Channel].CCR,CIRC);
    	break;

    case DMA_DISABLE_CIRCULAR:
    	CLEAR_BIT(DMA->CHANNEL[Channel].CCR,CIRC);
    	break;
    }

    /************************************* Configuration of DMA Channel Priority ****************************************/
	switch (ChannelPriority) {

	case DMA_LOW:
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, PL0);
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, PL1);
		break;

	case DMA_MEDIUM:
		SET_BIT(DMA->CHANNEL[Channel].CCR, PL0);
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, PL1);
		break;

	case DMA_HIGH:
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, PL0);
		SET_BIT(DMA->CHANNEL[Channel].CCR, PL1);
		break;

	case DMA_VERY_HIGH:
		SET_BIT(DMA->CHANNEL[Channel].CCR, PL0);
		SET_BIT(DMA->CHANNEL[Channel].CCR, PL1);
		break;
	}

	  /************************************* Configuration of DMA Peripheral Size  ***************************************/
		switch (peripheralsize) {

		case BYTE:
			CLEAR_BIT(DMA->CHANNEL[Channel].CCR, PSIZE0);
			CLEAR_BIT(DMA->CHANNEL[Channel].CCR, PSIZE1);
			break;

		case HALF_WORD:
			SET_BIT(DMA->CHANNEL[Channel].CCR, PSIZE0);
			CLEAR_BIT(DMA->CHANNEL[Channel].CCR, PSIZE1);
			break;

		case WORD:
			CLEAR_BIT(DMA->CHANNEL[Channel].CCR, PSIZE0);
			SET_BIT(DMA->CHANNEL[Channel].CCR, PSIZE1);
			break;

		}

		 /************************************* Configuration of DMA Memory Size  ***************************************/
	switch (memorysize) {

	case BYTE:
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, MSIZE0);
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, MSIZE1);
		break;

	case HALF_WORD:
		SET_BIT(DMA->CHANNEL[Channel].CCR, MSIZE0);
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, MSIZE1);
		break;

	case WORD:
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, MSIZE0);
		SET_BIT(DMA->CHANNEL[Channel].CCR, MSIZE1);
		break;

	}

	/************************************* Configuration of DMA Memory INC  ***************************************/
	switch (MemoryINC) {

	case MEM_INCREMENT_ENABLE:

		SET_BIT(DMA->CHANNEL[Channel].CCR, MINC);
		break;

	case MEM_INCREMENT_DISABLE:

		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, MINC);
		break;

	}

	/************************************* Configuration of DMA Peripheral INC  ***************************************/
		switch (PeripheralINC) {

		case PERIPHERAL_INCREMENT_ENABLE:

			SET_BIT(DMA->CHANNEL[Channel].CCR, PINC);
			break;

		case PERIPHERAL_INCREMENT_DISABLE:

			CLEAR_BIT(DMA->CHANNEL[Channel].CCR, PINC);
			break;

		}

		/******************************* SET Addresses of Peripheral & Memory **********************************************/
		DMA->CHANNEL[Channel].CPAR= (uint32)PeripheralAddress;
		DMA->CHANNEL[Channel].CMAR= (uint32)MemoryAddress;
		DMA->CHANNEL[Channel].CNDTR= NDT ;  /*  1000 means 1000 block of 32 bit each  */

/************************************************* Configuration of DMA interrupts  ******************************************/
#if    (DMA_TCIE ==  DMA_TCIE_ENABLE)

		SET_BIT(DMA->CHANNEL[Channel].CCR, TCIE);
#elif  (DMA_TCIE == DMA_TCIE_DISABLE)
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, TCIE);
#endif

#if   ( DMA_HTIE == DMA_HTIE_ENABLE)
		SET_BIT(DMA->CHANNEL[Channel].CCR, HTIE);

#elif  (DMA_HTIE == DMA_HTIE_DISABLE)
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, HTIE);
#endif

#if    (DMA_TEIE ==  DMA_TEIE_ENABLE)
		SET_BIT(DMA->CHANNEL[Channel].CCR, TEIE);

#elif  (DMA_TEIE == DMA_TEIE_DISABLE)
		CLEAR_BIT(DMA->CHANNEL[Channel].CCR, TEIE);
#endif

		/******************************************************* Enable DMA **********************************************/
		SET_BIT(DMA->CHANNEL[Channel].CCR, EN);
}

void DMA_clearFlag( uint8 Channel , uint8 Flag ){

	Channel *= 4 ;

	SET_BIT( DMA->IFCR , (Channel + Flag) );

}


void DMA_Enable( uint8 Channel ){

	DMA_clearFlag( Channel , DMA_GIF  );
	DMA_clearFlag( Channel , DMA_TCIF );
	DMA_clearFlag( Channel , DMA_HTIF );
	DMA_clearFlag( Channel , DMA_TEIF );

	SET_BIT( DMA->CHANNEL[ Channel ].CCR , EN );

}

void DMA_Disable( uint8 Channel ){

	CLEAR_BIT( DMA->CHANNEL[ Channel ].CCR , EN );

}

void DMA_setAddress( uint8 Channel , uint32 *PeripheralAddress , uint32 *MemoryAddress , uint16 NDT ){

	DMA->CHANNEL[ Channel ].CPAR  = (uint32)PeripheralAddress ;
	DMA->CHANNEL[ Channel ].CMAR  = (uint32)MemoryAddress ;
	DMA->CHANNEL[ Channel ].CNDTR =  NDT ;

}




uint8 DMA_getFlag( uint8 Channel , uint8 Flag ){

	uint8 Result = 0;

	Channel *= 4 ;

	Result = GET_BIT( DMA->ISR , (Channel + Flag ) );

	return Result ;

}

void DMA_enableClock(void)
{
	RCC_enablePeripheral(AHB_BUS, DMA1_RCC);
}


void DMA_setCallback(uint8 Channel, void (*ptr)(void))
{
    DMA_callback[Channel] = ptr;
}


/* IRQHandler Handlers */
void DMA1_Channel1_IRQHandler(void) {
    DMA_callback[0]();
    DMA -> IFCR = 0x0000000F; /* clear interrupt flags */
}
void DMA1_Channel2_IRQHandler(void) {
    DMA_callback[1]();
    DMA -> IFCR = 0x000000F0; /* clear interrupt flags */
}
void DMA1_Channel3_IRQHandler(void) {
    DMA_callback[2]();
    DMA -> IFCR = 0x00000F00; /* clear interrupt flags */
}
void DMA1_Channel4_IRQHandler(void) {
    DMA_callback[3]();
    DMA -> IFCR = 0x0000F000; /* clear interrupt flags */
}
void DMA1_Channel5_IRQHandler(void) {
    DMA_callback[4]();
    DMA -> IFCR = 0x000F0000; /* clear interrupt flags */
}
void DMA1_Channel6_IRQHandler(void) {
    DMA_callback[5]();
    DMA -> IFCR = 0x00F00000; /* clear interrupt flags */
}
void DMA1_Channel7_IRQHandler(void) {
    DMA_callback[6]();
    DMA -> IFCR = 0x0F000000; /* clear interrupt flags */
}

