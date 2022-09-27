/*************************************************************************************************
 * [MODULE_NAME]:  STP_INTERFACE.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  All # Defines to be used by User & Function's prototype
 ************************************************************************************************/

#ifndef STP_INTERACE_H_
#define STP_INTERFACE_H_

/*
 * Description :
 * Setup modes for Storage pin & Shift pin & Serial Data pin as an OUTPUT.
 * Initialize pins if there have a value before.
 */
void STP_init( void );

/*
 * Description :
 * Write a Data in form of zeros & ones to Serial Data pin (Data is 8_bit).
 * Give Rising edge to Shift pin after firing Data to shift data in IC.
 * Give Rising edge to Storage pin after shifting all Data.
 */
void STP_byteOutput ( uint8 Data );

/*
 * Description :
 * Write a Data in form of zeros & ones to Serial Data pin (Data is 16_bit).
 * Give Rising edge to Shift pin after firing Data to shift data in IC.
 * Give Rising edge to Storage pin after shifting all Data.
 */
void STP_halfWordOutput ( uint16 Data );

#endif
