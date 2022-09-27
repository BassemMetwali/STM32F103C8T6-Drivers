/*************************************************************************************************
 * [MODULE_NAME]:  NVIC_Prog.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  NVIC Program
 ************************************************************************************************/

#include "TYPES.h"
#include "MACROS.h"

#include "NVIC_INTERFACE.h"
#include "NVIC_REG.h"



/* Enable NVIC interrupt of Peripheral x for external interrupts only */
void NVIC_enablePeripheral ( uint8 INTID ){

	NVIC->ISER[ INTID / 32 ] = 1 << ( INTID % 32 ) ;
}


void NVIC_disablePeripheral ( uint8 INTID ){

	NVIC->ICER[ INTID / 32 ] = 1 << ( INTID % 32 ) ;

}

void NVIC_setPendingFlag ( uint8 INTID ){

	NVIC->ISPR[ INTID / 32 ] = 1 << ( INTID % 32 ) ;
}

void NVIC_clearPendingFlag ( uint8 INTID ){

	NVIC->ICPR[ INTID / 32 ] = 1 << ( INTID % 32 ) ;

}


uint8  NVIC_getActiveFlag( uint8 INTID ){

	uint8 Active_Flag = GET_BIT( (NVIC->IABR[ INTID/32 ]) , ( INTID % 32 ) );
	return Active_Flag ;

}

void NVIC_setPriority( sint8 INTID , uint8 GroupPriority , uint8 SubPriority , uint32 GroupMode )
{
	uint8 Priority =  SubPriority | ( GroupPriority << ( (GroupMode - 0x05FA0300) / 256 ) ) ;

   /*     Internal Core Peripherals         */
	if( INTID < 0  ){

			if( INTID == MEMORY_MANAGE || INTID == BUS_FAULT || INTID == USAGE_FAULT ){

				INTID += 3;
				SCB->SHPR1 = ( Priority ) << ( (8 * INTID) + 4 );

			}
			else if ( INTID == SV_CALL ){

				INTID += 7;
				SCB->SHPR2 = ( Priority ) << ( (8 * INTID) + 4 );

			}
			else if( INTID == PEND_SV || INTID == SYSTICK ){

				INTID += 8;

				SCB->SHPR3 = ( Priority ) << ( (8 * INTID) + 4 );

			}

		}
	   /*     External Core Peripherals         */
		else if( INTID >= 0 ){

			NVIC->IPR[ INTID ] = Priority << 4 ;

		}

	SCB->AIRCR = GroupMode;
}

