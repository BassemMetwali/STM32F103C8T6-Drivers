/*************************************************************************************************
 * [MODULE_NAME]:  DMA_PRIVATE.h
 *
 * [DATE CREATED]: Aug12, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  All Private Functions & Names of Registe's bits
 ************************************************************************************************/

#ifndef DMA_PRIVATE_
#define DMA_PRIVATE_


typedef enum {

	EN            ,
	TCIE          ,
	HTIE          ,
	TEIE          ,
	DIR           ,
	CIRC          ,
	PINC          ,
	MINC          ,
	PSIZE0        ,
	PSIZE1        ,
	MSIZE0        ,
	MSIZE1        ,
	PL0           ,
	PL1           ,
	MEM2MEM       ,

}CCR;

typedef enum {

	CGIF1     ,
	CTCIF1    ,
	CHTIF1    ,
	CTEIF1    ,
	CGIF2     ,
	CTCIF2    ,
	CHTIF2    ,
	CTEIF2    ,
	CGIF3     ,
	CTCIF3    ,
	CHTIF3    ,
	CTEIF3    ,
	CGIF4     ,
	CTCIF4    ,
	CHTIF4    ,
	CTEIF4    ,
	CGIF5     ,
	CTCIF5    ,
	CHTIF5    ,
	CTEIF5    ,
	CGIF6     ,
	CTCIF6    ,
	CHTIF6    ,
	CTEIF6    ,
	CGIF7     ,
	CTCIF7    ,
	CHTIF7    ,
	CTEIF7    ,
} IFCR;

#endif
