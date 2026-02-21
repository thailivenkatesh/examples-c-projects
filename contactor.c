	/*Charging & Discharging MOSFET pins*/
#define CONTACTOR     11U
#define PRE_CHRG_RLY  12U


#define CONTACTOR_INSTANCE     		PTA
#define CONTACTOR_PORT         		PORTA
#define CONTACTOR_PIN          		11U

#define PRE_CHRG_RLY_INSTANCE     	PTA
#define PRE_CHRG_RLY_PORT         	PORTA
#define PRE_CHRG_RLY_PIN          	12U  


PINS_DRV_ClearPins(CONTACTOR_INSTANCE, 1U << CONTACTOR_PIN);
PINS_DRV_ClearPins(PRE_CHRG_RLY_INSTANCE, 1U << PRE_CHRG_RLY_PIN);
/*************************************************/		
 uint8_t chargerSense(){

 uint32_t PORTAdata;
 uint8_t prechargerPin = 0;
 PINS_DRV_ClearPins(CONTACTOR_INSTANCE, 1U << CONTACTOR_PIN);
 PORTAdata = PINS_DRV_ReadPins(PTA); // Read the charge sense pin

 prechargerPin = (PORTAdata & (1<<11) ? 1 : 0);

 return prechargerPin;
}	
		
/***************************************************/		

if (chargerSense()) {

	printf("CHARGER Connected...\r\n");
    PINS_DRV_ClearPins(CONTACTOR_INSTANCE, 1U << CONTACTOR_PIN);
	PINS_DRV_SetPins(CONTACTOR_INSTANCE, 1U << CONTACTOR_PIN);
	
	/************************************************************************/
	
#define CONTACTOR_INSTANCE     		PTA
#define CONTACTOR_PORT         		PORTA
#define CONTACTOR_PIN          		11U
PINS_DRV_ClearPins(CONTACTOR_INSTANCE, 1U << CONTACTOR_PIN);

PINS_DRV_SetPins(CONTACTOR_INSTANCE, 1U << CONTACTOR_PIN);


#define BMS_MAX_CELLS			 28U  //Change kgp
#if	MOTOVOLT
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
#endif


bcc_status_t cutOffControls(uint8_t cid)
{
	 uint8_t	i,CCutOff=0,DCutOff=0,CutOff=0,Charge=0,DSCutOff=0,CSCutOff=0,tCutOff=0;
	 bcc_status_t balancingStatus;
	 
	 uint8_t  i,j,k;
     uint16_t cellvoltages[29];

for(j=1;j<=2;j++){,StackVoltage
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

		 if( (CellVoltages[i] >= CELL_OV_MAX_CV_VOLTAGE) ) {
		// if( (BatPack.CellVoltages[i] >= Batconfig.max_vol_cutoff) ) {
#if	PRNTDEBUG

			 PRINTF("| CellVoltage%d set\t| %d mV \t| \r\n", (i+1), CellVoltages[i]);
#endif

			 CCutOff = 1; // FOr cell voltage
		 }
	 }

	 for(i = 0; i < BMS_MAX_CELLS; i++) // Individual CELL voltage thresholds during Discharge
	 {
		 if( (CellVoltages[i] <= CELL_UV_MAX_VOLTAGE) ) {
	     //if( (BatPack.CellVoltages[i] <= Batconfig.min_vol_cutoff) ) {
#if	PRNTDEBUG
			 PRINTF("| CellVoltage%d set\t| %d mV \t| \r\n", (i+1), CellVoltages[i]);
#endif
			 DCutOff = 1; // FOr cell voltage
		 }
	 }
StackVoltage = (BatPack.u16VoltCell[1][0])+(BatPack.u16VoltCell[2][0]);
	 if( StackVoltage >= BMS_OCV_OV_MAX_CV_VOLTAGE) // Stack voltage threshold for Charge
	 {
#if	PRNTDEBUG
		 PRINTF("\n| CStackVoltage set|\r\n");
#endif
		 CSCutOff = 1;
	 }
	 if(StackVoltage <= BMS_UV_MIN_VOLTAGE) // Stack voltage threshold for DisCharge
	 {
#if	PRNTDEBUG
		 PRINTF("\n| DStackVoltage set|\r\n");
#endif
		 DSCutOff = 1;
	 }

	 if(BatPack.i32Current[1] > 0) //charge current
	 {
		 Charge = 1;
		 //Add Charge Current cut off
		 if ( (BatPack.u16VoltCell[1][15] <= 0) || BatPack.u16VoltCell[1][15] >= 48) ) {
#if	PRNTDEBUG
			 PRINTF("\n| CH Temperature set|\r\n");
#endif
			 tCutOff = 1; // Enable/Disable Temp. cut off
		 }

	 } else { //Discharge current

		 Charge = 0;
		 //Add DisCharge Current cut off
		 if ( (BatPack.u16VoltCell[1][15] <= -10) || BatPack.u16VoltCell[1][15] >= 54) ) {
#if	PRNTDEBUG
			 PRINTF("\n| DisC Temperature set|\r\n");
#endif
			 tCutOff = 1; // Enable/Disable Temp. cut off
		 }
	 }

	 if ( ( CCutOff && Charge ) || ( CSCutOff && Charge) || ( tCutOff && Charge) ) {


		 

#if	PRNTDEBUG
		 PRINTF("|Updated SOH.. %f \t|\r\n",SOH);
		 PRINTF("\n| Charge/Charger CUT Off Enabled \t |\r\n");
#endif
		 PINS_DRV_ClearPins(CONTACTOR_INSTANCE, 1U << CONTACTOR_PIN);

		 // Turn Off CB and reset individual timers/CB -- Check this if needed
		// balancingStatus = BCC_Reset_CB_Individual(&g_bccData.drvConfig, BCC_CID_DEV1);
#if	PRNTDEBUG
		 PRINTF("| ReSetIndividual CB..- %d \t|\r\n",balancingStatus);
#endif
		 //BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, false);
#if	PRNTDEBUG
		 PRINTF("| CB Turned OFF... \t|\r\n");
#endif

	 } else if ( (DCutOff && !Charge ) || (DSCutOff && !Charge) || ( tCutOff && !Charge) ) {

		 PINS_DRV_ClearPins(CONTACTOR_INSTANCE, 1U << CONTACTOR_PIN);
#if	PRNTDEBUG
		 PRINTF("\n|Discharge/Load CUT Off Enabled \t |\r\n");
#endif

	 }

	 return BCC_STATUS_SUCCESS;
}
uint8_t  i,j,k;
uint16_t u16VoltCell[15][22];

// Online C compiler to run C program online
#include <stdio.h>
typedef char uint8_t;
typedef short uint16_t;

int main() {
    // Write C code here
   uint8_t  i,j,k;
uint16_t u16VoltCell[15][22],cellvoltages[29];

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

    
    return 0;
}