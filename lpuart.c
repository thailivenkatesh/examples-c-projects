//12VBMS reference code   frame packet,handlecommands is edited  to 36VBMS  
#include<stdio.h>
#include<string.h>
char u8PktBuf[75];
#define MAXBYTES 75

#define BMS_MAX_CELLS			 12U  
#define BMS_ANx_TEMP_SENSORS      1U  

// App defines
#define DISCHARGING		(-100)
//#define DISCHARGING		-25
#define CHARGING		100
#define NCDISCHARGE		-25
#define NCCHARGE		0
#define NCIDLECR		-1
#define ONEHOUR			60
#define CHARGEPKT		1
#define IDLEPKT			2
#define CRORDCPKT		3

#define ONEMNPKCNT		6000  //for 1Minute


#define MAXCMDBYTES		250 //0xFA
#define TMAXREC			50
#define MINTMAXREC		14
#define	DEBUGML		0
#define SERIAL_DUMP 0
#define TENMSRECS 	5
#define BMS10MSLOG 	0
#define MAXDCREC	50
// ---------------------------------------------------------------------
typedef unsigned char u8;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned int  u16;
typedef unsigned long u32;
typedef signed int  s16;

uint32_t RTIpktCnt = 1;
//u16 TenmspktCnt = 0;
//u16 RTI1hrCnt = 0;
 uint32_t  NoOfChRecords = 0;
//volatile u16 NoOfiDleRecords = 0;

 uint32_t  CrSum = 0;
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
 
 uint32_t idleCrSum = 0;
 uint32_t idleVlSum = 0;
 uint32_t idleV2Sum = 0;
 uint32_t idleV3Sum = 0;
 uint32_t idleV4Sum = 0;	
 uint32_t idleV5Sum = 0;
 uint32_t idleV6Sum = 0;
 uint32_t idleV7Sum = 0;
 uint32_t idleV8Sum = 0;
 uint32_t idleV9Sum = 0;
 uint32_t idleV10Sum = 0;
 uint32_t idleVl1Sum = 0;
 uint32_t idleVl2Sum = 0;;
 
uint32_t pktlvcnt = 0;
	
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


typedef enum  {
  BMS_PARKING    = 0,
  BMS_DRIVING    = 1,
  BMS_CRANKING   = 2,
  BMS_START_STOP = 3,
  BMS_CALIB      = 4,
  BMS_SLEEP      = 5
} TYPE_BMS_MODE;

typedef unsigned char u8;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned int  u16;
typedef unsigned long u32;
typedef signed int  s16;
void main(void) {

	char event;
	u8 index1 = 0, CrIndex, i;
	u8 nindex;
	//u16 wrin;
	u8 RecordType;
	s32 Crange = 0;
	
	char tbuf[80];

	u16 RTIpktCnt = 1;
	u16 TenmspktCnt = 0;
	u16 RTI1hrCnt = 0;
	volatile u16 NoOfChRecords = 0;
	volatile u16 NoOfiDleRecords = 0;
	
	volatile s32 CrSum = 0;
	volatile u32 VlSum = 0;
	volatile s32 idleCrSum = 0;
	volatile u32 idleVlSum = 0;
	u32 pktlvcnt = 0;
	
	TYPE_BMS_MODE bmsmode;
	s16 s16Vdrop;
	u16 V2u16Raw;
	//BmsPkt_t Battery;

	
	bmsmode = BMS_PARKING;
	PowerOn = 0; // Boot up flag
	FlgEnable = 1;
    FlashWrite=1;
	index1 = 0;
	//! \todo implement a delay check that data is valid, before entering main loop?
	for EVER {  

		FlgEnable = 1;	
		
		//! Temperature measurement results
		
		
		if (RTIEvery10ms==1) {			
			


			// Write Records to Flash if configured
			if(FlashWrite) {
				
				Crange = (BatPack.i32Current / 1000);//conerting 
//				Crange = 98;
//				Battery.voltage = 12500;
//				Battery.current = 50;
				/*Cranking capture <= -100 to >= 100*/
				if ( (Crange <= DISCHARGING ) || (Crange >= CHARGING) ) { //Cranking

					bmsmode = BMS_CRANKING;
					
					if (index1 < MAXDCREC) {
						bmspkt[index1].cell[0] = BatPack.CellVoltages[0]; //VSensor[2].u16mV;
						bmspkt[index1].cell[1] = BatPack.CellVoltages[1]; //VSensor[2].u16mV;
						bmspkt[index1].cell[2] = BatPack.CellVoltages[2]; //VSensor[2].u16mV;
						bmspkt[index1].cell[3] = BatPack.CellVoltages[3]; //VSensor[2].u16mV;
						bmspkt[index1].cell[4] = BatPack.CellVoltages[4]; //VSensor[2].u16mV;
						bmspkt[index1].cell[5] = BatPack.CellVoltages[5]; //VSensor[2].u16mV;
						bmspkt[index1].cell[6] = BatPack.CellVoltages[6]; //VSensor[2].u16mV;
						bmspkt[index1].cell[7] = BatPack.CellVoltages[7]; //VSensor[2].u16mV;
						bmspkt[index1].cell[8] = BatPack.CellVoltages[8]; //VSensor[2].u16mV;
						bmspkt[index1].cell[9] = BatPack.CellVoltages[9]; //VSensor[2].u16mV;
						bmspkt[index1].cell[10] = BatPack.CellVoltages[10]; //VSensor[2].u16mV;
						bmspkt[index1].cell[11] = BatPack.CellVoltages[11]; //VSensor[2].u16mV;
						
						bmspkt[index1].i32Current = BatPack.i32Current;//CSensor.s32mA;
						bmspkt[index1].TempCell[0] = BatPack.TempCell[0];//TSensor[1].u16TempK+K2C; // External Temp.

						RecordType = CRORDCPKT;
						index1++;
					}					
					RTI1hrCnt = 0;// Rest the sleep/1hour tracking count
					RTIpktCnt = 1;// Reset 1 Minute tracking count
					TenmspktCnt = 0;// Reset 50ms tracking count
					
				} else { 
					
					CrIndex = index1; // Write crank records to flash
					index1 = 0;

					if (RecordType == CRORDCPKT) {
						for (i=0; i < CrIndex; i++) {
							event = 'Y';
							lcount++;//Move count to temp. and use
							pktlvcnt = lcount;
FormPacket(bms1mpkt[i].Cell[0],bms1mpkt[i].Cell[1],bms1mpkt[i].Cell[2],bms1mpkt[i].Cell[3],bms1mpkt[i].Cell[4],bms1mpkt[i].Cell[5],bms1mpkt[i].Cell[6],bms1mpkt[i].Cell[7],bms1mpkt[i].Cell[8],bms1mpkt[i].Cell[9],bms1mpkt[i].Cell[10],bms1mpkt[i].Cell[11],bms1mpkt[i].i32Current,bms1mpkt[i].TempCell[0],pktlvcnt,event);				
							//FormPacket(bmspkt[i].voltage,bmspkt[i].current,bmspkt[i].temp,pktlvcnt,event);	

						} // for
						
						//init_struct(); //Clear the buffer
					}
					
					
					//Non Cranking - Monitor/Read values
					bmsmode = BMS_DRIVING;
					
					RTIpktCnt ++;// to track the packets in 1 minute
					TenmspktCnt++;// To track Discharge packets					

					if ( TenmspktCnt == TENMSRECS ) { // 50ms

						/*Discharging capture <-25 to > -50 (Capture -3A to -99A)*/
						if ( (Crange < NCDISCHARGE) && (Crange > DISCHARGING) ) {
							nindex = 0;						
						bms1mpkt[nindex].cell[0] = BatPack.CellVoltages[0]; //VSensor[2].u16mV;
						bms1mpkt[nindex].cell[1] = BatPack.CellVoltages[1]; //VSensor[2].u16mV;
						bms1mpkt[nindex].cell[2] = BatPack.CellVoltages[2]; //VSensor[2].u16mV;
						bms1mpkt[nindex].cell[3] = BatPack.CellVoltages[3]; //VSensor[2].u16mV;
						bms1mpkt[nindex].cell[4] = BatPack.CellVoltages[4]; //VSensor[2].u16mV;
						bms1mpkt[nindex].cell[5] = BatPack.CellVoltages[5]; //VSensor[2].u16mV;
						bms1mpkt[nindex].cell[6] = BatPack.CellVoltages[6]; //VSensor[2].u16mV;
						bms1mpkt[nindex].cell[7] = BatPack.CellVoltages[7]; //VSensor[2].u16mV;
						bms1mpkt[nindex].cell[8] = BatPack.CellVoltages[8]; //VSensor[2].u16mV;
						bms1mpkt[nindex].cell[9] = BatPack.CellVoltages[9]; //VSensor[2].u16mV;
						bms1mpkt[nindex].cell[10] = BatPack.CellVoltages[10]; //VSensor[2].u16mV;
						bms1mpkt[nindex].cell[11] = BatPack.CellVoltages[11]; //VSensor[2].u16mV;
						
						bms1mpkt[nindex].i32Current = BatPack.i32Current;//CSensor.s32mA;
						bms1mpkt[nindex].TempCell[0] = BatPack.TempCell[0];//TSensor[1].u16TempK+K2C; // External Temp.
							
							//Write the packet to flash	
							// Write a record to flash and change the pkt type to stored
							event = 'N';
							lcount++;
							//Move count to tempvar and use
							pktlvcnt = lcount;
FormPacket(bms1mpkt[nindex].Cell[0],bms1mpkt[nindex].Cell[1],bms1mpkt[nindex].Cell[2],bms1mpkt[nindex].Cell[3],bms1mpkt[nindex].Cell[4],bms1mpkt[nindex].Cell[5],bms1mpkt[nindex].Cell[6],bms1mpkt[nindex].Cell[7],bms1mpkt[nindex].Cell[8],bms1mpkt[nindex].Cell[9],bms1mpkt[nindex].Cell[10],bms1mpkt[nindex].Cell[11],bms1mpkt[nindex].nindex32Current,bms1mpkt[nindex].TempCell[0],pktlvcnt,event);	
							RTI1hrCnt = 0;// Rest the sleep/1hour tracking count
							RecordType = CRORDCPKT;
							RTIpktCnt = 1; // Rest the 1M packet count
						}
						TenmspktCnt = 0; // To track Discharge packets						
					}
					/*Charging capture < 100 to > 0 (Capture 1A to 99A)*/
					if ( (Crange < CHARGING) && (Crange > NCCHARGE ) ) {
						// Average the non cranking records Current and Voltage
					
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
						
						
						
						RecordType = CHARGEPKT;
						NoOfChRecords++;

					} else if ((Crange <= NCCHARGE) && (Crange >= NCIDLECR)) { // Idle (Capture 0 to -1)
						// Average the non cranking records Current and Voltage
						idleCrSum = idleCrSum + BatPack.i32Current;
						idleVlSum = idleVlSum + BatPack.CellidleVoltages[0];
						idleV2Sum = idleV2Sum + BatPack.CellidleVoltages[1];
						idleV3Sum = idleV3Sum + BatPack.CellidleVoltages[2];
						idleV4Sum = idleV4Sum + BatPack.CellidleVoltages[3];
						idleV5Sum = idleV5Sum + BatPack.CellidleVoltages[4];
						idleV6Sum = idleV6Sum + BatPack.CellidleVoltages[5];
						idleV7Sum = idleV7Sum + BatPack.CellidleVoltages[6];
						idleV8Sum = idleV8Sum + BatPack.CellidleVoltages[7];
						idleV9Sum = idleV9Sum + BatPack.CellidleVoltages[8];
						idleV10Sum = idleV10Sum + BatPack.CellidleVoltages[9];
						idleVl1Sum = idleVl1Sum + BatPack.CellidleVoltages[10];
						idleVl2Sum = idleVl2Sum + BatPack.CellidleVoltages[11];
						RecordType = IDLEPKT;
						NoOfiDleRecords++;
					}
					
				} //Non Cranking 10ms

				if(RTIpktCnt == ONEMNPKCNT) { // for 1 minute validate
						//If charging 
						RTIpktCnt = 0;
						TenmspktCnt = 0; // To track Discharge packets

						if(RecordType == CHARGEPKT) {	

							nindex = 1;						
							
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
						bms1mpkt[nindex].Cell[12] = (u32) ( Vl3Sum / NoOfChRecords ); //VSensor[2].u16mV;
						bms1mpkt[nindex].Cell[13] = (u32) ( Vl4Sum / NoOfChRecords ); //VSensor[2].u16mV;
				
							bms1mpkt[nindex].i32Current = (s32) ( CrSum / NoOfChRecords );//CSensor.s32mA;
							bms1mpkt[nindex].TempCell[0] = BatPack.TempCell[0];
							// Write a record to flash and change the pkt type to stored
							event = 'N';
							lcount++;
							//Move count to tempvar and use
							pktlvcnt = lcount;
FormPacket(bms1mpkt[nindex].Cell[0],bms1mpkt[nindex].Cell[1],bms1mpkt[nindex].Cell[2],bms1mpkt[nindex].Cell[3],bms1mpkt[nindex].Cell[4],bms1mpkt[nindex].Cell[5],bms1mpkt[nindex].Cell[6],bms1mpkt[nindex].Cell[7],bms1mpkt[nindex].Cell[8],bms1mpkt[nindex].Cell[9],bms1mpkt[nindex].Cell[10],bms1mpkt[nindex].Cell[11],bms1mpkt[nindex].nindex32Current,bms1mpkt[nindex].TempCell[0],pktlvcnt,event);

							CrSum = 0;
							VlSum = 0;
							RTI1hrCnt = 0;// Rest the sleep/1hour tracking count
							NoOfChRecords = 0;
						} else if( RecordType == IDLEPKT) {

							RTI1hrCnt++;// To track 1hour packets
							nindex = 2;
						bms1mpkt[nindex].Cell[0]  = (u32) ( idleVlSum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[1]  = (u32) ( idleV2Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[2]  = (u32) ( idleV3Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[3]  = (u32) ( idleV4Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[4]  = (u32) ( idleV5Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[5]  = (u32) ( idleV6Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[6]  = (u32) ( idleV7Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[7]  = (u32) ( idleV8Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[8]  = (u32) ( idleV9Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[9]  = (u32) ( idleV10Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[10] = (u32) ( idleVl1Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[11] = (u32) ( idleVl2Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[12] = (u32) ( idleVl3Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;
						bms1mpkt[nindex].Cell[13] = (u32) ( idleVl4Sum / NoOfiDleRecords); //idleVSensor[2].u16midleV;

						bms1mpkt[nindex].i32Current = (s32) ( CrSum / NoOfChRecords );//CSensor.s32mA;
						bms1mpkt[nindex].TempCell[0] = BatPack.TempCell[0];

							// Write a record to flash and change the pkt type to stored
							event = 'N';
							lcount++;
							//Move count to tempvar and use
							pktlvcnt = lcount;

FormPacket(bms1mpkt[nindex].Cell[0],bms1mpkt[nindex].Cell[1],bms1mpkt[nindex].Cell[2],bms1mpkt[nindex].Cell[3],bms1mpkt[nindex].Cell[4],bms1mpkt[nindex].Cell[5],bms1mpkt[nindex].Cell[6],bms1mpkt[nindex].Cell[7],bms1mpkt[nindex].Cell[8],bms1mpkt[nindex].Cell[9],bms1mpkt[nindex].Cell[10],bms1mpkt[nindex].Cell[11],bms1mpkt[nindex].nindex32Current,bms1mpkt[nindex].TempCell[0],pktlvcnt,event);

							idleCrSum = 0;
							idleVlSum = 0;
							NoOfiDleRecords = 0;
						}

					} // for 1 minute validate
				
				} //Flash write	
				
			RTIEvery10ms=0;
			} //10ms
		
		//if the current is consistent for 1 hour set *bmsmode == BMS_SLEEP
		if (RTI1hrCnt == ONEHOUR) {

				bmsmode = BMS_SLEEP;
				RTI1hrCnt = 0;
		}
		
		// Process user commands 
			if( RTIEvery500ms())
			{

				if(flag == 1) // Check and process commands
				{
					memset(cmd, 0, MAXCMDBYTES); //Clear the Local BUffer
					HandleCommands(&bmsmode);
					flag = 0;
					//SCISend(cmd);				  			 		  
				}
			} //500ms
			


} //main


int HandleCommands(TYPE_BMS_MODE *bmsmode) {	
		
	if ( (set_arr[0] == '#') && (set_arr[1] == 'L') && (set_arr[2] == 'P') ) { //Live Packet
		LPUART_DRV_SendData(INST_LPUART2, u8PktBuf, strlen(u8PktBuf)); 
	} else if ( (set_arr[0] == '#') && (set_arr[1] == 'M') && (set_arr[2] == 'P')) { //Multiple Packets
		LPUART_DRV_SendData(INST_LPUART2, u8PktBuf, strlen(u8PktBuf));
	return 0;	
} //Handle
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
//void FormPacket(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,s32,u16,u32,u8);
void FormPacket(u32 cell,u32 cell1,u32 cell2,u32 cell3,u32 cell4,u32 cell5,u32 cell6,u32 cell7,u32 cell8,u32 cell9,u32 cell10,u32 cell11,s32 s32mA,u16 Temp,u32 lpcount,u8 event) {

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
			u8PktBuf[59 + i] = (dstr[i+1]);	 //1 234567 digits
		}
		//u8PktBuf[16] = '+'; //C
	}
    //Temperature
	dstr = Itoa(dst,Temp, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[66 + i] = (dstr[i + 1]);	 //5678 digits
	}
 
	u8PktBuf[70] = event;
	u8PktBuf[71] = '.';

   for(i=0;i<72;i++)
	printf("%d\t",u8PktBuf[i]);
    printf("\n");
	}

}




			