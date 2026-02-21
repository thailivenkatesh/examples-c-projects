
#include <stdio.h>


#define BMS_MAX_CELLS			    28U  //Change kgp

#define BMS_NOMINAL_VOLTAGE			38400U /*38.4v - 12*3.2*/
#define CELL_NOMINAL_VOLTAGE		3200U  /*3.2v*/
#define BMS_OCV_OV_MAX_VOLTAGE		44040U //43800U /*43.8v*/ //44,040
#define BMS_OCV_MIN_VOLTAGE			35500U /*35.5v*/
#define BMS_UV_MIN_VOLTAGE			35000U /*35v - 12*2.9 */
#define BMS_CELLBALANCE_VOLTAGE		3500U  /*3.5v*/ //3600
#define BMS_CELLBALANCE_SHIFT_VLT	3630U
#define CELL_OV_MAX_VOLTAGE			3600U
#define BMS_STACK_CV_VOLTAGE		43330U //43250U
#define BMS_OCV_OV_MAX_CV_VOLTAGE	43800U /*43.8v*/ //44,040
#define CELL_OV_MAX_CV_VOLTAGE		4250 //3650U  /*3.65v*/
#define CELLBALANCE_VOLTAGE_DIFF	10    /*10mV*/
#define CELL_UV_MAX_VOLTAGE			2900U /*2.9v*/
#define PRNTDEBUG 1


 void cutOffControls(char cid)
{
	 char	i,CCutOff=0,DCutOff=0,CutOff=0,Charge=0,DSCutOff=0,CSCutOff=0,tCutOff=0;
	 
 char  j,k;
short u16VoltCell[15][22],cellvoltages[29];
int StackVoltage;
for(j=1;j<=2;j++){
		for(i =1, k=15; i < 15,k<29; i++,k++) //0 to 3 - 1-4 cells
		{
			if(j==2)
			u16VoltCell[j][i] =3000+k;
			else
			u16VoltCell[j][i] =3000+i;

		}
	}

for(j=1;j<=2;j++){
		for(i =1, k=15; i < 15,k<29; i++,k++) //0 to 3 - 1-4 cells
		{
			if(j==2){
			cellvoltages[k-1] =	u16VoltCell[j][i];
			printf("cell%d %d\n",k,cellvoltages[k-1] );
			}
			else{
			cellvoltages[i-1] = u16VoltCell[j][i];
			printf("cell%d %d\n",i,cellvoltages[i-1] );
			}
		}
	}

	 for(i = 0; i < BMS_MAX_CELLS; i++) // Individual CELL voltage thresholds during Charge
	 {

		 if( (cellvoltages[i] >= CELL_OV_MAX_CV_VOLTAGE) ) {
		// if( (BatPack.CellVoltages[i] >= Batconfig.max_vol_cutoff) ) {
#if	PRNTDEBUG

			 printf("| CellVoltage%d set\t| %d mV \t| \r\n", (i+1), cellvoltages[i]);
#endif

			 CCutOff = 1; // FOr cell voltage
		 }
	 }

	 for(i = 0; i < BMS_MAX_CELLS; i++) // Individual CELL voltage thresholds during Discharge
	 {
		 if( (cellvoltages[i] <= CELL_UV_MAX_VOLTAGE) ) {
	     //if( (BatPack.CellVoltages[i] <= Batconfig.min_vol_cutoff) ) {
#if	PRNTDEBUG
			 printf("| CellVoltage%d set\t| %d mV \t| \r\n", (i+1), cellvoltages[i]);
#endif
			 DCutOff = 1; // FOr cell voltage
		 }
	 }
 // StackVoltage = (u16VoltCell[1][0])+(u16VoltCell[2][0]);
 
 StackVoltage=55001;
 
	 if( StackVoltage >= BMS_OCV_OV_MAX_CV_VOLTAGE) // Stack voltage threshold for Charge
	 {
#if	PRNTDEBUG
		 printf("\n| CStackVoltage set|\r\n");
#endif
		 CSCutOff = 1;
	 }
	 if(StackVoltage <= BMS_UV_MIN_VOLTAGE) // Stack voltage threshold for DisCharge
	 {
#if	PRNTDEBUG
		 printf("\n| DStackVoltage set|\r\n");
#endif
		 DSCutOff = 1;
	 }
u16VoltCell[1][15]=25;
	 if(0 > 0) //charge current
	 {
		 Charge = 1;
		 
		 if ( (u16VoltCell[1][15] <= 0) || (u16VoltCell[1][15] >= 48) ) {
#if	PRNTDEBUG
			 printf("\n| CH Temperature set|\r\n");
#endif
			 tCutOff = 1; // Enable/Disable Temp. cut off
		 }

	 } else { //Discharge current

		 Charge = 0;
		
		 if ( (u16VoltCell[1][15] <= -10) || (u16VoltCell[1][15] >= 54) ) {
#if	PRNTDEBUG
			 printf("\n| DisC Temperature set|\r\n");
#endif
			 tCutOff = 1; // Enable/Disable Temp. cut off
		 }
	 }

	 if ( ( CCutOff && Charge ) || ( CSCutOff && Charge) || ( tCutOff && Charge) ) {


		 

#if	PRNTDEBUG
		// printf("|Updated SOH.. %f \t|\r\n",SOH);
		 printf("\n| Charge/Charger CUT Off Enabled \t |\r\n");
#endif
		 //PINS_DRV_ClearPins(CONTACTOR_INSTANCE, 1U << CONTACTOR_PIN);
printf("\n| CONTACTOR_INSTANCE off \t |\r\n");
		 // Turn Off CB and reset individual timers/CB -- Check this if needed
		// balancingStatus = BCC_Reset_CB_Individual(&g_bccData.drvConfig, BCC_CID_DEV1);
#if	PRNTDEBUG
		 //printf("| ReSetIndividual CB..- %d \t|\r\n",balancingStatus);
#endif
		 //BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, false);
#if	PRNTDEBUG
		 printf("| CB Turned OFF... \t|\r\n");
#endif

	 } else if ( (DCutOff && !Charge ) || (DSCutOff && !Charge) || ( tCutOff && !Charge) ) {
printf("\n| CONTACTOR_INSTANCE off \t |\r\n");
		 //PINS_DRV_ClearPins(CONTACTOR_INSTANCE, 1U << CONTACTOR_PIN);
#if	PRNTDEBUG
		 printf("\n|Discharge/Load CUT Off Enabled \t |\r\n");
#endif

	 }

	
}


int main() {
    // Write C code here
  
cutOffControls(1);
    
    return 0;
}