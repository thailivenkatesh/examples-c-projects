


/*resVal = BCC_GET_ISENSE_VOLT(measurements[BCC_MSR_ISENSE1]);  //ISENSE value in uV. 

SendCANData[0]= resVal;


resVal = BCC_GET_ISENSE_AMP(DEMO_RSHUNT, measurements[BCC_MSR_ISENSE1];//ISENSE value in mA.
measurements[BCC_MSR_ISENSE2]);

SendCANData[1]=resval;

SendCANData[3]=BCC_GET_STACK_VOLT(measurements[BCC_MSR_STACK_VOLT]) / 1000U;//Stack voltage


SendCANData[4]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT1]) / 1000U;//Cells voltage. 

SendCANData[5]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT2]) / 1000U;

SendCANData[6]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT3]) / 1000U;
	
SendCANData[7]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT4]) / 1000U;
SendCANData[8]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT5]) / 1000U;
SendCANData[9]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT6]) / 1000U;
if (g_bccData.drvConfig.device[cid - 1] == BCC_DEVICE_MC33771)
{
SendCANData[10]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT7]) / 1000U;
SendCANData[11]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT8]) / 1000U;
SendCANData[12]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT9]) / 1000U;
SendCANData[13]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT10]) / 1000U;
SendCANData[14]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT11]) / 1000U;
SendCANData[15]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT12]) / 1000U;
SendCANData[16]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT13]) / 1000U;
SendCANData[17]=BCC_GET_VOLT(measurements[BCC_MSR_CELL_VOLT14]) / 1000U;
}


SendCANData[18]=measurements[BCC_MSR_AN0];//Analog inputs measurements.Temperature measured on AN0 - AN6 
SendCANData[19]=measurements[BCC_MSR_AN1];
SendCANData[20]=measurements[BCC_MSR_AN2];
SendCANData[21]=measurements[BCC_MSR_AN3];
SendCANData[23]=measurements[BCC_MSR_AN5];
SendCANData[24]=measurements[BCC_MSR_AN6];


resVal = BCC_GET_IC_TEMP(measurements[BCC_MSR_ICTEMP]);//IC temperature measurement. 
SendCANData[25]=BCC_GET_IC_TEMP(measurements[BCC_MSR_ICTEMP];*/
SendCANData[0]=2010//ISENSE value in uV
SendCANData[1]=2011;//ISENSE value in mA.

SendCANData[3]=5455U;//Stack voltage


SendCANData[4]=3401;//Cells voltage. 

SendCANData[5]=3402;//Cells voltage. 

SendCANData[6]=3403;//Cells voltage. 
	
SendCANData[7]=3404;//Cells voltage. 
SendCANData[8]=3405;//Cells voltage. 
SendCANData[9]=3406;//Cells voltage. 
if (g_bccData.drvConfig.device[cid - 1] == BCC_DEVICE_MC33771)
{
SendCANData[10]=3407;//Cells voltage. 
SendCANData[11]=3408;//Cells voltage. 
SendCANData[12]=3409;//Cells voltage. 
SendCANData[13]=3410;//Cells voltage. 
SendCANData[14]=3411;//Cells voltage. 
SendCANData[15]=3412;//Cells voltage. 
SendCANData[16]=3413;//Cells voltage. 
SendCANData[17]=3414;//Cells voltage. 
}


SendCANData[18]=3600;//Analog inputs measurements.Temperature measured on AN0 - AN6 
SendCANData[19]=3601;
SendCANData[20]=3602;
SendCANData[21]=3603;
SendCANData[23]=3604;
SendCANData[24]=3605;


resVal = BCC_GET_IC_TEMP(measurements[BCC_MSR_ICTEMP]);//IC temperature measurement. 
SendCANData[25]=1050;

void CAN_SendData2GUI(uint8_t u8Daughter)
{
uint8_t flexcan_senddata[52];

	
		flexcan_senddata[0] = (SendCANData[0]>>8)&0xFF;
		flexcan_senddata[1] = (SendCANData[0]>>0)&0xFF;
		flexcan_senddata[2] = (SendCANData[1]>>8)&0xFF;
		flexcan_senddata[3] = (SendCANData[1]>>0)&0xFF;
		flexcan_senddata[4] = (SendCANData[2]>>8)&0xFF;
		flexcan_senddata[5] = (SendCANData[2]>>0)&0xFF;
		flexcan_senddata[6] = (SendCANData[3]>>8)&0xFF;
		flexcan_senddata[7] = (SendCANData[3]>>0)&0xFF;
		
		flexcan_senddata[8] = (SendCANData[4]>>8)&0xFF;
		flexcan_senddata[9] = (SendCANData[4]>>0)&0xFF;
		flexcan_senddata[10] = (SendCANData[5]>>8)&0xFF;
		flexcan_senddata[11] = (SendCANData[5]>>0)&0xFF;
		flexcan_senddata[12] = (SendCANData[6]>>8)&0xFF;
		flexcan_senddata[13] = (SendCANData[6]>>0)&0xFF;
		flexcan_senddata[14] = (SendCANData[7]>>8)&0xFF;
		flexcan_senddata[15] = (SendCANData[7]>>0)&0xFF;
		
		flexcan_senddata[16] = (SendCANData[8]>>8)&0xFF;
		flexcan_senddata[17] = (SendCANData[8]>>0)&0xFF;
		flexcan_senddata[18] = (SendCANData[9]>>8)&0xFF;
		flexcan_senddata[19] = (SendCANData[9]>>0)&0xFF;
		flexcan_senddata[20] = (SendCANData[10]>>8)&0xFF;
		flexcan_senddata[21] = (SendCANData[10]>>0)&0xFF;
		flexcan_senddata[22] = (SendCANData[11]>>8)&0xFF;
		flexcan_senddata[23] = (SendCANData[11]>>0)&0xFF;
		
		flexcan_senddata[24] = (SendCANData[12]>>8)&0xFF;
		flexcan_senddata[25] = (SendCANData[12]>>0)&0xFF;
		flexcan_senddata[26] = (SendCANData[13]>>8)&0xFF;
		flexcan_senddata[27] = (SendCANData[13]>>0)&0xFF;
		flexcan_senddata[28] = (SendCANData[14]>>8)&0xFF;
		flexcan_senddata[29] = (SendCANData[14]>>0)&0xFF;
		flexcan_senddata[30] = (SendCANData[15]>>8)&0xFF;
		flexcan_senddata[31] = (SendCANData[15]>>0)&0xFF;
		
		flexcan_senddata[32] = (SendCANData[16]>>8)&0xFF;
		flexcan_senddata[33] = (SendCANData[16]>>0)&0xFF;
		flexcan_senddata[34] = (SendCANData[17]>>8)&0xFF;
		flexcan_senddata[35] = (SendCANData[17]>>0)&0xFF;		
		flexcan_senddata[36] = (SendCANData[18]>>8)&0xFF;
		flexcan_senddata[37] = (SendCANData[18]>>0)&0xFF;
		flexcan_senddata[38] = (SendCANData[19]>>8)&0xFF;
		flexcan_senddata39] = (SendCANData[19]>>0)&0xFF;
		
		flexcan_senddata[40] = (SendCANData[20]>>8)&0xFF;
		flexcan_senddata[41] = (SendCANData[20]>>0)&0xFF;
		flexcan_senddata[42] = (SendCANData[21]>>8)&0xFF;
		flexcan_senddata[43] = (SendCANData[21]>>0)&0xFF;
		flexcan_senddata[44] = (SendCANData[22]>>8)&0xFF;
		flexcan_senddata[45] = (SendCANData[22]>>0)&0xFF;		
		flexcan_senddata[46] = (SendCANData[23]>>8)&0xFF;
		flexcan_senddata[47] = (SendCANData[23]>>0)&0xFF;
		
		flexcan_senddata[48] = (SendCANData[24]>>8)&0xFF;
		flexcan_senddata[49] = (SendCANData[24]>>0)&0xFF;
		flexcan_senddata[50] = (SendCANData[25]>>8)&0xFF;
		flexcan_senddata[51] = (SendCANData[26]>>0)&0xFF;
		
		
		
		
		
		SendCANData(0x18810000 , SendCANData);
		Delayus(500);
		if(u8Daughter<16)
		{
			SendCANData(0x18801000  , SendCANData);
			Delayus(500);
		}

	}



		
		
		
		
		  for(k=2;k<128;k++)//127value
	  {
		  a[k]=k;//copying all values to array from 2 to 127
	  }
        for(k=2;k<128;k++)//moving array nos 2to 127
        {

        CAN0->RAMn[ 0*MSG_BUF_SIZE + k]= a[k];	/* MB0 word 2: data word 0 */
        }
			/*for(i=0,k=0;i<26;i++,k+2)
{
CAN0->RAMn[ 0*MSG_BUF_SIZE+i]=(SendCANData[i]>>8)&0xFF;
CAN0->RAMn[ 0*MSG_BUF_SIZE+i+1]=(SendCANData[i]>>0)&0xFF;
}*/

		
		
		/*
		for(i=0;i<26;i++)
			TXDATA[i]=(CCAN0->RAMn[ 0*MSG_BUF_SIZE +(i+2)]<<8)&0xff00|CCAN0->RAMn[ 0*MSG_BUF_SIZE +(i+3)]; */
		
	        TXDATA[0]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 2]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 3]);
			TXDATA[1]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 4]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 5]);
			TXDATA[2]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 6]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 7]);
			TXDATA[3]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 8]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 9]);
			TXDATA[4]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 10]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE+11]);
			TXDATA[5]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 12]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 13]);
			TXDATA[6]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 14]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 15]);
			TXDATA[7]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 16]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 17]);
			TXDATA[8]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 18]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 19]);
			TXDATA[9]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 20]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 21]);
			TXDATA[10]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 22]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 23]);
			TXDATA[11]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 24]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 25]);
			TXDATA[12]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 26]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 27]);
			TXDATA[13]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 28]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 29]);
			TXDATA[14]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 30]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 31]);
			TXDATA[15]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 32]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 33]);
			TXDATA[16]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 34]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 35]);
			TXDATA[17]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 36]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 37]);
			TXDATA[18]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 38]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 39]);
			TXDATA[19]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 40]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 41]);
			TXDATA[20]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 42]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 43]);
			TXDATA[21]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 44]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 45]);
			TXDATA[22]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 46]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 47]);
			TXDATA[23]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 48]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 49]);
			TXDATA[24]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 50]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 51]);
			TXDATA[25]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 53]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 54]);
			
			
			
			
	    /*CAN0->RAMn[ 0*MSG_BUF_SIZE + 2]=(SendCANData[0])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 3]=(SendCANData[1])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 4]=(SendCANData[2])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 5]=(SendCANData[3])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 6]=(SendCANData[4])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 7]=(SendCANData[5])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 8]=(SendCANData[6])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 9]=(SendCANData[7])&0xFFFF;
		
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 10]=(SendCANData[8])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 11]=(SendCANData[9])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 12]=(SendCANData[10]>>8)&0xFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 13]=(SendCANData[11])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 14]=(SendCANData[12])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 15]=(SendCANData[13])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 16]=(SendCANData[14])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 17]]=(SendCANData[15])&0xFFFF;
		
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 18]=(SendCANData[16])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 19]=(SendCANData[17])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 20]=(SendCANData[18])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 21]=(SendCANData[19])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 21]=(SendCANData[20])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 23]=(SendCANData[21])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 24]=(SendCANData[22])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 25]=(SendCANData[23])&0xFFFF;
		
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 26]=(SendCANData[24])&0xFFFF;
		CAN0->RAMn[ 0*MSG_BUF_SIZE + 27]=(SendCANData[25])&0xFFFF;*/
		for(i=0;i<26;i++)
			CAN0->RAMn[ 0*MSG_BUF_SIZE + (i+2)]=(SendCANData[i])&0xFFFF;
		
			/* TXDATA[0]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 2];
			TXDATA[1]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 3];
			TXDATA[2]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 4];
			TXDATA[3]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 5];
			TXDATA[4]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 6];
			TXDATA[5] = CAN0->RAMn[ 0*MSG_BUF_SIZE + 7];
			TXDATA[6]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 8];
			TXDATA[7]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 9];
			TXDATA[8]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 10];
			TXDATA[9]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 11];
			TXDATA[10]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 12];
			TXDATA[11]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 13];
			TXDATA[12]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 14];
			TXDATA[13]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 15];
			TXDATA[14]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 16];
			TXDATA[15]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 17];
			TXDATA[16]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 18];
			TXDATA[17]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 19];
			TXDATA[18]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 20];
			TXDATA[19]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 21];
			TXDATA[20]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 21];
			TXDATA[21]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 23];
			TXDATA[22]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 24];
			TXDATA[23]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 25];
			TXDATA[24]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 26];
			TXDATA[25]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 27];*/
			for(i=0;<26;i++)
			 TXDATA[i]= CAN0->RAMn[ 0*MSG_BUF_SIZE + i+2];	
		 
		 
		 
		 
		 //for 8bytes
		     CAN0->RAMn[ 0*MSG_BUF_SIZE + k]= a[k];	/// MB0 word 2: data word 0
        }*/
	       /* CAN0->RAMn[ 0*MSG_BUF_SIZE + 2]=(SendCANData[0]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 3]=(SendCANData[0]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 4]=(SendCANData[1]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 5]=(SendCANData[1]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 6]=(SendCANData[2]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 7]=(SendCANData[2]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 8]=(SendCANData[3]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 9]=(SendCANData[3]>>0)&0xFF;

			CAN0->RAMn[ 0*MSG_BUF_SIZE + 10]=(SendCANData[4]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 11]=(SendCANData[4]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 12]=(SendCANData[5]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 13]=(SendCANData[5]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 14]=(SendCANData[6]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 15]=(SendCANData[6]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 16]=(SendCANData[7]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 17]=(SendCANData[7]>>0)&0xFF;

			CAN0->RAMn[ 0*MSG_BUF_SIZE + 18]=(SendCANData[8]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 19]=(SendCANData[8]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 20]=(SendCANData[9]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 21]=(SendCANData[9]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 21]=(SendCANData[10]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 23]=(SendCANData[10]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 24]=(SendCANData[11]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 25]=(SendCANData[11]>>0)&0xFF;

			CAN0->RAMn[ 0*MSG_BUF_SIZE + 26]=(SendCANData[12]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 27]=(SendCANData[12]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 28]=(SendCANData[13]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 29]=(SendCANData[13]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 30]=(SendCANData[14]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 31]=(SendCANData[14]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 32]=(SendCANData[15]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 33]=(SendCANData[15]>>0)&0xFF;

			CAN0->RAMn[ 0*MSG_BUF_SIZE + 34]=(SendCANData[16]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 35]=(SendCANData[16]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 36]=(SendCANData[17]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 37]=(SendCANData[17]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 38]=(SendCANData[18]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 39]=(SendCANData[18]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 40]=(SendCANData[19]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 41]=(SendCANData[19]>>0)&0xFF;

		    CAN0->RAMn[ 0*MSG_BUF_SIZE + 42]=(SendCANData[20]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 43]=(SendCANData[20]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 44]=(SendCANData[21]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 45]=(SendCANData[21]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 46]=(SendCANData[22]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 47]=(SendCANData[22]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 48]=(SendCANData[23]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 19]=(SendCANData[23]>>0)&0xFF;

			CAN0->RAMn[ 0*MSG_BUF_SIZE + 50]=(SendCANData[24]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 21]=(SendCANData[24]>>0)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 52]=(SendCANData[25]>>8)&0xFF;
			CAN0->RAMn[ 0*MSG_BUF_SIZE + 53]=(SendCANData[25]>>0)&0xFF;


			TXDATA[0]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 2]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 3]);
			TXDATA[1]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 4]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 5]);
			TXDATA[2]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 6]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 7]);
			TXDATA[3]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 8]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 9]);
			TXDATA[4]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 10]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE+11]);
			TXDATA[5]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 12]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 13]);
			TXDATA[6]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 14]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 15]);
			TXDATA[7]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 16]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 17]);
			TXDATA[8]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 18]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 19]);
			TXDATA[9]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 20]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 21]);
			TXDATA[10]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 22]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 23]);
			TXDATA[11]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 24]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 25]);
			TXDATA[12]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 26]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 27]);
			TXDATA[13]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 28]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 29]);
			TXDATA[14]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 30]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 31]);
			TXDATA[15]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 32]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 33]);
			TXDATA[16]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 34]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 35]);
			TXDATA[17]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 36]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 37]);
			TXDATA[18]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 38]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 39]);
			TXDATA[19]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 40]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 41]);
			TXDATA[20]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 42]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 43]);
			TXDATA[21]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 44]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 45]);
			TXDATA[22]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 46]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 47]);
			TXDATA[23]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 48]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 49]);
			TXDATA[24]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 50]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 51]);
			TXDATA[25]=((CAN0->RAMn[ 0*MSG_BUF_SIZE + 53]<<8)&0xff00)|(CAN0->RAMn[ 0*MSG_BUF_SIZE + 54]);
			
/*****************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int SendCANData=23204545,SendCANData[2],txdata;//8992

int main()
{
    printf("Hello World\n");
    	SendCANData[1]= (SendCANData>>16)&0xFFFF;
		SendCANData[0] = (SendCANData>>0)&0xFFFF;
      printf("%d\t%d",SendCANData[0] ,SendCANData[1]);
      txdata=((SendCANData[1]<<16)&0xffff0000)|(SendCANData[0]); 
      printf("\n%	  d",txdata);
    return 0;
		    uint16_t SendCANData[26];//measurment samplevalues

	SendCANData[0]=2010;//ISENSE value in uV
	SendCANData[1]=2011;//ISENSE value in mA.
	SendCANData[2]=5445;//Stack voltage
	SendCANData[3]=3400;//cells voltage
	SendCANData[4]=3401;//Cells voltage.
	SendCANData[5]=3402;//Cells voltage.
	SendCANData[6]=3403;//Cells voltage.
	SendCANData[7]=3404;//Cells voltage.
	SendCANData[8]=3405;//Cells voltage.
	SendCANData[9]=3406;//Cells voltage.
	SendCANData[10]=3407;//Cells voltage.
	SendCANData[11]=3408;//Cells voltage.
	SendCANData[12]=3409;//Cells voltage.
	SendCANData[13]=3410;//Cells voltage.
	SendCANData[14]=3411;//Cells voltage.
	SendCANData[15]=3412;//Cells voltage.
	SendCANData[16]=3413;//Cells voltage.
	SendCANData[17]=3414;//Cells voltage.
	SendCANData[18]=3600;//Analog inputs measurements.Temperature measured on AN0 - AN6
	SendCANData[19]=3601;
	SendCANData[20]=3602;
	SendCANData[21]=3603;
	SendCANData[21]=3604;
	SendCANData[23]=3605;
	SendCANData[24]=3606;
	SendCANData[25]=1057;//IC temperature measurement.

	/* Assumption:  Message buffer CODE is INACTIVE */
	CAN0->IFLAG1 = 0x00000001;       /* Clear CAN 0 MB 0 flag without clearing others*/
	//CAN0->RAMn[ 0*MSG_BUF_SIZE + 2] = 0xA5112233; /* MB0 word 2: data word 0 */
	//CAN0->RAMn[ 0*MSG_BUF_SIZE + 3] = 0x44556677; /* MB0 word 3: data word 1 */


	CAN0->RAMn[ 0*MSG_BUF_SIZE + 2]=(uint32_t)((SendCANData[1]<<16)&0xffff0000)|(SendCANData[0]);    //ISENSE UV   ISENSE MV
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 3]=(uint32_t)((SendCANData[3]<<16)&0xffff0000)|(SendCANData[2]);    //STACK  V     CELL1 V
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 4]=(uint32_t)((SendCANData[5]<<16)&0xffff0000)|(SendCANData[4]);    //CELL2  V     CELL3 V
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 5]=(uint32_t)((SendCANData[7]<<16)&0xffff0000)|(SendCANData[6]);    //CELL4  V     CELL5 V
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 6]=(uint32_t)((SendCANData[9]<<16)&0xffff0000)|(SendCANData[8]);    //CELL6  V     CELL7 V
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 7]=(uint32_t)((SendCANData[11]<<16)&0xffff0000)|(SendCANData[10]);  //CELL8  V     CELL9 V
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 8]=(uint32_t)((SendCANData[13]<<16)&0xffff0000)|(SendCANData[12]);  //CELL10 V     CELL11 V
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 9]=(uint32_t)((SendCANData[15]<<16)&0xffff0000)|(SendCANData[14]);  //CELL12 V     CELL13 V
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 10]=(uint32_t)((SendCANData[17]<<16)&0xffff0000)|(SendCANData[16]); //CELL14 V     AN0
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 11]=(uint32_t)((SendCANData[19]<<16)&0xffff0000)|(SendCANData[18]); //AN1          AN2
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 12]=(uint32_t)((SendCANData[21]<<16)&0xffff0000)|(SendCANData[20]); //AN3          AN4
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 13]=(uint32_t)((SendCANData[23]<<16)&0xffff0000)|(SendCANData[22]); //AN5          AN6
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 14]=(uint32_t)SendCANData[24];                                     //IC TEMP


	//COPIED INTO BUFFER to check transfer data
	TXDATA[0]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 2])&0xffff;//SendCANData[0]
	TXDATA[1]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 2])>>16)&0xffff;//SendCANData[1]
	TXDATA[2]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 3])&0xffff;//SendCANData[2]
	TXDATA[3]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 3])>>16)&0xffff;//SendCANData[3]
	TXDATA[4]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 4])&0xffff;//SendCANData[4]
	TXDATA[5]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 4])>>16)&0xffff;//SendCANData[5]
	TXDATA[6]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 5])&0xffff;//SendCANData[6]
	TXDATA[7]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 5])>>16)&0xffff;//SendCANData[7]
	TXDATA[8]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 6])&0xffff;//SendCANData[8]
	TXDATA[9]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 6])>>16)&0xffff;//SendCANData[9]
	TXDATA[10]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 7])&0xffff;//SendCANData[10]
	TXDATA[11]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 7])>>16)&0xffff;//SendCANData[11]
	TXDATA[12]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 8])&0xffff;//SendCANData[12]
	TXDATA[13]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 8])>>16)&0xffff;//SendCANData[13]
	TXDATA[14]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 9])&0xffff;//SendCANData[14]
	TXDATA[15]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 9])>>16)&0xffff;//SendCANData[15]
	TXDATA[16]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 10])&0xffff;//SendCANData[16]
	TXDATA[17]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 10])>>16)&0xffff;//SendCANData[17]
	TXDATA[18]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 11])&0xffff;//SendCANData[18]
	TXDATA[19]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 11])>>16)&0xffff;//SendCANData[19]
	TXDATA[20]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 12])&0xffff;//SendCANData[20]
	TXDATA[21]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 12])>>16)&0xffff;//SendCANData[21]
	TXDATA[22]=(uint16_t)(CAN0->RAMn[ 0*MSG_BUF_SIZE + 13])&0xffff;//SendCANData[22]
	TXDATA[23]=(uint16_t)((CAN0->RAMn[ 0*MSG_BUF_SIZE + 13])>>16)&0xffff;//SendCANData[23]
	TXDATA[24]=(uint16_t)CAN0->RAMn[ 0*MSG_BUF_SIZE + 14];//SendCANData[24]



}
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 2]=(SendCANData[0])&0xFFFF;/* MB0 word 2: data word 0 */
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 3]=(SendCANData[1])&0xFFFF;/* MB0 word 2: data word 0 */
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 4]=(SendCANData[2])&0xFFFF;/* MB0 word 2: data word 1 */
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 5]=(SendCANData[3])&0xFFFF;/* MB0 word 2: data word 1 */
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 6]=(SendCANData[4])&0xFFFF;/* MB0 word 2: data word 2 */
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 7]=(SendCANData[5])&0xFFFF;/* MB0 word 2: data word 2 */
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 8]=(SendCANData[6])&0xFFFF;/* MB0 word 2: data word 3 */
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 9]=(SendCANData[7])&0xFFFF;/* MB0 word 2: data word 3 */
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 10]=(SendCANData[8])&0xFFFF;/* MB0 word 2: data word 4*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 11]=(SendCANData[9])&0xFFFF;/* MB0 word 2: data word 4*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 12]=(SendCANData[10])&0xFF;/*MB0 word 2: data word 5*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 13]=(SendCANData[11])&0xFFFF;/* MB0 word 2: data word 5*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 14]=(SendCANData[12])&0xFFFF;/* MB0 word 2: data word 6*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 15]=(SendCANData[13])&0xFFFF;/* MB0 word 2: data word 6*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 16]=(SendCANData[14])&0xFFFF;/* MB0 word 2: data word 7*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 17]=(SendCANData[15])&0xFFFF;/* MB0 word 2: data word 7*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 18]=(SendCANData[16])&0xFFFF;/* MB0 word 2: data word 8*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 19]=(SendCANData[17])&0xFFFF;/* MB0 word 2: data word 8*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 20]=(SendCANData[18])&0xFFFF;/* MB0 word 2: data word 9*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 21]=(SendCANData[19])&0xFFFF;/* MB0 word 2: data word 9*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 21]=(SendCANData[20])&0xFFFF;/* MB0 word 2: data word 10*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 23]=(SendCANData[21])&0xFFFF;/* MB0 word 2: data word 10*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 24]=(SendCANData[22])&0xFFFF;/* MB0 word 2: data word 11*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 25]=(SendCANData[23])&0xFFFF;/* MB0 word 2: data word 11*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 26]=(SendCANData[24])&0xFFFF;/* MB0 word 2: data word 12*/
	CAN0->RAMn[ 0*MSG_BUF_SIZE + 27]=(SendCANData[25])&0xFFFF;/* MB0 word 2: data word 12*/
	//for(i=0;i<26;i++)
	//CAN0->RAMn[ 0*MSG_BUF_SIZE + (i+2)]=(SendCANData[i])&0xFFFF;

	TXDATA[0]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 2];
	TXDATA[1]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 3];
	TXDATA[2]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 4];
	TXDATA[3]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 5];
	TXDATA[4]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 6];
	TXDATA[5]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 7];
	TXDATA[6]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 8];
	TXDATA[7]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 9];
	TXDATA[8]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 10];
	TXDATA[9]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 11];
	TXDATA[10]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 12];
	TXDATA[11]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 13];
	TXDATA[12]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 14];
	TXDATA[13]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 15];
	TXDATA[14]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 16];
	TXDATA[15]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 17];
	TXDATA[16]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 18];
	TXDATA[17]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 19];
	TXDATA[18]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 20];
	TXDATA[19]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 21];
	TXDATA[20]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 21];
	TXDATA[21]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 23];
	TXDATA[22]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 24];
	TXDATA[23]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 25];
	TXDATA[24]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 26];
	TXDATA[25]= CAN0->RAMn[ 0*MSG_BUF_SIZE + 27];*/
	
	
	
	/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
# define NDEBUG
#include <assert.h>
 
int main()
{
    int x = 7;
 
    /*  Some big code in between and let's say x
       is accidentally changed to 9  */
    x = 9;
 
    // Programmer assumes x to be 7 in rest of the code
    assert(x==7);
 
    /* Rest of the code */
    printf("%d",x);
 
    return 0;
}