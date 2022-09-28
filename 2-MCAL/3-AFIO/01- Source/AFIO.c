/*************************************************************************************************
 * [MODULE_NAME]:  AFIO_Prog.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  AFIO Program
 ************************************************************************************************/
#include "TYPES.h"
#include "MACROS.h"

#include "AFIO_INTERFACE.h"
#include "AFIO_REG.h"

#include "RCC_INTERFACE.h"



void AFIO_setEXTIConfiguration( uint8 EXTI_Line , uint8 PortMap )
{

	uint8 RegIndex = 0;


	if (EXTI_Line <= 3)
	{
		RegIndex=0;

	}
	else if (EXTI_Line <= 7)
	{
		RegIndex=1;
		EXTI_Line-=4;

	}
	else if (EXTI_Line <= 11)
	{
		RegIndex=2;
		EXTI_Line-=8;
	}
	else if (EXTI_Line <= 15)
	{
		RegIndex=3;
		EXTI_Line-=12;
	}
	AFIO->EXTICR[RegIndex] &=~((0b1111) << (4*EXTI_Line));
	AFIO->EXTICR[RegIndex] |=((PortMap) << (4*EXTI_Line));

}


void AFIO_enableClock (void) {

	RCC_enablePeripheral(APB2_BUS , AFIO_RCC);
}
