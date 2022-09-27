/*************************************************************************************************
 * [MODULE_NAME]:  NVIC_INTERFACE.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  All # Defines to be used by User & Function's prototype
 ************************************************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/* Internal Peripherals ID  */

#define PEND_SV        -6
#define SYSTICK        -5

#define SV_CALL        -4

#define MEMORY_MANAGE  -3
#define BUS_FAULT      -2
#define USAGE_FAULT    -1

/* External Peripherals ID  */

enum {
    NVIC_WWDG           ,
    NVIC_PVD            ,
    NVIC_TAMPER         ,
    NVIC_RTC            ,
    NVIC_FLASH          ,
    NVIC_RCC            ,
    NVIC_EXTI0          ,
    NVIC_EXTI1          ,
    NVIC_EXTI2          ,
    NVIC_EXTI3          ,
    NVIC_EXTI4          ,
    NVIC_DMA1_Channel1  ,
    NVIC_DMA1_Channel2  ,
    NVIC_DMA1_Channel3  ,
    NVIC_DMA1_Channel4  ,
    NVIC_DMA1_Channel5  ,
    NVIC_DMA1_Channel6  ,
    NVIC_DMA1_Channel7  ,
    NVIC_ADC1_2         ,
    NVIC_USB_HP_CAN_TX  ,
    NVIC_USB_LP_CAN_RX0 ,
    NVIC_CAN_RX1        ,
    NVIC_CAN_SCE        ,
    NVIC_EXTI9_5        ,
    NVIC_TIM1_BRK       ,
    NVIC_TIM1_UP        ,
    NVIC_TIM1_TRG_COM   ,
    NVIC_TIM1_CC        ,
    NVIC_TIM2           ,
    NVIC_TIM3           ,
    NVIC_TIM4           ,
    NVIC_I2C1_EV        ,
    NVIC_I2C1_ER        ,
    NVIC_I2C2_EV        ,
    NVIC_I2C2_ER        ,
    NVIC_SPI1           ,
    NVIC_SPI2           ,
    NVIC_USART1         ,
    NVIC_USART2         ,
    NVIC_USART3         ,
    NVIC_EXTI15_10      ,
    NVIC_RTCAlarm       ,
    NVIC_USBWakeup      ,
    NVIC_TIM8_BRK       ,
    NVIC_TIM8_UP        ,
    NVIC_TIM8_TRG_COM   ,
    NVIC_TIM8_CC        ,
    NVIC_ADC3           ,
    NVIC_FSMC           ,
    NVIC_SDIO           ,
    NVIC_TIM5           ,
    NVIC_SPI3           ,
    NVIC_UART4          ,
    NVIC_UART5          ,
    NVIC_TIM6           ,
    NVIC_TIM7           ,
    NVIC_DMA2_Channel1  ,
    NVIC_DMA2_Channel2  ,
    NVIC_DMA2_Channel3  ,
    NVIC_DMA2_Channel4  ,
    NVIC_DMA2_Channel4_5
};

enum {
    NVIC_GROUP_PRIORITY_0  ,
	NVIC_GROUP_PRIORITY_1  ,
	NVIC_GROUP_PRIORITY_2  ,
	NVIC_GROUP_PRIORITY_3  ,
	NVIC_GROUP_PRIORITY_4  ,
	NVIC_GROUP_PRIORITY_5  ,
	NVIC_GROUP_PRIORITY_6  ,
	NVIC_GROUP_PRIORITY_7  ,
	NVIC_GROUP_PRIORITY_8  ,
	NVIC_GROUP_PRIORITY_9  ,
	NVIC_GROUP_PRIORITY_10 ,
	NVIC_GROUP_PRIORITY_11,
	NVIC_GROUP_PRIORITY_12,
	NVIC_GROUP_PRIORITY_13,
	NVIC_GROUP_PRIORITY_14,
	NVIC_GROUP_PRIORITY_15
};

enum {
    NVIC_SUBGROUP_PRIORITY_0  ,
	NVIC_SUBGROUP_PRIORITY_1  ,
	NVIC_SUBGROUP_PRIORITY_2  ,
	NVIC_SUBGROUP_PRIORITY_3  ,
	NVIC_SUBGROUP_PRIORITY_4  ,
	NVIC_SUBGROUP_PRIORITY_5  ,
	NVIC_SUBGROUP_PRIORITY_6  ,
	NVIC_SUBGROUP_PRIORITY_7  ,
	NVIC_SUBGROUP_PRIORITY_8  ,
	NVIC_SUBGROUP_PRIORITY_9  ,
	NVIC_SUBGROUP_PRIORITY_10 ,
	NVIC_SUBGROUP_PRIORITY_11,
	NVIC_SUBGROUP_PRIORITY_12,
	NVIC_SUBGROUP_PRIORITY_13,
	NVIC_SUBGROUP_PRIORITY_14,
	NVIC_SUBGROUP_PRIORITY_15
};


#define GROUP4     0x05FA0300     /* 0 bit for sub & 4 bit For group   << 0 */
#define GROUP3     0x05FA0400     /* 1 bit for sub & 3 bit For group   << 1 */
#define GROUP2     0x05FA0500     /* 2 bit for sub & 2 bit For group   << 2 */
#define GROUP1     0x05FA0600     /* 3 bit for sub & 1 bit For group   << 3 */
#define GROUP0     0x05FA0700     /* 4 bit for sub & 0 bit For group   << 4 */


void NVIC_enablePeripheral ( uint8 INTID );

void NVIC_disablePeripheral ( uint8 INTID );

void NVIC_setPendingFlag ( uint8 INTID );

void NVIC_clearPendingFlag ( uint8 INTID );

uint8  NVIC_getActiveFlag( uint8 INTID );

void NVIC_setPriority( sint8 INTID , uint8 GroupPriority , uint8 SubPriority , uint32 GroupMode );

#endif
