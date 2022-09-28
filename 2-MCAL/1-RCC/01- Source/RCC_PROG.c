/*************************************************************************************************
 * [MODULE_NAME]:  RCC_PROG.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Program of RCC
 ************************************************************************************************/

#include "TYPES.h"
#include "MACROS.h"

#include"RCC_INTERFACE.h"
#include"RCC_CONFG.h"
#include"RCC_PRIVATE.h"
#include"RCC_REG.h"



/*
 * Description :
 * Enable any peripheral on Buses.
 * If the input peripheral number or peripheral bus are not correct, The function will not handle the request.
 */
void RCC_enable8MHzHSI(void){
	/*SET_BIT(RCC->RCC_CR, HSION);
	while (BIT_IS_CLEAR(RCC->RCC_CR, HSIRDY));
	SET_BIT(RCC->RCC_CIR, HSIRDYC);
	CLEAR_BIT(RCC->RCC_CFGR, SW0);
	CLEAR_BIT(RCC->RCC_CFGR, SW1);*/
	 RCC->RCC_CFGR=0;
	 RCC->RCC_CR=(1<<HSION);
	 while (BIT_IS_CLEAR(RCC->RCC_CR,HSIRDY) );
	 RCC->RCC_CIR=(1<<HSIRDYC);


}

/*
 * Description :
 * Enable any peripheral on Buses.
 * If the input peripheral number or peripheral bus are not correct, The function will not handle the request.
 */

void RCC_enableHSE(void){

	    SET_BIT(RCC->RCC_CR,HSEON);
		while (BIT_IS_CLEAR(RCC->RCC_CR,HSERDY) );
		SET_BIT(RCC->RCC_CIR,HSERDYC);
		SET_BIT(RCC->RCC_CFGR,SW0);
		CLEAR_BIT(RCC->RCC_CFGR,SW1);
		/* RCC->RCC_CFGR=(1<<SW0);
		 * RCC->RCC_CR=(1<<HSEON);
		 * while (BIT_IS_CLEAR(RCC->RCC_CR,HSERDY) );
		 * RCC->RCC_CIR=(1<<HSERDYC);
		 */

}

/*
 * Description :
 * Enable any peripheral on Buses.
 * If the input peripheral number or peripheral bus are not correct, The function will not handle the request.
 */
void RCC_enablePLL(uint8 clocksource, uint8 PLL_Value){

	    SET_BIT(RCC->RCC_CFGR,SW1);
		CLEAR_BIT(RCC->RCC_CFGR,SW0);
		 /* RCC->RCC_CFGR=(1<<SW1); */


		switch(clocksource){                       //Jump to CLK source of PLL.
		case PLL_Half_HSI:                             //If PLL CLK source is half HSI.
			/* RCC->RCC_CR =0; */
			CLEAR_BIT(RCC -> RCC_CFGR, PLLSRC);    //HSI oscillator clock / 2 selected as PLL input clock.
			break;
		case PLL_Half_HSE:                            //If PLL CLK source is half HSE.
			/* RCC->RCC_CR =(1<<HSEON); */
			SET_BIT( RCC->RCC_CR   , HSEON );
			SET_BIT(RCC -> RCC_CFGR, PLLSRC);     //HSE oscillator clock selected as PLL input clock.
			SET_BIT(RCC -> RCC_CFGR, PLLXTPRE);    //HSE clock divided by 2.
			break;
		case PLL_HSE:                                   //If PLL CLK source is HSE.
			/* RCC->RCC_CR =(1<<HSEON); */
			SET_BIT( RCC->RCC_CR   , HSEON );
			SET_BIT(RCC -> RCC_CFGR, PLLSRC);       //HSE oscillator clock selected as PLL input clock.
			CLEAR_BIT(RCC -> RCC_CFGR, PLLXTPRE);   //HSE clock not divided.
			break;
		default :
			// Error Message
			break;
		}
        #if ( PLL_Value >= NO_CLOCK_FACTOR ) && ( PLL_Value <= PLL_CLOCK_MULTIPLE_BY_16)

		    RCC->RCC_CFGR &= ~( ( 0b1111 )     << PLLMUL0 ) ;  /* Clear if there are any Configuration */
	    	RCC->RCC_CFGR |=  ( ( PLL_Value )  << PLLMUL0   ); /* Set New Clock Configuration */
     /* RCC->RCC_CFGR= (RCC->RCC_CFGR & 0xFFC3FFFF) | (PLL_Value << PLLMUL0); */
		#elif ( CLOCK_FACTOR > PLL_CLOCK_MULTIPLE_BY_16 ) || ( CLOCK_FACTOR < NO_CLOCK_FACTOR )
			#warning "Wrong Multiplication Factor"

		#endif
	    SET_BIT(RCC -> RCC_CR, PLLON);               //Enable PLL.
	    while(BIT_IS_CLEAR(RCC -> RCC_CR, PLLRDY));  //Polling until PLL is ready.
	    SET_BIT(RCC -> RCC_CIR, PLLRDYC);            //Clear PLL ready flag.
		/* RCC->RCC_CR |=(1<<PLLON);
		 * while (BIT_IS_CLEAR(RCC->RCC_CR,PLLRDY) );
		 * RCC->RCC_CIR=(1<<PLLRDYC); */
}

void RCC_Enable_RTC(void){
	SET_BIT(RCC -> RCC_BDCR, RTCEN); //Enable RTC.
}

/**
  * @brief  Returns the clock source used as system clock.
  * @param  None
  * @retval The clock source used as system clock. The returned value can
  *   be one of the following:
  *     - 0x00: HSI used as system clock
  *     - 0x04: HSE used as system clock
  *     - 0x08: PLL used as system clock
  */
uint8 RCC_getSYSCLKSource(void)
{
  return ((uint8)(RCC->RCC_CFGR & CFGR_SWSMask));
}

void RCC_MCO(uint8 MCO_clockSource)
{
	switch(MCO_clockSource)
	{
	case MCO_NOCLK:
	CLEAR_BIT(RCC->RCC_CFGR,MCO2);
	CLEAR_BIT(RCC->RCC_CFGR,MCO0);
	CLEAR_BIT(RCC->RCC_CFGR,MCO1);
	break;
	case MCO_SYSCLK:
	SET_BIT(RCC->RCC_CFGR,MCO2);
	CLEAR_BIT(RCC->RCC_CFGR,MCO0);
	CLEAR_BIT(RCC->RCC_CFGR,MCO1);
	break;
	case MCO_HSI:
	SET_BIT(RCC->RCC_CFGR,MCO2);
	CLEAR_BIT(RCC->RCC_CFGR,MCO0);
	SET_BIT(RCC->RCC_CFGR,MCO1);
	break;
	case MCO_HSE:
	SET_BIT(RCC->RCC_CFGR,MCO2);
	SET_BIT(RCC->RCC_CFGR,MCO0);
	CLEAR_BIT(RCC->RCC_CFGR,MCO1);
	break;
	case MCO_PLL_DIVIDED_BY_2:
	SET_BIT(RCC->RCC_CFGR,MCO2);
	SET_BIT(RCC->RCC_CFGR,MCO0);
	SET_BIT(RCC->RCC_CFGR,MCO1);
	break;
	default: /*Error */  break;

	}
 /* or -->	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xF8FFFFFF) | (MCO_CLKSource << MCO0); //Micro-controller clock output. */
}
void RCC_AHBPrescaler(uint8 AHB_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFFFFF0F) | (AHB_PrescalerValue << HPRE0); //Control the division factor of the AHB clock.
}

void RCC_APB1Prescaler(uint8 APB1_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFFFF8FF) | (APB1_PrescalerValue << PPRE10); //Control the division factor of the APB1 clock.
}

void RCC_APB2Prescaler(uint8 APB2_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFFFC7FF) | (APB2_PrescalerValue << PPRE20); //Control the division factor of the APB2 clock.
}

void RCC_ADCPrescaler(uint8 ADC_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFFF3FFF) | (ADC_PrescalerValue << ADCPRE0); //Control the division factor of the ADCs clock.
}

void RCC_USBPrescaler(uint8 USB_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFBFFFFF) | (USB_PrescalerValue << USBPRE); //Control the division factor of the USB clock.
}

void RCC_enableCSS(void)
{
	SET_BIT(RCC->RCC_CR,CSSON);
}
void RCC_disableCSS(void)
{
	CLEAR_BIT(RCC->RCC_CR,CSSON);
}

void RCC_HSE_RC(void)
{
	/* The HSEBYP Can Be Written Only When HSE Oscilator Is Disabled */
			/* HSE Clock Disabled */
	        CLEAR_BIT( RCC->RCC_CR  , HSEON );

			/* BIT 18 -> To Select HSE BYPASS */
			/* HSEBYPASS Clock Enable */
			SET_BIT( RCC->RCC_CR , HSEBYP );

			/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
			/* HSE Selected As A System Clock */
			SET_BIT( RCC->RCC_CFGR , SW0  );
			CLEAR_BIT( RCC->RCC_CFGR , SW1  );

			/* Bit 16 -> Enable The HSE Clock */
			SET_BIT( RCC->RCC_CR   , HSEON );
}
void RCC_HSE_Crystal(void)
{

	/* The HSEBYP Can Be Written Only When HSE Oscilator Is Disabled */
			/* HSE Clock Disabled */
	    //   CLEAR_BIT( RCC->RCC_CR   , HSEON );

			/* BIT 18 -> To Select HSE BYPASS */
			/* HSEBYPASS Clock Disable */
		//	CLEAR_BIT( RCC->RCC_CR , HSEBYP );

			/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
			/* HSE Selected As A System Clock */
		//	SET_BIT( RCC->RCC_CFGR , SW0  );
		//	CLEAR_BIT( RCC->RCC_CFGR , SW1  );

			/* Bit 16 -> Enable The HSE Clock */
		//	SET_BIT( RCC->RCC_CR   , HSEON );
	 RCC->RCC_CFGR=(1<<SW0);
	 RCC->RCC_CR=(1<<HSEON);
	 while (BIT_IS_CLEAR(RCC->RCC_CR,HSERDY) );
	  RCC->RCC_CIR=(1<<HSERDYC);

}


void RCC_Init(void){

	/*******************************************
	 - This function enables system clock based
	   on the user configuration.
	 - It also configure some registers in the RCC
	   Peripheral.
	 *******************************************/
#if CLOCK_TYPE == HSI
	RCC_enable8MHzHSI();
#elif  CLOCK_TYPE == HSE_RC
	RCC_enableHSE();
	RCC_HSE_RC();
#elif  CLOCK_TYPE == PLL
	RCC_enablePLL(PLL_SOURCE, PLL_CLOCK_FACTOR);
#elif  CLOCK_TYPE == HSE_Crystal
	RCC_HSE_Crystal();
#else
	/* Error message: No system clock is enabled */
#endif

	RCC_AHBPrescaler(AHB_PRESCALER);
	RCC_APB1Prescaler(APB1_PRESCALER);
	RCC_APB2Prescaler(APB2_PRESCALER);
	RCC_ADCPrescaler(ADC_PRESCALER);
	RCC_USBPrescaler(USB_PRESCALER);
	RCC_MCO(MCO_SOURCE);

#if  CLOCK_SECURITY_SYSTEM==ENABLE_CLOCK_SECURITY_SYSTEM

	 RCC_enableCSS();

#elif CLOCK_SECURITY_SYSTEM==DISABLE_CLOCK_SECURITY_SYSTEM

	 RCC_disableCSS();

#endif

}






/*
 * Description :
 * Enable any peripheral on Buses.
 * If the input peripheral number or peripheral bus are not correct, The function will not handle the request.
 */
void RCC_enablePeripheral(uint8 peripheral_bus, uint8 peripheral_name)
{
	switch (peripheral_bus)
	{
	case AHB_BUS: SET_BIT(RCC->RCC_AHBENR,peripheral_name);  break;
	case APB2_BUS:SET_BIT(RCC->RCC_APB2ENR,peripheral_name); break;
	case APB1_BUS:SET_BIT(RCC->RCC_APB1ENR,peripheral_name); break;
	default :/*return error*/ break;
	}

}


/*
 * Description :
 * Disable any peripheral on Buses.
 * If the input peripheral number or peripheral bus are not correct, The function will not handle the request.
 */

void RCC_disablePeripheral(uint8 peripheral_bus, uint8 peripheral_name)
{
	switch (peripheral_bus)
	{
	case AHB_BUS: CLEAR_BIT(RCC->RCC_AHBENR,peripheral_name); break;
	case APB2_BUS:CLEAR_BIT(RCC->RCC_APB2ENR,peripheral_name); break;
	case APB1_BUS:CLEAR_BIT(RCC->RCC_APB1ENR,peripheral_name); break;
	default :/*return error*/ break;
	}

}


