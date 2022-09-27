/*************************************************************************************************
 * [MODULE_NAME]:  DAC_CONFG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Configuration of DAC Peripheral
 ************************************************************************************************/


#ifndef DAC_CONFG_
#define DAC_CONFG_


/**********************************************************************/
/*                                                                    */
/*                        GPIO Peripheral Modes                       */
/*                              0-GPIOA_ID                            */
/*                              1-GPIOB_ID                            */
/*                              2-GPIOC_ID                            */
/**********************************************************************/
#define DAC_PORT                      GPIOA_ID


#define NO_OF_SAMPLES_PER_SEC         125

/**********************************************************************/
/*                                                                    */
/*                        GPIO PORT Modes                             */
/*                              0-LOW_PINS                            */
/*                              1-HIGH_PINS                           */
/**********************************************************************/
#define DAC_L_H                       LOW_PINS



#endif
