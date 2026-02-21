	
	
	

//		
uint32_t  RxCODE;              /*< Received message buffer code 			*/
uint32_t  RxID;                /*< Received message ID 					    */
uint32_t  RxLENGTH;            /*< Recieved message number of data bytes 	*/	

uint32_t  RxCODE1;              /*< Received message buffer code 			*/
uint32_t  RxID1;                /*< Received message ID 					*/
uint32_t  RxLENGTH1;            /*< Recieved message number of data bytes 	*/

uint32_t  RxCODE2;              /*< Received message buffer code 			*/
uint32_t  RxID2;                /*< Received message ID 					*/
uint32_t  RxLENGTH2;            /*< Recieved message number of data bytes 	*/

uint32_t  RxCODE3;              /*< Received message buffer code 			*/
uint32_t  RxID3;                /*< Received message ID 					*/
uint32_t  RxLENGTH3;            /*< Recieved message number of data bytes 	*/

uint32_t  RxCODE4;              /*< Received message buffer code 			*/
uint32_t  RxID4;                /*< Received message ID 					*/
uint32_t  RxLENGTH4;            /*< Recieved message number of data bytes 	*/

uint32_t  RxCODE5;              /*< Received message buffer code 			*/
uint32_t  RxID5;                /*< Received message ID 					*/
uint32_t  RxLENGTH5;            /*< Recieved message number of data bytes 	*/

uint32_t  RxCODE6;              /*< Received message buffer code 			*/
uint32_t  RxID6;                /*< Received message ID 					*/
uint32_t  RxLENGTH6;            /*< Recieved message number of data bytes 	*/

uint32_t  RxCODE7;              /*< Received message buffer code 			*/
uint32_t  RxID7;                /*< Received message ID 					*/
uint32_t  RxLENGTH7;            /*< Recieved message number of data bytes 	*/

uint32_t  RxCODE8;              /*< Received message buffer code 			*/
uint32_t  RxID8;                /*< Received message ID 					*/
uint32_t  RxLENGTH8;            /*< Recieved message number of data bytes 	*/
  //0x90		
  CAN0->RAMn[ 1*MSG_BUF_SIZE + 0] = 0x04600000;
  CAN0->RAMn[ 1*MSG_BUF_SIZE + 1] = 0x90; 
  //0x91		
  CAN0->RAMn[ 2*MSG_BUF_SIZE + 0] = 0x04600000;
  CAN0->RAMn[ 2*MSG_BUF_SIZE + 1] = 0x91; 
  //0x92		
  CAN0->RAMn[ 3*MSG_BUF_SIZE + 0] = 0x04600000;
  CAN0->RAMn[ 3*MSG_BUF_SIZE + 1] = 0x92; 
  //0x93		
  CAN0->RAMn[ 4*MSG_BUF_SIZE + 0] = 0x04600000;
  CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] = 0x93; 
  //0x94		
  CAN0->RAMn[ 5*MSG_BUF_SIZE + 0] = 0x04600000;
  CAN0->RAMn[ 5*MSG_BUF_SIZE + 1] = 0x94; 
  //0x95		
  CAN0->RAMn[ 6*MSG_BUF_SIZE + 0] = 0x04600000;
  CAN0->RAMn[ 6*MSG_BUF_SIZE + 1] = 0x95; 
  //0x96		
  CAN0->RAMn[ 7*MSG_BUF_SIZE + 0] = 0x04600000;
  CAN0->RAMn[ 7*MSG_BUF_SIZE + 1] = 0x96; 
  //0x97		
  CAN0->RAMn[ 8*MSG_BUF_SIZE + 0] = 0x04600000;
  CAN0->RAMn[ 8*MSG_BUF_SIZE + 1] = 0x97; 
  //0x98		
  CAN0->RAMn[ 9*MSG_BUF_SIZE + 0] = 0x04600000;
  CAN0->RAMn[ 9*MSG_BUF_SIZE + 1] = 0x98; 
  
  
  void FLEXCAN0_receive_msg(void)
{
/*! Receive msg from ID 0x556 using msg buffer 4
 * =============================================
 */
  uint8_t j;
  uint32_t dummy;

  RxCODE   = (CAN0->RAMn[ 1*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID     = (CAN0->RAMn[ 1*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT;	/* Read ID 			*/
  RxLENGTH = (CAN0->RAMn[ 1*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;	/* Read Message Length */
  
  RxCODE1   = (CAN0->RAMn[ 2*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID1     = (CAN0->RAMn[ 2*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT;	/* Read ID 			*/
  RxLENGTH1 = (CAN0->RAMn[ 2*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;	/* Read Message Length */
  
  RxCODE2   = (CAN0->RAMn[ 3*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID2     = (CAN0->RAMn[ 3*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT;	/* Read ID 			*/
  RxLENGTH2 = (CAN0->RAMn[ 3*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;	/* Read Message Length */
  
  RxCODE3   = (CAN0->RAMn[ 4*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID3    = (CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT;	/* Read ID 			*/
  RxLENGTH3 = (CAN0->RAMn[ 4*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;	/* Read Message Length */
  
  RxCODE4   = (CAN0->RAMn[ 5*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID4     = (CAN0->RAMn[ 5*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT;	/* Read ID 			*/
  RxLENGTH4 = (CAN0->RAMn[ 5*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;	/* Read Message Length */
  
  RxCODE5   = (CAN0->RAMn[ 6*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID5     = (CAN0->RAMn[ 6*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT;	/* Read ID 			*/
  RxLENGTH5 = (CAN0->RAMn[ 6*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;	/* Read Message Length */
  
  RxCODE6   = (CAN0->RAMn[ 7*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID6     = (CAN0->RAMn[ 7*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT;	/* Read ID 			*/
  RxLENGTH6 = (CAN0->RAMn[ 7*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;	/* Read Message Length */
  
  RxCODE7   = (CAN0->RAMn[ 8*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID7     = (CAN0->RAMn[ 8*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT;	/* Read ID 			*/
  RxLENGTH7 = (CAN0->RAMn[ 8*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;	/* Read Message Length */
  
  RxCODE8   = (CAN0->RAMn[ 9*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID8     = (CAN0->RAMn[ 9*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT;	/* Read ID 			*/
  RxLENGTH8 = (CAN0->RAMn[ 9*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;	/* Read Message Length */
  
}

		
	if ((CAN0->IFLAG1 >> 4) & 1) {  /* If CAN 0 MB 4 flag is set (received msg), read MB4 */
	FLEXCAN0_receive_msg ();      /* Read message */

		if(RxID== 0x90){

			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage<<8;  //Cumulative total voltage  
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage;  //Gather total voltage
			int32_t temp_Current; 
			
			temp_Current=BatPack.i32Current;
			if(temp_Current < 0)temp_Current =-(1)*temp_Current;
			else temp_Current=temp_Current;
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = temp_Current<<8;  //Current   
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = BatPack.SOC;  //SOC					

			
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 1] = 0x15540000; /* MB0 word 1: Tx msg with STD ID 0x555 *///35,78,26,560
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C600000 | 8 << CAN_WMBn_CS_DLC_SHIFT;//29BIT
			RxID=0;				
		}
		if(RxID== 0x91){
			
			 uint16_t lowestCellvoltage,highestCellvoltage,highestCellIndex,lowestCell;

			 bmsVoltageSorting(); /*Ascending order*/
			 bmsGetHLVoltageIndexes(&lowestCellvoltage, &highestCellvoltage,&highestCellIndex,&lowestCell);

			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)highestCellvoltage<<8;  //Maximum cell voltage value (mV) 
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage;  //Gather total voltage
		
			
		
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = lowestCellvoltage<<8;  //Minimum cell voltage value (mV)   
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = BatPack.SOC;  //SOC					

			
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 1] = 0x15540000; /* MB0 word 1: Tx msg with STD ID 0x555 *///35,78,26,560
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C600000 | 8 << CAN_WMBn_CS_DLC_SHIFT;//29BIT
			RxID=0;				
		}			
		if(RxID== 0x92){

			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage<<8;  //Cumulative total voltage  
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage;  //Gather total voltage
			int32_t temp_Current; 
			
			temp_Current=BatPack.i32Current;
			if(temp_Current < 0)temp_Current =-(1)*temp_Current;
			else temp_Current=temp_Current;
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = temp_Current<<8;  //Current   
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = BatPack.SOC;  //SOC					

			
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 1] = 0x15540000; /* MB0 word 1: Tx msg with STD ID 0x555 *///35,78,26,560
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C600000 | 8 << CAN_WMBn_CS_DLC_SHIFT;//29BIT
			RxID=0;				
		}
		if(RxID== 0x93){

			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage<<8;  //Cumulative total voltage  
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage;  //Gather total voltage
			int32_t temp_Current; 
			
			temp_Current=BatPack.i32Current;
			if(temp_Current < 0)temp_Current =-(1)*temp_Current;
			else temp_Current=temp_Current;
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = temp_Current<<8;  //Current   
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = BatPack.SOC;  //SOC					

			
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 1] = 0x15540000; /* MB0 word 1: Tx msg with STD ID 0x555 *///35,78,26,560
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C600000 | 8 << CAN_WMBn_CS_DLC_SHIFT;//29BIT
			RxID=0;				
		}
		if(RxID== 0x94){

			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage<<8;  //Cumulative total voltage  
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage;  //Gather total voltage
			int32_t temp_Current; 
			
			temp_Current=BatPack.i32Current;
			if(temp_Current < 0)temp_Current =-(1)*temp_Current;
			else temp_Current=temp_Current;
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = temp_Current<<8;  //Current   
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = BatPack.SOC;  //SOC					

			
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 1] = 0x15540000; /* MB0 word 1: Tx msg with STD ID 0x555 *///35,78,26,560
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C600000 | 8 << CAN_WMBn_CS_DLC_SHIFT;//29BIT
			RxID=0;				
		}
		if(RxID== 0x95){

			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage<<8;  //Cumulative total voltage  
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage;  //Gather total voltage
			int32_t temp_Current; 
			
			temp_Current=BatPack.i32Current;
			if(temp_Current < 0)temp_Current =-(1)*temp_Current;
			else temp_Current=temp_Current;
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = temp_Current<<8;  //Current   
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = BatPack.SOC;  //SOC					

			
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 1] = 0x15540000; /* MB0 word 1: Tx msg with STD ID 0x555 *///35,78,26,560
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C600000 | 8 << CAN_WMBn_CS_DLC_SHIFT;//29BIT
			RxID=0;				
		}			
		if(RxID== 0x96){

			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage<<8;  //Cumulative total voltage  
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage;  //Gather total voltage
			int32_t temp_Current; 
			
			temp_Current=BatPack.i32Current;
			if(temp_Current < 0)temp_Current =-(1)*temp_Current;
			else temp_Current=temp_Current;
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = temp_Current<<8;  //Current   
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = BatPack.SOC;  //SOC					

			
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 1] = 0x15540000; /* MB0 word 1: Tx msg with STD ID 0x555 *///35,78,26,560
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C600000 | 8 << CAN_WMBn_CS_DLC_SHIFT;//29BIT
			RxID=0;				
		}
		if(RxID== 0x97){

			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage<<8;  //Cumulative total voltage  
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage;  //Gather total voltage
			int32_t temp_Current; 
			
			temp_Current=BatPack.i32Current;
			if(temp_Current < 0)temp_Current =-(1)*temp_Current;
			else temp_Current=temp_Current;
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = temp_Current<<8;  //Current   
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = BatPack.SOC;  //SOC					

			
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 1] = 0x15540000; /* MB0 word 1: Tx msg with STD ID 0x555 *///35,78,26,560
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C600000 | 8 << CAN_WMBn_CS_DLC_SHIFT;//29BIT
			RxID=0;				
		}	
		if(RxID== 0x98){

			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage<<8;  //Cumulative total voltage  
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 2] = (uint16_t)BatPack.StackVoltage;  //Gather total voltage
			int32_t temp_Current; 
			
			temp_Current=BatPack.i32Current;
			if(temp_Current < 0)temp_Current =-(1)*temp_Current;
			else temp_Current=temp_Current;
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = temp_Current<<8;  //Current   
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 3] = BatPack.SOC;  //SOC					

			
			CAN0->RAMn[ 1*MSG_BUF_SIZE + 1] = 0x15540000; /* MB0 word 1: Tx msg with STD ID 0x555 *///35,78,26,560
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C600000 | 8 << CAN_WMBn_CS_DLC_SHIFT;//29BIT
			RxID=0;				
		}			
		CAN0->IFLAG1=0;
	}