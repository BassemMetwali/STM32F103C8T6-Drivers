/*************************************************************************************************
 * [MODULE_NAME]:  GPIO_PROG.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Program of GPIO
 ************************************************************************************************/

#include "TYPES.h"
#include "MACROS.h"

#include"GPIO_INTERFACE.h"
#include "GPIO_REG.h"

#include "RCC_INTERFACE.h"

/*
 * Description :
 * Setup the Mode & Direction of the required pin from 16 Modes.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinMode(uint8 port_num, uint8 pin_num,uint8 mode)
{

	if ((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)) {

		/* Do Nothing */

	}

	else {

		switch (port_num) {
		case GPIOA_ID:
			if (pin_num <= 7) {

				GPIOA->CRL &= ~((0b1111) << (pin_num * 4));
				GPIOA->CRL |= (mode) << (pin_num * 4);

			} else if (pin_num <= 15) {

				pin_num = pin_num - 8;
				GPIOA->CRH &= ~((0b1111) << (pin_num * 4));
				GPIOA->CRH |= (mode) << (pin_num * 4);
			}

			  break;
		case GPIOB_ID:
				if (pin_num <= 7) {

					GPIOB->CRL &= ~((0b1111) << (pin_num * 4));
					GPIOB->CRL |= (mode) << (pin_num * 4);

				} else if (pin_num <= 15) {

					pin_num = pin_num - 8;
					GPIOB->CRH &= ~((0b1111) << (pin_num * 4));
					GPIOB->CRH |= (mode) << (pin_num * 4);
				}

						break;
		case GPIOC_ID:
				if (pin_num <= 7) {

					GPIOC->CRL &= ~((0b1111) << (pin_num * 4));
					GPIOC->CRL |= (mode) << (pin_num * 4);

				} else if (pin_num <= 15) {

					pin_num = pin_num - 8;
					GPIOC->CRH &= ~((0b1111) << (pin_num * 4));
					GPIOC->CRH |= (mode) << (pin_num * 4);
				}

						break;
		default:break;

		}

	}

}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up/pull-down resistor.
 */
void GPIO_setPinValue(uint8 port_num, uint8 pin_num, uint8 value)
{
	if ((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)) {

		/* Do Nothing */

	}

	else {

		switch (port_num) {
		case GPIOA_ID:

			if (value == HIGH) {

				SET_BIT(GPIOA->ODR, pin_num);

			} else if (value == LOW) {
				CLEAR_BIT(GPIOA->ODR, pin_num);
			}

			break;
		case GPIOB_ID:

			if (value == HIGH) {

				SET_BIT(GPIOB->ODR, pin_num);

			} else if (value == LOW) {
				CLEAR_BIT(GPIOB->ODR, pin_num);
			}

			break;
		case GPIOC_ID:

			if (value == HIGH) {

				SET_BIT(GPIOC->ODR, pin_num);

			} else if (value == LOW) {
				CLEAR_BIT(GPIOC->ODR, pin_num);
			}

			break;

		}

	}
}



uint8 GPIO_getPinValue(uint8 port_num, uint8 pin_num) {
	uint8 pin_value = LOW;
	if ((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)) {

		/* Do Nothing */

	}

	else {

		switch (port_num) {
		case GPIOA_ID:
			pin_value = GET_BIT(GPIOA->IDR, pin_num);
			break;
		case GPIOB_ID:
			pin_value = GET_BIT(GPIOB->IDR, pin_num);
			break;
		case GPIOC_ID:
			pin_value = GET_BIT(GPIOC->IDR, pin_num);
			break;

		}
	}

	return pin_value;
}

/*
 * Description :
 * Setup the direction of the required port all pins from 16 modes.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortMode(uint8 port_num, uint8 mode)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		switch (port_num) {
		case GPIOA_ID:
			GPIOA->CRL = 0x00000000;
			GPIOA->CRH = 0x00000000;
			for (uint8 i = 0; i < 8; i++) {
				GPIOA->CRL |= mode << i * 4;
				GPIOA->CRH |= mode << i * 4;
			}
			break;

		case GPIOB_ID:
			GPIOB->CRL = 0x00000000;
			GPIOB->CRH = 0x00000000;
			for (uint8 i = 0; i < 8; i++) {
				GPIOB->CRL |= mode << i * 4;
				GPIOB->CRH |= mode << i * 4;
			}
			break;
		case GPIOC_ID:
			GPIOC->CRL = 0x00000000;
			GPIOC->CRH = 0x00000000;
			for (uint8 i = 0; i < 8; i++) {
				GPIOC->CRL |= mode << i * 4;
				GPIOC->CRH |= mode << i * 4;
			}
			break;
		default:
			break;

		}
	}

}


/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint16 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{

		switch (port_num) {

		case GPIOA_ID:
			GPIOA->ODR = value;
			break;
		case GPIOB_ID:
			GPIOB->ODR = value;
			break;
		case GPIOC_ID:
			GPIOC->ODR = value;
			break;
		default:break;

		}

	}
}


/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint16 GPIO_readPort(uint8 port_num)
{
	uint16 value = LOW;

	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the port value as required */
		switch(port_num)
		{
		case GPIOA_ID:
			value = GPIOA->IDR;
			break;
		case GPIOB_ID:
			value = GPIOB->IDR;
			break;
		case GPIOC_ID:
			value = GPIOC->IDR;
			break;

		}
	}

	return value;
}

uint8   GPIO_togglePinValue (uint8 port_num, uint8 pin_num) {

    uint8 State;
    State = GPIO_getPinValue(port_num, pin_num);
    switch (State)
    {
    case HIGH:
    	State = LOW;
    	GPIO_setPinValue(port_num, pin_num, State);
        break;
    case LOW:
    	State = HIGH;
    	GPIO_setPinValue(port_num, pin_num, State);
        break;
    default:
        break;
    }
    return State;

}


void GPIO_enablePortClock (uint8 port_num) {
    switch (port_num)
    {
    case GPIOA_ID:
    	RCC_enablePeripheral(APB2_BUS , GPIOA_RCC);
        break;
    case GPIOB_ID:
    	RCC_enablePeripheral(APB2_BUS , GPIOB_RCC);
        break;
    case GPIOC_ID:
    	RCC_enablePeripheral(APB2_BUS , GPIOC_RCC);
        break;
    default:
        break;
    }
}

