#include<stdio.h>
#include<string.h>
char u8PktBuf[31];
#define MAXBYTES 31
#define int16_t int
typedef struct {

	int16_t min_vol_cutoff;//2
	int16_t max_vol_cutoff;//2
	int16_t max_temp_cutoff;//2
	int16_t charge_current_cutoff;//2
	int16_t dicharge_current_cutoff;//2
	int16_t CB;
	int16_t charge;
	int16_t discharge;
	//float   initial_Soc;//4

}Batteryconfig;

unsigned int read_arr[14] ={3573,2288,3573,2813,3410,3563,3566,3564,3573,3566,3363,3218,3695,3497};
char *Itoa (char *dst, long long val, int digits)
{
	char *p_str = dst;
	int u, tmp;
	long sign, i;
	char hex = 0;

	/*******************************************************************
      format:
        hex: add leading 0x
 		dec: add leading sign
	 *******************************************************************/
	if (digits < 0)
	{
		hex = 1;
		digits = -digits;
		*p_str++ = '0';
		*p_str++ = 'x';
	}
	else
	{
		digits += 1;
	}
	/*******************************************************************
      sign, only if decimal
	 *******************************************************************/
	if ((val < 0) && (hex == 0))
	{
		u = ((int)-(val+1)) + 1; 
		sign = -1;
	}
	else
	{
		u = (int)val;
		sign = +1;
	}
	/*******************************************************************
      output
	 *******************************************************************/
	p_str += digits;

	if (hex == 0)
	{
		/***************************************************************
          write as decimal without leading zeroes
		 ***************************************************************/
		do
		{
			tmp = u % 10;
			*--p_str = (char)tmp+'0';
			u /= 10; 
		} while (u > 0);

		if (sign < 0)
		{
			*--p_str = '-';
		}

		while (p_str > dst)
		{
			//*--p_str = ' ';
			*--p_str = '0';
		}
	}
	else
	{
		/***************************************************************
          write as hex 
		 ***************************************************************/
		for (i=0; i<digits; i++)
		{
			tmp = u & 0x0F;
			if (tmp < 10)
				*--p_str = (char)tmp + '0';
			else
				*--p_str = (char)tmp + 'A' - 10;
			u = u >> 4;
		}
	}

	return dst;
}

void FormPacket1(int intmV) {
	int i,j;
	char *dstr = 0;
	char dst[25];
	//Voltage
	dstr = Itoa(dst, intmV, 2);
	for (i = 0; i < 2; i++) {
		u8PktBuf[0 + i] = (dstr[i+1])-48;	//45678 digits
	}	
    for(i=0;i<2;i++)
	printf("%d\t",u8PktBuf[i]);
printf("\n");
}

 Batteryconfig Batconfig; 
int main()
{
    int a,b,c,d,e,f;//$ 2763 3650 650 210 210 3500 #//
    char set_arr[24];
    //printf("%d\n",a);
	set_arr[0]='$'; 
    set_arr[1]=50;      
    set_arr[2]=57;   
    set_arr[3]=56;    
    set_arr[4]=53;
	
	set_arr[5]=53; 	
    set_arr[6]=57;      
    set_arr[7]=52; 
	
    set_arr[9]=56;   
    set_arr[10]=55;    
    set_arr[11]=50;
	
    set_arr[12]=52;      
    set_arr[13]=51;   
    set_arr[14]=56;
    
    set_arr[15]=52;
    set_arr[16]=51;   
    set_arr[17]=56;
    
    set_arr[18]=53;
	set_arr[19]=55;
    set_arr[20]=51;   
    set_arr[21]=56;
	
	set_arr[22]='#';
			int i;
	//FormPacket(34800,43888,6527,202,2);
	for (i=0;i<23;i++)
	FormPacket1(set_arr[i]);
	if((set_arr[0]=='$'&& set_arr[22]))
	{
    Batconfig.min_vol_cutoff=set_arr[1]*1000+set_arr[2]*100+set_arr[3]*10+set_arr[4];
	Batconfig.max_vol_cutoff=set_arr[5]*1000+set_arr[6]*100+set_arr[7]*10+set_arr[8];
	Batconfig.max_temp_cutoff=set_arr[9]*100+set_arr[10]*10+set_arr[11];
	Batconfig.charge_current_cutoff=set_arr[12]*100+set_arr[13]*10+set_arr[14];
	Batconfig.dicharge_current_cutoff=set_arr[15]*100+set_arr[16]*10+set_arr[17];
	Batconfig.CB=set_arr[18]*1000+set_arr[19]*100+set_arr[20]*10+set_arr[21];
    printf("%d\t %d\t%d\t%d\t%d\t%d\n",Batconfig.min_vol_cutoff,Batconfig.max_vol_cutoff,Batconfig.max_temp_cutoff,Batconfig.charge_current_cutoff,Batconfig.dicharge_current_cutoff,Batconfig.CB);
	}
    return 0;
}
/*#define EEPROM_WRITE_ADDR4	0x05
#define EEPROM_WRITE_ADDR5	0x06

#define EEPROM_WRITE_ADDR6	0x07
#define EEPROM_WRITE_ADDR7	0x08

#define EEPROM_WRITE_ADDR6	0x09
#define EEPROM_WRITE_ADDR7	0x10

#define EEPROM_WRITE_ADDR6	0x11
#define EEPROM_WRITE_ADDR7	0x12

#define EEPROM_WRITE_ADDR6	0x13
#define EEPROM_WRITE_ADDR7	0x14

#define EEPROM_WRITE_ADDR6	0x15
#define EEPROM_WRITE_ADDR7	0x16

#define EEPROM_WRITE_ADDR6	0x17
#define EEPROM_WRITE_ADDR7	0x18

	 /*****app data******/
	// if(if(start_flag == 3)	 {
		//temp_status=bms_config();
	 //if (temp_status==1)
		// PRINTF("| config success ..\r\n");
		 
/*int bms_config()//call from main function
{
		 tempmin_vol_cutoff = Batconfig.min_vol_cutoff;//Batconfig.min_vol_cutoff
		 WrVal4 = tempmin_vol_cutoff&0xff;//lower byte
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR4,WrVal4);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 WrVal5 = (tempmin_vol_cutoff&0xff00)>>8;
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR5,.WrVal5);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 
		 tempmax_vol_cutoff = Batconfig.max_vol_cutoff;//Batconfig.min_vol_cutoff
		 WrVal6 = tempmax_vol_cutoff&0xff;//lower byte
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR6,WrVal6);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 WrVal7 = (tempmax_vol_cutoff&0xff00)>>8;
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR7,.WrVal7);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 
		 tempmax_temp_cutoff = Batconfig.max_temp_cutoff;//Batconfig.min_vol_cutoff
		 WrVal8 = tempmax_temp_cutoff&0xff;//lower byte
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR8,WrVal8);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 WrVal9 = (tempmax_temp_cutoff&0xff00)>>8;
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR9,.WrVal9);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 
		 tempcharge_current_cutoff = Batconfig.charge_current_cutoff;//Batconfig.min_vol_cutoff
		 WrVal10 = tempcharge_current_cutoff&0xff;//lower byte
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR10,WrVal10);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 WrVal11 = (tempcharge_current_cutoff&0xff00)>>8;
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR11,.WrVal11);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 
		 tempdicharge_current_cutoff = Batconfig.dicharge_current_cutoff;//Batconfig.min_vol_cutoff
		 WrVal12 = tempdicharge_current_cutoff&0xff;//lower byte
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR12,WrVal12);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 WrVal13 = (tempdicharge_current_cutoff&0xff00)>>8;
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR13,.WrVal13);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 
		 tempCB = Batconfig.CB;//Batconfig.min_vol_cutoff
		 WrVal14 = tempCB &0xff;//lower byte
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR14,WrVal14);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 WrVal15 = (tempCB &0xff00)>>8;
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR15,.WrVal15);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 
		 Batconfig_set=1;//Batconfig.min_vol_cutoff
		 WrVal116 = Batconfig_set&0xff;//lower byte
		 EEPROM_write(EEPROM_WRITE,&EEPROM_WRITE_ADDR16,WrVal16);
         
	 
	 /*****main *******/
	 
	 	/* BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&EEPROM_WRITE_ADDR4,RdVal16,1);
		 Batconfig_set=RdVal16;
} 
		 
 if((Batconfig_set == 1)){ //Initial
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&EEPROM_WRITE_ADDR4,RdVal4,1);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&&EEPROM_WRITE_ADDR4,&Rdval5,1);
	     Batconfig.min_vol_cutoff = ((Rdval5)<<8)+RdVal4;//higher byte +lower byte
		 
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&EEPROM_WRITE_ADDR4,RdVal6,1);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&&EEPROM_WRITE_ADDR4,&Rdval7,1);
	     Batconfig.max_vol_cutoff = ((Rdval7)<<8)+RdVal6;//higher byte +lower byte
		 
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&EEPROM_WRITE_ADDR4,RdVal8,1);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&&EEPROM_WRITE_ADDR4,&Rdval9,1);
	     Batconfig.max_temp_cutoff = ((Rdval9)<<8)+RdVal8;//higher byte +lower byte
		 
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&EEPROM_WRITE_ADDR4,RdVal10,1);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&&EEPROM_WRITE_ADDR4,&Rdval1,1);
	     Batconfig.charge_current_cutoff= ((Rdval11)<<8)+RdVal10;//higher byte +lower byte
		 
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&EEPROM_WRITE_ADDR4,RdVal12,1);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&&EEPROM_WRITE_ADDR4,&Rdval3,1);
	     Batconfig.dicharge_current_cutoff = ((Rdval13)<<8)+RdVal12;//higher byte +lower byte
		 
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&EEPROM_WRITE_ADDR4,RdVal14,1);
		 BCC_MCU_WaitMs(EEPROM_WRRD_DELAY);
		 EEPROM_read(EEPROM_READ,&&EEPROM_WRITE_ADDR4,&Rdval15,1);
	     Batconfig.CB= ((Rdval15)<<8)+RdVal14;//higher byte +lower byte
	 }*/
	 
	 
	 

