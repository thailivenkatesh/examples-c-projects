#include "driverlib.h"
#include "device.h"
//
// Defines
//
#define TXCOUNT  100
#define MSG_DATA_LENGTH    8
#define RX_MSG_OBJ_ID      1
#define TX_MSG_OBJ_ID      2
//
// Globals
//
volatile unsigned long i;
volatile uint32_t txMsgCount = 0;
volatile uint32_t rxMsgCount = 0;
volatile uint32_t errorFlag = 0;


uint16_t rxMsgData[8];
uint16_t txMsgData[8];


__interrupt void canbISR(void);
//
// Main
//
void main(void)
{
    //
    // Initialize device clock and peripherals
    //
    Device_init();
    //
    // Initialize GPIO and configure GPIO pins for CANTX/CANRX
    // on module B
    //
    Device_initGPIO();
    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANRXA);
    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANTXA);
    //
    // Initialize the CAN controllers
    //
    CAN_initModule(CANA_BASE);
    //
    // Set up the CAN bus bit rate to 500kHz for each module
    // Refer to the Driver Library User Guide for information on how to set
    // tighter timing control. Additionally, consult the device data sheet
    // for more information about the CAN module clocking.
    //

    CAN_setBitRate(CANA_BASE, DEVICE_SYSCLK_FREQ, 500000, 20);
    //
        // Enable interrupts on the CAN B peripheral.
        //
        CAN_enableInterrupt(CANA_BASE, CAN_INT_IE0 | CAN_INT_ERROR |
                            CAN_INT_STATUS);

        //
        // Initialize PIE and clear PIE registers. Disables CPU interrupts.
        //
        Interrupt_initModule();

        //
        // Initialize the PIE vector table with pointers to the shell Interrupt
        // Service Routines (ISR).
        //
        Interrupt_initVectorTable();

        //
        // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
        //
        EINT;
        ERTM;

        //
        // Interrupts that are used in this example are re-mapped to
        // ISR functions found within this file.
        // This registers the interrupt handler in PIE vector table.
        //
        Interrupt_register(INT_CANA0, &canbISR);

        //
        // Enable the CAN-B interrupt signal
        //
        Interrupt_enable(INT_CANA0);
        CAN_enableGlobalInterrupt(CANA_BASE, CAN_GLOBAL_INT_CANINT0);
    //
        // Initialize the receive message object used for receiving CAN messages.
        // Message Object Parameters:
        //      CAN Module: B
        //      Message Object ID Number: 1
        //      Message Identifier: 0x95555555
        //      Message Frame: Extended
        //      Message Type: Receive
        //      Message ID Mask: 0x0     //2,505,397,589    536,870,912
        //      Message Object Flags: Receive Interrupt
        //      Message Data Length: 4 Bytes
        //
    CAN_setupMessageObject(CANA_BASE, RX_MSG_OBJ_ID,0x10111111,
                           CAN_MSG_FRAME_EXT, CAN_MSG_OBJ_TYPE_RX, 0,
                           CAN_MSG_OBJ_RX_INT_ENABLE, MSG_DATA_LENGTH);

         CAN_setupMessageObject(CANA_BASE, TX_MSG_OBJ_ID, 0x11111511,
                                CAN_MSG_FRAME_EXT, CAN_MSG_OBJ_TYPE_TX, 0,
                                CAN_MSG_OBJ_NO_FLAGS, MSG_DATA_LENGTH);
            txMsgData[0] = 0x12;
            txMsgData[1] = 0x34;
            txMsgData[2] = 0x56;
            txMsgData[3] = 0x78;
            txMsgData[4] = 0x83;
            txMsgData[5] = 0x97;
            txMsgData[6] = 0x28;
            txMsgData[7] = 0x49;

         // Start CAN module B operations
         //
         CAN_startModule(CANA_BASE);

         while(1){
         CAN_sendMessage(CANA_BASE, TX_MSG_OBJ_ID, MSG_DATA_LENGTH,
                                                 txMsgData);
         }

   /*      for(i = 0; i < TXCOUNT; i++)
            {
             if(txMsgCount == rxMsgCount)
                    {
                 CAN_sendMessage(CANA_BASE, TX_MSG_OBJ_ID, MSG_DATA_LENGTH,
                                         txMsgData);
                 txMsgCount++;
                    }
             else
                    {
                        errorFlag = 1;
                    }

            }*/

     }
//
// CAN B ISR - The interrupt service routine called when a CAN interrupt is
//             triggered on CAN module B.
//
__interrupt void
canbISR(void)
{
    uint32_t status;

    //
    // Read the CAN-B interrupt status to find the cause of the interrupt
    //
    status = CAN_getInterruptCause(CANA_BASE);

    //
    // If the cause is a controller status interrupt, then get the status
    //
    if(status == CAN_INT_INT0ID_STATUS)
    {
        //
        // Read the controller status.  This will return a field of status
        // error bits that can indicate various errors.  Error processing
        // is not done in this example for simplicity.  Refer to the
        // API documentation for details about the error status bits.
        // The act of reading this status will clear the interrupt.
        //
        status = CAN_getStatus(CANA_BASE);

        //
        // Check to see if an error occurred.
        //
        if(((status  & ~(CAN_STATUS_RXOK)) != CAN_STATUS_LEC_MSK) &&
           ((status  & ~(CAN_STATUS_RXOK)) != CAN_STATUS_LEC_NONE))
        {
            //
            // Set a flag to indicate some errors may have occurred.
            //
            errorFlag = 1;
        }
    }
    //
    // Check if the cause is the CAN-B receive message object 1
    //
    else if(status == RX_MSG_OBJ_ID)
    {
        //
        // Get the received message
        //
        CAN_readMessage(CANA_BASE, RX_MSG_OBJ_ID, rxMsgData);

        //
        // Getting to this point means that the RX interrupt occurred on
        // message object 1, and the message RX is complete.  Clear the
        // message object interrupt.
        //
        CAN_clearInterruptStatus(CANA_BASE, RX_MSG_OBJ_ID);

        //
        // Increment a counter to keep track of how many messages have been
        // received. In a real application this could be used to set flags to
        // indicate when a message is received.
        //
        rxMsgCount++;

        //
        // Since the message was received, clear any error flags.
        //
        errorFlag = 0;
    }
    //
    // If something unexpected caused the interrupt, this would handle it.
    //
    else
    {
        //
        // Spurious interrupt handling can go here.
        //
    }

    //
    // Clear the global interrupt flag for the CAN interrupt line
    //
    CAN_clearGlobalInterruptStatus(CANA_BASE, CAN_GLOBAL_INT_CANINT0);

    //
    // Acknowledge this interrupt located in group 9
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

}


//
// End of File
//



/*
#include "driverlib.h"
#include "device.h"

#define TX_MSG_OBJ_ID    1
#define RX_MSG_OBJ_ID      1
#define MSG_DATA_LENGTH    8
uint16_t txMsgData[8];
uint16_t rxMsgData[8];

volatile uint32_t rxMsgCount = 0;
volatile uint32_t errorFlag = 0;
__interrupt void canbISR(void);

void main()
{

    Device_init();
    Device_initGPIO();

    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANRXB);
    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANTXB);


     CAN_initModule(CANB_BASE);

     CAN_setBitRate(CANB_BASE, DEVICE_SYSCLK_FREQ, 500000, 20);
     CAN_enableInterrupt(CANB_BASE, CAN_INT_IE0 | CAN_INT_ERROR |
                           CAN_INT_STATUS);

     Interrupt_initModule();
     Interrupt_initVectorTable();
      EINT;
      ERTM;
     Interrupt_register(INT_CANB0, &canbISR);

               Interrupt_enable(INT_CANB0);
                     CAN_enableGlobalInterrupt(CANB_BASE, CAN_GLOBAL_INT_CANINT0);


                     CAN_setupMessageObject(CANB_BASE, RX_MSG_OBJ_ID, 0x555,
                                    CAN_MSG_FRAME_EXT, CAN_MSG_OBJ_TYPE_RX, 0,
                                    CAN_MSG_OBJ_RX_INT_ENABLE, MSG_DATA_LENGTH);



                     CAN_setupMessageObject(CANB_BASE, TX_MSG_OBJ_ID, 0x511,
                                                        CAN_MSG_FRAME_EXT, CAN_MSG_OBJ_TYPE_TX, 0,
                                                        CAN_MSG_OBJ_NO_FLAGS, MSG_DATA_LENGTH);
                     CAN_startModule(CANB_BASE);



                      txMsgData[0] = 2;
                      txMsgData[1] = 4;
                      txMsgData[2] = 6;
                      txMsgData[3] = 8;
                      txMsgData[4] = 3;
                      txMsgData[5] = 5;
                      txMsgData[6] = 7;
                      txMsgData[7] = 9;
                      CAN_sendMessage(CANB_BASE, TX_MSG_OBJ_ID, MSG_DATA_LENGTH,
                                      txMsgData);

                      CAN_startModule(CANB_BASE);
}
__interrupt void
canbISR(void)
{

    uint32_t status;

    //
    // Read the CAN-B interrupt status to find the cause of the interrupt
    //
    status = CAN_getInterruptCause(CANB_BASE);
    //
    // Read the controller status.  This will return a field of status
    // error bits that can indicate various errors.  Error processing
    // is not done in this example for simplicity.
    // The act of reading this status will clear the interrupt.

    status = CAN_getStatus(CANB_BASE);
    //
    // If the cause is a controller status interrupt, then get the status
    //
    if(status == CAN_INT_INT0ID_STATUS)
    {
        // Check to see if an error occurred.
        if(((status  & ~(CAN_STATUS_RXOK)) != CAN_STATUS_LEC_MSK) &&
           ((status  & ~(CAN_STATUS_RXOK)) != CAN_STATUS_LEC_NONE))
        {
            errorFlag = 1;

        }

    }
    else if(status == RX_MSG_OBJ_ID)
    {

        CAN_readMessage(CANB_BASE, RX_MSG_OBJ_ID, rxMsgData);

        //
        // Getting to this point means that the RX interrupt occurred on
        // message object 1, and the message RX is complete.  Clear the
        // message object interrupt.
        //
        CAN_clearInterruptStatus(CANB_BASE, RX_MSG_OBJ_ID);

        //
        // Increment a counter to keep track of how many messages have been
        // received. In a real application this could be used to set flags to
        // indicate when a message is received.
        //
         rxMsgCount++;

        //
        // Since the message was received, clear any error flags.
        //
        errorFlag = 0;
        // Since the message was received, clear any error flags.
        //
       // DataRecieved = 1;
    }
    else
       {
           //
           // Spurious interrupt handling can go here.
           //
       }


    //
    // Clear the global interrupt flag for the CAN interrupt line
    //
    CAN_clearGlobalInterruptStatus(CANB_BASE, CAN_GLOBAL_INT_CANINT0);

    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}
    if((Canstatus & 0x0007) != 0 && (Canstatus & 0x0007) != 7)
        LastErr = Canstatus & 0x0007;
    if((Canstatus & 0x0080) != 0)       //Bus off
    {
        Busoff_cnt++;
        if(Busoff_cnt > 100)        //1s
        {



            if(CanErrCnt<9)
                CanErrCnt++;
            else
            {

                //COMMOutput_Info.status &= ~CAN_CONNECTED;
                LED_TurnOff(COMM_LED);
            }
            Busoff_cnt = 0;


        //}
    else
    {
        Busoff_cnt = 0;
        CanErrCnt = 0;
        step++;

        if((Canstatus&0x0007) < 3 || (Canstatus&0x0007) > 5)
        {
            if((step & 0x01) == 0)
            {
                txMsgData[0] = 1;   //Package ID
                txMsgData[1] = (COMMOutput_Info.Mode & 0x000F) + ((COMMOutput_Info.PowerDirection & 0x000F)<<4);
                txMsgData[2] = COMMOutput_Info.status;
            }
            else
            {
                txMsgData[0] = 2;
                txMsgData[1] = (COMMOutput_Info.uRef & 0xff00)>>8;
                txMsgData[2] = COMMOutput_Info.uRef & 0x00ff;
            }

            txMsgData[3] = (COMMOutput_Info.Vout & 0xff00)>>8;
            txMsgData[4] = COMMOutput_Info.Vout & 0x00ff;
            txMsgData[5] = (COMMOutput_Info.Iout & 0xff00)>>8;
            txMsgData[6] = COMMOutput_Info.Iout & 0x00ff;
            txMsgData[7] = CANData_checkSum(txMsgData);

            CAN_sendMessage(CANB_BASE, TX_MSG_OBJ_ID, MSG_DATA_LENGTH,
                            txMsgData);
        }


        if(DataRecieved == 1)
        {

            //if((step & 0x7) == 0)
            //  GPIO_togglePin(COMM_LED);
            if(Cortrol_CAN_Ok == 1)
                PFC_HAL_toggleLED(COMM_LED,7);
            else
                PFC_HAL_toggleLED(COMM_LED,30);
            COM_error_cnt = 0;

            DataRecieved = 0;
            if(CANData_checkSum(rxMsgData) == rxMsgData[7])
            {
                if(rxMsgData[0] == 1)
                {
                    COMMIntput_Info.Mode = rxMsgData[1] & 0x000F;
                    COMMIntput_Info.PowerDirection = (rxMsgData[1] & 0x00F0) >> 4;
                    COMMIntput_Info.status = rxMsgData[2];
                }
                else
                {
                    COMMIntput_Info.uRef = (rxMsgData[1] << 8) | rxMsgData[2];
                }
                COMMIntput_Info.Vout = (rxMsgData[3] << 8) | rxMsgData[4];
                COMMIntput_Info.Iout = (rxMsgData[5] << 8) | rxMsgData[6];
                COMMOutput_Info.status |= CAN_CONNECTED;
            }

        }
    }

//}





















//#############################################################################
//
// FILE:   can_ex4_simple_transmit.c
//
// TITLE:   CAN simple External Transmit Example
//
//! \addtogroup driver_example_list
//! <h1> CAN-A External Transmit </h1>
//!
//! This example initializes CAN module A for external communication.
//! CAN-A module is setup to transmit data for "n" number of times,
//! where "n" is the value of TXCOUNT. Another CAN node configured for the
//! same bit-rate is needed to provide the ACK. No interrupts are used.
//!
//! \b Hardware \b Required \n
//!  - A C2000 board with CAN transceiver and another CAN node configured
//!    for the same bit-rate to provide the ACK.
//!
//! \b Watch \b Variables \n
//!  - TXCOUNT - Adjust to set the number of messages to be transmitted
//!  - txMsgCount - A counter for the number of messages sent
//!  - txMsgData - An array with the data being sent
//!
//
//#############################################################################
// $TI Release: F2837xS Support Library v3.11.00.00 $
// $Release Date: Sun Oct  4 15:58:38 IST 2020 $
// $Copyright:
// Copyright (C) 2014-2020 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################
//
// Included Files
//
#include "driverlib.h"
#include "device.h"
//
// Defines
//
//#define TXCOUNT  100000
#define TXCOUNT  10
#define MSG_DATA_LENGTH    8
#define TX_MSG_OBJ_ID    1
#define RX_MSG_OBJ_ID      1
//
// Globals
//
volatile unsigned long i;
volatile uint32_t txMsgCount = 0;
volatile uint32_t rxMsgCount = 0;
volatile uint32_t errorFlag = 0;

uint16_t txMsgData[8];
uint16_t rxMsgData[8];
uint16_t rxMsgData1[8];
__interrupt void canaISR(void);
//
// Main
//
void main(void)
{

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Initialize GPIO and configure GPIO pins for CANTX/CANRX
    // on module A and B
    //
    Device_initGPIO();
    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANRXA);
    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANTXA);
    //GPIO_setPinConfig(DEVICE_GPIO_CFG_CANRXB);
    //GPIO_setPinConfig(DEVICE_GPIO_CFG_CANTXB);

    //
    // Initialize the CAN controllers
    //
    CAN_initModule(CANA_BASE);
    //CAN_initModule(CANB_BASE);

    //
    // Set up the CAN bus bit rate to 500kHz for each module
    // Refer to the Driver Library User Guide for information on how to set
    // tighter timing control. Additionally, consult the device data sheet
    // for more information about the CAN module clocking.
    //
    CAN_setBitRate(CANA_BASE, DEVICE_SYSCLK_FREQ, 500000, 20);
    //CAN_setBitRate(CANB_BASE, DEVICE_SYSCLK_FREQ, 500000, 20);

    //
    // Enable interrupts on the CAN B peripheral.
    //
    CAN_enableInterrupt(CANA_BASE, CAN_INT_IE0 | CAN_INT_ERROR |
                        CAN_INT_STATUS);

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    EINT;
    ERTM;

    //
    // Interrupts that are used in this example are re-mapped to
    // ISR functions found within this file.
    // This registers the interrupt handler in PIE vector table.
    //
    //Interrupt_register(INT_CANA0, &canaISR);

    //
    // Enable the CAN-B interrupt signal
    //
    Interrupt_enable(INT_CANA0);
    CAN_enableGlobalInterrupt(CANA_BASE, CAN_GLOBAL_INT_CANINT0);

    //
    // Initialize the transmit message object used for sending CAN messages.
    // Message Object Parameters:
    //      CAN Module: A
    //      Message Object ID Number: 1
    //      Message Identifier: 0x95555555
    //      Message Frame: Extended
    //      Message Type: Transmit
    //      Message ID Mask: 0x0
    //      Message Object Flags: None
    //      Message Data Length: 4 Bytes
    //
    CAN_setupMessageObject(CANA_BASE, TX_MSG_OBJ_ID, 0x511,
                           CAN_MSG_FRAME_STD, CAN_MSG_OBJ_TYPE_TX, 0,
                           CAN_MSG_OBJ_NO_FLAGS, MSG_DATA_LENGTH);

    //
        // Initialize the receive message object used for receiving CAN messages.
        // Message Object Parameters:
        //      CAN Module: B
        //      Message Object ID Number: 1
        //      Message Identifier: 0x95555555
        //      Message Frame: Extended
        //      Message Type: Receive
        //      Message ID Mask: 0x0
        //      Message Object Flags: Receive Interrupt
        //      Message Data Length: 4 Bytes
        //
    CAN_setupMessageObject(CANA_BASE, RX_MSG_OBJ_ID,0x555,
                           CAN_MSG_FRAME_STD, CAN_MSG_OBJ_TYPE_RX, 0,
                           CAN_MSG_OBJ_RX_INT_ENABLE, MSG_DATA_LENGTH);

    CAN_setupMessageObject(CANB_BASE, 2,0x556,
                               CAN_MSG_FRAME_STD, CAN_MSG_OBJ_TYPE_RX, 0,
                               CAN_MSG_OBJ_RX_INT_ENABLE, MSG_DATA_LENGTH);
    //
    // Initialize the transmit message object data buffer to be sent
    //
    txMsgData[0] = 0x12;
    txMsgData[1] = 0x34;
    txMsgData[2] = 0x56;
    txMsgData[3] = 0x78;
    txMsgData[4] = 0x83;
    txMsgData[5] = 0x97;
    txMsgData[6] = 0x28;
    txMsgData[7] = 0x49;
       txMsgData[0] = 12;
       txMsgData[1] = 34;
       txMsgData[2] = 56;
       txMsgData[3] = 78;
       txMsgData[4] = 5;
       txMsgData[5] = 6;
       txMsgData[6] = 7;
       txMsgData[7] = 8;

    //
    // Start CAN module A and B operations
    //
    CAN_startModule(CANA_BASE);




    uint32_t status;

        //
        // Read the CAN-B interrupt status to find the cause of the interrupt
        //
        status = CAN_getInterruptCause(CANA_BASE);

        //
        // If the cause is a controller status interrupt, then get the status
        //
        if(status == CAN_INT_INT0ID_STATUS)
        {
            //
            // Read the controller status.  This will return a field of status
            // error bits that can indicate various errors.  Error processing
            // is not done in this example for simplicity.  Refer to the
            // API documentation for details about the error status bits.
            // The act of reading this status will clear the interrupt.
            //
            status = CAN_getStatus(CANA_BASE);

            //
            // Check to see if an error occurred.
            //
            if(((status  & ~(CAN_STATUS_RXOK)) != CAN_STATUS_LEC_MSK) &&
               ((status  & ~(CAN_STATUS_RXOK)) != CAN_STATUS_LEC_NONE))
            {
                //
                // Set a flag to indicate some errors may have occurred.
                //
                errorFlag = 1;
            }

        }
        //
        // Check if the cause is the CAN-B receive message object 1
        //
        else if((status == RX_MSG_OBJ_ID) || (status == 2))
        {


            //
            // Get the received message
            //
            if(RX_MSG_OBJ_ID == 1){
            CAN_readMessage(CANA_BASE, RX_MSG_OBJ_ID, rxMsgData);

            //
            // Getting to this point means that the RX interrupt occurred on
            // message object 1, and the message RX is complete.  Clear the
            // message object interrupt.
            //
            CAN_clearInterruptStatus(CANA_BASE, RX_MSG_OBJ_ID);

            //
            // Increment a counter to keep track of how many messages have been
            // received. In a real application this could be used to set flags to
            // indicate when a message is received.
            //

            }
             if(status == 2){
                CAN_readMessage(CANA_BASE, 2, rxMsgData1);
                CAN_clearInterruptStatus(CANA_BASE, 2);
            }
             rxMsgCount++;

            //
            // Since the message was received, clear any error flags.
            //
            errorFlag = 0;

        }




                txMsgData[0] = rxMsgData[0];
                txMsgData[1] = rxMsgData[1];
                txMsgData[2] = rxMsgData[2];
                txMsgData[3] = rxMsgData[3];
                txMsgData[4] = rxMsgData[4];
                txMsgData[5] = rxMsgData[5];
                txMsgData[6] = rxMsgData[6];
                txMsgData[7] = rxMsgData[7];

        CAN_sendMessage(CANA_BASE, TX_MSG_OBJ_ID, MSG_DATA_LENGTH,
                            txMsgData);





        else if(status == 2)
           {
               //
               // Get the received message
               //
               CAN_readMessage(CANB_BASE, 2, rxMsgData1);

               //
               // Getting to this point means that the RX interrupt occurred on
               // message object 1, and the message RX is complete.  Clear the
               // message object interrupt.
               //
               CAN_clearInterruptStatus(CANB_BASE, 2);

               //
               // Increment a counter to keep track of how many messages have been
               // received. In a real application this could be used to set flags to
               // indicate when a message is received.
               //
               rxMsgCount++;

               //
               // Since the message was received, clear any error flags.
               //
               errorFlag = 0;
           }


        //
        // If something unexpected caused the interrupt, this would handle it.
        //
       // else
       // {
            //
            // Spurious interrupt handling can go here.
            //
       // }

        //
        // Clear the global interrupt flag for the CAN interrupt line
        //
        CAN_clearGlobalInterruptStatus(CANA_BASE, CAN_GLOBAL_INT_CANINT0);

        //
        // Acknowledge this interrupt located in group 9
        //
        Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
    //CAN_startModule(CANB_BASE);

    //
    // Transmit messages from CAN-A to CAN-B
    //
   // for(i = 0; i < TXCOUNT; i++)
   // {
        //
        // Check the error flag to see if errors occurred
        //
        if(errorFlag)
        {
            asm("   ESTOP0");
        }

        //
        // Verify that the number of transmitted messages equal the number of
        // messages received before sending a new message
        //
        //if(txMsgCount == rxMsgCount)
        //{
            //CAN_sendMessage(CANA_BASE, TX_MSG_OBJ_ID, MSG_DATA_LENGTH,txMsgData);
            //txMsgCount++;
        //}
        else
        {
            errorFlag = 1;
        }

        //
        // Delay 0.25 second before continuing
        //
       // DEVICE_DELAY_US(250000);

        //
        // Increment the value in the transmitted message data.
        //
        txMsgData[0] += 0x01;
        txMsgData[1] += 0x01;
        txMsgData[2] += 0x01;
        txMsgData[3] += 0x01;
        txMsgData[4] += 0x01;
        txMsgData[5] += 0x01;
        txMsgData[6] += 0x01;
        txMsgData[7] += 0x01;
        //
        // Reset data if exceeds a byte
        //
        if(txMsgData[0] > 0xFF)
        {
            txMsgData[0] = 0;
        }
        if(txMsgData[1] > 0xFF)
        {
            txMsgData[1] = 0;
        }
        if(txMsgData[2] > 0xFF)
        {
            txMsgData[2] = 0;
        }
        if(txMsgData[3] > 0xFF)
        {
            txMsgData[3] = 0;
        }
        if(txMsgData[4] > 0xFF)
        {
           txMsgData[4] = 0;
        }
        if(txMsgData[5] > 0xFF)
        {
          txMsgData[5] = 0;
        }
        if(txMsgData[6] > 0xFF)
        {
           txMsgData[6] = 0;
        }
        if(txMsgData[7] > 0xFF)
        {
            txMsgData[7] = 0;
        }
   // }


    //

 // int  value= rxMsgData[0];
//int   value1= rxMsgData[1];
    //
    // Stop application
    //
    //asm("   ESTOP0");
  }
//
// CAN B ISR - The interrupt service routine called when a CAN interrupt is
//             triggered on CAN module B.
//

__interrupt void
canaISR(void)
{
    uint32_t status;

    //
    // Read the CAN-B interrupt status to find the cause of the interrupt
    //
    status = CAN_getInterruptCause(CANA_BASE);

    //
    // If the cause is a controller status interrupt, then get the status
    //
    if(status == CAN_INT_INT0ID_STATUS)
    {
        //
        // Read the controller status.  This will return a field of status
        // error bits that can indicate various errors.  Error processing
        // is not done in this example for simplicity.  Refer to the
        // API documentation for details about the error status bits.
        // The act of reading this status will clear the interrupt.
        //
        status = CAN_getStatus(CANA_BASE);

        //
        // Check to see if an error occurred.
        //
        if(((status  & ~(CAN_STATUS_RXOK)) != CAN_STATUS_LEC_MSK) &&
           ((status  & ~(CAN_STATUS_RXOK)) != CAN_STATUS_LEC_NONE))
        {
            //
            // Set a flag to indicate some errors may have occurred.
            //
            errorFlag = 1;
        }

    }
    //
    // Check if the cause is the CAN-B receive message object 1
    //
    else if((status == RX_MSG_OBJ_ID) || (status == 2))
    {


        //
        // Get the received message
        //
        if(RX_MSG_OBJ_ID == 1){
        CAN_readMessage(CANA_BASE, RX_MSG_OBJ_ID, rxMsgData);

        //
        // Getting to this point means that the RX interrupt occurred on
        // message object 1, and the message RX is complete.  Clear the
        // message object interrupt.
        //
        CAN_clearInterruptStatus(CANA_BASE, RX_MSG_OBJ_ID);

        //
        // Increment a counter to keep track of how many messages have been
        // received. In a real application this could be used to set flags to
        // indicate when a message is received.
        //

        }
         if(status == 2){
            CAN_readMessage(CANA_BASE, 2, rxMsgData1);
            CAN_clearInterruptStatus(CANA_BASE, 2);
        }
         rxMsgCount++;

        //
        // Since the message was received, clear any error flags.
        //
        errorFlag = 0;

    }




            txMsgData[0] = rxMsgData[0];
            txMsgData[1] = rxMsgData[1];
            txMsgData[2] = rxMsgData[2];
            txMsgData[3] = rxMsgData[3];
            txMsgData[4] = rxMsgData[4];
            txMsgData[5] = rxMsgData[5];
            txMsgData[6] = rxMsgData[6];
            txMsgData[7] = rxMsgData[7];

    CAN_sendMessage(CANA_BASE, TX_MSG_OBJ_ID, MSG_DATA_LENGTH,
                        txMsgData);





    else if(status == 2)
       {
           //
           // Get the received message
           //
           CAN_readMessage(CANB_BASE, 2, rxMsgData1);

           //
           // Getting to this point means that the RX interrupt occurred on
           // message object 1, and the message RX is complete.  Clear the
           // message object interrupt.
           //
           CAN_clearInterruptStatus(CANB_BASE, 2);

           //
           // Increment a counter to keep track of how many messages have been
           // received. In a real application this could be used to set flags to
           // indicate when a message is received.
           //
           rxMsgCount++;

           //
           // Since the message was received, clear any error flags.
           //
           errorFlag = 0;
       }


    //
    // If something unexpected caused the interrupt, this would handle it.
    //
   // else
   // {
        //
        // Spurious interrupt handling can go here.
        //
   // }

    //
    // Clear the global interrupt flag for the CAN interrupt line
    //
    CAN_clearGlobalInterruptStatus(CANA_BASE, CAN_GLOBAL_INT_CANINT0);

    //
    // Acknowledge this interrupt located in group 9
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}


//
// End of File
//



*/
