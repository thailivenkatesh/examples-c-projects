//app_config.c
//static const 
gapAdStructure_t advScanStruct[3]//static const removed

//ble_conn_manager.h
extern gapAdStructure_t advScanStruct[3];//venk

//main
int main (void)
{
     

	(void)NV_ReadHWParameters(&gHardwareParameters);
	advScanStruct[2].aData=(uint8_t*)gHardwareParameters.device_id;
	gHardwareParameters.device_id=(uint8_t*)"SDAS-11";//updated value
    (void)NV_WriteHWParameters(&gHardwareParameters);

     
}		
			
//flashadapter.h
typedef PACKED_STRUCT hardwareParameters_tag
{
  
     char*    device;//venk
    /* For forward compatibility additional fields may be added here 
       Existing data in flash will not be compatible after modifying the hardwareParameters_t typedef*/
          /* crc for data between start of reserved area and start of hardwareParamsCrc field (not included). */ 
}hardwareParameters_t;












/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
  
char* a;
char b[10]="sdas-88888";

a=(char*)"SDAS-51";

printf("old a%s\n",a);
a=(char*)b;

printf("new a%s\n",a);
printf("b%s",b);
    return 0;
}


	(void)NV_ReadHWParameters(&gHardwareParameters);
	advScanStruct[2].aData=(uint8_t*)gHardwareParameters.device_id;
	gHardwareParameters.device_id[10]=(uint8_t*)"SDAS-9999";//updated value
    (void)NV_WriteHWParameters(&gHardwareParameters);
	//advScanStruct[2].aData=(uint8_t*)gHardwareParameters.device;
	
	
	
	
	
	typedef struct serial_tag{
    serialInterfaceType_t  serialType;
    uint8_t                serialChannel;
    /* Rx parameters */
    volatile bufIndex_t    rxIn;
    volatile bufIndex_t    rxOut;
    pSerialCallBack_t      rxCallback;
    void                  *pRxParam;
    uint8_t                rxBuffer[gSMRxBufSize_c];
    /* Tx parameters */
    
    volatile uint8_t       txIn;
    volatile uint8_t       txOut;
    volatile uint8_t       txCurrent;
    volatile uint8_t       txNo;
    volatile uint8_t       events;
    volatile uint8_t       state;
}serial_t;

/*
 * Defines events recognized by the SerialManager's Task
 * Message used to enque async tx data
 */
typedef struct SerialManagetMsg_tag{
    pSerialCallBack_t txCallback;
    void             *pTxParam;
    uint8_t          *pData;
    uint16_t          dataSize;
}SerialMsg_t;
pSer->txQueue[3].pData;
uint8_t* serial_id=pSer->txQueue[3].pData;

serialStatus_t Serial_AsyncWrite( uint8_t InterfaceId,
                                  uint8_t *pBuf,
                                  uint16_t bufLen,
                                  pSerialCallBack_t cb,
                                  void *pTxParam )
								  {
									   if( (0 == pSer->txQueue[pSer->txIn].dataSize) && (NULL == pSer->txQueue[pSer->txIn].txCallback) && (pSer->txNo < gSerialMgrTxQueueSize_c) )
            {
                pMsg = &pSer->txQueue[pSer->txIn];
                pMsg->dataSize   = bufLen;
                pMsg->pData      = (void*)pBuf;
                uint_8* serial_id=pMsg->pData ;//venk
                pMsg->txCallback = cb;
                pMsg->pTxParam   = pTxParam;
                mSerial_IncIdx_d(pSer->txIn, gSerialMgrTxQueueSize_c)
                pSer->txNo++;
            }
								  }
								  
								  
								  
								  
								  
 /*(void)NV_ReadHWParameters(&gHardwareParameters);//venk
    pSer->txQueue[3].pData="temp-123";
    gHardwareParameters.serial_id=pSer->txQueue[3].pData;//venk
    (void)NV_WriteHWParameters(&gHardwareParameters);//venk*/
	
	
	
/*reading #CTeemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
	
	#include "Flash_Adapter.h"//venk
	
	
	
	static serialStatus_t Serial_WriteInternal( uint8_t InterfaceId )
{
#if FSL_FEATURE_SOC_LPUART_COUNT
    case gSerialMgrLpuart_c:
	       (void)NV_ReadHWParameters(&gHardwareParameters);
        	gHardwareParameters.serial_id=pSer->txQueue[idx].pData;
        	(void)NV_WriteHWParameters(&gHardwareParameters);
        if( LPUART_SendData(pSer->serialChannel, pSer->txQueue[idx].pData, pSer->txQueue[idx].dataSize) )
        {

        	
        	status = gSerial_InternalError_c;
        }
        break;
#endif




/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
  
char* a;
char* b="#ctemp-112";

a=(char*)"SDAS-51";

printf("old a=%s\n",a);
a=(char*)b;
if((*b++=='#')&&(*b=='c'))
a=a+2;
printf("new a=%s\n",a);
printf("b=%s",b);
    return 0;
}


/*reading #CTeemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
    	(void)NV_ReadHWParameters(&gHardwareParameters);//venk
    	gHardwareParameters.serial_id=pSer->txQueue[idx].pData;//venk
    	if((*gHardwareParameters.serial_id++=='#')&&((*gHardwareParameters.serial_id=='C')||(*gHardwareParameters.serial_id=='c')))//venk
    	{
    	gHardwareParameters.serial_id=(gHardwareParameters.serial_id+1);//venk
    	gHardwareParameters.device_id=(uint8_t*)"serial_id_ok";
    	advScanStruct[2].aData=gHardwareParameters.serial_id;
    	(void)NV_WriteHWParameters(&gHardwareParameters);//venk*/
    	}
		
		wirelessuart.c
	advScanStruct[2].aData=gHardwareParameters.serial_id;//venk	

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
  
char* a;

a=(char*)"#ctemp-112";
printf("old a=%s\n",a);

if((*a++=='#')&&(*a=='c'))
a=a+1;
printf("new a=%s\n",a);

return 0;
}


********************************************************************************** */
#include "ble_conn_manager.h"//venk
bleResult_t Ble_Initialize
(
    gapGenericCallback_t gapGenericCallback
)
{
	 (void)NV_ReadHWParameters(&gHardwareParameters);//venk
	 Dear sir,
	          I am not feeling well now,please kindly requesting to give me permission from 3:00pm to 6:00pm for early leaving. 
			  
			  0x1fffe58e <memHeap+146> "\001üÿ\037u\0238 #ctemp-88"
			  
 /******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
  
//char a[9]="SDAS-999";
char a[19]= "\001üÿ\037u\0238 #ctemp-88";

//a=(char*)"#ctemp-112";
//printf("old a=%s\n",a);

//if((*a++=='#')&&(*a=='c'))
//a=a+1;
printf("new a=%s\n",a);

return 0;
}

25/10/2021

 	 if (gHardwareParameters.devidset)
    	advScanStruct[2].aData = (uint8_t*) "SDAS-123";//default
    	else
    	advScanStruct[2].aData=gHardwareParameters.device_id;//updated eeprom value*/

    	temp_id=pSer->txQueue[idx].pData;//venk
    	if((*temp_id=='#')&&(*++temp_id=='c'))//venk
    	{

    	gHardwareParameters.device_id=(temp_id+1);//venk
    	gHardwareParameters.devidset = 0;

    	(void)NV_WriteHWParameters(&gHardwareParameters);//venk*/
    	}
extern gapAdStructure_t                 advScanStruct[3];//venk
    uint8_t  devidset;//venk
    uint8_t* device_id;//venk
	
	
	
	
	    /*Scanning and Advertising Data stored in eeprom and read from eeprom added venk */
	//(void)NV_ReadHWParameters(&gHardwareParameters);
	//advScanStruct[2].aData=(uint8_t*)gHardwareParameters.device_id;

    /*Scanning and Advertising Data stored in eeprom and read from eeprom a */

	/*if((*gHardwareParameters.serial_id++=='#')&&((*gHardwareParameters.serial_id=='C')||(*gHardwareParameters.serial_id=='c')))//venk
	{
	gHardwareParameters.serial_id=(gHardwareParameters.serial_id+1);//venk
	gHardwareParameters.device_id=(uint8_t*)"#C_ok";
	advScanStruct[2].aData=gHardwareParameters.serial_id;
	(void)NV_WriteHWParameters(&gHardwareParameters);//venk
	}*/


	(void)NV_ReadHWParameters(&gHardwareParameters);//venk
	 if (gHardwareParameters.devidset){
	advScanStruct[2].aData = (uint8_t*) "SDAS-123";
	gHardwareParameters.device_id=(uint8_t*) "SDAS-200";
	(void)NV_WriteHWParameters(&gHardwareParameters);}
	
	
	
	
	26-10-2021
	
 /******************************************************************************************************************/
/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/
		//(void)NV_ReadHWParameters(&gHardwareParameters);//venk
	    if (!gHardwareParameters.devidset)//default nonzero
		advScanStruct[2].aData = (uint8_t*) "SDAS-123";//default
		else
			//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		advScanStruct[2].aData=gHardwareParameters.device_id;//updated eeprom value**/

		temp_id=pSer->txQueue[idx].pData;//venk
		gHardwareParameters.temp_id1=temp_id;
		if((*gHardwareParameters.temp_id1=='#')&&(*++gHardwareParameters.temp_id1=='c'))//venk
		{

		//gHardwareParameters.device_id=(gHardwareParameters.temp_id1+1);//venk
		gHardwareParameters.device_id= (uint8_t*) "SDAS-223";;//venk
		//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		gHardwareParameters.devidset =1;

		(void)NV_WriteHWParameters(&gHardwareParameters);//venk*/
		}


/*******************************************************************************************************************/
28-10-2021
* \brief Transmit a data buffer to the specified interface.
*
* \param[in] InterfaceId the interface number
*
* \return The status of the operation
*
********************************************************************************** */
static serialStatus_t Serial_WriteInternal( uint8_t InterfaceId )
{
    serialStatus_t status = gSerial_Success_c;
    serial_t *pSer = &mSerials[InterfaceId];
    uint16_t idx;

    OSA_InterruptDisable();
    if( pSer->state == 0 )
    {
        pSer->state = 1;
#if gSerialMgr_DisallowMcuSleep_d
        PWR_DisallowDeviceToSleep();
#endif
    }
    else
    {
        /* The interface is busy transmitting!
         * The current data will be transmitted after the previous transmissions end.
         */
        OSA_InterruptEnable();
        return gSerial_Success_c;
    }
    OSA_InterruptEnable();

    idx = pSer->txCurrent;
    if(pSer->txQueue[idx].dataSize == 0)
    {
#if gSerialMgr_DisallowMcuSleep_d
        PWR_AllowDeviceToSleep();
#endif
        pSer->state = 0;
        return gSerial_Success_c;
    }

    switch ( mSerials[InterfaceId].serialType )
    {
#if (gSerialMgrUseUart_c)
#if FSL_FEATURE_SOC_UART_COUNT
    case gSerialMgrUart_c:
        if( UART_SendData( pSer->serialChannel, pSer->txQueue[idx].pData, pSer->txQueue[idx].dataSize ) )
        {
            status = gSerial_InternalError_c;
        }
        break;
#endif
#if FSL_FEATURE_SOC_LPUART_COUNT
    case gSerialMgrLpuart_c:






 /******************************************************************************************************************/
/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/
		(void)NV_ReadHWParameters(&gHardwareParameters);//venk
	    if (!gHardwareParameters.devidset)//default nonzero
		advScanStruct[2].aData = (uint8_t*) "SDAS-123";//default
		else
			//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		advScanStruct[2].aData=gHardwareParameters.device_id;//updated eeprom value**/

		temp_id=pSer->txQueue[idx].pData;//venk
		gHardwareParameters.temp_id1=temp_id;
		if((*gHardwareParameters.temp_id1=='#')&&(*++gHardwareParameters.temp_id1=='c'))//venk
		{

		gHardwareParameters.device_id=(gHardwareParameters.temp_id1+1);//venk
		gHardwareParameters.device_id= (uint8_t*) "SDAS-223";;//venk
		//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		gHardwareParameters.devidset =1;

		(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		}

/*******************************************************************************************************************/






        if( LPUART_SendData(pSer->serialChannel, pSer->txQueue[idx].pData, pSer->txQueue[idx].dataSize) )
        {
            status = gSerial_InternalError_c;
        }
        break;  
		
		
	


/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>


int main()
{
  
//char a[9]="SDAS-999";

char *b;
char *a= "\001üÿ\037#\024: #c301";
while(1)
{
if(*a++=='c')
{
b=(char*)a;
printf(" b=%s\n",b);
}
}
return 0;
}


/******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/

	serial_t *pSer = &mSerials[0];
	uint16_t idx;
	idx = pSer->txCurrent;


		(void)NV_ReadHWParameters(&gHardwareParameters);//venk
	    if (!gHardwareParameters.devidset)//default nonzero
		advScanStruct[2].aData = (uint8_t*) "SDAS-123";//default
		else
			//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		advScanStruct[2].aData=gHardwareParameters.device_id;//updated eeprom value

		temp_id=pSer->txQueue[3].pData;//venk
		gHardwareParameters.temp_id1=temp_id;
		gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1+11);//venk
		advScanStruct[2].aData=gHardwareParameters.device_id;
		(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		if((*gHardwareParameters.temp_id1=='#')&&(*++gHardwareParameters.temp_id1=='c'))//venk
		{

		gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1+1);//venk
		//gHardwareParameters.device_id= (uint8_t*) "SDAS-223";;//venk
		//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		gHardwareParameters.devidset =1;

		(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		}


/*******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/*******************************************************************************************************************/
/******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/

	serial_t *pSer = &mSerials[0];
	uint16_t idx;//declare in global
	idx = pSer->txCurrent;


		(void)NV_ReadHWParameters(&gHardwareParameters);//venk
	    if (gHardwareParameters.devidset)//default nonzero
		advScanStruct[2].aData = (uint8_t*) "SDAS-123";//default
		
		
		else
			//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		advScanStruct[2].aData=gHardwareParameters.device_id;//updated eeprom value
		
		
		if(idx==1)
		gHardwareParameters.devidset=0;	

		temp_id=pSer->txQueue[3].pData;//venk
		gHardwareParameters.temp_id1=temp_id;
		gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1+11);//venk
		advScanStruct[2].aData=gHardwareParameters.device_id;
		(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		
		gHardwareParameters.devidset =1;

		


/*******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/*******************************************************************************************************************/

29-10-21
/******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/
/*************coding working fine for running time advertisemnt ******************/
	serial_t *pSer = &mSerials[0];
	uint16_t idx;
	idx = pSer->txCurrent;


		(void)NV_ReadHWParameters(&gHardwareParameters);//venk
	    if (!gHardwareParameters.devidset)//default nonzero
		advScanStruct[2].aData = (uint8_t*) "SDAS-123";//default
		else
			//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		advScanStruct[2].aData=gHardwareParameters.device_id;//updated eeprom value

		temp_id=pSer->txQueue[3].pData;//venk
		gHardwareParameters.temp_id1=temp_id;
		gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1+11);//venk
		advScanStruct[2].aData=gHardwareParameters.device_id;
		(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		if((*gHardwareParameters.temp_id1=='#')&&(*++gHardwareParameters.temp_id1=='c'))//venk
		{

		gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1+1);//venk
		//gHardwareParameters.device_id= (uint8_t*) "SDAS-223";;//venk
		//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		gHardwareParameters.devidset =1;

		(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		}


/*******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/*******************************************************************************************************************/




/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

#include <string.h>
char buffer[20],buffer1[20];

char *temp_id1,*temp_id;

int main ()
{

	temp_id="\001üÿ\037#\024: #cdas-301yyyyyyy!";//pSer->txQueue[3].pData;//venk

	temp_id1=temp_id+11;
	puts(temp_id1);
	strcpy( buffer, temp_id1);
	puts(buffer);
	memcpy(buffer1,buffer,8);

	puts(buffer1);
  return 0;
}
/******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/

	serial_t *pSer = &mSerials[0];
	uint16_t idx;
	idx = pSer->txCurrent;
	
	char len,buffer[20],buffer1[20];
	(void)NV_ReadHWParameters(&gHardwareParameters);//reading hardware parameters venk
	if (!gHardwareParameters.devidset)//default nonzero
	advScanStruct[2].aData = (uint8_t*) "SDAS-123";//default
	else
	//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
	advScanStruct[2].aData=gHardwareParameters.device_id;//updated eeprom value
	
	/***************scanning app value and moving to temporary buffer**************/
	temp_id=pSer->txQueue[3].pData;//"\r\n[00-s]: #cdas-999yyyyyyy!";//venk
	
	char g=strlen(temp_id);	
	if(g==27)
	len=8;
	else if(g==26)
	len=7;
	else if(g==25)
	len=6;
	else if(g==24)
	len=5;
	else
	len=4;

	gHardwareParameters.temp_id1=temp_id+11;//omitting 11 char
	strcpy( buffer, gHardwareParameters.temp_id1);//storing in buffer
	memcpy(buffer1,buffer,len);//required value
	char *result = (char *)malloc(strlen(buffer1)+1);
	strcpy(result,buffer1);
	gHardwareParameters.device_id=(uint8_t*) (result);//required value copied to eeprom variable venk		
	advScanStruct[2].aData=gHardwareParameters.device_id;//advertising the data
	(void)NV_WriteHWParameters(&gHardwareParameters);//venk
	if((*gHardwareParameters.device_id=='c')||(*++gHardwareParameters.temp_id1=='C'))//venk
	{
	advScanStruct[2].aData=gHardwareParameters.device_id;
	gHardwareParameters.devidset =1;
	(void)NV_WriteHWParameters(&gHardwareParameters);//venk
	}


/*******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/*******************************************************************************************************************/


#include <stdio.h>
#include<stdlib.h>
#include <string.h>
char buffer[20],buffer1[20];
char *temp_id1,*temp_id,*temp_id2,*hp;
int main ()
{

	temp_id="\001üÿ\037#\024: #cdas-301yyyyyyy!";//pSer->txQueue[3].pData;//venk
	puts(temp_id);
	temp_id1=temp_id+11;
	puts(temp_id1);
	strcpy( buffer, temp_id1);
	puts(buffer);
	memcpy(buffer1,buffer,8);
	puts(buffer1);
	char *result = (char *)malloc(strlen(buffer1)+1);
	strcpy(result,buffer1);
	puts(result);
	hp=result;
	printf("final value\n");
	puts(hp);//hardware pointers
	return 0;
}

/*******************************************/

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
char len,buffer[20],buffer1[20];
char *temp_id1,*temp_id,*temp_id2,*hardwareparam;
int main ()
{
	temp_id="\r\n[00-s]: #cdas-999yyyyyyy!";//pSer->txQueue[3].pData;//venk
	char g=strlen(temp_id);
	printf("lenght=%d\n",g);
	puts(temp_id);
	temp_id1=temp_id+11;
	puts(temp_id1);
	strcpy( buffer, temp_id1);
	puts(buffer);
	if(g==27)
	len=8;
	else if(g==26)
	len=7;
	else if(g==25)
	len=6;
	else if(g==24)
	len=5;
	else
	len=4;
	memcpy(buffer1,buffer,len);
	puts(buffer1);
	char *result = (char *)malloc(strlen(buffer1)+1);
	strcpy(result,buffer1);
	puts(result);
	hardwareparam=result;
	printf("final value\n");
	puts(hardwareparam);//hardware pointers
	return 0;
}

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct SerialManagetMsg_tag{

    int          *pTxParam;
    int          *pData;
    int          dataSize;
}SerialMsg_t;

typedef struct serial_tag{
    /* Rx parameters */
    int         rxIn;
    int         rxOut;
    int         rxCallback;
    void       *pRxParam;
    /* Tx parameters */
    SerialMsg_t            txQueue[5];
}serial_t;

static serial_t      mSerials[1];

int main()
{
    
    serial_t *pSer = &mSerials[0];
    char  idx;
    idx = pSer->rxIn;
    char*temp_id;
pSer->txQueue[3].pData;//venk
char str[] = "Hello World";
char *result = (char *)malloc(strlen(str)+1);
strcpy(result,str);
puts(result);
}
1/11/2021

/******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/
//data capturing every time ok
        	serial_t *pSer = &mSerials[0];
        	uint16_t idx;
        	idx = pSer->txCurrent;


		(void)NV_ReadHWParameters(&gHardwareParameters);//venk
		if (!gHardwareParameters.devidset)//default nonzero
		advScanStruct[2].aData = (uint8_t*) "SDAS-123";//default
		else
		//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		advScanStruct[2].aData=gHardwareParameters.device_id;//updated eeprom value
			if(idx==0)
			   idx=5;
			else{
			   idx = pSer->txCurrent;}
		temp_id=pSer->txQueue[idx-1].pData;//venk
		gHardwareParameters.temp_id1=temp_id;
		gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1+11);//venk
		advScanStruct[2].aData=gHardwareParameters.device_id;
		(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		if((*gHardwareParameters.temp_id1=='#')&&(*++gHardwareParameters.temp_id1=='c'))//venk
		{

		gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1+1);//venk
		//gHardwareParameters.device_id= (uint8_t*) "SDAS-223";;//venk
		//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		gHardwareParameters.devidset =1;

		(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		}


/*******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/*******************************************************************************************************************/


/******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/
//code ok for  sigle time saving
		serial_t *pSer = &mSerials[0];
		uint16_t idx;
		idx = pSer->txCurrent;


		(void)NV_ReadHWParameters(&gHardwareParameters);//venk
		if (!gHardwareParameters.devidset)//default nonzero
		{
		advScanStruct[2].aData = (uint8_t*) "SDAS-123";//default
		gHardwareParameters.devidset =1;
		}
		else
		{
			advScanStruct[2].aData=gHardwareParameters.device_id;
		}
		//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		//advScanStruct[2].aData=gHardwareParameters.device_id;//updated eeprom value
		//each time value is storing in different buffer id depends on idx value
		if(idx==0)
			idx=5;
		else
			idx = pSer->txCurrent;

		//advScanStruct[2].aData = (uint8_t*) "SDAS-123";

		temp_id=pSer->txQueue[idx-1].pData;//venk
		temp_id2=temp_id+11;

        if((*temp_id2=='c')||(*temp_id2=='s')||(*temp_id2=='#')||(*temp_id2=='d')||(*temp_id2!='n'))

        {
		//temp_id=pSer->txQueue[3].pData;//venk
		gHardwareParameters.temp_id1=temp_id;
		gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1+11);//venk
		advScanStruct[2].aData=gHardwareParameters.device_id;
		(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		/*if((*gHardwareParameters.device_id=='#')||(*gHardwareParameters.device_id=='c')||(*gHardwareParameters.device_id==' ')||(*gHardwareParameters.device_id=='s'))//venk
		{


	    advScanStruct[2].aData=gHardwareParameters.device_id;
		gHardwareParameters.devidset =1;

		(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		}*/

		}

2-11-2021

/******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/
		serial_t *pSer = &mSerials[0];
		uint16_t idx;
		idx = pSer->txCurrent;


		(void)NV_ReadHWParameters(&gHardwareParameters);//venk
		if (!gHardwareParameters.devidset)//default nonzero
		{
		advScanStruct[2].aData = (uint8_t*) "SDAS-123";//default
		//gHardwareParameters.devidset =1;
		}
		else
		{
			advScanStruct[2].aData=gHardwareParameters.device_id;
		}
		//advScanStruct[2].aData = (uint8_t*) "SDAS-223";//default
		//advScanStruct[2].aData=gHardwareParameters.device_id;//updated eeprom value
		//each time value is storing in different buffer id depends on idx value
		if(idx==0)
			idx=5;
		else
			idx = pSer->txCurrent;

		//advScanStruct[2].aData = (uint8_t*) "SDAS-123";

		temp_id=pSer->txQueue[idx-1].pData;//venk
		temp_id2=temp_id+11;

       // if((*temp_id2=='c')||(*temp_id2=='s')||(*temp_id2=='#')||(*temp_id2=='d')||(*temp_id2!='n')||(*temp_id2!='\n'))
		if(*temp_id2=='c')
        {
		//temp_id=pSer->txQueue[3].pData;//venk
		gHardwareParameters.temp_id1=temp_id;
		gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1+11);//venk
		advScanStruct[2].aData=gHardwareParameters.device_id;
		gHardwareParameters.devidset =1;
		(void)NV_WriteHWParameters(&gHardwareParameters);//venk

		/*if((*gHardwareParameters.device_id=='#')||(*gHardwareParameters.device_id=='c')||(*gHardwareParameters.device_id==' ')||(*gHardwareParameters.device_id=='s'))//venk
		{


	    advScanStruct[2].aData=gHardwareParameters.device_id;
		gHardwareParameters.devidset =1;

		(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		}*/
		//(void)NV_WriteHWParameters(&gHardwareParameters);//venk
		}





/*******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/*******************************************************************************************************************/


/******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/
	//code ok for first time updating
	serial_t *pSer = &mSerials[0];
		uint16_t idx;
		idx = pSer->txCurrent;


		(void)NV_ReadHWParameters(&gHardwareParameters);//venk
		if (!gHardwareParameters.devidset)//default nonzero
		{
		    advScanStruct[2].aData = (uint8_t*) "SDAS-123";//default

		}
		else
		{
			advScanStruct[2].aData=gHardwareParameters.device_id+2;
		}

		if(idx==0)
			idx=5;
		else
			idx = pSer->txCurrent;

		temp_id=pSer->txQueue[idx-1].pData;//venk
		temp_id2=temp_id+9;

        if((*temp_id2=='#')&&(*++temp_id2=='c'))
	        {
			gHardwareParameters.temp_id1=temp_id2;
			gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1);//venk
			advScanStruct[2].aData=gHardwareParameters.device_id+2;
			gHardwareParameters.devidset =1;
			(void)NV_WriteHWParameters(&gHardwareParameters);//venk

			}

/*******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/*******************************************************************************************************************/

/******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/
//code updating 2ndtime also ok
		serial_t *pSer = &mSerials[0];
		uint16_t idx;
		idx = pSer->txCurrent;
		(void)NV_ReadHWParameters(&gHardwareParameters);//venk
		if (!gHardwareParameters.devidset)//default nonzero
		       advScanStruct[2].aData = (uint8_t*) "cdas-123";//default
		//advScanStruct[2].aData=gHardwareParameters.device_id;
		else
			advScanStruct[2].aData=gHardwareParameters.device_id;
		if(idx==0)
			idx=5;
		else
			idx = pSer->txCurrent;
		temp_id=pSer->txQueue[idx-1].pData;//venk
		temp_id2=temp_id+9;
		temp_id3=temp_id+9;
		if(((*temp_id2==' ')&&(*++temp_id2=='#'))||((*temp_id3=='#')&&(*++temp_id3=='c')))
			{
				gHardwareParameters.temp_id1=temp_id2;
				if(*gHardwareParameters.temp_id1=='c')
				    {gHardwareParameters.temp_id1=gHardwareParameters.temp_id1+1;
				(void)NV_WriteHWParameters(&gHardwareParameters);}
				else
					{gHardwareParameters.temp_id1=gHardwareParameters.temp_id1+2;
				(void)NV_WriteHWParameters(&gHardwareParameters);}

				gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1);//venk
				advScanStruct[2].aData=gHardwareParameters.device_id;
				gHardwareParameters.devidset =1;
				(void)NV_WriteHWParameters(&gHardwareParameters);//venk

			}

/*******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/*******************************************************************************************************************/


3-11-2021


/******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/
		serial_t *pSer = &mSerials[0];
		uint16_t idx;
		idx = pSer->txCurrent;
		(void)NV_ReadHWParameters(&gHardwareParameters);//venk

		//initially default value loaded if eeprom write new updated else condition
		if (!gHardwareParameters.devidset)//default nonzero
			advScanStruct[2].aData = (uint8_t*) "cdas-123";//default

		else
			advScanStruct[2].aData=gHardwareParameters.device_id;
		//idx points to current txQueue buffer
		if(idx==0)
			idx=5;

		else
			idx = pSer->txCurrent;

		//current buffer loaded to temp value
		temp_id=pSer->txQueue[idx-1].pData;//venk
		temp_id2=temp_id+9;
		temp_id3=temp_id+9;

		if(((*temp_id2==' ')&&(*++temp_id2=='#'))||((*temp_id3=='#')&&(*++temp_id3=='c')))
			{
				gHardwareParameters.temp_id1=temp_id2;
				if(*gHardwareParameters.temp_id1=='c')
					{
						gHardwareParameters.temp_id1=gHardwareParameters.temp_id1+1;
						(void)NV_WriteHWParameters(&gHardwareParameters);
					}

				else
					{
						gHardwareParameters.temp_id1=gHardwareParameters.temp_id1+2;
						(void)NV_WriteHWParameters(&gHardwareParameters);
					}

				gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1);//venk
				advScanStruct[2].aData=gHardwareParameters.device_id;
				gHardwareParameters.devidset =1;
				(void)NV_WriteHWParameters(&gHardwareParameters);//venk

			}

/*******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/*******************************************************************************************************************/
//handler solved code
/******************************************************************************************************************/
	/*reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id *///venk
/******************************************************************************************************************/
		serial_t *pSer = &mSerials[0];
		uint16_t idx;
		idx = pSer->txCurrent;
		(void)NV_ReadHWParameters(&gHardwareParameters);//venk

		//initially default value loaded if eeprom write new updated else condition
		if (!gHardwareParameters.devidset)//default nonzero
			advScanStruct[2].aData = (uint8_t*) "cdas-123";//default

		else{
			//advScanStruct[2].aData = (uint8_t*) "cdas-123";//default
			advScanStruct[2].aData=gHardwareParameters.device_id;}
		//idx points to current txQueue buffer
		if(idx==0)
			idx=5;

		else
			idx = pSer->txCurrent;

		//current buffer loaded to temp value
		temp_id=pSer->txQueue[idx-1].pData;//venk
		temp_id2=temp_id+9;
		temp_id3=temp_id+9;

		if(((*temp_id2==' ')&&(*++temp_id2=='#'))||((*temp_id3=='#')&&(*++temp_id3=='c')))
			{
				gHardwareParameters.temp_id1=temp_id2;
				if(*gHardwareParameters.temp_id1=='c')
					{
						gHardwareParameters.temp_id1=gHardwareParameters.temp_id1+1;
						(void)NV_WriteHWParameters(&gHardwareParameters);
					}

				else
					{
						gHardwareParameters.temp_id1=gHardwareParameters.temp_id1+2;
						(void)NV_WriteHWParameters(&gHardwareParameters);
					}

				gHardwareParameters.device_id=(uint8_t*) (gHardwareParameters.temp_id1);//venk
				advScanStruct[2].aData=gHardwareParameters.device_id;
				gHardwareParameters.devidset =1;
				(void)NV_WriteHWParameters(&gHardwareParameters);//venk

			}

/*******************************************************************************************************************/
	//reading #CTemp-123 from iot toolbox  and reading and writting to gHardwareParameters.serial_id //venk
/*******************************************************************************************************************/
8-11-2021

		   When you send the new device name to mcu, you firstly write it into memory. 
		   And then make mcu disconnect from the phone using 'Gap_Disconnect'. 
		   Read the adv structure from the memory. Use 'Gap_SetAdvertisingData' to set the adv data.
		   Use 'App_StartAdvertising' to start the adv again.
		    Hi,
I followed your procedure it is working better than previous code but
when i try to change device name it is updating ok for 4 times 
when i update 5th time it is not updating or even
when i reset the mcu it is updating 2 times again showing previous updated value
and Iam not understanding why there is inconsistent in updating the value.


////////////////////11-11-21 project ok update at runtime////////////////////////////////


  sDeviceInfo devieInfo;// = (sDeviceInfo*)pStream;
            uint32_t strLen = FLib_StrLen(pStream);
            FLib_MemSet(&devieInfo,0,sizeof(sDeviceInfo));
            FLib_MemCpy(&devieInfo,(sDeviceInfo*)pStream,strLen);
            if((devieInfo.headerInfo == 'c') ||(devieInfo.headerInfo == 'C'))
            {
            	//disconnect from phone
                for (uint8_t mPeerId = 0; mPeerId < (uint8_t)gAppMaxConnections_c; mPeerId++)
                {
                    if (maPeerInformation[mPeerId].deviceId != gInvalidDeviceId_c)
                    {
                        (void)Gap_Disconnect(maPeerInformation[mPeerId].deviceId);
                    }
                }
                //FLib_MemSet(gAppAdvertisingData.aAdStructures[2].aData,0,sizeof(gAppAdvertisingData.aAdStructures[2]));
                uint32_t strLen1 = FLib_StrLen(devieInfo.deviceName);
               // if(strLen1==7)
                	//strLen1=7;
               // FLib_MemSet(gHardwareParameters.id_no,' ',8);
                FLib_MemCpy(gHardwareParameters.id_no,devieInfo.deviceName,strLen1);//venk
               // gHardwareParameters.id_no=devieInfo.deviceName;

    			// FLib_MemCpy(gHardwareParameters.id_no,devieInfo.deviceName,8);//venk change to 8
    				gHardwareParameters.devidset =0;//venk
    				(void)NV_WriteHWParameters(&gHardwareParameters);//venk
    				gAppAdvertisingData.aAdStructures[2].aData=gHardwareParameters.id_no;

    			// FLib_MemCpy(gAppAdvertisingData.aAdStructures[2].aData,gHardwareParameters.id_no,8);//venk

                //FLib_MemCpy(gAppAdvertisingData.aAdStructures[2].aData,devieInfo.deviceName,6);
                gAppAdvertisingData.aAdStructures[2].length = FLib_StrLen(gAppAdvertisingData.aAdStructures[2].aData) + 1; // length of name, and the type also occupy 1 byte
                (void)Gap_SetAdvertisingData(&gAppAdvertisingData, &gAppScanRspData);
                App_StartAdvertising(BleApp_AdvertisingCallback, BleApp_ConnectionCallback);
            }


Dear Sir,
         Please find the cell balancing links of NXP.

https://community.nxp.com/t5/Model-Based-Design-Toolbox-MBDT/Balancing-Logic-of-MC33771-Blocks-in-MBDT/td-p/1162888

https://community.nxp.com/t5/Model-Based-Design-Toolbox-MBDT/Issue-of-MC3377XB-BALANCING-MBDT-BLOCK/td-p/1233530

https://community.nxp.com/t5/Power-Management/MC33771-S32K-BALANCING/m-p/853475