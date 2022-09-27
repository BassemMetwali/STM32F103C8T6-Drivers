/*************************************************************************************************
 * [MODULE_NAME]:  NVIC_REG.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Registers of NVIC
 ************************************************************************************************/
#ifndef NVIC_REG_H_
#define NVIC_REG_H_

typedef struct{
	volatile uint32 ISER[32];
	volatile uint32 ICER[32];
	volatile uint32 ISPR[32];
	volatile uint32 ICPR[32];
	volatile uint32 IABR[32];
	volatile uint32 RESERVED[32];
	volatile uint8 IPR[128]; /* Points to 8 bits only in this register */
}NVIC;


#define NVIC      ( ( volatile NVIC *)0xE000E100 )


/* it should be in SCB Driver */
typedef struct{

	volatile uint32 CPUID;
	volatile uint32 ICSR;
	volatile uint32 VTOR;
	volatile uint32 AIRCR;
	volatile uint32 SCR;
	volatile uint32 CCR;
	volatile uint32 SHPR1;
	volatile uint32 SHPR2;
	volatile uint32 SHPR3;
	volatile uint32 SHCSR;
	volatile uint32 CFSR;
	volatile uint32 HFSR;
	volatile uint32 RESERVED;
	volatile uint32 MMFAR;
	volatile uint32 BFAR;

}SCB;

#define SCB ((volatile SCB *) 0xE000ED00 )




#endif
