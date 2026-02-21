/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
typedef	struct{
	int wrb0;
	int wrb1;
	int wrb2;
	int secerflg;
	int wrcnt;
	int r1;
	int r2;
	int r3;	
} BmsRec_t;

typedef union {   // why union?
	int BmsRecArray[sizeof(BmsRec_t)];
	BmsRec_t BmsCompValues;
} BmsRecValues_t;



void EEPROM_WriteWrrecValues(BmsRecValues_t BMSRecValues)
{
	int *a;
	a=&BMSRecValues;
	for(int i=0;i<3;i++)
	    printf("Hello World :%d\n",*(a+i));
}

#include <stdio.h>

int main()
{
   
	BmsRecValues_t BMSRecValues;
	    int wb0 = 100;
		int wb1 = 200;
		int wb2 = 300;
	    BMSRecValues.BmsCompValues.wrb0 = wb0;
		BMSRecValues.BmsCompValues.wrb1 = wb1;
		BMSRecValues.BmsCompValues.wrb2 = wb2;
		//BMSRecValues.BmsCompValues.secerflg = SeraseFlg;
	//	BMSRecValues.BmsCompValues.wrcnt = wrcount;
		
	EEPROM_WriteWrrecValues(BMSRecValues);

    return 0;
}
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
typedef	struct{
	int wrb0;
	int wrb1;
	int wrb2[];

} BmsRec_t;//12

typedef union {   // why union?
	int BmsRecArray[sizeof(BmsRec_t)];//48
	BmsRec_t BmsCompValues;//
} BmsRecValues_t;//



void EEPROM_WriteWrrecValues(BmsRecValues_t BMSRecValues)
{
	int *a;
	a=&BMSRecValues;
	for(int i=0;i<3;i++)
	    printf("Hello World :%d\n",*(a+i));
}

#include <stdio.h>

int main()
{
    BmsRec_t BmsCompValues;
   printf(" BmsRec_t=%d\n",sizeof( BmsRec_t));
   printf(" BmsRecValues_t=%d\n",sizeof( BmsRecValues_t));
   printf(" BmsCompValues=%d\n",BmsCompValues);
	BmsRecValues_t BMSRecValues;
	    int wb0 = 100;
		int wb1 = 200;
		int wb2 = 300;
	    BMSRecValues.BmsCompValues.wrb0 = wb0;
		BMSRecValues.BmsCompValues.wrb1 = wb1;
		BMSRecValues.BmsCompValues.wrb2 = wb2;
		//BMSRecValues.BmsCompValues.secerflg = SeraseFlg;
	//	BMSRecValues.BmsCompValues.wrcnt = wrcount;
		
	EEPROM_WriteWrrecValues(BMSRecValues);

    return 0;
}
 FlexNVM EEprom Example Start

 Flash is UNSECURE!

 There is no available EEprom (FlexNVM) on this Device by default.
 Example is trying to configure FlexNVM block as EEprom.


        ---- HALTED DUE TO FLASH ERROR! ----

 FlexNVM EEprom Example Start

 Flash is UNSECURE!

 There is no available EEprom (FlexNVM) on this Device by default.
 Example is trying to configure FlexNVM block as EEprom.


        ---- HALTED DUE TO FLASH ERROR! ----

 FlexNVM EEprom Example Start

 Flash is UNSECURE!

 There is no available EEprom (FlexNVM) on this Device by default.
 Example is trying to configure FlexNVM block as EEprom.


        ---- HALTED DUE TO FLASH ERROR! ----


	flash_callback_t PFlashCallback=0;         /*!< The callback function for the flash API. */

	FlexRAMBlockBase=0;               /*!< For the FlexNVM device, this is the base address of the FlexRAM */
	/*!< For the non-FlexNVM device, this is the base address of the acceleration RAM memory */
	FlexRAMTotalSize=0; /*!< For the FlexNVM device, this is the size of the FlexRAM */
	/*!< For the non-FlexNVM device, this is the size of the acceleration RAM memory */

	DFlashBlockBase0 /*!< For the FlexNVM device, this is the base address of the D-Flash memory (FlexNVM memory) */
	/*!< For the non-FlexNVM device, this field is unused */
	DFlashTotalSize=0; /*!< For the FlexNVM device, this is the total size of the FlexNVM memory; */
	/*!< For the non-FlexNVM device, this field is unused */
	EEpromTotalSize=0; /*!< For the FlexNVM device, this is the size in bytes of the EEPROM area which was
	partitioned from FlexRAM */
	/*!< For the non-FlexNVM device, this field is unused */








/*! @brief Set 32B FlexRAM Size(EEESIZE) for EEprom, Subsystem A = B = EEESIZE / 2 */
#define EEPROM_DATA_SET_SIZE_CODE (0x39U)

/*! @brief Flash driver Structure */
static flash_config_t s_flashDriver;
uint32_t i;
        uint32_t s_buffer;     /* Buffer for program */
        uint32_t s_buffer_rbc; /* Buffer for readback */
        uint32_t destAdrss;                /* Address of the target location */

        uint32_t dflashBlockBase = 0;
        uint32_t dflashTotalSize = 0;
        uint32_t eepromBlockBase = 0;
        uint32_t eepromTotalSize = 0;
        uint32_t flexramBlockBase = 0;
        uint32_t flexramTotalSize = 0;
s_buffer = i + 1;
destAdrss = flexramBlockBase;//0
s_buffer_rbc = *(volatile uint32_t *)(destAdrss + i * 4);
s_buffer = 0xFFFFFFFFU;
result = FLASH_EepromWrite(&s_flashDriver, destAdrss, (uint8_t *)s_buffer, sizeof(s_buffer));
	FLASH_EepromWrite(&s_flashDriver, addr,(uint8_t)data, sizeof(data));
if (kStatus_FLASH_Success != result)
{
error_trap();
}
/*!
 * @brief Enumeration for various flash properties.
 */
typedef enum _flash_property_tag
{
    kFLASH_PropertyPflashSectorSize = 0x00U,         /*!< Pflash sector size property.*/
    kFLASH_PropertyPflashTotalSize = 0x01U,          /*!< Pflash total size property.*/
    kFLASH_PropertyPflashBlockSize = 0x02U,          /*!< Pflash block size property.*/
    kFLASH_PropertyPflashBlockCount = 0x03U,         /*!< Pflash block count property.*/
    kFLASH_PropertyPflashBlockBaseAddr = 0x04U,      /*!< Pflash block base address property.*/
    kFLASH_PropertyPflashFacSupport = 0x05U,         /*!< Pflash fac support property.*/
    kFLASH_PropertyPflashAccessSegmentSize = 0x06U,  /*!< Pflash access segment size property.*/
    kFLASH_PropertyPflashAccessSegmentCount = 0x07U, /*!< Pflash access segment count property.*/
    kFLASH_PropertyFlexRamBlockBaseAddr = 0x08U,     /*!< FlexRam block base address property.*/
    kFLASH_PropertyFlexRamTotalSize = 0x09U,         /*!< FlexRam total size property.*/
    kFLASH_PropertyDflashSectorSize = 0x10U,         /*!< Dflash sector size property.*/
    kFLASH_PropertyDflashTotalSize = 0x11U,          /*!< Dflash total size property.*/
    kFLASH_PropertyDflashBlockSize = 0x12U,          /*!< Dflash block size property.*/
    kFLASH_PropertyDflashBlockCount = 0x13U,         /*!< Dflash block count property.*/
    kFLASH_PropertyDflashBlockBaseAddr = 0x14U,      /*!< Dflash block base address property.*/
    kFLASH_PropertyEepromTotalSize = 0x15U,          /*!< EEPROM total size property.*/
    kFLASH_PropertyFlashMemoryIndex = 0x20U,         /*!< Flash memory index property.*/
    kFLASH_PropertyFlashCacheControllerIndex = 0x21U /*!< Flash cache controller index property.*/
} flash_property_tag_t;




/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "clock_config.h"
#include "pin_mux.h"
#include "fsl_flash.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


#define BUFFER_LEN 4

/*! @brief Set 32B FlexRAM Size(EEESIZE) for EEprom, Subsystem A = B = EEESIZE / 2 */
#define EEPROM_DATA_SET_SIZE_CODE (0x39U)

/*! @brief Set EEprom backup memory */
/*
#if ((FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0011 != 0xFFFFFFFF) && \
     (FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0011 != 0x00000000) && \
     (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0011 != 0xFFFF) &&    \
     (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0011 != 0x0000))
#define FLEXNVM_PARTITION_CODE (0x3U)
*/
#if(FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0100 != 0xFFFFFFFF) && \
    (FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0100 != 0x00000000) &&  \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0100 != 0xFFFF) &&     \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0100 != 0x0000)
#define FLEXNVM_PARTITION_CODE (0x4U)
#elif(FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0101 != 0xFFFFFFFF) && \
    (FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0101 != 0x00000000) &&  \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0101 != 0xFFFF) &&     \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0101 != 0x0000)
#define FLEXNVM_PARTITION_CODE (0x5U)
#elif(FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1001 != 0xFFFFFFFF) && \
    (FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1001 != 0x00000000) &&  \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1001 != 0xFFFF) &&     \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1001 != 0x0000)
#define FLEXNVM_PARTITION_CODE (0x9U)
#elif(FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1010 != 0xFFFFFFFF) && \
    (FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1010 != 0x00000000) &&  \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1010 != 0xFFFF) &&     \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1010 != 0x0000)
#define FLEXNVM_PARTITION_CODE (0xaU)
#elif(FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1011 != 0xFFFFFFFF) && \
    (FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1011 != 0x00000000) &&  \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1011 != 0xFFFF) &&     \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1011 != 0x0000)
#define FLEXNVM_PARTITION_CODE (0xbU)
#elif(FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1100 != 0xFFFFFFFF) && \
    (FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1100 != 0x00000000) &&  \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1100 != 0xFFFF) &&     \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1100 != 0x0000)
#define FLEXNVM_PARTITION_CODE (0xcU)
#elif(FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1101 != 0xFFFFFFFF) && \
    (FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1101 != 0x00000000) &&  \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1101 != 0xFFFF) &&     \
    (FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1101 != 0x0000)
#define FLEXNVM_PARTITION_CODE (0xdU)
#else
#define FLEXNVM_PARTITION_CODE (0x8U)
#endif
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void error_trap(void);
void app_finalize(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Flash driver Structure */
static flash_config_t s_flashDriver;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*
* @brief Gets called when an error occurs.
*
* @details Print error message and trap forever.
*/
void error_trap(void)
{
    PRINTF("\r\n\r\n\r\n\t---- HALTED DUE TO FLASH ERROR! ----");
    while (1)
    {
    }
}

/*
* @brief Gets called when the app is complete.
*
* @details Print finshed message and trap forever.
*/
void app_finalize(void)
{
    /* Print finished message. */
    PRINTF("\r\n End of FlexNVM EEprom Example \r\n");
    while (1)
    {
    }
}

/*!
 * @brief Use Standard Software Drivers (SSD) to modify eeprom.
 *
 * @details This function uses SSD to demonstrate flash mode:
 *            + Check eeprom information.
 *            + Program a sector.
 */
int main(void)
{
    flash_security_state_t securityStatus = kFLASH_SecurityStateNotSecure; /* Return protection status */
    status_t result; /* Return code from each flash driver function */

    /* Init hardware */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /* Clean up Flash driver Structure*/
    memset(&s_flashDriver, 0, sizeof(flash_config_t));

    /* print welcome message */
    PRINTF("\r\n FlexNVM EEprom Example Start \r\n");

#if defined(SIM_FCFG2_PFLSH_MASK)
    if (SIM->FCFG2 & SIM_FCFG2_PFLSH_MASK)
    {
        PRINTF("\r\n Current device doesn't support FlexNVM feature \r\n");
        app_finalize();
    }
#endif

    /* Setup flash driver structure for device and initialize variables. */
    result = FLASH_Init(&s_flashDriver);
    if (kStatus_FLASH_Success != result)
    {
        error_trap();
    }

    /* Check security status. */
    result = FLASH_GetSecurityState(&s_flashDriver, &securityStatus);
    if (kStatus_FLASH_Success != result)
    {
        error_trap();
    }
    /* Print security status. */
    switch (securityStatus)
    {
        case kFLASH_SecurityStateNotSecure:
            PRINTF("\r\n Flash is UNSECURE!");
            break;
        case kFLASH_SecurityStateBackdoorEnabled:
            PRINTF("\r\n Flash is SECURE, BACKDOOR is ENABLED!");
            break;
        case kFLASH_SecurityStateBackdoorDisabled:
            PRINTF("\r\n Flash is SECURE, BACKDOOR is DISABLED!");
            break;
        default:
            break;
    }
    PRINTF("\r\n");

#if FLASH_SSD_IS_FLEXNVM_ENABLED
    /* Debug message for user. */
    /* Test flexnvm dflash feature only if flash is unsecure. */
    if (kFLASH_SecurityStateNotSecure != securityStatus)
    {
        PRINTF("\r\n EEprom opeation will not be executed, as Flash is SECURE!");
        app_finalize();
    }
    else
    {
        uint32_t s_buffer[BUFFER_LEN];     /* Buffer for program */
        uint32_t s_buffer_rbc[BUFFER_LEN]; /* Buffer for readback */
        uint32_t destAdrss;                /* Address of the target location */

        uint32_t dflashBlockBase = 0;
        uint32_t dflashTotalSize = 0;
        uint32_t eepromBlockBase = 0;
        uint32_t eepromTotalSize = 0;
        uint32_t flexramBlockBase = 0;
        uint32_t flexramTotalSize = 0;

        /* Get flash properties*/
        FLASH_GetProperty(&s_flashDriver, kFLASH_PropertyDflashBlockBaseAddr, &dflashBlockBase);
        FLASH_GetProperty(&s_flashDriver, kFLASH_PropertyFlexRamBlockBaseAddr, &flexramBlockBase);
        FLASH_GetProperty(&s_flashDriver, kFLASH_PropertyFlexRamTotalSize, &flexramTotalSize);

        FLASH_GetProperty(&s_flashDriver, kFLASH_PropertyEepromTotalSize, &eepromTotalSize);

        //eepromTotalSize = 32;
        if (!eepromTotalSize)
        {
            /* Note: The EEPROM backup size must be at least 16 times the EEPROM partition size in FlexRAM. */
            //uint32_t eepromDataSizeCode = EEPROM_DATA_SET_SIZE_CODE;
            //uint32_t flexnvmPartitionCode = FLEXNVM_PARTITION_CODE;
        	uint32_t eepromDataSizeCode =0x31;
        	uint32_t flexnvmPartitionCode =0x5u;

            PRINTF("\r\n There is no available EEprom (FlexNVM) on this Device by default.");
            PRINTF("\r\n Example is trying to configure FlexNVM block as EEprom.");

            result = FLASH_ProgramPartition(&s_flashDriver, kFLASH_PartitionFlexramLoadOptionLoadedWithValidEepromData,
                                            eepromDataSizeCode, flexnvmPartitionCode);
           // uint32_t res=1;
           if (kStatus_FLASH_Success != result)
            {
                error_trap();
            }

            /* Reset MCU */
            PRINTF("\r\n Perform a system reset \r\n");
            NVIC_SystemReset();
       }

        FLASH_GetProperty(&s_flashDriver, kFLASH_PropertyDflashTotalSize, &dflashTotalSize);
        eepromBlockBase = dflashBlockBase + dflashTotalSize;

        /* Print flash information - EEprom. */
        PRINTF("\r\n EEprom Information: ");
        PRINTF("\r\n EEprom Base Address: (0x%x) ", eepromBlockBase);
        PRINTF("\r\n EEprom Total Size:\t%d B", eepromTotalSize);

        PRINTF("\r\n Make FlexRAM available for EEPROM ");
        result = FLASH_SetFlexramFunction(&s_flashDriver, kFLASH_FlexramFunctionOptionAvailableForEeprom);
        if (kStatus_FLASH_Success != result)
       {
            error_trap();
        }
        PRINTF("\r\n Now EEPROM data is read and written by accessing the FlexRAM address space ");
       // PRINTF("\r\n FlexRAM Base Address: (0x%x) ", flexramBlockBase);

        /* Print message for user. */
        /* Prepare buffer. */
        for (uint32_t i = 0; i < BUFFER_LEN; i++)
        {
            s_buffer[i] = i + 1;
        }

        PRINTF("\r\n Read 16 bytes data from start of EEPROM space");
        destAdrss = flexramBlockBase;
        for (uint32_t i = 0; i < BUFFER_LEN; i++)
        {
#if defined(__DCACHE_PRESENT) && __DCACHE_PRESENT
            /* Clean the D-Cache before reading the flash data*/
            SCB_CleanInvalidateDCache();
#endif
            s_buffer_rbc[i] = *(volatile uint32_t *)(destAdrss + i * 4);
            if (s_buffer_rbc[i] == s_buffer[i])
            {
                if (i == BUFFER_LEN - 1)
                {
                    PRINTF("\r\n The first 16 bytes data in EEPROM are what we have progrommed before");

                    for (uint32_t i = 0; i < BUFFER_LEN; i++)
                    {
                        s_buffer[i] = 0xFFFFFFFFU;
                    }
                    result = FLASH_EepromWrite(&s_flashDriver, destAdrss, (uint8_t *)s_buffer, sizeof(s_buffer));
                    if (kStatus_FLASH_Success != result)
                    {
                        error_trap();
                    }
                    PRINTF("\r\n Recover the first 16 bytes memory space of EEprom as 0xFFs");
                    app_finalize();
                }
            }
            else if (s_buffer_rbc[i] != 0)
            {
                PRINTF("\r\n The first 16 bytes data in EEPROM are not all 0x00s");
                PRINTF("\r\n Program the first 16 bytes memory space of EEprom as 0x00s");
                /* Prepare buffer. */
                for (uint32_t i = 0; i < BUFFER_LEN; i++)
                {
                    s_buffer[i] = 0;
                }
                result = FLASH_EepromWrite(&s_flashDriver, destAdrss, (uint8_t *)s_buffer, sizeof(s_buffer));
                if (kStatus_FLASH_Success != result)
                {
                    error_trap();
                }
                PRINTF("\r\n Successfully Programmed Location 0x%x -> 0x%x \r\n", destAdrss,
                       (destAdrss + sizeof(s_buffer)));

                /* Reset MCU */
                PRINTF("\r\n Perform a system reset \r\n");
                NVIC_SystemReset();
            }
            else
            {
                if (i == BUFFER_LEN - 1)
                {
                    PRINTF("\r\n The first 16 bytes data in EEPROM are all 0x00s");
                }
            }
        }

        PRINTF("\r\n Program a buffer(16 bytes) into the first 16 bytes memory space of EEprom");
        result = FLASH_EepromWrite(&s_flashDriver, destAdrss, (uint8_t *)s_buffer, sizeof(s_buffer));
       if (kStatus_FLASH_Success != result)
        {
            error_trap();
        }
        PRINTF("\r\n Successfully Programmed Location 0x%x -> 0x%x \r\n", destAdrss, (destAdrss + sizeof(s_buffer)));

        /* Reset MCU */
        PRINTF("\r\n Perform a system reset \r\n");
        NVIC_SystemReset();
    }
#endif

    app_finalize();

    return 0;
}

 NvModuleInit();

     int data=22,read=0,destAdrss,k;
     destAdrss=0x14000000;

     //k=FLASH_ReadOnce(0 , addr, (uint8_t)data, sizeof(data));




     	//FLASH_EepromWrite(0, addr,(uint8_t)data, sizeof(data));
     FLASH_EepromWrite(&s_flashDriver, destAdrss,(uint8_t)data, sizeof(data));
     	// *p=&addr;
     //k = *(volatile uint32_t *)(destAdrss );
     k=FLASH_ReadOnce(&s_flashDriver,destAdrss , (uint8_t)&read, sizeof(data));
    int w=read;




#define FSL_FEATURE_FLASH_IS_FTFL (0)//changed to 1

#define FSL_FEATURE_FLASH_IS_FTFE (1)
  #define  gNvUseFlexNVM_d                     (0)//changed to 1
  #define gFLEXNVM_PARTITION_CODE_c       (0x8U)//changed to 5u
  #define FLASH_DRIVER_IS_FLASH_RESIDENT 1 /*!< Used for the flash resident application. */ changed to 0
  #include "NV_Flash.h"
#include "fsl_flash.h"



10/13/2021
typedef PACKED_STRUCT hardwareParameters_tag
{
    uint8_t  identificationWord[10];   /* valid data present */
    uint8_t  reserved[32];             /* for backward compatibillity */
    uint8_t  ieee_802_15_4_address[8]; /* IEEE 802.15.4 MAC address */
    uint8_t  bluetooth_address[6];     /* Bluetooth address */
    uint32_t xtalTrim;                 /* KW4x only */
    uint32_t edCalibrationOffset;      /* KW01 ED offset */
    uint32_t pllFStepOffset;           /* KW01 fine tune pll */
    uint32_t reserved0;
    /* For forward compatibility additional fields may be added here 
       Existing data in flash will not be compatible after modifying the hardwareParameters_t typedef*/
    uint16_t hardwareParamsCrc;        /* crc for data between start of reserved area and start of hardwareParamsCrc field (not included). */ 
}hardwareParameters_t;

applmain.c
ble_init()

controller task init()
controller bd_addr()
read(hardware parameters)
write(hardware parameters)


/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

typedef struct
{
    int    length;     /*!< Total length of the [adType + aData] fields. Equal to 1 + lengthOf(aData). */
    int    adType;     /*!< AD Type of this AD Structure. */
    char*  aData;      /*!< Data contained in this AD Structure; length of this array is equal to (gapAdStructure_t.length - 1). */
} gapAdStructure_t;


static const gapAdStructure_t advScanStruct[3] = {{22,11,"ble"},{ 2,22,"12vbms" }, {3,33,"SDAS-9999"}};
int main()
{
//	gapAdStructure_t.advScanStruct[0].length;
//for(int i=0;i<3;i++)
	advScanStruct[2].aData="123";
		printf("%s\n",advScanStruct[2].aData);;
}

