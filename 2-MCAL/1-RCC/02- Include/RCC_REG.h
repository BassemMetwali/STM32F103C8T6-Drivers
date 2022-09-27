/*************************************************************************************************
 * [MODULE_NAME]:  RCC_REG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Registers of RCC (MCAL)
 ************************************************************************************************/

#ifndef RCC_REG_H_
#define RCC_REG_H_

#include "TYPES.h"

typedef struct{

volatile uint32 RCC_CR;         /* Control Register */
volatile uint32	RCC_CFGR;       /* Clock Configuration Register */
volatile uint32	RCC_CIR;        /* Clock Interrupt Register */
volatile uint32	RCC_APB2RSTR;   /* APB2 Peripheral reset Register */
volatile uint32	RCC_APB1RSTR;   /* APB1 Peripheral reset Register */
volatile uint32	RCC_AHBENR;     /* AHB Peripheral Clock Enable Register */
volatile uint32	RCC_APB2ENR;    /* APB2 Peripheral Clock Enable Register */
volatile uint32	RCC_APB1ENR;    /* APB1 Peripheral Clock Enable Register */
volatile uint32	RCC_BDCR;       /* Backup Domain Control Register */
volatile uint32	RCC_CSR;        /* Control/Status Register */

}RCC;

#define RCC ((volatile RCC *)0x40021000)



#endif
