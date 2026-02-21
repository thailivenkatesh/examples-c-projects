uint8_t  Wrchrg_set = 0;
uint8_t Wrchrg_set_flag;
uint8_t  Rdchrg_set;
uint16_t CHRG_Flag_Addr= 0x0022;


	if(((chargerSense()!=0)&&(Wrchrg_set==1))||((chargerSense()!=0)&&(Wrchrg_set_flag==1))){
	Wrchrg_set=0;
	if(Wrchrg_set_flag==1)
	Wrchrg_set_flag=0;
	}
	
	main(){
	EEPROM_read(EEPROM_READ,&CHRG_Flag_Addr,&Rdchrg_set,1);
	if(Rdchrg_set > 1)Rdchrg_set = 0;
	Wrchrg_set_flag = Rdchrg_set;
	}


	Wrchrg_set = 1;
	cutoff controls(){
	Wrchrg_set = 1;
	Wrchrg_set_flag=Wrchrg_set;
	BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
	EEPROM_write(EEPROM_WRITE,&CHRG_Flag_Addr,Wrchrg_set_flag);
	}



	if((chargerSense()!=0)&&(Wrchrg_set_flag==1)){
	Wrchrg_set_flag=0;
	}

	if(((chargerSense()==0)&& (Wrchrg_set==0))||((chargerSense()==0)&& (Wrchrg_set_flag==0))){

	//PRINTF("CHARGER Connected...\r\n");
	/* Set Charge & Discharge MOSFETS */
	PINS_DRV_SetPins(CHARGE_MOSFET_INSTANCE, 1U << CHARGE_MOSFET_PIN);
	PINS_DRV_SetPins(DISCHARGE_MOSFET_INSTANCE, 1U << DISCHARGE_MOSFET_PIN);

	}

