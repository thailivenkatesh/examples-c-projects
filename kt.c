/*
 * features.c
 *
 *  Created on: 19-Jan-2022*/


//calculating open circuit voltage
int32_t getBatpackSOC(uint32_t Stackvoltage){


	if(Stackvoltage <= 36105) {
	 		return 0;
	 	} else if(Stackvoltage > 36105 && Stackvoltage <= 37082) {
	 		return 1;
	 	} else if(Stackvoltage > 37082 && Stackvoltage <= 37785) {
	 		return 2;
	 	} else if(Stackvoltage > 37785 && Stackvoltage <= 38308) {
	 		return 3;
	 	} else if(Stackvoltage > 38308 && Stackvoltage <= 38725) {
	 		return 4;
	 	} else if(Stackvoltage > 38725 && Stackvoltage <= 38976) {
	 		return 5;
	 	} else if(Stackvoltage > 38976 && Stackvoltage <= 39086) {
	 		return 6;
	 	} else if(Stackvoltage > 39086 && Stackvoltage <= 39113) {
	 		return 7;
	 	} else if(Stackvoltage > 39113 && Stackvoltage <= 39145) {
	 		return 8;
	 	} else if(Stackvoltage > 39145 && Stackvoltage <= 39157) {
	 		return 9;
	 	} else if(Stackvoltage > 39157 && Stackvoltage <= 39191) {
	 		return 10;
	 	} else if(Stackvoltage > 39191 && Stackvoltage <= 39228) {
	 		return 11;
	 	} else if(Stackvoltage > 39228 && Stackvoltage <= 39267) {
	 		return 12;
	 	} else if(Stackvoltage > 39267 && Stackvoltage <= 39330) {
	 		return 13;
	 	} else if(Stackvoltage > 39330 && Stackvoltage <= 39384) {
	 		return 14;
	 	} else if(Stackvoltage > 39384 && Stackvoltage <= 39455) {
	 		return 15;
	 	} else if(Stackvoltage > 39455 && Stackvoltage <= 39518) {
	 		return 16;
	 	} else if(Stackvoltage > 39518 && Stackvoltage <= 39592) {
	 		return 17;
	 	}
		 else if(Stackvoltage > 39592 && Stackvoltage <= 39658) {
	 		return 18;
	 	} else if(Stackvoltage > 39658 && Stackvoltage <= 39714) {
	 		return 19;
	 	} else if(Stackvoltage > 39714 && Stackvoltage <= 39765) {
	 		return 20;
	 	} else if(Stackvoltage > 39765 && Stackvoltage <= 39814) {
	 		return 21;
	 	} else if(Stackvoltage > 39814 && Stackvoltage <= 39870) {
	 		return 22;
	 	} else if(Stackvoltage > 39870 && Stackvoltage <= 3919) {
	 		return 23;
	 	} else if(Stackvoltage > 39919 && Stackvoltage <= 39951) {
	 		return 24;
	 	} else if(Stackvoltage > 39951 && Stackvoltage <= 39997) {
	 		return 25;
	 	} else if(Stackvoltage > 39997 && Stackvoltage <= 40014) {
	 		return 26;
	 	} else if(Stackvoltage > 40014 && Stackvoltage <= 40038) {
	 		return 27;
	 	} else if(Stackvoltage > 40038 && Stackvoltage <= 40058) {
	 		return 28;
	 	} else if(Stackvoltage > 40058 && Stackvoltage <= 40068) {
	 		return 29;
	 	} else if(Stackvoltage > 40068 && Stackvoltage <= 40075) {
	 		return 30;
	 	} else if(Stackvoltage > 40075 && Stackvoltage <= 40092) {
	 		return 31;
	 	} else if(Stackvoltage > 40092 && Stackvoltage <= 40097) {
	 		return 32;
	 	} else if(Stackvoltage > 40097 && Stackvoltage <= 40102) {
	 		return 33;
	 	} else if(Stackvoltage > 40102 && Stackvoltage <= 40104) {
	 		return 34;
	 	}
			 else if(Stackvoltage > 40104 && Stackvoltage <= 40108) {
	 		return 35;
	 	} else if(Stackvoltage > 40108 && Stackvoltage <= 40112) {
	 		return 36;
	 	} else if(Stackvoltage > 40112 && Stackvoltage <= 40114) {
	 		return 37;
	 	} else if(Stackvoltage > 40114 && Stackvoltage <= 40119) {
	 		return 38;
	 	} else if(Stackvoltage > 40119 && Stackvoltage <= 40124) {
	 		return 39;
	 	} else if(Stackvoltage > 40124 && Stackvoltage <= 40131) {
	 		return 41;
	 	} else if(Stackvoltage > 40131 && Stackvoltage <= 40134) {
	 		return 42;
	 	} else if(Stackvoltage > 40134 && Stackvoltage <= 40136) {
	 		return 43;
	 	} else if(Stackvoltage > 40136 && Stackvoltage <= 40141) {
	 		return 44;
	 	} else if(Stackvoltage > 40141 && Stackvoltage <= 40151) {
	 		return 45;
	 	} else if(Stackvoltage > 40151 && Stackvoltage <= 40158) {
	 		return 46;
	 	} else if(Stackvoltage > 40158 && Stackvoltage <= 40165) {
	 		return 95;
	 	} else if(Stackvoltage > 40165 && Stackvoltage <= 40170) {
	 		return 47;
	 	} else if(Stackvoltage > 40170 && Stackvoltage <= 40175) {
	 		return 48;
	 	} else if(Stackvoltage > 40175 && Stackvoltage <= 40185) {
	 		return 49;
	 	} else if(Stackvoltage > 40185 && Stackvoltage <= 40192) {
	 		return 50;
	 	} else if(Stackvoltage > 40192 && Stackvoltage <= 40200) {
	 		return 51;
	 	}
		else if(Stackvoltage > 40200 && Stackvoltage <= 40214) {
	 		return 52;
	 	} else if(Stackvoltage > 40214 && Stackvoltage <= 40224) {
	 		return 53;
	 	} else if(Stackvoltage > 40224 && Stackvoltage <= 40236) {
	 		return 54;
	 	} else if(Stackvoltage > 40236 && Stackvoltage <= 40256) {
	 		return 55;
	 	} else if(Stackvoltage > 40256 && Stackvoltage <= 40268) {
	 		return 56;
	 	} else if(Stackvoltage > 40268 && Stackvoltage <= 40287) {
	 		return 57;
	 	} else if(Stackvoltage > 40287 && Stackvoltage <= 40309) {
	 		return 58;
	 	} else if(Stackvoltage > 40309 && Stackvoltage <= 40344) {
	 		return 59;
	 	} else if(Stackvoltage > 40344 && Stackvoltage <= 40373) {
	 		return 60;
	 	} else if(Stackvoltage > 40373 && Stackvoltage <= 40405) {
	 		return 61;
	 	} else if(Stackvoltage > 40405 && Stackvoltage <= 40439) {
	 		return 62;
	 	} else if(Stackvoltage > 40439 && Stackvoltage <= 40468) {
	 		return 63;
	 	} else if(Stackvoltage > 40468 && Stackvoltage <= 40502) {
	 		return 64;
	 	} else if(Stackvoltage > 40502 && Stackvoltage <= 40522) {
	 		return 65;
	 	} else if(Stackvoltage > 40522 && Stackvoltage <= 40534) {
	 		return 66;
	 	} else if(Stackvoltage > 40534 && Stackvoltage <= 40551) {
	 		return 67;
	 	} else if(Stackvoltage > 40551 && Stackvoltage <= 40561) {
	 		return 68;
	 	}

		 else if(Stackvoltage > 40561 && Stackvoltage <= 40576) {
	 		return 69;
	 	} else if(Stackvoltage > 40576 && Stackvoltage <= 40580) {
	 		return 70;
	 	} else if(Stackvoltage > 40580 && Stackvoltage <= 40583) {
	 		return 71;
	 	} else if(Stackvoltage > 40583 && Stackvoltage <= 40593) {
	 		return 72;
	 	} else if(Stackvoltage > 40593 && Stackvoltage <= 40612) {
	 		return 73;
	 	} else if(Stackvoltage > 40612 && Stackvoltage <= 40620) {
	 		return 74;
	 	} else if(Stackvoltage > 40620 && Stackvoltage <= 40624) {
	 		return 75;
	 	} else if(Stackvoltage > 40624 && Stackvoltage <= 40637) {
	 		return 76;
	 	} else if(Stackvoltage > 40637 && Stackvoltage <= 40644) {
	 		return 77;
	 	} else if(Stackvoltage > 40644 && Stackvoltage <= 40654) {
	 		return 78;
	 	} else if(Stackvoltage > 40654 && Stackvoltage <= 40671) {
	 		return 79;
	 	} else if(Stackvoltage > 40671 && Stackvoltage <= 40676) {
	 		return 80;
	 	} else if(Stackvoltage > 40676 && Stackvoltage <= 40685) {
	 		return 81;
	 	} else if(Stackvoltage > 40685 && Stackvoltage <= 40703) {
	 		return 82;
	 	} else if(Stackvoltage > 40703 && Stackvoltage <= 40715) {
	 		return 83;
	 	} else if(Stackvoltage > 40715 && Stackvoltage <= 40732) {
	 		return 84;
	 	} else if(Stackvoltage > 40732 && Stackvoltage <= 40751) {
	 		return 85;
	 	}

		 else if(Stackvoltage > 40751 && Stackvoltage <= 40773) {
	 		return 86;
	 	} else if(Stackvoltage > 40773 && Stackvoltage <= 40798) {
	 		return 87;
	 	} else if(Stackvoltage > 40798 && Stackvoltage <= 40837) {
	 		return 88;
	 	} else if(Stackvoltage > 40837 && Stackvoltage <= 40886) {
	 		return 89;
	 	} else if(Stackvoltage > 40886 && Stackvoltage <= 40959) {
	 		return 90;
	 	} else if(Stackvoltage > 40959 && Stackvoltage <= 41091) {
	 		return 91;
	 	} else if(Stackvoltage > 41091 && Stackvoltage <= 41359) {
	 		return 92;
	 	} else if(Stackvoltage > 41359 && Stackvoltage <= 42468) {
	 		return 93;
	 	} else if(Stackvoltage > 42468 && Stackvoltage <= 42719) {
	 		return 94;
	 	} else if(Stackvoltage > 42719 && Stackvoltage <= 42919) {
	 		return 95;
	 	} else if(Stackvoltage > 42919 && Stackvoltage <= 43106) {
	 		return 96;
	 	} else if(Stackvoltage > 43106 && Stackvoltage <= 43325) {
	 		return 97;
	 	} else if(Stackvoltage > 43325 && Stackvoltage <= 43500) {
	 		return 98;
	 	} else if(Stackvoltage > 43500 && Stackvoltage <= 43650) {
	 		return 99;
	 	} else if(Stackvoltage > 43650 && Stackvoltage <= 43800) {
	 		return 100;
	 	}

 	return 0;

 }


/* steps for calculating the SOC based on Coulomb Count */
1.calculating soc using ocv
 convert ocv to ah( batPackAh)
 batPackAh=(percentage/100)*6AH;
 this ocv is calculated only once
2.read cc raw values multiply by vres(0.6).
21600*0.6=~12600
3.read ccsamples.
4.BatPack.s32CCCounter=ccraw/ccsamples. 
5.calculate iavg which is required ah inflow or outflow from batpack.
6.BMS_RSHUNT=12500
7. calculating iavg = (float)((float)BatPack.s32CCCounter/(float)BMS_RSHUNT).//12600/12500=1.03
iavg /= 3600;//1.08/3600=0.00029
8.this is the value added to bat ah for every second.
9.batPackAh =  (batPackAh + iavg);//4ah+iavg
10.store updated value in EEPROM.
11.read EEPROM values updated soc every time using Wrsoc_set flag.
 if Wrsoc_set=0 read ocv read only once initially. 
 if Wrsoc_set=1 read updated soc every time.  
12.repeat the process from step 2 to step 11.
 


 

void socBasedonCC() {

	uint32_t StackVoltage;
	int32_t Soc;

	StackVoltage = BatPack.StackVoltage;
	

	Soc=getBatpackSOC(StackVoltage);//ocv


	EEPROM_read(EEPROM_READ,&SOC_Flag_Addr,&Rdsoc_set,1);
	Wrsoc_set =Rdsoc_set;


	if(Wrsoc_set == 0)	{ //Initial
		actualSOC = (float) Soc; // %SOC
		Wrsoc_set = 1;
		BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		EEPROM_write(EEPROM_WRITE,&SOC_Flag_Addr,Wrsoc_set);
		BatPack.SOH=96;


	} else if(Wrsoc_set == 1) { // Updated soc

		BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		EEPROM_read(EEPROM_READ,&SOC_Addr0,&SOC_RdVal0,1);
		BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		EEPROM_read(EEPROM_READ,&SOC_Addr1,&SOC_Rdval1,1);
		BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		EEPROM_read(EEPROM_READ,&SOC_Addr2,&SOC_Rdval2,1);
		BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		EEPROM_read(EEPROM_READ,&SOC_Addr3,&SOC_Rdval3,1);
		actualSOC3 = (((SOC_Rdval3)<<24)+((SOC_Rdval2)<<16)+((SOC_Rdval1)<<8)+SOC_RdVal0);//read eeprom
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

	iavg = (float)((float)BatPack.s32CCCounter/(float)BMS_RSHUNT);//21600/12500=1.78
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

//steps for storing bat config set values
1.send the command  as $2900,3650,65,100,100,3630 docklight/hyperterminal.
2.data received in LPUART2 in ASCII format.
3.convert this ascii values to integer by subtracting 48 from all data received.
4.mask data and copy to corresponding values. 
min_vol_cutoff=2900;
max_vol_cutoff=3640;
max_temp_cutoff=65;
chrg_cur_cutoff=100;
dchrg_cur_cutoff=200;
CB=3630;
5.write  in EEPROM
6.Read from EEPROM in bootup.


void bms_config()//call from main function
{

	
	PRINTF("write value:%d\r\n",val);
	Batconfig.min_vol_cutoff=((set_arr[1]-48)*1000)+((set_arr[2]-48)*100)+((set_arr[3]-48)*10)+((set_arr[4]-48)*1);
	Batconfig.max_vol_cutoff=((set_arr[5]-48)*1000)+((set_arr[6]-48)*100)+((set_arr[7]-48)*10)+((set_arr[8]-48)*1);
	Batconfig.max_temp_cutoff=((set_arr[9]-48)*10)+((set_arr[10]-48)*1);
	Batconfig.chrg_cur_cutoff=((set_arr[11]-48)*100)+((set_arr[12]-48)*10)+((set_arr[13]-48)*1);
	Batconfig.dchrg_cur_cutoff=((set_arr[14]-48)*100)+((set_arr[15]-48)*10)+((set_arr[16]-48)*1);
	Batconfig.CB=((set_arr[17]-48)*1000)+((set_arr[18]-48)*100)+((set_arr[19]-48)*10)+((set_arr[20]-48)*1);


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
//convering read_arr values to Ascii to send to lpuart
//steps for conveting values to ascii
1.convert values to ASCII. 
2. copy to read_arr buffer.
3.send S000000000000000000000.
4.convert Gui_read_arr() to ascii values.
4.send to LPUART2.
5.data is sent every one second.

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
        read_arr[121] = BatPack.StackVoltage/10000%10+48;
        read_arr[122] = BatPack.StackVoltage/1000%10+48;
        read_arr[123] = BatPack.StackVoltage/100%10+48;
        read_arr[124] = BatPack.StackVoltage/10%10+48;
        read_arr[125] = BatPack.StackVoltage/1%10+48;


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
         read_arr[166] = BatPack.TempCell[0]/10%10+48;
         read_arr[167] = BatPack.TempCell[0]/1%10+48;
         //ic Temp 8

         uint8_t tempic=0;
         tempic=BatPack.iCTemp/10;
         read_arr[169] = tempic/10%10+48;
         read_arr[170] = tempic/1%10+48;

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
    }

//steps for power modes
1.call bmsconfigsleep function enters CPU to STOP1 mode. 
2.press any key to wake from the stop mode.
3.call sysyem reset.
void bmsconfigsleep(){
	 /* Variable used for storing user option */
	    uint8_t option,Exitloop = 0;
	    /* Variable used for storing core frequency */
	    uint32_t frequency;
	    /* Variable used for status of changing mode */
	    status_t retV = STATUS_SUCCESS;
	    /* Buffer for sprintf operations */
	    bcc_status_t bccError;
	    char buffer[20];

	 /*Board EVB - red led off
	      Board MB - led 0 off */
	    PINS_DRV_WritePin(LED_PORT, LED_0, 1);
	    /*Board EVB - green led on
	      Board MB - led 1 on */
	    PINS_DRV_WritePin(LED_PORT, LED_1, 0);

		print((const char*)"******** CPU is going in STOP1...\r\n");
		/*Board EVB - red led on
		Board MB - led 0 on */
		PINS_DRV_WritePin(LED_PORT, LED_0, 0);
		/*Board EVB - green led off
		Board MB - led 1 off */
		PINS_DRV_WritePin(LED_PORT, LED_1, 1);
		/* Set power mode to STOP1 */
		retV = POWER_SYS_SetMode(STOP1, POWER_MANAGER_POLICY_AGREEMENT);
		if (retV == STATUS_SUCCESS){
			print((const char*)"CPU was entered STOP1 mode successfully and then woke up to exit STOP1 mode.\r\n");
			print((const char*)"Current mode is RUN.\r\n");
			}
		else{
			print((const char*)"Switch STOP1 mode unsuccessfully\r\n");
			}
		SystemSoftwareReset();
}

//ble
The code is added at 'BleApp_ReceivedUartStream'.
1.Input '#' and after this char, it is your device name from IOT tool box.
2.For example, '#cdas999', the adv name will become 'cdas999'. 
3.the device name should be 8 byte. This is due the limit of adv packet length.
4.write adv name into memory. 
5.When you send the new device name to mcu, you firstly write it into memory.
6.then make mcu disconnect from the phone using 'Gap_Disconnect'. 
7.Read the adv structure from the memory. 
8.Use 'Gap_SetAdvertisingData' to set the adv data. 
9.Use 'App_StartAdvertising' to start the adv again.
10.system reset. 
11.device name scan in NXP app.

    /* Read and update the DevSerial number from App*/

    uint32_t strLen = FLib_StrLen((char *) pStream);
    uint8_t tempset[8];

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

    	FLib_MemSet(&tempset,'0',sizeof(tempset));
    	 FLib_MemCpy(tempset,(sDeviceInfo*)devieInfo.deviceName,sizeof(devieInfo.deviceName));

    	uint32_t strLen1 = FLib_StrLen(tempset);
    	NV_FlashEraseSector(&gHardwareParameters.devserialnum, sizeof(gHardwareParameters.devserialnum));
    	NV_FlashEraseSector(&gHardwareParameters.len, sizeof(gHardwareParameters.len));

    	FLib_MemCpy(gHardwareParameters.devserialnum,devieInfo.deviceName,strLen1);
		gHardwareParameters.devidset = 0;
		//gHardwareParameters.len=strLen;
		//(void)NV_WriteHWParameters(&gHardwareParameters);
		gAppAdvertisingData.aAdStructures[2].aData=gHardwareParameters.devserialnum;
			//gAppAdvertisingData.aAdStructures[2].aData=gHardwareParameters.devserialnum;
    	// length of name, and the type also occupy 1 byte
    	gAppAdvertisingData.aAdStructures[2].length = FLib_StrLen( (char *) gAppAdvertisingData.aAdStructures[2].aData) + 1;
    	gHardwareParameters.len=strLen1;
    	gHardwareParameters.len1=strLen;
    	gHardwareParameters.len11=gAppAdvertisingData.aAdStructures[2].length;

    	(void)NV_WriteHWParameters(&gHardwareParameters);
    	(void)Gap_SetAdvertisingData(&gAppAdvertisingData, &gAppScanRspData);
    	App_StartAdvertising(BleApp_AdvertisingCallback, BleApp_ConnectionCallback);
    	NVIC_SystemReset();
    }
    /*End*/
	
	
		if(u8Daughter > 15)
			return;
		//StackVoltage & CellVoltage & Temperature
	    //stack cell1  cell2  cell3//0X01 cid1
	   //stack cell1  cell2  cell3//0X07  cid2
			FCData[0] = BatPack.u16VoltCell[u8Daughter][0];
			FCData[1] = BatPack.u16VoltCell[u8Daughter][1];
			FCData[2] = BatPack.u16VoltCell[u8Daughter][2];
			FCData[3] = BatPack.u16VoltCell[u8Daughter][3];

			flexcan_senddata[0] = (FCData[0]>>8)&0xFF;
			flexcan_senddata[1] = (FCData[0]>>0)&0xFF;
			flexcan_senddata[2] = (FCData[1]>>8)&0xFF;
			flexcan_senddata[3] = (FCData[1]>>0)&0xFF;
			flexcan_senddata[4] = (FCData[2]>>8)&0xFF;
			flexcan_senddata[5] = (FCData[2]>>0)&0xFF;
			flexcan_senddata[6] = (FCData[3]>>8)&0xFF;
			flexcan_senddata[7] = (FCData[3]>>0)&0xFF;

			Delayus(500);

			if(u8Daughter == 1)
			SendCANData(0X01, flexcan_senddata);
			else{
				SendCANData(0x07 , flexcan_senddata);
			}

			//cell4 cell5  cell6  cell 7//0X02 cid1
			//cell4 cell5  cell6  cell 7//0X08  cid2
			FCData[0] = BatPack.u16VoltCell[u8Daughter][4];
			FCData[1] = BatPack.u16VoltCell[u8Daughter][5];
			FCData[2] = BatPack.u16VoltCell[u8Daughter][6];
			FCData[3] = BatPack.u16VoltCell[u8Daughter][7];

			flexcan_senddata[0] = (FCData[0]>>8)&0xFF;
			flexcan_senddata[1] = (FCData[0]>>0)&0xFF;
			flexcan_senddata[2] = (FCData[1]>>8)&0xFF;
			flexcan_senddata[3] = (FCData[1]>>0)&0xFF;
			flexcan_senddata[4] = (FCData[2]>>8)&0xFF;
			flexcan_senddata[5] = (FCData[2]>>0)&0xFF;
			flexcan_senddata[6] = (FCData[3]>>8)&0xFF;
			flexcan_senddata[7] = (FCData[3]>>0)&0xFF;

			Delayus(500);

			if(u8Daughter == 1)
			SendCANData(0x02, flexcan_senddata);//0X01 T0 0X025
			else{
				SendCANData(0x08, flexcan_senddata);//0X01 T0 0X025
			}
			//cell8 cell9 cell10 cell11//0X03 cid1
			//cell8 cell9 cell10 cell11//0X09 cid2
			FCData[0] = BatPack.u16VoltCell[u8Daughter][8];
			FCData[1] = BatPack.u16VoltCell[u8Daughter][9];
			FCData[2] = BatPack.u16VoltCell[u8Daughter][10];
			FCData[3] = BatPack.u16VoltCell[u8Daughter][11];

			flexcan_senddata[0] = (FCData[0]>>8)&0xFF;
			flexcan_senddata[1] = (FCData[0]>>0)&0xFF;
			flexcan_senddata[2] = (FCData[1]>>8)&0xFF;
			flexcan_senddata[3] = (FCData[1]>>0)&0xFF;
			flexcan_senddata[4] = (FCData[2]>>8)&0xFF;
			flexcan_senddata[5] = (FCData[2]>>0)&0xFF;
			flexcan_senddata[6] = (FCData[3]>>8)&0xFF;
			flexcan_senddata[7] = (FCData[3]>>0)&0xFF;

			Delayus(500);

			if(u8Daughter == 1)
			SendCANData(0x03 , flexcan_senddata);
			else{
				SendCANData(0x09 , flexcan_senddata);
			}
			//cell2 cell13 cell14 AN1 cid1 0x04
			//cell2 cell13 cell14 cid2 0x10
			FCData[0] = BatPack.u16VoltCell[u8Daughter][12];
			FCData[1] = BatPack.u16VoltCell[u8Daughter][13];
			FCData[2] = BatPack.u16VoltCell[u8Daughter][14];
			flexcan_senddata[0] = (FCData[0]>>8)&0xFF;
			flexcan_senddata[1] = (FCData[0]>>0)&0xFF;
			flexcan_senddata[2] = (FCData[1]>>8)&0xFF;
			flexcan_senddata[3] = (FCData[1]>>0)&0xFF;
			flexcan_senddata[4] = (FCData[2]>>8)&0xFF;
			flexcan_senddata[5] = (FCData[2]>>0)&0xFF;

			if(u8Daughter==1)
			{
			FCData[3] = BatPack.u16VoltCell[u8Daughter][15];
			flexcan_senddata[6] = (FCData[3]>>8)&0xFF;
			flexcan_senddata[7] = (FCData[3]>>0)&0xFF;
			}
			else{
				flexcan_senddata[6] = 0;
				flexcan_senddata[7] = 0;
			}

			Delayus(500);

			if(u8Daughter == 1)
			SendCANData(0X04 , flexcan_senddata);//0X01 T0 0X025
			else{
				SendCANData(0x10, flexcan_senddata);//0X01 T0 0X025
			}
			//AN2   AN3    AN4    AN5 cid1 0x05
			if(u8Daughter == 1){
			FCData[0] = BatPack.u16VoltCell[u8Daughter][16];
			FCData[1] = BatPack.u16VoltCell[u8Daughter][17];
			FCData[2] = BatPack.u16VoltCell[u8Daughter][18];
			FCData[3] = BatPack.u16VoltCell[u8Daughter][19];

			flexcan_senddata[0] = (FCData[0]>>8)&0xFF;
			flexcan_senddata[1] = (FCData[0]>>0)&0xFF;
			flexcan_senddata[2] = (FCData[1]>>8)&0xFF;
			flexcan_senddata[3] = (FCData[1]>>0)&0xFF;
			flexcan_senddata[4] = (FCData[2]>>8)&0xFF;
			flexcan_senddata[5] = (FCData[2]>>0)&0xFF;
			flexcan_senddata[6] = (FCData[3]>>8)&0xFF;
			flexcan_senddata[7] = (FCData[3]>>0)&0xFF;

			Delayus(500);
			SendCANData(0x05, flexcan_senddata);

			//AN6   AN7 0x06 cid1
			    FCData[0] = BatPack.u16VoltCell[u8Daughter][20];
				FCData[1] = BatPack.u16VoltCell[u8Daughter][21];


				flexcan_senddata[0] = (FCData[0]>>8)&0xFF;
				flexcan_senddata[1] = (FCData[0]>>0)&0xFF;
				flexcan_senddata[2] = (FCData[1]>>8)&0xFF;
				flexcan_senddata[3] = (FCData[1]>>0)&0xFF;
				flexcan_senddata[4] = 0;
				flexcan_senddata[5] = 0;
				flexcan_senddata[6] = 0;
				flexcan_senddata[7] = 0;


				Delayus(500);
				SendCANData(0x06, flexcan_senddata);//0X01 T0 0X025

		//Current cid1
		FCData[0] = (BatPack.i32Current[1] >> 16)& 0xFFFF;
		FCData[1] = BatPack.i32Current[1] & 0xFFFF;

		flexcan_senddata[0] = (FCData[0]>>8)&0xFF;
		flexcan_senddata[1] = (FCData[0]>>0)&0xFF;
		flexcan_senddata[2] = (FCData[1]>>8)&0xFF;
		flexcan_senddata[3] = (FCData[1]>>0)&0xFF;
		flexcan_senddata[4] = (FCData[2]>>8)&0xFF;
		flexcan_senddata[5] = (FCData[2]>>0)&0xFF;
		flexcan_senddata[6] = (FCData[3]>>8)&0xFF;

		Delayus(500);
		SendCANData(0x07, flexcan_senddata);
	}
	Delayus(500);
}
2AFE CAN IDENTIFIERS
TX_MailBox 0X08
DLC 8
EXT ID
0x01  STACK CELL1 CELL2 CELL3 
0X02  CELL4 CELL5 CELL6 CELL7
0X03  CELL8 CELL9 CELL10 CELL11
0X04  CELL12 CELL13 CELL14 AN1
0X05  AN2 AN3 AN4 AN5
0X06  AN6 AN7 
0X07  ISENSE
0x08  CELL1 CELL2 CELL3 CELL4
0X09  CELL5 CELL6 CELL7 CELL8
0X10  CELL9 CELL10 CELL11 CELL12
0X11  CELL13 CELL14 


36V BMS CAN IDENTIFIERS