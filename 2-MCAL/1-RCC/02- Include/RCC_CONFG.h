/*************************************************************************************************
 * [MODULE_NAME]:  RCC_REG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Registers of RCC
 ************************************************************************************************/

#ifndef RCC_CONFG_H_
#define RCC_CONFG_H_


/*******************************************************************/
/*                                                                 */
/*                       ClockType Maybe :                         */
/*                       1-HSI                                     */
/*                       2-HSE_RC                                  */
/*                       3-PLL                                     */
/*                       4-HSE_Crystal                             */
/*                                                                 */
/*******************************************************************/


#define CLOCK_TYPE       HSE_Crystal

/**********************************************************************/
/*                                                                    */
/*               Choose Clock Source To PLL                           */
/*                0-PLL_HSE (High Speed External up to 25 MHz)        */
/*                1-PLL_Half_HSE = HSE/2                              */
/*                2-PLL_Half_HSI  (High speed internal up to 8 MHz)   */
/**********************************************************************/

#define PLL_SOURCE       PLL_Half_HSI


/********************************************************************************************/
/*                              ClockFactor For PLL  Maybe :                                */
/*                              0-NO_CLOCK_FACTOR                                           */
/*                              1-PLL_Clock_MULTIPLE_BY_2                                   */
/*                              2-PLL_Clock_MULTIPLE_BY_3                                   */
/*                              3-PLL_Clock_MULTIPLE_BY_4                                   */
/*                              4-PLL_Clock_MULTIPLE_BY_5                                   */
/*                              5-PLL_Clock_MULTIPLE_BY_6                                   */
/*                              6-PLL_Clock_MULTIPLE_BY_7                                   */
/*                              7-PLL_Clock_MULTIPLE_BY_8                                   */
/*                              8-PLL_Clock_MULTIPLE_BY_9                                   */
/*                              9-PLL_Clock_MULTIPLE_BY_10                                  */
/*                              10-PLL_Clock_MULTIPLE_BY_11                                 */
/*                              11-PLL_Clock_MULTIPLE_BY_12                                 */
/*                              12-PLL_Clock_MULTIPLE_BY_13                                 */
/*                              13-PLL_Clock_MULTIPLE_BY_14                                 */
/*                              14-PLL_Clock_MULTIPLE_BY_15                                 */
/*                              15-PLL_Clock_MULTIPLE_BY_16                                 */
/********************************************************************************************/


#define PLL_CLOCK_FACTOR     PLL_Clock_MULTIPLE_BY_16

/*******************************************************************/
/*                                                                 */
/*             Microcontroller Clock output(MCO) Maybe :           */
/*               1-MCO_SYSCLK (System clock must not exceed 50 MHz */
/*               2-MCO_HSI                                         */
/*               3-MCO_HSE                                         */
/*               4-MCO_PLL_DIVIDED_BY_2                            */
/*               5-MCO_NOCLK                                       */
/*                                                                 */
/*******************************************************************/

#define MCO_SOURCE   MCO_NOCLK

/**********************************************************************/
/*                                                                    */
/*                 Clock Security System May be                       */
/*                 1-ENABLE_CLOCK_SECURITY_SYSTEM:                    */
/* 				   To Set HSI By H.W When There are Failure In HSE    */
/* 				   To Set HSI By H.W When Leaving Stop Or Standby     */
/* 				   2-DISABLE_CLOCK_SECURITY_SYSTEM                    */
/* 				   The Previouse To Feature Doesnot Happen            */
/*                                                                    */
/**********************************************************************/

#define CLOCK_SECURITY_SYSTEM     DISABLE_CLOCK_SECURITY_SYSTEM

/********************************************************************************************/
/*                                                                                           */
/*                            AHB Prescaler Factor Maybe :                                   */
/*                              1-AHB_SYSCLK_not_divided                                     */
/*                              2-AHB_SYSCLK_divided_by_2                                    */
/*                              3-AHB_SYSCLK_divided_by_4                                    */
/*                              4-AHB_SYSCLK_divided_by_8                                    */
/*                              5-AHB_SYSCLK_divided_by_16                                   */
/*                              6-AHB_SYSCLK_divided_by_64                                   */
/*                              7-AHB_SYSCLK_divided_by_128                                  */
/*                              8-AHB_SYSCLK_divided_by_256                                  */
/*                              9-AHB_SYSCLK_divided_by_512                                  */
/*                                                                                           */
/********************************************************************************************/

#define AHB_PRESCALER  AHB_SYSCLK_not_divided

/********************************************************************************************/
/*                                                                                           */
/*                            APB1 Prescaler Factor Maybe :                                  */
/*                              1-APB1_SYSCLK_not_divided                                    */
/*                              2-APB1_SYSCLK_divided_by_2                                   */
/*                              3-APB1_SYSCLK_divided_by_4                                   */
/*                              4-APB1_SYSCLK_divided_by_8                                   */
/*                              5-APB1_SYSCLK_divided_by_16                                  */
/*                                                                                           */
/********************************************************************************************/

#define APB1_PRESCALER  APB1_SYSCLK_not_divided

/********************************************************************************************/
/*                                                                                          */
/*                            APB2 Prescaler Factor Maybe :                                 */
/*                              1-APB2_SYSCLK_not_divided                                   */
/*                              2-APB2_SYSCLK_divided_by_2                                  */
/*                              3-APB2_SYSCLK_divided_by_4                                  */
/*                              4-APB2_SYSCLK_divided_by_8                                  */
/*                              5-APB2_SYSCLK_divided_by_16                                 */
/*                                                                                          */
/********************************************************************************************/

#define APB2_PRESCALER  APB2_SYSCLK_not_divided

/********************************************************************************************/
/*                                                                                         */
/*                            ADC Prescaler Factor Maybe :                                 */
/*                              1-ADC_PCLK2_divided_by_2                                   */
/*                              2-ADC_PCLK2_divided_by_4                                   */
/*                              3-ADC_PCLK2_divided_by_6                                   */
/*                              4-ADC_PCLK2_divided_by_8                                    */
/********************************************************************************************/

#define ADC_PRESCALER  ADC_PCLK2_divided_by_2

/********************************************************************************************/
/*                                                                                         */
/*                            USB Prescaler Factor Maybe :                                 */
/*                              1-USB_PLL_clock_is_divided_by_OneHalf                      */
/*                              2-USB_PLL_clock_is_not_divided                             */
/********************************************************************************************/

#define USB_PRESCALER  USB_PLL_clock_is_not_divided

#endif
