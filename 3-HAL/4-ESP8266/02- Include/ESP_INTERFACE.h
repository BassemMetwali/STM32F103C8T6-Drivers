/*************************************************************************************************
 * [MODULE_NAME]:  ESP_INTERFACE.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  All # Defines to be used by User & Function's prototype
 ************************************************************************************************/
#ifndef ESP_INTERFACE_H_
#define ESP_INTERFACE_H

void ESP8266_init ( void );

void ESP_ConnectWifi(uint8 *WifiName, uint8 *Pass);

void ESP_ConnectTOServer(uint8 *StrIP, uint8 *Port);

uint8 ESP_receiveFromServer(uint8 URLLength, uint8 *URL);

void ESP_sendToServer(uint8 * Key, uint8 * Data, uint8 * Length) ;

static uint8 ESP_ValidateCmd( void );


#endif
