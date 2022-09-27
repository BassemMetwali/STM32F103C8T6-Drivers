/*************************************************************************************************
 * [MODULE_NAME]:  EXTI_INTERFACE.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  All # Defines to be used by User & Function's prototype
 ************************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/********************************** External Interrupt Modes ********************************************/

#define RISING_EDGE    0
#define FALLING_EDGE   1
#define ON_CHANGE      2

/******************************************* PORTS  *****************************************************/

#define PORTA           0
#define PORTB           1
#define PORTC           2

/********************************** External Interrupt Lines ********************************************/

#define EXTI_LINE0  0
#define EXTI_LINE1  1
#define EXTI_LINE2  2
#define EXTI_LINE3  3

#define EXTI_LINE4  4
#define EXTI_LINE5  5
#define EXTI_LINE6  6
#define EXTI_LINE7  7

#define EXTI_LINE8  8
#define EXTI_LINE9  9
#define EXTI_LINE10 10
#define EXTI_LINE11 11

#define EXTI_LINE12 12
#define EXTI_LINE13 13
#define EXTI_LINE14 14
#define EXTI_LINE15 15

/************************************ Functions Prototypes **********************************************/

/*
 * Description :
 * Setup the Mode & EXTILine.
 * EXTI has 19 Line & 3 modes:RISING_EDGE / FALLING_EDGE / ON_CHANGE.
 */
void EXTI_init( uint8 EXTILine , uint8 EXTIMode );

/*
 * Description :
 * Enable any EXTILine independently.
 */
void EXTI_enableEXTI( uint8 EXTILine);

/*
 * Description :
 * Disable any EXTILine independently.
 */
void EXTI_disableEXTI( uint8 EXTILine);

/*
 * Description :
 * Generate a Software Interrupt.
 */
void EXTI_SoftWareTrigger( uint8 EXTILine);

/*
 * Description :
 * Read interrupt Pending Flag.
 */
uint8 EXTI_readPendingFlag( uint8 EXTILine);

/*
 * Description :
 * Clear interrupt Pending Flag.
 */
void EXTI_clearPendingFlag( uint8 EXTILine);

/*
 * Description :
 * CallBack Function used to pass any function to it and EXTILine you want & when the interrupt is triggered it calls this function.
 */
void EXTI_setCallBack (uint8 EXTILine, void (*ptr) (void));


#endif
