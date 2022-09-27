#include "TYPES.h"
#include "MACROS.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "EXTI_INTERFACE.h"
#include "NVIC_INTERFACE.h"
#include "AFIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"
#include "DELAY_INTERFACE.h"
#include "IR_INTERFACE.h"

uint8 Value = 0 ;

void Stop(void)
{

	STK_stopInterval();


	GPIO_setPinValue( GPIOB_ID, PIN12, LOW); /* Delta1 contactor */
	GPIO_setPinValue( GPIOB_ID, PIN13, LOW); /* Star1 contactor */
	GPIO_setPinValue( GPIOB_ID, PIN14, LOW); /* Main1 contactor */

	GPIO_setPinValue( GPIOB_ID, PIN1, LOW); /* Delta2 contactor */
	GPIO_setPinValue( GPIOB_ID, PIN0, LOW); /* Star2 contactor */
	GPIO_setPinValue( GPIOA_ID, PIN7, LOW); /* Main2 contactor */


	GPIO_setPinValue( GPIOA_ID, PIN6, LOW); /* Delta3 contactor */
	GPIO_setPinValue( GPIOA_ID, PIN5, LOW); /* Star3 contactor */
	GPIO_setPinValue( GPIOA_ID, PIN4, LOW); /* Main3 contactor */

	Value =1;

}

/* Start Function  */
void Start (void)
{
	Value=0;
	GPIO_setPinValue( GPIOB_ID, PIN12, LOW);  /* Delta1 contactor */
 	GPIO_setPinValue( GPIOB_ID, PIN13, HIGH); /* Main1 contactor */
	GPIO_setPinValue( GPIOB_ID, PIN14, HIGH); /* Star1 contactor */

	GPIO_setPinValue( GPIOB_ID, PIN1, LOW); /* Delta2 contactor */
	GPIO_setPinValue( GPIOB_ID, PIN0, HIGH); /* Main2 contactor */
	GPIO_setPinValue( GPIOA_ID, PIN7, HIGH); /* STAR2 contactor */

	GPIO_setPinValue( GPIOA_ID, PIN6, LOW); /* Delta3 contactor */
	GPIO_setPinValue( GPIOA_ID, PIN5, HIGH); /* Main3 contactor */
	GPIO_setPinValue( GPIOA_ID, PIN4, HIGH); /* Star3 contactor */



	STK_setBusyWait(1000000); /* Approx 1000 000 Ticks = 1 sec */



	GPIO_setPinValue( GPIOB_ID, PIN12, HIGH); /* Delta contactor */
	GPIO_setPinValue( GPIOB_ID, PIN14, LOW);  /* Star contactor */

	GPIO_setPinValue( GPIOB_ID, PIN1, HIGH); /* Delta2 contactor */
	GPIO_setPinValue( GPIOA_ID, PIN7, LOW);  /* STAR2 contactor */

	GPIO_setPinValue( GPIOA_ID, PIN6, HIGH); /* Delta3 contactor */
	GPIO_setPinValue( GPIOA_ID, PIN4, LOW);  /* STAR3 contactor */

   if (Value == 1)
   {
	   Stop();
	   Value=0;
   }



}



int main(void) {

	RCC_Init(); /* without initialize MCU by default PLL & HSI */

	STK_init();

	NVIC_enablePeripheral(NVIC_EXTI0);
	NVIC_setPriority(NVIC_EXTI0, NVIC_GROUP_PRIORITY_1,
			NVIC_SUBGROUP_PRIORITY_0, GROUP4);

	NVIC_enablePeripheral(NVIC_EXTI1);
	NVIC_setPriority(NVIC_EXTI1, NVIC_GROUP_PRIORITY_0,
			NVIC_SUBGROUP_PRIORITY_0, GROUP4);

	AFIO_enableClock();
	AFIO_setEXTIConfiguration(AFIO_EXTI_LINE0, AFIO_PORTA); /*  PA0 as EXTI */
	AFIO_setEXTIConfiguration(AFIO_EXTI_LINE1, AFIO_PORTA); /*  PA1 as EXTI */

	EXTI_setCallBack(EXTI_LINE0, Start); /* darory a set el call back abl l initialize fe ay driver  */
	EXTI_init(EXTI_LINE0, FALLING_EDGE);

	EXTI_setCallBack(EXTI_LINE1, Stop); /* darory a set el call back abl l initialize fe ay driver  */
	EXTI_init(EXTI_LINE1, FALLING_EDGE);


	GPIO_enablePortClock(GPIOB_ID);
	GPIO_enablePortClock(GPIOA_ID);

	GPIO_setupPinMode( GPIOB_ID, PIN14, OUTPUT_SPEED_2MHZ_PP);
	GPIO_setupPinMode( GPIOB_ID, PIN13, OUTPUT_SPEED_2MHZ_PP);
	GPIO_setupPinMode( GPIOB_ID, PIN12, OUTPUT_SPEED_2MHZ_PP);

	GPIO_setupPinMode( GPIOB_ID, PIN1, OUTPUT_SPEED_2MHZ_PP);
	GPIO_setupPinMode( GPIOB_ID, PIN0, OUTPUT_SPEED_2MHZ_PP);
	GPIO_setupPinMode( GPIOA_ID, PIN7, OUTPUT_SPEED_2MHZ_PP);

	GPIO_setupPinMode( GPIOA_ID, PIN6, OUTPUT_SPEED_2MHZ_PP);
	GPIO_setupPinMode( GPIOA_ID, PIN5, OUTPUT_SPEED_2MHZ_PP);
	GPIO_setupPinMode( GPIOA_ID, PIN4, OUTPUT_SPEED_2MHZ_PP);

	GPIO_setupPinMode( GPIOA_ID, PIN0, INPUT_PULLUP_PULLDOWN);
	GPIO_setupPinMode( GPIOA_ID, PIN1, INPUT_PULLUP_PULLDOWN);

	GPIO_setPinValue( GPIOA_ID, PIN0, HIGH);
	GPIO_setPinValue( GPIOA_ID, PIN1, HIGH);

	GPIO_setPinValue( GPIOB_ID, PIN12, LOW); /* Delta1 contactor */
	GPIO_setPinValue( GPIOB_ID, PIN13, LOW); /* Star1 contactor */
	GPIO_setPinValue( GPIOB_ID, PIN14, LOW); /* Main1 contactor */

	GPIO_setPinValue( GPIOB_ID, PIN1, LOW); /* Delta2 contactor */
	GPIO_setPinValue( GPIOB_ID, PIN0, LOW); /* Star2 contactor */
	GPIO_setPinValue( GPIOA_ID, PIN7, LOW); /* Main2 contactor */


	GPIO_setPinValue( GPIOA_ID, PIN6, LOW); /* Delta3 contactor */
	GPIO_setPinValue( GPIOA_ID, PIN5, LOW); /* Star3 contactor */
	GPIO_setPinValue( GPIOA_ID, PIN4, LOW); /* Main3 contactor */



	while (1) {

	}

	return 0;
}

