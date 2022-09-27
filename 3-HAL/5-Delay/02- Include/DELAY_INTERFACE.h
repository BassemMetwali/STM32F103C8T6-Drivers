/*************************************************************************************************
 * [MODULE_NAME]:  DELAY_INTERFACE.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  All # Defines to be used by User & Function's prototype
 ************************************************************************************************/
#ifndef DELAY_INTERFACE_H_
#define DEALY_INTERFACE_H_

void _delay_ms( uint32 Time );


/* Suppose That The Clock System (AHB) = 8MHZ EXT & The Systick Clock Is = AHB/8 */
void _delay_us( uint32 Time );




#endif
