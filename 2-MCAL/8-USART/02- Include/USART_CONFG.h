/*************************************************************************************************
 * [MODULE_NAME]:  USART_CONFG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Configuration of USART Peripheral
 ************************************************************************************************/
#ifndef USART_CONFG_H_
#define USART_CONFG_H

/* System Clock */

#define F_CPU                    8000000UL

/* USART1_Configuration */

#define USART1_STATUS            USART1_ENABLE
#define USART1_BAUD_RATE         (uint16)9600

#define USART1_WORD_LENGTH       _8BIT_WORD_LENGTH
#define USART1_PARITY            PARITY_DISABLE
#define USART1_INTERRUPT         INT_DISABLE

#define USART1_TRANSMITTER       TRANSMITTER_ENABLE
#define USART1_RECEIVER          RECEIVER_ENABLE

#define USART1_STOP_BITS         ONE_STOP_BIT

#endif


