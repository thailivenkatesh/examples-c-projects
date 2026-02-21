 unsigned char read_arr[] = "%0000000000000000000000000000000000000000000000000000000000000000,
 0,085,100,00000,*000,0000,25,25,25,3729,4082,4047,0353,56476,2900,4250,60,100,250,25,25,25,25,25,25,29,31,
 4001,4002,4003,4004,4005,4006,4007,4008,4009,4010,4011,4012,4013,4014,
4015,4016,4017,4018,4019,4020,4021,4022,4023,4024,4025,4026,4027,4028#\r\n";
 void Gui_read_arr(){
         uint8_t Power_On_Status=1;
        //Power On Status
         read_arr[66] = Power_On_Status+48;

         uint8_t Guisoc;
		 
         Guisoc=(uint8_t)BatPack.SOC;
         if(Guisoc>=100){
         read_arr[68] = Guisoc/100%10+48;
         read_arr[69] = Guisoc/10%10+48;
         read_arr[70] = Guisoc/1%10+48;
         }
         else{
             read_arr[68] = 48;
             read_arr[69] = Guisoc/10%10+48;
             read_arr[70] = Guisoc/1%10+48;
         }

        //soh
         read_arr[72] =  BatPack.SOH/100%10+48;
         read_arr[73] =  BatPack.SOH/10%10+48;
         read_arr[74] =  BatPack.SOH/1%10+48;

         //power

        uint16_t icur;
        uint32_t power;

        icur = BatPack.StackVoltage*BatPack.i32Current;
        power=(uint32_t)icur/1000;
        if(power>=10000){
        read_arr[76] = power/10000%10+48;
        read_arr[77] = power/1000%10+48;
        read_arr[78] = power/100%10+48;
        read_arr[79] = power/10%10+48;
        read_arr[80] = power/1%10+48;
        }
        else if ((power>=1000)&&(power<10000)){
        read_arr[76] = 48;
        read_arr[77] = power/1000%10+48;
        read_arr[78] = power/100%10+48;
        read_arr[79] = power/10%10+48;
        read_arr[80] = power/1%10+48;
      }
        else if ((power>=100)&&(power<1000)){
        read_arr[76] = 48;
        read_arr[77] = 48;
        read_arr[78] = power/100%10+48;
        read_arr[79] = power/10%10+48;
        read_arr[80] = power/1%10+48;
        }
        else{
        read_arr[76] = 48;
        read_arr[77] = 48;
        read_arr[78] = 48;
        read_arr[79] = power/10%10+48;
        read_arr[80] = power/1%10+48;
        }
    //Current (A) (*)Standby / (+)Charging / (-)Discharge//*000//81 82 83 84 85
    //Charge Cycle  0000//86 87 88 89 90

         //temp min
         uint8_t Temp_Min=0;
         read_arr[92] = Temp_Min/10%10+48;
         read_arr[93] = Temp_Min/1%10+48;
         //temp max
         uint8_t Temp_Max=48;
         read_arr[95] = Temp_Max/10%10+48;
         read_arr[96] = Temp_Max/1%10+48;
         //temp avg;
         uint8_t Temp_Avg=24;
         read_arr[98] = Temp_Avg/10%10+48;
         read_arr[99] = Temp_Avg/1%10+48;

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


         uint16_t Volt_Avg=0;
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
        read_arr[121] = StackVolt/10000%10+48;
        read_arr[122] = StackVolt/1000%10+48;
        read_arr[123] = StackVolt/100%10+48;
        read_arr[124] = StackVolt/10%10+48;
        read_arr[125] = StackVolt/1%10+48;

        //Min Volt Cutoff (SET VALUE)
         read_arr[127] =  (Batconfig.min_vol_cutoff)/1000%10+48;//
         read_arr[128] =  Batconfig.min_vol_cutoff/100%10+48;
         read_arr[129] =  Batconfig.min_vol_cutoff/10%10+48;
         read_arr[130] =  Batconfig.min_vol_cutoff/1%10+48;

         //Max Volt Cutoff (SET VALUE)
         read_arr[132] = (Batconfig.max_vol_cutoff)/1000%10+48;//
         read_arr[133] = Batconfig.max_vol_cutoff/100%10+48;
         read_arr[134] = Batconfig.max_vol_cutoff/10%10+48;
         read_arr[135] = Batconfig.max_vol_cutoff/1%10+48;

         //Max_Temp_Cut_Off (SET VALUE)//65

         read_arr[137] = Batconfig.max_temp_cutoff/10%10+48;
         read_arr[138] = Batconfig.max_temp_cutoff/1%10+48;

        // Charge_Current_Cut_Off (SET VALUE)//100

         read_arr[140] = Batconfig.chrg_cur_cutoff/100%10+48;
         read_arr[141] = Batconfig.chrg_cur_cutoff/10%10+48;
         read_arr[142] = Batconfig.chrg_cur_cutoff/1%10+48;

        // Discharge_Current_Cut_Off (SET VALUE)//100

         read_arr[144] = Batconfig.dchrg_cur_cutoff /100%10+48;
         read_arr[145] = Batconfig.dchrg_cur_cutoff /10%10+48;
         read_arr[146] = Batconfig.dchrg_cur_cutoff /1%10+48;

        //Temp 1
         read_arr[148] = BatPack.u16VoltCell[1][15]/10%10+48;
         read_arr[149] = BatPack.u16VoltCell[1][15]/1%10+48;
         //Temp 2
         read_arr[151] = BatPack.u16VoltCell[1][16]/10%10+48;
         read_arr[152] = BatPack.u16VoltCell[1][16]/1%10+48;
         //Temp 3
         read_arr[154] = BatPack.u16VoltCell[1][17]/10%10+48;
         read_arr[155] = BatPack.u16VoltCell[1][17]/1%10+48;
         //Temp 4
         read_arr[157] = BatPack.u16VoltCell[1][18]/10%10+48;
         read_arr[158] = BatPack.u16VoltCell[1][18]/1%10+48;
         //Temp 5
         read_arr[160] = BatPack.u16VoltCell[1][19]/10%10+48;
         read_arr[161] = BatPack.u16VoltCell[1][19]/1%10+48;
         //Temp 6
         read_arr[163] = BatPack.u16VoltCell[1][20]/10%10+48;
         read_arr[164] = BatPack.u16VoltCell[1][20]/1%10+48;
         //pcbTemp 7
         read_arr[166] = BatPack.u16VoltCell[1][21]/10%10+48;
         read_arr[167] = BatPack.u16VoltCell[1][21]/1%10+48;
         //ic Temp 8

         uint8_t tempic=0;
         tempic=BatPack.u16Temp[1]/10;
         read_arr[169] = BatPack.u16Temp[1]/10%10+48;
         read_arr[170] = BatPack.u16Temp[1]/1%10+48;

         read_arr[172] = BatPack.u16VoltCell[1][1]/1000%10+48;//cell1
         read_arr[173] = BatPack.u16VoltCell[1][1]/100%10+48;
         read_arr[174] = BatPack.u16VoltCell[1][1]/10%10+48;
         read_arr[175] = BatPack.u16VoltCell[1][1]/1%10+48;

         read_arr[177] = BatPack.u16VoltCell[1][2]/1000%10+48;//cell2
         read_arr[178] = BatPack.u16VoltCell[1][2]/100%10+48;
         read_arr[179] = BatPack.u16VoltCell[1][2]/10%10+48;
         read_arr[180] = BatPack.u16VoltCell[1][2]/1%10+48;

         read_arr[182] = BatPack.u16VoltCell[1][3]/1000%10+48;//cell3
         read_arr[183] = BatPack.u16VoltCell[1][3]/100%10+48;
         read_arr[184] = BatPack.u16VoltCell[1][3]/10%10+48;
         read_arr[185] = BatPack.u16VoltCell[1][3]/1%10+48;

         read_arr[187] = BatPack.u16VoltCell[1][4]/1000%10+48;//cell4
         read_arr[188] = BatPack.u16VoltCell[1][4]/100%10+48;
         read_arr[189] = BatPack.u16VoltCell[1][4]/10%10+48;
         read_arr[190] = BatPack.u16VoltCell[1][4]/1%10+48;

         read_arr[192] = BatPack.u16VoltCell[1][5]/1000%10+48;//cell5
         read_arr[193] = BatPack.u16VoltCell[1][5]/100%10+48;
         read_arr[194] = BatPack.u16VoltCell[1][5]/10%10+48;
         read_arr[195] = BatPack.u16VoltCell[1][5]/1%10+48;

         read_arr[197] = BatPack.u16VoltCell[1][6]/1000%10+48;//cell6
         read_arr[198] = BatPack.u16VoltCell[1][6]/100%10+48;
         read_arr[199] = BatPack.u16VoltCell[1][6]/10%10+48;
         read_arr[200] = BatPack.u16VoltCell[1][6]/1%10+48;

         read_arr[202] = BatPack.u16VoltCell[1][7]/1000%10+48;//cell7
         read_arr[203] = BatPack.u16VoltCell[1][7]/100%10+48;
         read_arr[204] = BatPack.u16VoltCell[1][7]/10%10+48;
         read_arr[205] = BatPack.u16VoltCell[1][7]/1%10+48;

         read_arr[207] = BatPack.u16VoltCell[1][8]/1000%10+48;//cell8
         read_arr[208] = BatPack.u16VoltCell[1][8]/100%10+48;
         read_arr[209] = BatPack.u16VoltCell[1][8]/10%10+48;
         read_arr[210] = BatPack.u16VoltCell[1][8]/1%10+48;

         read_arr[212] = BatPack.u16VoltCell[1][9]/1000%10+48;//cell9
         read_arr[213] = BatPack.u16VoltCell[1][9]/100%10+48;
         read_arr[214] = BatPack.u16VoltCell[1][9]/10%10+48;
         read_arr[215] = BatPack.u16VoltCell[1][9]/1%10+48;

         read_arr[217] = BatPack.u16VoltCell[1][10]/1000%10+48;//cell10
         read_arr[218] = BatPack.u16VoltCell[1][10]/100%10+48;
         read_arr[219] = BatPack.u16VoltCell[1][10]/10%10+48;
         read_arr[220] = BatPack.u16VoltCell[1][10]/1%10+48;

         read_arr[222] = BatPack.u16VoltCell[1][11]/1000%10+48;//cell11
         read_arr[223] = BatPack.u16VoltCell[1][11]/100%10+48;
         read_arr[224] = BatPack.u16VoltCell[1][11]/10%10+48;
         read_arr[225] = BatPack.u16VoltCell[1][11]/1%10+48;

         read_arr[227] = BatPack.u16VoltCell[1][12]/1000%10+48;//cell12
         read_arr[228] = BatPack.u16VoltCell[1][12]/100%10+48;
         read_arr[229] = BatPack.u16VoltCell[1][12]/10%10+48;
         read_arr[230] = BatPack.u16VoltCell[1][12]/1%10+48;
		 
		 
		 read_arr[232] = BatPack.u16VoltCell[1][13]/1000%10+48;//cell13
         read_arr[233] = BatPack.u16VoltCell[1][13]/100%10+48;
         read_arr[234] = BatPack.u16VoltCell[1][13]/10%10+48;
         read_arr[235] = BatPack.u16VoltCell[1][13]/1%10+48;

         read_arr[237] = BatPack.u16VoltCell[1][14]/1000%10+48;//cell14
         read_arr[238] = BatPack.u16VoltCell[1][14]/100%10+48;
         read_arr[239] = BatPack.u16VoltCell[1][14]/10%10+48;
         read_arr[240] = BatPack.u16VoltCell[1][14]/1%10+48;

		 
		 //SECOND Pack
		 
		 read_arr[242] = BatPack.u16VoltCell[2][1]/1000%10+48;//cell1
         read_arr[243] = BatPack.u16VoltCell[2][1]/100%10+48;
         read_arr[244] = BatPack.u16VoltCell[2][1]/10%10+48;
         read_arr[245] = BatPack.u16VoltCell[2][1]/1%10+48;

         read_arr[247] = BatPack.u16VoltCell[2][2]/1000%10+48;//cell2
         read_arr[248] = BatPack.u16VoltCell[2][2]/100%10+48;
         read_arr[249] = BatPack.u16VoltCell[2][2]/10%10+48;
         read_arr[250] = BatPack.u16VoltCell[2][2]/1%10+48;

         read_arr[252] = BatPack.u16VoltCell[2][3]/1000%10+48;//cell3
         read_arr[253] = BatPack.u16VoltCell[2][3]/100%10+48;
         read_arr[254] = BatPack.u16VoltCell[2][3]/10%10+48;
         read_arr[255] = BatPack.u16VoltCell[2][3]/1%10+48;

         read_arr[257] = BatPack.u16VoltCell[2][4]/1000%10+48;//cell4
         read_arr[258] = BatPack.u16VoltCell[2][4]/100%10+48;
         read_arr[259] = BatPack.u16VoltCell[2][4]/10%10+48;
         read_arr[260] = BatPack.u16VoltCell[2][4]/1%10+48;

         read_arr[262] = BatPack.u16VoltCell[2][5]/1000%10+48;//cell5
         read_arr[263] = BatPack.u16VoltCell[2][5]/100%10+48;
         read_arr[264] = BatPack.u16VoltCell[2][5]/10%10+48;
         read_arr[265] = BatPack.u16VoltCell[2][5]/1%10+48;

         read_arr[267] = BatPack.u16VoltCell[2][6]/1000%10+48;//cell6
         read_arr[268] = BatPack.u16VoltCell[2][6]/100%10+48;
         read_arr[269] = BatPack.u16VoltCell[2][6]/10%10+48;
         read_arr[270] = BatPack.u16VoltCell[2][6]/1%10+48;



         read_arr[272] = BatPack.u16VoltCell[2][7]/1000%10+48;//cell8
         read_arr[273] = BatPack.u16VoltCell[2][7]/100%10+48;
         read_arr[274] = BatPack.u16VoltCell[2][7]/10%10+48;
         read_arr[275] = BatPack.u16VoltCell[2][7]/1%10+48;

         read_arr[277] = BatPack.u16VoltCell[2][8]/1000%10+48;//cell9
         read_arr[278] = BatPack.u16VoltCell[2][8]/100%10+48;
         read_arr[279] = BatPack.u16VoltCell[2][8]/10%10+48;
         read_arr[280] = BatPack.u16VoltCell[2][8]/1%10+48;

         read_arr[282] = BatPack.u16VoltCell[2][9]/1000%10+48;//cell10
         read_arr[283] = BatPack.u16VoltCell[2][9]/100%10+48;
         read_arr[284] = BatPack.u16VoltCell[2][9]/10%10+48;
         read_arr[285] = BatPack.u16VoltCell[2][9]/1%10+48;

         read_arr[287] = BatPack.u16VoltCell[2][10]/1000%10+48;//cell11
         read_arr[288] = BatPack.u16VoltCell[2][10]/100%10+48;
         read_arr[289] = BatPack.u16VoltCell[2][10]/10%10+48;
         read_arr[290] = BatPack.u16VoltCell[2][10]/1%10+48;

         read_arr[292] = BatPack.u16VoltCell[2][11]/1000%10+48;//cell12
         read_arr[293] = BatPack.u16VoltCell[2][11]/100%10+48;
         read_arr[294] = BatPack.u16VoltCell[2][11]/10%10+48;
         read_arr[295] = BatPack.u16VoltCell[2][11]/1%10+48;
		 
		 
		 read_arr[297] = BatPack.u16VoltCell[2][12]/1000%10+48;//cell13
         read_arr[298] = BatPack.u16VoltCell[2][12]/100%10+48;
         read_arr[299] = BatPack.u16VoltCell[2][12]/10%10+48;
         read_arr[300] = BatPack.u16VoltCell[2][12]/1%10+48;

         read_arr[302] = BatPack.u16VoltCell[2][13]/1000%10+48;//cell14
         read_arr[303] = BatPack.u16VoltCell[2][13]/100%10+48;
         read_arr[304] = BatPack.u16VoltCell[2][13]/10%10+48;
         read_arr[305] = BatPack.u16VoltCell[2][13]/1%10+48;
    }
 void socBasedonCC() {

	uint32_t StackVoltage;
	int32_t Soc;

	StackVoltage = BatPack.StackVoltage;
	// Soc = bmsOCVmap(StackVoltage, 36800, 42200, 0, 100);  ///*34.8v - 12*2.9*//*43.8v*- 12*3.65*/

	Soc=getBatpackSOC(StackVoltage);


	EEPROM_read(EEPROM_READ,&SOC_Flag_Addr,&Rdsoc_set,1);
	Wrsoc_set =Rdsoc_set;
	//PRINTF("batSoc.soc_set:%d\r\n", Wrsoc_set);
	//Wrsoc_set=0;
  // EEPROM_write(EEPROM_WRITE,&SOC_Flag_Addr,Wrsoc_set);

	if(Wrsoc_set == 0)	{ //Initial
		actualSOC = (float) Soc; // %SOC
		Wrsoc_set = 1;
		BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		EEPROM_write(EEPROM_WRITE,&SOC_Flag_Addr,Wrsoc_set);
		BatPack.SOH=96;


	} else if(Wrsoc_set == 1) { // Updated

		BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		EEPROM_read(EEPROM_READ,&SOC_Addr0,&SOC_RdVal0,1);
		BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		EEPROM_read(EEPROM_READ,&SOC_Addr1,&SOC_Rdval1,1);
		BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		EEPROM_read(EEPROM_READ,&SOC_Addr2,&SOC_Rdval2,1);
		BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		EEPROM_read(EEPROM_READ,&SOC_Addr3,&SOC_Rdval3,1);
		actualSOC3 = (((SOC_Rdval3)<<24)+((SOC_Rdval2)<<16)+((SOC_Rdval1)<<8)+SOC_RdVal0);//higher byte +lower byte
		// PRINTF("actualSOC3 : %ld Ah\r\n", actualSOC3);
		actualSOC = (double)actualSOC3/10000000;
		// PRINTF("ACTUAL SOC   : %lf \r\n", actualSOC);
		// PRINTF("computedSOC  : %lf \r\n", computedSOC);


		uint16_t BatSOH;
		BCC_MCU_WaitMs(5);
		EEPROM_read(EEPROM_READ,&SOHAddr,&Rdsoh,1);
		BCC_MCU_WaitMs(5);
		EEPROM_read(EEPROM_READ,&SOHAddr1,&Rdsoh1,1);
		BatSOH = ((Rdsoh)<<8)+Rdsoh1;//higher byte +lower byte
		BatPack.SOH=(uint8_t)(BatSOH/10);
		if(BatPack.SOH>100)BatPack.SOH=100;


		//		 if(computedSOC==0)
		//		 actualSOC = (float) Soc;
		//		 else
		//		 actualSOC = computedSOC;


	}

	if(actualSOC < 0) actualSOC = 0;
	else if(actualSOC > 100)	actualSOC = 100; // Set the max boundaries
#if	PRNTDEBUG
	PRINTF("SOC :%lf\r\n", actualSOC);
#endif
	AhSOC = (actualSOC * Bat_Ah );	//100*6Ah
	batPackAh  = (AhSOC / 100 ); 	//600Ah/100
	//PRINTF("batPackAh : %.5f Ah\r\n", batPackAh);   //BYTE READ*/

	iavg = (float)((float)BatPack.s32CCCounter/(float)BMS_RSHUNT);//21600*0.6/12500=1.03
	//iavg=(iavg+0.000055);
	iavg /= 3600;//1.78/3600=0.00048

	acc1 = (acc1 + iavg);
#if	PRNTDEBUG
	PRINTF("Ah counter : %f Ah\r\n", acc1);
	PRINTF("iCurrent : %f Ah\r\n", iavg);
#endif

	batPackAh1 =  (batPackAh + iavg);//4ah+iavg
#if	PRNTDEBUG
	PRINTF("BatPack Ah :%f \r\n", batPackAh1);
#endif
	computedSOC = ((batPackAh1/Bat_Ah)*100);//in percentage
	BatPack.SOC = computedSOC; // For Printing


	tempSoc = (int32_t)(computedSOC* 10000000);
	// PRINTF("tempSoc :%d \r\n", tempSoc);
	SOC_WrVal0 = ((tempSoc&0xff)>>0);//lower byte
	EEPROM_write(EEPROM_WRITE,&SOC_Addr0,SOC_WrVal0);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	SOC_WrVal1 = (tempSoc & 0xff00)>>8;
	EEPROM_write(EEPROM_WRITE,&SOC_Addr1,SOC_WrVal1);    //higher byte
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	SOC_WrVal2 = (tempSoc & 0xff0000)>>16;
	EEPROM_write(EEPROM_WRITE,&SOC_Addr2,SOC_WrVal2);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	SOC_WrVal3 = (tempSoc & 0xff000000)>>24;
	EEPROM_write(EEPROM_WRITE,&SOC_Addr3,SOC_WrVal3);


}



 uint8_t chargerSense()
 {

	 uint32_t portEdata;
	 uint8_t chargerPin = 0;

	 portEdata = PINS_DRV_ReadPins(PTE); // Read the charge sense pin

#if	DEBUG
	    PRINTF("| CHARGER BAT SENSE\t - 0x%x\t\r\n", portEdata) ;
#endif
	 chargerPin = (portEdata & (1<<6) ? 1 : 0);

	 return chargerPin;


 }
void bms_config()//call from main function
{

	/*int val=69;
		EEPROM_write(EEPROM_WRITE,&WrAddr4,val);
		printf("WRITEWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\r\n");
		PRINTF("write value:%d\r\n",val);*/
	Batconfig.min_vol_cutoff=((set_arr[1]-48)*1000)+((set_arr[2]-48)*100)+((set_arr[3]-48)*10)+((set_arr[4]-48)*1);
	Batconfig.max_vol_cutoff=((set_arr[5]-48)*1000)+((set_arr[6]-48)*100)+((set_arr[7]-48)*10)+((set_arr[8]-48)*1);
	Batconfig.max_temp_cutoff=((set_arr[9]-48)*10)+((set_arr[10]-48)*1);
	Batconfig.chrg_cur_cutoff=((set_arr[11]-48)*100)+((set_arr[12]-48)*10)+((set_arr[13]-48)*1);
	Batconfig.dchrg_cur_cutoff=((set_arr[14]-48)*100)+((set_arr[15]-48)*10)+((set_arr[16]-48)*1);
	Batconfig.CB=((set_arr[17]-48)*1000)+((set_arr[18]-48)*100)+((set_arr[19]-48)*10)+((set_arr[20]-48)*1);
//			Batconfig.min_vol_cutoff=2900;
//			Batconfig.max_vol_cutoff=3640;
//			Batconfig.max_temp_cutoff=65;
//			Batconfig.chrg_cur_cutoff=100;
//			Batconfig.dchrg_cur_cutoff=200;
//			Batconfig.CB=3630;

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

	tempCB = Batconfig.CB;//Batconfig.min_vol_cutoff
	CB_WrVal0 = tempCB &0xff;//lower byte
	EEPROM_write(EEPROM_WRITE,&CB_Addr0,CB_WrVal0);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	CB_WrVal1 = (tempCB &0xff00)>>8;
	EEPROM_write(EEPROM_WRITE,&CB_Addr1,CB_WrVal1);
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);

}
void  bmsconfigread(){

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
	Batconfig.CB= ((CB_RdVal1)<<8)+CB_RdVal0;//higher byte +lower byte

#if	PRNTDEBUG
	PRINTF("\r\nBatconfig.min_vol_cutoff : %d\r\n",Batconfig.min_vol_cutoff);
	PRINTF("\r\nBatconfig.max_vol_cutoff : %d\r\n",Batconfig.max_vol_cutoff);
	PRINTF("\r\n Batconfig.max_temp_cutoff : %d\r\n", Batconfig.max_temp_cutoff);
	PRINTF("\r\nBatconfig.chrg_cur_cutoff : %d\r\n",Batconfig.chrg_cur_cutoff);
	PRINTF("\r\nBatconfig.dchrg_cur_cutoff : %d\r\n",Batconfig.dchrg_cur_cutoff);
	PRINTF("\r\nBatconfig.CB : %d\r\n",Batconfig.CB);
#endif
	// }
}