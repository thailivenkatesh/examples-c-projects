


void bmsSetConfig()	{//call from main function

	//gui format format$2900,3650,65,100,100,0,14#
	Batconfig.min_vol_cutoff = ((set_arr[1]-48)*1000)+((set_arr[2]-48)*100)+((set_arr[3]-48)*10)+((set_arr[4]-48)*1);
	Batconfig.max_vol_cutoff = ((set_arr[6]-48)*1000)+((set_arr[7]-48)*100)+((set_arr[8]-48)*10)+((set_arr[9]-48)*1);
	Batconfig.max_temp_cutoff = ((set_arr[11]-48)*10)+((set_arr[12]-48)*1);
	Batconfig.chrg_cur_cutoff = ((set_arr[14]-48)*100)+((set_arr[15]-48)*10)+((set_arr[16]-48)*1);
	Batconfig.dchrg_cur_cutoff = ((set_arr[18]-48)*100)+((set_arr[19]-48)*10)+((set_arr[20]-48)*1);
	//Batconfig.cbVoltage =((set_arr[17]-48)*1000)+((set_arr[18]-48)*100)+((set_arr[19]-48)*10)+((set_arr[20]-48)*1);


	tempmin_vol_cutoff = Batconfig.min_vol_cutoff;//Batconfig.min_vol_cutoff
	Min_V_WrVal0 = tempmin_vol_cutoff&0xff;//lower byte
	EEPROM_write(EEPROM_WRITE,&Min_V_cutoff_Addr0,Min_V_WrVal0);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	Min_V_WrVal1 = (tempmin_vol_cutoff&0xff00)>>8;
	EEPROM_write(EEPROM_WRITE,&Min_V_cutoff_Addr1,Min_V_WrVal1);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);


	tempmax_vol_cutoff = Batconfig.max_vol_cutoff;//Batconfig.min_vol_cutoff
	Max_V_WrVal0 = tempmax_vol_cutoff&0xff;//lower byte
	EEPROM_write(EEPROM_WRITE,&Max_V_cutoff_Addr0,Max_V_WrVal0);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	Max_V_WrVal1 = (tempmax_vol_cutoff&0xff00)>>8;
	EEPROM_write(EEPROM_WRITE,&Max_V_cutoff_Addr1,Max_V_WrVal1);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);


	tempmax_vol_cutoff = Batconfig.max_temp_cutoff;//Batconfig.min_vol_cutoff
	Max_T_WrVal0 = tempmax_vol_cutoff&0xff;//lower byte
	EEPROM_write(EEPROM_WRITE,&Max_T_cutoff_Addr0,Max_T_WrVal0);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	Max_T_WrVal1 = (tempmax_vol_cutoff&0xff00)>>8;
	EEPROM_write(EEPROM_WRITE,&Max_T_cutoff_Addr1,Max_T_WrVal1);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);

	tempchrg_cur_cutoff = Batconfig.chrg_cur_cutoff;//Batconfig.min_vol_cutoff
	Chrg_I_WrVal0 = tempchrg_cur_cutoff&0xff;//lower byte
	EEPROM_write(EEPROM_WRITE,&Chrg_I_cutoff_Addr0,Chrg_I_WrVal0);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
//	Chrg_I_WrVal1 = (tempchrg_cur_cutoff&0xff00)>>8;
//	EEPROM_write(EEPROM_WRITE,&Chrg_I_cutoff_Addr1,Chrg_I_WrVal1);
//	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);

	tempdchrg_cur_cutoff = Batconfig.dchrg_cur_cutoff;//Batconfig.min_vol_cutoff
	Dchrg_I_WrVal0 = tempdchrg_cur_cutoff&0xff;//lower byte
	EEPROM_write(EEPROM_WRITE,&Dchrg_I_cutoff_Addr0,Dchrg_I_WrVal0);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
//	Dchrg_I_WrVal1 = (tempdchrg_cur_cutoff&0xff00)>>8;
//	EEPROM_write(EEPROM_WRITE,&Dchrg_I_cutoff_Addr1,Dchrg_I_WrVal1);
//	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);

	tempCB = Batconfig.cbVoltage;//Batconfig.min_vol_cutoff
	CB_WrVal0 = tempCB &0xff;//lower byte
	EEPROM_write(EEPROM_WRITE,&CB_Addr0,CB_WrVal0);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	CB_WrVal1 = (tempCB &0xff00)>>8;
	EEPROM_write(EEPROM_WRITE,&CB_Addr1,CB_WrVal1);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);

}

void  bmsConfigRead()	{

	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	EEPROM_read(EEPROM_READ,&Min_V_cutoff_Addr0,&Min_V_RdVal0,1);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	EEPROM_read(EEPROM_READ,&Min_V_cutoff_Addr1,&Min_V_RdVal1,1);
	Batconfig.min_vol_cutoff = ((Min_V_RdVal1)<<8)+Min_V_RdVal0;//higher byte +lower byte

	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	EEPROM_read(EEPROM_READ,&Max_V_cutoff_Addr0,&Max_V_RdVal0,1);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	EEPROM_read(EEPROM_READ,&Max_V_cutoff_Addr1,&Max_V_RdVal1,1);
	Batconfig.max_vol_cutoff= ((Max_V_RdVal1)<<8)+Max_V_RdVal0;//higher byte +lower byte


	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);//65
	EEPROM_read(EEPROM_READ,&Max_T_cutoff_Addr0,&Max_T_RdVal0,1);
//	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
//	EEPROM_read(EEPROM_READ,&Max_T_cutoff_Addr1,&Max_T_RdVal1,1);
//	Batconfig.max_temp_cutoff = ((Max_T_RdVal1)<<8)+Max_T_RdVal0;//higher byte +lower byte
	Batconfig.max_temp_cutoff =Max_T_RdVal0;

	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);//100
	EEPROM_read(EEPROM_READ,&Chrg_I_cutoff_Addr0,&Chrg_I_RdVal0,1);
//	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
//	EEPROM_read(EEPROM_READ,&Chrg_I_cutoff_Addr1,&Chrg_I_RdVal1,1);
//	Batconfig.chrg_cur_cutoff= ((Chrg_I_RdVal1)<<8)+Chrg_I_RdVal0;//higher byte +lower byte
	Batconfig.chrg_cur_cutoff= Chrg_I_RdVal0;


	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);//100
	EEPROM_read(EEPROM_READ,&Dchrg_I_cutoff_Addr0,&Dchrg_I_RdVal0,1);
//	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
//	EEPROM_read(EEPROM_READ,&Dchrg_I_cutoff_Addr1,&Dchrg_I_RdVal1,1);
//	Batconfig.dchrg_cur_cutoff = ((Dchrg_I_RdVal1)<<8)+Dchrg_I_RdVal0;//higher byte +lower byte
	Batconfig.dchrg_cur_cutoff = Dchrg_I_RdVal0;

	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	EEPROM_read(EEPROM_READ,&CB_Addr0,&CB_RdVal0,1);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	EEPROM_read(EEPROM_READ,&CB_Addr1,&CB_RdVal1,1);
	Batconfig.cbVoltage = ((CB_RdVal1)<<8)+CB_RdVal0;//higher byte +lower byte

#if	PRNTDEBUG
	PRINTF("\r\nBatconfig.min_vol_cutoff : %d\r\n",Batconfig.min_vol_cutoff);
	PRINTF("\r\nBatconfig.max_vol_cutoff : %d\r\n",Batconfig.max_vol_cutoff);
	PRINTF("\r\n Batconfig.max_temp_cutoff : %d\r\n", Batconfig.max_temp_cutoff);
	PRINTF("\r\nBatconfig.chrg_cur_cutoff : %d\r\n",Batconfig.chrg_cur_cutoff);
	PRINTF("\r\nBatconfig.dchrg_cur_cutoff : %d\r\n",Batconfig.dchrg_cur_cutoff);
	//PRINTF("\r\nBatconfig.CB : %d\r\n",Batconfig.CB);
#endif
	// }
}

//gui format format$2900,3650,65,100,100,0,14#
unsigned char set_arr[50];
char start_flag = 0;
if (STATUS_SUCCESS == LPUART_DRV_ReceiveData(INST_LPUART2, set_arr, 24)) {

					if (set_arr[0] == 'S')
						startsend_flag = 1;
					if (set_arr[0] == '$')
						startsend_flag = 3;
					if (set_arr[0] == 'E')
						startsend_flag = 0;
				}


				if(startsend_flag == 1) // Start sending over UART
				{
					bmsGui_toAscii();
					LPUART_DRV_SendData(INST_LPUART2, read_arr, strlen(read_arr));

				} else if(startsend_flag == 3){

					bmsSetConfig();
					startsend_flag = 0;
				}
	



	
				void bmsGui_toAscii()	{
         uint8_t Power_On_Status=1;
        //Power On Status
         read_arr[0] = Power_On_Status+48;

         uint8_t Guisoc;
         Guisoc=(uint8_t)BatPack.SOC;
        
         read_arr[2] = Guisoc/100%10+48;
         read_arr[3] = Guisoc/10%10+48;
         read_arr[4] = Guisoc/1%10+48;
 


         //power

        uint32_t power,tempStackVoltage;
        float tempCurrent;

        tempStackVoltage=BatPack.StackVoltage/1000;
        tempCurrent = BatPack.i32Current;
        if (tempCurrent > 0 ){
        	tempCurrent=tempCurrent/1000;
        	power =tempStackVoltage*tempCurrent;
        }
        else{
        	tempCurrent=-(tempCurrent);
        	tempCurrent=tempCurrent/1000;
        	power =tempStackVoltage*(tempCurrent);
        }

        read_arr[6] = power/10000%10+48;
        read_arr[7] = power/1000%10+48;
        read_arr[8] = power/100%10+48;
        read_arr[9] = power/10%10+48;
        read_arr[10] = power/1%10+48;

    //Current (A) (*)Standby / (+)Charging / (-)Discharge//*000//81 82 83 84 85


         int32_t tempi32Current;
         tempi32Current = BatPack.i32Current;
         if (tempi32Current > 0 ){
		 int temp= (tempi32Current);
    	 read_arr[12] = 43; ////1//43
    	 read_arr[13] = temp/1000%10+48;//
    	 read_arr[14] = 46;//0
    	 read_arr[15] = temp/100%10+48;//2
     }
     else {//-1029

    	 int temp= -(tempi32Current);
    	 read_arr[12] = 45;//-
    	 read_arr[13] = temp/1000%10+48;//0
    	 read_arr[14] = 46;//.
    	 read_arr[15] = temp/100%10+48;//1

     }

    //Charge Cycle  0000//86 87 88 89 90

         read_arr[87] = Batcycle/1000%10+48;
         read_arr[88] = Batcycle/100%10+48;
         read_arr[89] = Batcycle/10%10+48;
         read_arr[90] = Batcycle/1%10+48;

         //temp min
        // uint8_t Temp_Min=0;
         read_arr[92] = BatPack.TempCell[0]/10%10+48;
         read_arr[93] = BatPack.TempCell[0]/1%10+48;
         //temp max
        // uint8_t Temp_Max=48;
         read_arr[95] = BatPack.TempCell[0]/10%10+48;
         read_arr[96] = BatPack.TempCell[0]/1%10+48;
         //temp avg;
         uint8_t Temp_Avg=24;
         read_arr[98] = BatPack.TempCell[0]/10%10+48;
         read_arr[99] = BatPack.TempCell[0]/1%10+48;

         uint16_t lowestCellvoltage,highestCellvoltage,highestCellIndex,lowestCell;

         bmsVoltageSorting(); /*Ascending order*/
         bmsGetHLVoltageIndexes(&lowestCellvoltage, &highestCellvoltage,&highestCellIndex,&lowestCell);
         //Volt Min (mV)
         read_arr[101] = lowestCellvoltage/1000%10+48;
         read_arr[102] = lowestCellvoltage/100%10+48;
         read_arr[103] = lowestCellvoltage/10%10+48;
         read_arr[104] = lowestCellvoltage/1%10+48;
         //Volt Max (mV)
         read_arr[106] = highestCellvoltage/1000%10+48;
         read_arr[107] = highestCellvoltage/100%10+48;
         read_arr[108] = highestCellvoltage/10%10+48;
         read_arr[109] = highestCellvoltage/1%10+48;


         uint16_t Volt_Avg = 0;
         Volt_Avg=(lowestCellvoltage+highestCellvoltage)/2;
         //Volt Avg (mV)
         read_arr[111] = Volt_Avg/1000%10+48;//cell12
         read_arr[112] = Volt_Avg/100%10+48;
         read_arr[113] = Volt_Avg/10%10+48;
         read_arr[114] = Volt_Avg/1%10+48;


         //Volt Difference
         uint8_t Volt_Difference;
         Volt_Difference=highestCellvoltage-lowestCellvoltage;
         read_arr[116] = 48;//cell12
         read_arr[117] = 48;
         read_arr[118] = Volt_Difference/10%10+48;
         read_arr[119] = Volt_Difference/1%10+48;


        //stack voltage
        read_arr[121] = BatPack.StackVoltage/10000%10+48;
        read_arr[122] = BatPack.StackVoltage/1000%10+48;
        read_arr[123] = BatPack.StackVoltage/100%10+48;
        read_arr[124] = BatPack.StackVoltage/10%10+48;
        read_arr[125] = BatPack.StackVoltage/1%10+48;

        
        

         read_arr[172] = BatPack.CellVoltages[0]/1000%10+48;//cell1
         read_arr[173] = BatPack.CellVoltages[0]/100%10+48;
         read_arr[174] = BatPack.CellVoltages[0]/10%10+48;
         read_arr[175] = BatPack.CellVoltages[0]/1%10+48;

         read_arr[177] = BatPack.CellVoltages[1]/1000%10+48;//cell2
         read_arr[178] = BatPack.CellVoltages[1]/100%10+48;
         read_arr[179] = BatPack.CellVoltages[1]/10%10+48;
         read_arr[180] = BatPack.CellVoltages[1]/1%10+48;

         read_arr[182] = BatPack.CellVoltages[2]/1000%10+48;//cell3
         read_arr[183] = BatPack.CellVoltages[2]/100%10+48;
         read_arr[184] = BatPack.CellVoltages[2]/10%10+48;
         read_arr[185] = BatPack.CellVoltages[2]/1%10+48;

         read_arr[187] = BatPack.CellVoltages[3]/1000%10+48;//cell4
         read_arr[188] = BatPack.CellVoltages[3]/100%10+48;
         read_arr[189] = BatPack.CellVoltages[3]/10%10+48;
         read_arr[190] = BatPack.CellVoltages[3]/1%10+48;

         read_arr[192] = BatPack.CellVoltages[4]/1000%10+48;//cell5
         read_arr[193] = BatPack.CellVoltages[4]/100%10+48;
         read_arr[194] = BatPack.CellVoltages[4]/10%10+48;
         read_arr[195] = BatPack.CellVoltages[4]/1%10+48;

         read_arr[197] = BatPack.CellVoltages[5]/1000%10+48;//cell6
         read_arr[198] = BatPack.CellVoltages[5]/100%10+48;
         read_arr[199] = BatPack.CellVoltages[5]/10%10+48;
         read_arr[200] = BatPack.CellVoltages[5]/1%10+48;

         read_arr[202] = BatPack.CellVoltages[6]/1000%10+48;//cell7
         read_arr[203] = BatPack.CellVoltages[6]/100%10+48;
         read_arr[204] = BatPack.CellVoltages[6]/10%10+48;
         read_arr[205] = BatPack.CellVoltages[6]/1%10+48;

         read_arr[207] = BatPack.CellVoltages[7]/1000%10+48;//cell8
         read_arr[208] = BatPack.CellVoltages[7]/100%10+48;
         read_arr[209] = BatPack.CellVoltages[7]/10%10+48;
         read_arr[210] = BatPack.CellVoltages[7]/1%10+48;

         read_arr[212] = BatPack.CellVoltages[8]/1000%10+48;//cell9
         read_arr[213] = BatPack.CellVoltages[8]/100%10+48;
         read_arr[214] = BatPack.CellVoltages[8]/10%10+48;
         read_arr[215] = BatPack.CellVoltages[8]/1%10+48;

         read_arr[217] = BatPack.CellVoltages[9]/1000%10+48;//cell10
         read_arr[218] = BatPack.CellVoltages[9]/100%10+48;
         read_arr[219] = BatPack.CellVoltages[9]/10%10+48;
         read_arr[220] = BatPack.CellVoltages[9]/1%10+48;

         read_arr[222] = BatPack.CellVoltages[10]/1000%10+48;//cell11
         read_arr[223] = BatPack.CellVoltages[10]/100%10+48;
         read_arr[224] = BatPack.CellVoltages[10]/10%10+48;
         read_arr[225] = BatPack.CellVoltages[10]/1%10+48;

         read_arr[227] = BatPack.CellVoltages[11]/1000%10+48;//cell12
         read_arr[228] = BatPack.CellVoltages[11]/100%10+48;
         read_arr[229] = BatPack.CellVoltages[11]/10%10+48;
         read_arr[230] = BatPack.CellVoltages[11]/1%10+48;
		 
		 read_arr[227] = BatPack.CellVoltages[11]/1000%10+48;//cell12
         read_arr[228] = BatPack.CellVoltages[11]/100%10+48;
         read_arr[229] = BatPack.CellVoltages[11]/10%10+48;
         read_arr[230] = BatPack.CellVoltages[11]/1%10+48;
		 
		          read_arr[227] = BatPack.CellVoltages[11]/1000%10+48;//cell12
         read_arr[228] = BatPack.CellVoltages[11]/100%10+48;
         read_arr[229] = BatPack.CellVoltages[11]/10%10+48;
         read_arr[230] = BatPack.CellVoltages[11]/1%10+48;
		 //Temp 1
         read_arr[148] = BatPack.TempCell[0]/10%10+48;
         read_arr[149] = BatPack.TempCell[0]/1%10+48;
         //Temp 2
         read_arr[151] = BatPack.TempCell[0]/10%10+48;
         read_arr[152] = BatPack.TempCell[0]/1%10+48;
         //Temp 3
         read_arr[154] = BatPack.TempCell[0]/10%10+48;
         read_arr[155] = BatPack.TempCell[0]/1%10+48;
         //Temp 4
         read_arr[157] = BatPack.TempCell[0]/10%10+48;
         read_arr[158] = BatPack.TempCell[0]/1%10+48;
         //Temp 5
         read_arr[160] = BatPack.TempCell[0]/10%10+48;
         read_arr[161] = BatPack.TempCell[0]/1%10+48;
         //Temp 6
         read_arr[163] = BatPack.TempCell[0]/10%10+48;
         read_arr[164] = BatPack.TempCell[0]/1%10+48;
         //pcbTemp 7
         read_arr[166] = BatPack.TempCell[1]/10%10+48;
         read_arr[167] = BatPack.TempCell[1]/1%10+48;
         //ic Temp 8

         uint8_t tempic=0;
         tempic=BatPack.iCTemp/10;
         read_arr[169] = tempic/10%10+48;
         read_arr[170] = tempic/1%10+48;
    }
