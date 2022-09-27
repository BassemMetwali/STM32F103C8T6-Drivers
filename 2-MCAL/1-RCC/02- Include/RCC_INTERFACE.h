/*************************************************************************************************
 * [MODULE_NAME]:  RCC_REG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Registers of RCC
 ************************************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/**********************************************************************/
/*                                                                    */
/*                 Peripheral Clock Enable For AHB Bus                */
/*                              0-DMA1                                */
/*                              1-DMA2                                */
/*                              2-SRAM                                */
/*                              3-RESERVED                            */
/*                              4-FLITF                               */
/*                              5-RESERVED                            */
/*                              6-CRC                                 */
/*                              7-RESERVED                            */
/*                              8-FSMC                                */
/*                              9-RESERVED                            */
/*                              10-SDIO                               */
/*                                                                    */
/**********************************************************************/



#define    DMA1_RCC         0
#define    DMA2_RCC         1
#define    SRAM_RCC         2
#define    FLITF_RCC        4
#define    CRC_RCC          6
#define    FSMC_RCC         8
#define    SDIO_RCC         10



/**********************************************************************/
/*                                                                    */
/*                 Peripheral Clock Enable For APB2 Bus               */
/*                              0-AFIO                                */
/*                              1-RESERVED                            */
/*                              2-GPIOA                               */
/*                              3-GPIOB                               */
/*                              4-GPIOC                               */
/*                              5-GPIOD                               */
/*                              6-GPIOE                               */
/*                              7-GPIOF                               */
/*                              8-GPIOG                               */
/*                              9-ADC1                                */
/*                              10-ADC2                               */
/*                              11-TIM1                               */
/*                              12-SPI1                               */
/*                              13-TIM8                               */
/*                              14-USART1                             */
/*                              15-ADC3                               */
/*                              16-RESERVED                           */
/*                              17-RESERVED                           */
/*                              18-RESERVED                           */
/*                              19-TIM9                               */
/*                              20-TIM10                              */
/*                              21-TIM11                              */
/*                                                                    */
/**********************************************************************/




#define    AFIO_RCC         0
#define    GPIOA_RCC        2
#define    GPIOB_RCC        3
#define    GPIOC_RCC        4
#define    GPIOD_RCC        5
#define    GPIOE_RCC        6
#define    GPIOF_RCC        7
#define    GPIOG_RCC        8
#define    ADC1_RCC         9
#define    ADC2_RCC         10
#define    TIM1_RCC         11
#define    SPI1_RCC         12
#define    TIM8_RCC         13
#define    USART1_RCC       14
#define    ADC3_RCC         15
#define    TIM9_RCC         19
#define    TIM10_RCC        20
#define    TIM11_RCC        21



/**********************************************************************/
/*                                                                    */
/*                 Peripheral Clock Enable For APB1 Bus               */
/*                              0-TIM2                                */
/*                              1-TIM3                                */
/*                              2-TIM4                                */
/*                              3-TIM5                                */
/*                              4-TIM6                                */
/*                              5-TIM7                                */
/*                              6-TIM12                               */
/*                              7-TIM13                               */
/*                              8-TIM14                               */
/*                              9-RESERVED                            */
/*                              10-RESERVED                           */
/*                              11-WWDG                               */
/*                              12-RESERVED                           */
/*                              13-RESERVED                           */
/*                              14-SPI2                               */
/*                              15-SPI3                               */
/*                              16-RESERVED                           */
/*                              17-USART2                             */
/*                              18-USART3                             */
/*                              19-UART4                              */
/*                              20-UART5                              */
/*                              21-I2C1                               */
/*                              22-I2C2                               */
/*                              23-USB                                */
/*                              24-RESERVED                           */
/*                              25-CAN                                */
/*                              26-RESERVED                           */
/*                              27-BKP                                */
/*                              28-PWR                                */
/*                              29-DAC                                */
/*                                                                    */
/**********************************************************************/




#define    TIM2_RCC         0
#define    TIM3_RCC         1
#define    TIM4_RCC         2
#define    TIM5_RCC         3
#define    TIM6_RCC         4
#define    TIM7_RCC         5
#define    TIM12_RCC        6
#define    TIM13_RCC        7
#define    TIM14_RCC        8
#define    WWDG_RCC         11
#define    SPI2_RCC         14
#define    SPI3_RCC         15
#define    USART2_RCC       17
#define    USART3_RCC       18
#define    UART4_RCC        19
#define    UART5_RCC        20
#define    I2C1_RCC         21
#define    I2C2_RCC         22
#define    USB_RCC          23
#define    CAN_RCC          25
#define    BKP_RCC          27
#define    PWR_RCC          28
#define    DAC_RCC          29

/**********************************************************************/
/*                                                                    */
/*                 Choose Peripheral BUS in ARM                       */
/*                              0-AHB BUS                             */
/*                              1-APB1 BUS                            */
/*                              2-APB2 BUS                            */
/**********************************************************************/


#define    AHB_BUS       0
#define    APB1_BUS      1
#define    APB2_BUS      2

/*******************************************************************/
/*                                                                 */
/*                       ClockType Maybe :                         */
/*                       1-HSI                                     */
/*                       2-HSE_RC                                  */
/*                       3-PLL                                     */
/*                       4-HSE_Crystal                             */
/*                                                                 */
/*******************************************************************/


#define HSI                         1
#define HSE_RC                      2
#define PLL                         3
#define HSE_Crystal                 4



/**********************************************************************/
/*                                                                    */
/*               Choose Clock Source To PLL                           */
/*                0-PLL_HSE (High Speed External up to 25 MHz)        */
/*                1-PLL_Half_HSE = HSE/2                              */
/*                2-PLL_Half_HSI  (High speed internal up to 8 MHz)   */
/**********************************************************************/


#define    PLL_HSE           0
#define    PLL_Half_HSE      1
#define    PLL_Half_HSI      2


/********************************************************************************************/
/*                                                                                           */
/*                             PLL_Value For PLL  Maybe :                                    */
/*                              1-PLL_CLOCKk_MULTIPLE_BY_2                                   */
/*                              2-PLL_CLOCKk_MULTIPLE_BY_3                                   */
/*                              3-PLL_CLOCKk_MULTIPLE_BY_4                                   */
/*                              4-PLL_CLOCKk_MULTIPLE_BY_5                                   */
/*                              5-PLL_CLOCKk_MULTIPLE_BY_6                                   */
/*                              6-PLL_CLOCKk_MULTIPLE_BY_7                                   */
/*                              7-PLL_CLOCKk_MULTIPLE_BY_8                                   */
/*                              8-PLL_CLOCKk_MULTIPLE_BY_9                                   */
/*                              9-PLL_CLOCKk_MULTIPLE_BY_10                                  */
/*                              10-PLL_CLOCKk_MULTIPLE_BY_11                                 */
/*                              11-PLL_CLOCKk_MULTIPLE_BY_12                                 */
/*                              12-PLL_CLOCKk_MULTIPLE_BY_13                                 */
/*                              13-PLL_CLOCKk_MULTIPLE_BY_14                                 */
/*                              14-PLL_CLOCKk_MULTIPLE_BY_15                                 */
/*                              15-PLL_CLOCKk_MULTIPLE_BY_16                                 */
/*                                                                                          */
/********************************************************************************************/

#define NO_CLOCK_FACTOR                                0b0000
#define PLL_CLOCK_MULTIPLE_BY_2                        0b0000
#define PLL_CLOCK_MULTIPLE_BY_3					       0b0001
#define PLL_CLOCK_MULTIPLE_BY_4                        0b0010
#define PLL_CLOCK_MULTIPLE_BY_5                        0b0011
#define PLL_CLOCK_MULTIPLE_BY_6                        0b0100
#define PLL_CLOCK_MULTIPLE_BY_7                        0b0101
#define PLL_CLOCK_MULTIPLE_BY_8                        0b0110
#define PLL_CLOCK_MULTIPLE_BY_9                        0b0111
#define PLL_CLOCK_MULTIPLE_BY_10                       0b1000
#define PLL_CLOCK_MULTIPLE_BY_11                       0b1001
#define PLL_CLOCK_MULTIPLE_BY_12                       0b1010
#define PLL_CLOCK_MULTIPLE_BY_13                       0b1011
#define PLL_CLOCK_MULTIPLE_BY_14                       0b1100
#define PLL_CLOCK_MULTIPLE_BY_15                       0b1101
#define PLL_Clock_MULTIPLE_BY_16                       0b1110


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

#define MCO_NOCLK                          0
#define MCO_SYSCLK                         1
#define MCO_HSI                            2
#define MCO_HSE                            3
#define MCO_PLL_DIVIDED_BY_2               4

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

#define DISABLE_CLOCK_SECURITY_SYSTEM              0
#define ENABLE_CLOCK_SECURITY_SYSTEM               1

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

#define AHB_SYSCLK_not_divided        0
#define AHB_SYSCLK_divided_by_2       8
#define AHB_SYSCLK_divided_by_4       9
#define AHB_SYSCLK_divided_by_8       10
#define AHB_SYSCLK_divided_by_16      11
#define AHB_SYSCLK_divided_by_64      12
#define AHB_SYSCLK_divided_by_128     13
#define AHB_SYSCLK_divided_by_256     14
#define AHB_SYSCLK_divided_by_512     15

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

#define APB1_SYSCLK_not_divided        0
#define APB1_SYSCLK_divided_by_2       4
#define APB1_SYSCLK_divided_by_4       5
#define APB1_SYSCLK_divided_by_8       6
#define APB1_SYSCLK_divided_by_16      7

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

#define APB2_SYSCLK_not_divided        0
#define APB2_SYSCLK_divided_by_2       4
#define APB2_SYSCLK_divided_by_4       5
#define APB2_SYSCLK_divided_by_8       6
#define APB2_SYSCLK_divided_by_16      7


/********************************************************************************************/
/*                                                                                         */
/*                            ADC Prescaler Factor Maybe :                                 */
/*                              1-ADC_PCLK2_divided_by_2                                   */
/*                              2-ADC_PCLK2_divided_by_4                                   */
/*                              3-ADC_PCLK2_divided_by_6                                   */
/*                              4-ADC_PCLK2_divided_by_8                                    */
/********************************************************************************************/


#define ADC_PCLK2_divided_by_2  0
#define ADC_PCLK2_divided_by_4  1
#define ADC_PCLK2_divided_by_6  2
#define ADC_PCLK2_divided_by_8  3

/********************************************************************************************/
/*                                                                                         */
/*                            USB Prescaler Factor Maybe :                                 */
/*                              1-USB_PLL_clock_is_divided_by_OneHalf                      */
/*                              2-USB_PLL_clock_is_not_divided                             */
/********************************************************************************************/

#define USB_PLL_clock_is_divided_by_OneHalf   0
#define USB_PLL_clock_is_not_divided          1

void RCC_enablePeripheral (uint8 peripheral_bus, uint8 peripheral_name);
void RCC_disablePeripheral(uint8 peripheral_bus, uint8 peripheral_name);
void RCC_enable8MHzHSI(void);
void RCC_enableHSE(void);
void RCC_enablePLL(uint8 clocksource, uint8 PLL_Value);
void RCC_Enable_RTC(void);
void RCC_MCO(uint8 MCO_clockSource);
void RCC_AHBPrescaler(uint8 AHB_PrescalerValue);
void RCC_APB1Prescaler(uint8 APB1_PrescalerValue);
void RCC_APB2Prescaler(uint8 APB2_PrescalerValue);
void RCC_ADCPrescaler(uint8 ADC_PrescalerValue);
void RCC_USBPrescaler(uint8 USB_PrescalerValue);
void RCC_enableCSS(void);
void RCC_disableCSS(void);
void RCC_HSE_RC(void);
void RCC_HSE_Crystal(void);
void RCC_Init(void);




#endif
