//
// Included Files
//
#include "driverlib.h"
#include "device.h"
//
// Defines
//
#define TXCOUNT            100
#define MSG_DATA_LENGTH    8
#define TX_MSG_OBJ_ID      1
//
// Globals
//
volatile unsigned long i;
volatile uint32_t txMsgCount = 0;
//
// Buffer to store the message Received by node A
//
uint16_t rxMsgData[8];
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
    // on modules A & B
    //
    Device_initGPIO();
    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANRXA);
    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANTXA);
    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANRXB);
    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANTXB);
    //
    // Initialize the CAN controllers
    //
    CAN_initModule(CANA_BASE);
    CAN_initModule(CANB_BASE);
    //
    // Set up the CAN bus bit rate to 500kHz for each module
    // Refer to the Driver Library User Guide for information on how to set
    // tighter timing control. Additionally, consult the device data sheet
    // for more information about the CAN module clocking.
    //
    CAN_setBitRate(CANA_BASE, DEVICE_SYSCLK_FREQ, 500000, 20);
    CAN_setBitRate(CANB_BASE, DEVICE_SYSCLK_FREQ, 500000, 20);
    //
    // Initialize the mailbox used for sending the remote frame
    // - and receiving the corresponding data frame
    // Message Object Parameters:
    //      CAN Module: A
    //      Message Object ID Number: 1
    //      Message Identifier: 0x111
    //      Message Frame: Standard
    //      Message Type: Receive (but transmits a Remote frame first)
    //      Message ID Mask: 0x0
    //      Message Object Flags: None
    //      Message Data Length: 8 Bytes
    //
    CAN_setupMessageObject(CANA_BASE, TX_MSG_OBJ_ID, 0x111,
                           CAN_MSG_FRAME_STD, CAN_MSG_OBJ_TYPE_RX, 0,
                           CAN_MSG_OBJ_NO_FLAGS, MSG_DATA_LENGTH);
    //
    // Initialize the mailbox used for responding to the remote frame
    // Message Object Parameters:
    //      CAN Module: B
    //      Message Object ID Number: 1
    //      Message Identifier: 0x111
    //      Message Frame: Standard
    //      Message Type: Transmit (Auto respond to a remote frame)
    //      Message ID Mask: 0x0
    //      Message Object Flags: None
    //      Message Data Length: 8 Bytes ("Don't care" for this MBX)
    //
    CAN_setupMessageObject(CANB_BASE, TX_MSG_OBJ_ID, 0x11,
                           CAN_MSG_FRAME_STD, CAN_MSG_OBJ_TYPE_RXTX_REMOTE, 0,
                           CAN_MSG_OBJ_NO_FLAGS, MSG_DATA_LENGTH);
    //
    // Initialize the receive buffer to a known value
    //
    rxMsgData[0] = 0;
    rxMsgData[1] = 0;
    rxMsgData[2] = 0;
    rxMsgData[3] = 0;
    rxMsgData[4] = 0;
    rxMsgData[5] = 0;
    rxMsgData[6] = 0;
    rxMsgData[7] = 0;
    //
    // Start CAN module operations
    //
    CAN_startModule(CANA_BASE);
    CAN_startModule(CANB_BASE);
    //
    // Copy data into the mailbox1 RAM of CAN-B. This is the data that will be
    // automatically transmitted in response to  a remote frame.
    //
    // Wait for busy bit to clear
    //
    while((HWREGH(CANB_BASE + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) ==
          CAN_IF1CMD_BUSY)
    {
    }
    //
    // Write to IF1DATA & IF1DATB registers
    //
    HWREG_BP(CANB_BASE + CAN_O_IF1DATA)  =  0x67452301UL;
    HWREG_BP(CANB_BASE + CAN_O_IF1DATB)  =  0xEFCDAB89UL;
    //
    // Transfer to MBX RAM
    //
    HWREG_BP(CANB_BASE + CAN_O_IF1CMD)  =  0x00830001UL;
    //
    // Wait for busy bit to clear
    //
    while((HWREGH(CANB_BASE + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) ==
           CAN_IF1CMD_BUSY)
    {
    }
    //
    // Transmit Remote frame(s) from CAN-A and await data frame(s) from node B
    //
    //while(1)  // Uncomment for infinite transmissions
    for(i = 0; i <=TXCOUNT; i++)
    {

        if(i==100)
            i=0;
        //
        // Initiate transmission of remote frame. "rxMsgData" is "dummy"
        // No data will go out on a Remote Frame
        //
        CAN_sendMessage(CANA_BASE, TX_MSG_OBJ_ID, MSG_DATA_LENGTH, rxMsgData);
        //
        // Poll TxOk bit in CAN_ES register to check completion of transmission
        //
        while(((HWREG_BP(CANA_BASE + CAN_O_ES) & CAN_ES_TXOK)) !=
                CAN_ES_TXOK){}
        txMsgCount++; // Increment TX counter
        //
        // Poll RxOk bit in CAN_ES register to check completion of reception
        //
        while(((HWREG_BP(CANA_BASE + CAN_O_ES) & CAN_ES_RXOK)) !=
                CAN_ES_RXOK){}
        CAN_readMessage(CANA_BASE, 1, rxMsgData);
    }
    //
    // Stop application
    //
    asm("   ESTOP0");
}
//
// End of File
//