/*************************************************************************************************
 * [MODULE_NAME]:  EXTI_Prog.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  EXTI Program
 ************************************************************************************************/

#include "TYPES.h"
#include "MACROS.h"

#include "EXTI_INTERFACE.h"
#include "EXTI_REG.h"

/* an Array Of Pointer To Function */
static void(*EXTI_callback[16])(void);

/*
 * Description :
 * Setup the Mode & EXTILine.
 * EXTI has 19 Line & 3 modes:RISING_EDGE / FALLING_EDGE / ON_CHANGE.
 */
void EXTI_init( uint8 EXTILine , uint8 EXTIMode )
{

	switch (EXTIMode) {

	case RISING_EDGE:
		SET_BIT(EXTI->RTSR, EXTILine);
		CLEAR_BIT(EXTI->FTSR, EXTILine);
		break;
	case FALLING_EDGE:
		SET_BIT(EXTI->FTSR, EXTILine);
		CLEAR_BIT(EXTI->RTSR, EXTILine);
		break;
	case ON_CHANGE:
		SET_BIT(EXTI->FTSR, EXTILine);
		SET_BIT(EXTI->RTSR, EXTILine);
		break;

	}

	SET_BIT(EXTI->IMR , EXTILine);
}

/*
 * Description :
 * Enable any EXTILine independently.
 */
void EXTI_enableEXTI( uint8 EXTILine){

	SET_BIT(EXTI->IMR , EXTILine);

}

/*
 * Description :
 * Disable any EXTILine independently.
 */
void EXTI_disableEXTI( uint8 EXTILine){

	CLEAR_BIT(EXTI->IMR , EXTILine);

}

/*
 * Description :
 * Generate a Software Interrupt.
 */
void EXTI_SoftWareTrigger( uint8 EXTILine){

	SET_BIT( EXTI->SWIER , EXTILine );

}

/*
 * Description :
 * Read interrupt Pending Flag.
 */
uint8 EXTI_readPendingFlag( uint8 EXTILine){

	uint8 value=0;
	value = GET_BIT(EXTI->PR,EXTILine);
     return value ;
}

/*
 * Description :
 * Clear interrupt Pending Flag.
 */
void EXTI_clearPendingFlag( uint8 EXTILine){


	 SET_BIT(EXTI->PR,EXTILine);

}

/*
 * Description :
 * CallBack Function used to pass any function to it and EXTILine you want & when the interrupt is triggered it calls this function.
 */
void EXTI_setCallBack (uint8 EXTILine, void (*ptr)(void)) {
    EXTI_callback[EXTILine] = ptr;
}


/*
 * Description :
 * The Main ISR/IRQ(Interrupt ReQuest) for all EXTILines.
 */
void EXTI0_IRQHandler (void) {
    EXTI_callback[0]();
    /* Clear Pending Flag */
    SET_BIT(EXTI->PR, 0);
}
void EXTI1_IRQHandler (void) {
    EXTI_callback[1]();
    /* Clear Pending Flag */
    SET_BIT(EXTI->PR, 1);
}
void EXTI2_IRQHandler (void) {
    EXTI_callback[2]();
    SET_BIT(EXTI->PR, 2);
}
void EXTI3_IRQHandler (void) {
    EXTI_callback[3]();
    SET_BIT(EXTI->PR, 3);
}
void EXTI4_IRQHandler (void) {
    EXTI_callback[4]();
    SET_BIT(EXTI->PR, 4);
}
void EXTI5_IRQHandler (void) {
    EXTI_callback[5]();
    SET_BIT(EXTI->PR, 5);
}
void EXTI6_IRQHandler (void) {
    EXTI_callback[6]();
    SET_BIT(EXTI->PR, 6);
}
void EXTI7_IRQHandler (void) {
    EXTI_callback[7]();
    SET_BIT(EXTI->PR, 7);
}
void EXTI8_IRQHandler (void) {
    EXTI_callback[8]();
    SET_BIT(EXTI->PR, 8);
}
void EXTI9_IRQHandler (void) {
    EXTI_callback[9]();
    SET_BIT(EXTI->PR, 9);
}
void EXTI10_IRQHandler (void) {
    EXTI_callback[10]();
    SET_BIT(EXTI->PR, 10);
}
void EXTI11_IRQHandler (void) {
    EXTI_callback[11]();
    SET_BIT(EXTI->PR, 11);
}
void EXTI12_IRQHandler (void) {
    EXTI_callback[12]();
    SET_BIT(EXTI->PR, 12);
}
void EXTI13_IRQHandler (void) {
    EXTI_callback[13]();
    SET_BIT(EXTI->PR, 13);
}
void EXTI14_IRQHandler (void) {
    EXTI_callback[14]();
    SET_BIT(EXTI->PR, 14);
}
void EXTI15_IRQHandler (void) {
    EXTI_callback[15]();
    SET_BIT(EXTI->PR, 15);
}
