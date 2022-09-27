/*************************************************************************************************
 * [MODULE_NAME]:  STP_CONFG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Configuration of STP IC
 ************************************************************************************************/
#ifndef STP_CONFG_H_
#define STP_CONFG_H_



/**********************************************************************/
/*                                                                    */
/*               STP_DATA_PORT Peripheral Modes                       */
/*                              0-GPIOA_ID                            */
/*                              1-GPIOB_ID                            */
/*                              2-GPIOC_ID                            */
/**********************************************************************/

#define STP_DATA_PORT   	 GPIOA_ID
#define STP_DATA_PIN    	 PIN0

#define STP_BIT_LATCH_PORT   GPIOA_ID
#define STP_BIT_LATCH_PIN    PIN1

#define STP_BYTE_LATCH_PORT  GPIOA_ID
#define STP_BYTE_LATCH_PIN   PIN2



#endif
