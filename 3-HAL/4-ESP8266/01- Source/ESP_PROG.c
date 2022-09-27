/*************************************************************************************************
 * [MODULE_NAME]:  ESP_Prog.c
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  ESP8266 Program
 ************************************************************************************************/
#include "TYPES.h"
#include "MACROS.h"

#include "USART_INTERFACE.h"

#include "ESP_INTERFACE.h"
#include "ESP_CONFG.h"
#include "ESP_PRIVATE.h"

uint8 Action=0;

void ESP8266_init ( void ){


	uint8 Result = 0;
    while (Result == 0 )
    {
    	/*stop echo*/
	    USART1_SendStringSynch ((uint8 *)"ATE0\r\n");
	    Result =  ESP_ValidateCmd();

    }

    Result = 0;

    while (Result == 0 )
      {
      	/*stop echo*/
  	    USART1_SendStringSynch ((uint8 *)"AT+CWMODE=1\r\n");
  	    Result =  ESP_ValidateCmd();

      }


}

void ESP_ConnectWifi(uint8 *WifiName, uint8 *Pass)
{

	uint8 Result = 0;

	while(Result ==0)
	{
		/*Connect to WiFi*/
		USART1_SendStringSynch((uint8 *)"AT+CWJAP_CUR=\"");
		USART1_SendStringSynch(WifiName);
		USART1_SendStringSynch((uint8 *)"\",\"");
		USART1_SendStringSynch(Pass);
		USART1_SendStringSynch((uint8 *)"\"\r\n");
		/* Check OK */
		Result = ESP_ValidateCmd();
	}


}

void ESP_ConnectTOServer(uint8 *StrIP, uint8 *Port)
{
	uint8 Result=0;
	while(Result == 0)
	{
		/*1-send mode*/
		USART1_SendStringSynch((uint8 *)"AT+CIPSTART=\"TCP\",\"");
		USART1_SendStringSynch(StrIP); /* Website Key or IP */
		USART1_SendStringSynch((uint8 *)"\",");
		USART1_SendStringSynch(Port); /* 80 for websites */
		USART1_SendStringSynch((uint8 *)"\r\n");
		/* Check OK */
		Result = ESP_ValidateCmd();
	}

}
uint8 ESP_receiveFromServer(uint8 URLLength, uint8 *URL)
{
	uint8 Result=0;



	while(Result == 0)
	{
		USART1_SendStringSynch((uint8 *) "AT+CIPSEND=");
		USART1_SendStringSynch((uint8 *)URLLength);
		USART1_SendStringSynch((uint8 *) "\r\n");
		/* Check OK */
		Result = ESP_ValidateCmd();
	}

	Result=0;
	while(Result == 0)
	{
		USART1_SendStringSynch((uint8 *) "GET http://");
		USART1_SendStringSynch((uint8 *) URL); /* my URL = www.iotev.com/status1.txt */
		USART1_SendStringSynch((uint8 *) "/status.txt\r\n"); /* status.txt is a file which contains a variable */

		/* Check OK */
		Result = ESP_ValidateCmd();
	}



	return  Action;   /* Data will be in ASCII */
}

void ESP_sendToServer(uint8 * Key, uint8 * Data, uint8 * Length) {

	uint8 Result = 0;

	while (Result == 0) {
		USART1_SendStringSynch((uint8 *) "AT+CIPSEND=");
		USART1_SendStringSynch((uint8 *) Length);
		USART1_SendStringSynch((uint8 *) "\r\n");
		/* Check OK */
		Result = ESP_ValidateCmd();
	}

	Result = 0;
	while (Result == 0) {
		USART1_SendStringSynch((uint8 *) "GET /update?api_key=");
		USART1_SendStringSynch((uint8 *) Key);
		USART1_SendStringSynch((uint8 *) "&field1=");
		USART1_SendStringSynch((uint8 *) Data);
		USART1_SendStringSynch((uint8 *) "\r\n");

		/* Check OK */
		Result = ESP_ValidateCmd();
	}

}

static uint8 ESP_ValidateCmd( void )
{
	uint8 counter = 0  ;
	uint8 Dummy = 0    ;
	uint8 Result = 0   ;
	uint8 Command[100] = { 0 };

	while (Dummy != 255)
	{

		Dummy = USART1_RecCharSynch();
		Command[counter] = Dummy;
		counter++;

	}
	for (uint8 i = 0; i < 70; i++)
	{
		if (Command[i] == ':')
		{
			Action = Command[i + 1];
			 break ;
		}

	}

	for (uint8 i = 0; i < 100; i++)
	{
		/* Check if OK is sent */
		if (Command[i] == 'O' && Command[i + 1] == 'K')
		{
			Result = 1;
			break;
		}
	}

	return Result;

}
