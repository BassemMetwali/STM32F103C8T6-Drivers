/*************************************************************************************************
 * [MODULE_NAME]:  DMA_INTERFACE.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  All # Defines to be used by User & Function's prototype
 ************************************************************************************************/

#ifndef DMA_INTERFACE_
#define DMA_INTERFACE_


//DMA Flags
#define DMA_GIF   0
#define DMA_TCIF  1
#define DMA_HTIF  2
#define DMA_TEIF  3

//DMA CHANNELS
#define CHANNEL1  0
#define CHANNEL2  1
#define CHANNEL3  2
#define CHANNEL4  3
#define CHANNEL5  4
#define CHANNEL6  5
#define CHANNEL7  6

//Interrupt Enable
#define DMA_TCIE_ENABLE   0
#define DMA_TCIE_DISABLE  1

#define DMA_HTIE_ENABLE   0
#define DMA_HTIE_DISABLE  1

#define DMA_TEIE_ENABLE   0
#define DMA_TEIE_DISABEL  1


//Enable
#define DMA_ENABLE  0
#define DMA_DISABLE 1


//DMA Configuration
//Direction
#define MEM_TO_MEM_ENABLE    0
#define MEM_TO_MEM_DISABLE   1

#define PREI_TO_MEM          0
#define MEM_TO_PREI          1

//Circular
#define DMA_ENABLE_CIRCULAR    0
#define DMA_DISABLE_CIRCULAR   1

//PIN & MIN
#define PERIPHERAL_INCREMENT_ENABLE  0
#define PERIPHERAL_INCREMENT_DISABLE 1

//MIN
#define MEM_INCREMENT_ENABLE  0
#define MEM_INCREMENT_DISABLE 1

//Size
#define BYTE       0
#define HALF_WORD  1
#define WORD       2

//Channel Priority
#define DMA_LOW         0
#define DMA_MEDIUM      1
#define DMA_HIGH        2
#define DMA_VERY_HIGH   3




#endif
