
#include<stdio.h>
#include<string.h>
char u8PktBuf[84];
#define MAXBYTES 84

#define BMS_MAX_CELLS			 14U  //Change kgp
#define BMS_ANx_TEMP_SENSORS      1U  //Change kgp	
#define uint32_t int
uint32_t RTIpktCnt = 1;
//u16 TenmspktCnt = 0;
//u16 RTI1hrCnt = 0;
 uint32_t  NoOfChRecords = 0;
//volatile u16 NoOfiDleRecords = 0;
#define TMAXREC			50
#define MINTMAXREC		14
 uint32_t CrSum = 0;
 uint32_t VlSum = 0;
 uint32_t V2Sum = 0;
 uint32_t V3Sum = 0;
 uint32_t V4Sum = 0;	
 uint32_t V5Sum = 0;
 uint32_t V6Sum = 0;
 uint32_t V7Sum = 0;
 uint32_t V8Sum = 0;
 uint32_t V9Sum = 0;
 uint32_t V10Sum = 0;
 uint32_t Vl1Sum = 0;
 uint32_t Vl2Sum = 0;
typedef unsigned char u8;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned int  u16;
typedef unsigned long u32;
typedef signed int  s16;
uint32_t pktlvcnt = 0;
	
	
	// typedef struct {

	// int CellVoltages[BMS_MAX_CELLS];			/*!< 12 CT voltages measured values in [mV]. */
	// int TempCell[BMS_ANx_TEMP_SENSORS]; 	/*!< ANx Temperature values*/
	// int i32Current;                     /*!signed current shunt voltage measured value in [mV]  */

// }TYPE_BatteryPack;
// TYPE_BatteryPack BatPack;
	// typedef struct {

	// int Cell[BMS_MAX_CELLS];			/*!< 12 CT voltages measured values in [mV]. */
	// int TempCell[BMS_ANx_TEMP_SENSORS]; 	/*!< ANx Temperature values*/
	// int i32Current;                     /*!signed current shunt voltage measured value in [mV]  */

// }TYPE_BatteryPack1;
// TYPE_BatteryPack1 bms1mpkt;

typedef struct {

int CellVoltages[BMS_MAX_CELLS];			/*!< 12 CT voltages measured values in [mV]. */
	int TempCell[BMS_ANx_TEMP_SENSORS]; 	/*!< ANx Temperature values*/
	int i32Current;							/* State of Health */

}TYPE_BatteryPack;
TYPE_BatteryPack BatPack;
typedef struct {
int Cell[BMS_MAX_CELLS];			/*!< 12 CT voltages measured values in [mV]. */
	int TempCell[BMS_ANx_TEMP_SENSORS]; 	/*!< ANx Temperature values*/
	int i32Current;                     /*!signed current shunt voltage measured value in [mV]  */

}BmsPkt1M_t;

// temp 1Minute. records for Charge & Before sleep 
BmsPkt1M_t bms1mpkt[MINTMAXREC]; 
// temp Cranking. records
TYPE_BatteryPack bmspkt[TMAXREC]; 

char *Itoa (char *dst, long val, int digits)
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

void FormPacket1(int cell,int cell1,int cell2,int cell3,int cell4,int cell5,int cell6,int cell7,int cell8,int cell9,int cell10,int cell11,int lpcount, long s32mA,int Temp) {
	int i,j;
	char *dstr = 0;
	char dst[25];
	char temp[8];
	memset(u8PktBuf,0,MAXBYTES);

	u8PktBuf[0] = '#';
	u8PktBuf[1] = 'S';
	u8PktBuf[2] = 'A';
	//lcnt
	dstr = Itoa(dst, lpcount, 8);
	for (i = 0; i < 8; i++) {
	u8PktBuf[3 + i] = (dstr[i + 1])-48;
	}
	
	//cell1
	dstr = Itoa(dst, cell, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[11 + i] = (dstr[i+1])-48;	//45678 digits
	}	
   //cell2
	dstr = Itoa(dst, cell1, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[15 + i] = (dstr[i+1])-48;	//45678 digits
	}	
    //cell3	
	dstr = Itoa(dst, cell2, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[19 + i] = (dstr[i+1])-48;	//45678 digits
	}
	//cell4
	dstr = Itoa(dst, cell3, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[23 + i] = (dstr[i+1])-48;	//45678 digits
	}	
   //cell5
	dstr = Itoa(dst, cell4, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[27 + i] = (dstr[i+1])-48;	//45678 digits
	}	
	//cell6
	dstr = Itoa(dst, cell5, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[31 + i] = (dstr[i+1]);	//45678 digits
	}
	//cell7
	dstr = Itoa(dst, cell6, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[35 + i] = (dstr[i+1])-48;	//45678 digits
	}	
   //cell8
	dstr = Itoa(dst, cell7, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[39 + i] = (dstr[i+1])-48;	//45678 digits
	}	
	//cell9
	dstr = Itoa(dst, cell8, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[43 + i] = (dstr[i+1])-48;	//45678 digits
	}
	//cell10
	dstr = Itoa(dst, cell9, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[47 + i] = (dstr[i+1]);	//45678 digits
	}	
    //cell11
	dstr = Itoa(dst, cell10, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[51 + i] = (dstr[i+1]);	//45678 digits
	}	
	//cell12
	dstr = Itoa(dst, cell11, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[55 + i] = (dstr[i+1]);	//45678 digits
	}
	
    //current
	dstr = Itoa(dst, s32mA, 7);
	
	if( s32mA < 0) { //D For -ve values
		for(i=0;i<8;i++) {
			if(dstr[i] == '-') break;
		}
		temp[0]= '-';
		for(j=1;j<=i;j++) {
			temp[j]='0';
		}
		for(j=i;j<8;j++) {
			temp[i] = dstr[j+1];
			i++;
		}
		for (i = 0; i < 7; i++) {
			u8PktBuf[59 + i] = temp[i];	 //1 234567 digits
		}
	} else {
		for (i = 0; i < 8; i++) {
			u8PktBuf[59 + i] = (dstr[i+1])-48;	 //1 234567 digits
		}
		//u8PktBuf[16] = '+'; //C
	}
    //Temperature
	dstr = Itoa(dst,Temp, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[66 + i] = (dstr[i + 1])-48;	 //5678 digits
	}
    for(i=0;i<70;i++)
	printf("%d\t",u8PktBuf[i]);
    printf("\n");
}

	//Current
	int main(){
		int i;
		for(i=0;i<14;i++)
	BatPack.CellVoltages[i]=3000+i;
	BatPack.TempCell[0]=20;
    BatPack.i32Current=-337;

	 int k;
	 for (k=0;k<99;k++){
				////if (RTIEvery10ms) {
	
			    CrSum = CrSum + BatPack.i32Current;
				VlSum = VlSum + BatPack.CellVoltages[0];
				V2Sum = V2Sum + BatPack.CellVoltages[1];
				V3Sum = V3Sum + BatPack.CellVoltages[2];
				V4Sum = V4Sum + BatPack.CellVoltages[3];
				V5Sum = V5Sum + BatPack.CellVoltages[4];
				V6Sum = V6Sum + BatPack.CellVoltages[5];
				V7Sum = V7Sum + BatPack.CellVoltages[6];
				V8Sum = V8Sum + BatPack.CellVoltages[7];
				V9Sum = V9Sum + BatPack.CellVoltages[8];
				V10Sum = V10Sum + BatPack.CellVoltages[9];
				Vl1Sum = Vl1Sum + BatPack.CellVoltages[10];
				Vl2Sum = Vl2Sum + BatPack.CellVoltages[11];

				
				
				RTIpktCnt++;
				NoOfChRecords++;
			}
			 int OneSecCh0Flag;
			 OneSecCh0Flag=100;
			 if(RTIpktCnt == OneSecCh0Flag ) { // for 1 minute validate

				RTIpktCnt = 0;
				int nindex = 0;

						bms1mpkt[nindex].Cell[0]  = (u32) ( VlSum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[1]  = (u32) ( V2Sum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[2]  = (u32) ( V3Sum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[3]  = (u32) ( V4Sum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[4]  = (u32) ( V5Sum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[5]  = (u32) ( V6Sum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[6]  = (u32) ( V7Sum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[7]  = (u32) ( V8Sum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[8]  = (u32) ( V9Sum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[9]  = (u32) ( V10Sum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[10] = (u32) ( Vl1Sum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[11] = (u32) ( Vl2Sum / NoOfChRecords ); //VSensor[2].u16mV;

				
							bms1mpkt[nindex].i32Current = (s32) ( CrSum / NoOfChRecords );//CSensor.s32mA;
							bms1mpkt[nindex].TempCell[0] = BatPack.TempCell[0];
				
	

FormPacket1(bms1mpkt[i].Cell[0],bms1mpkt[i].Cell[1],bms1mpkt[i].Cell[2],bms1mpkt[i].Cell[3],bms1mpkt[i].Cell[4],bms1mpkt[i].Cell[5],bms1mpkt[i].Cell[6],bms1mpkt[i].Cell[7],bms1mpkt[i].Cell[8],bms1mpkt[i].Cell[9],bms1mpkt[i].Cell[10],bms1mpkt[i].Cell[11],99999999,bms1mpkt[i].i32Current,bms1mpkt[i].TempCell[0]);


			 } // for 1 minute validate

	
	return 0;
	}
	