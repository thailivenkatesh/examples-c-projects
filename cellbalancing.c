
CCS: Dead Band for PWM Signal
https://e2e.ti.com/support/microcontrollers/c2000-microcontrollers-group/c2000/f/c2000-microcontrollers-forum/825413/ccs-dead-band-for-pwm-signal


1.1 Solutions for Fast Charging Electric Vehicle Supply Equipment (EVSE) Design

https://training.ti.com/solutions-fast-charging-electric-vehicle-supply-equipment-evse-design?context=1137754-1139639-1128120

Digitally controlled high efficiency and high power density PFC circuits

https://training.ti.com/digitally-controlled-high-efficiency-and-high-power-density-pfc-circuits-part-2


ti 01604 issues

https://e2e.ti.com/search?q=01604&category=forum
White Paper - Estimating the State Of Charge of Li-Ion batteries
http://liionbms.com/php/wp_soc_estimate.php

Open source BMS for 48V to 400V lithium-ion battery pack

https://endless-sphere.com/forums/viewtopic.php?t=92952


Coulomb counting is a technique used to track the State of Charge of a battery pack.
It works by integrating the active flowing current (measured in amps) over time to derive 
the total sum of energy entering or leaving the battery pack. 
This produces a capacity that is typically measured in Amp-hours.


Coulomb Counting Method. The Coulomb counting method measures the discharging current of a battery
and integrates the discharging current over time in order to estimate SOC
 
 
CC_NB_NB_SAMPLES - number of samples taken for the Coulomb count. 
/******************************************************************************/
#define BCC_REG_CC_NB_SAMPLES_ADDR 0x2DU
#define BCC_R_CC_NB_SAMPLES_MASK   0xFFFFU
/******************************************************************************/
/* $2E COULOMB_CNT1 - Coulomb counting accumulator. */
/******************************************************************************/
#define BCC_REG_COULOMB_CNT1_ADDR  0x2EU
#define BCC_R_COULOMB_CNT_MSB_MASK 0xFFFFU
/******************************************************************************/
/* $2F COULOMB_CNT2 - Coulomb counting accumulator. */
/******************************************************************************/
#define BCC_REG_COULOMB_CNT2_ADDR  0x2FU
#define BCC_R_COULOMB_CNT_LSB_MASK 0xFFFFU
**
 * This macro returns 32 bit signed value of COULOMB_CNT.
 * Note: COULOMB_CNT1 register represents higher part of final value
 * (MSB). COULOMB_CNT2 is lower part (LSB).
 *
 * @param coulombCnt1 Content of register COULOMB_CNT1.
 * @param coulombCnt2 Content of register COULOMB_CNT2.
 */#define BCC_GET_COULOMB_CNT(coulombCnt1, coulombCnt2) \
  ((int32_t)(((uint32_t)((coulombCnt1) & BCC_R_COULOMB_CNT_MSB_MASK) << 0xFU) | \
  (((uint32_t)(coulombCnt2) & BCC_R_COULOMB_CNT_LSB_MASK)))
  
   rawVal = (int32_t)BCC_GET_COULOMB_CNT(measurements[BCC_MSR_COULOMB_CNT1],
            measurements[BCC_MSR_COULOMB_CNT2]);
			



 
 
 
Time = get_abs_time(); // get the absolute time
Read registers COULOMB_CNT1, COULOMB_CNT2 and CC_NB_SAMPLES;
COULOMB_CNT = (COULOMB_CNT1, COULOMB_CNT2); // concatenate MSB and  LSB
I_AVG = (COULOMB_CNT - COULOMB_CNT_old)/(CC_NB_SAMPLES -CC_NB_SAMPLES_old); // this is average current
DELTA_Q = I_AVG * (Time – Time_old); // this delta charge may be accumulated in adifferent variable
COULOMB_CNT_old = COULOMB_CNT;
CC_NB_SAMPLES_old = CC_NB_SAMPLES;
Time_old = Time;
Read any register different from COULOMB_CNT1, COULOMB_CNT2 andCC_NB_SAMPLES
Jump to step 1


The SOC can be then estimated by subtracting the DOD quantity from the SOH one.
SoH= State-of-Health
The state-of-health (SoH of a battery describes the difference between a battery being studied 
and a fresh battery and considers cell aging. It is defined as the ratio of the maximum battery
 charge to its rated capacity.
 
the discharge rate is given by the battery capacity (in Ah)
divided by the number of hours it takes to charge/discharge the battery.
For example, a battery capacity 
of 500 Ah that is theoretically discharged to its cut-off voltage 
in 20 hours will have a discharge rate of 500 Ah/20 h = 25 A.
 


Hi  JozefKozen,
                Having BCC software driver for MC33771C from elektronika sales 
and changed the code to meet the requirements and applied cell balancing as per the MC33771C
document procedure for individual cell to check the status but cell voltage doesn't change and why im getting 
CB_SHORT as logic 1 and driver is off is it related to cell balancing problem or any hardware issues or any register settings required.

Thanks & Regards

venkatesh

//when you send a balancing command for one cell, the driver will look at this bit CB_DRVEN, 
//and if it is set on 1, it proceeds to the balancing act.
BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, true);
//his only turns on the MOSFET connected to the balancing resistor
//set the timers for a small amount of time and measure the new cell values after each time until you get to the desired voltage.
balancingStatus = BCC_CB_SetIndividual(&g_bccData.drvConfig, BCC_CID_DEV1, highestCellIndex,true, CBINDV_CELL_TIME);
//Explicitly make CB_DRVEN bit is set to logic 0, then CB timers get reset to 0 and all CB MOSFETs are turned off. 
BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, false);
//Before the CB_DRVEN bit is set again to logic 1, all
//CBx_CFG registers need to be configured again. Otherwise, a cell balancing sequence
//will be started with the previous settings
BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, true);
balancingStatus = BCC_CB_SetIndividual(&g_bccData.drvConfig, BCC_CID_DEV1, highestCellIndex,true, CBINDV_CELL_TIME);

PRINTF("| BCC_CB_SetIndividual - %d \t|\r\n", balancingStatus);


we enabled  CB_DRVEN bit
CBx_CFG[CB_TIMER]  enabled   As an action, this only turns on the MOSFET connected to the balancing resistor
but  we are getting voltages on  all balancing resistors  and mosfets on.



BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, true);
balancingStatus = BCC_CB_SetIndividual(&g_bccData.drvConfig, BCC_CID_DEV1, highestCellIndex,true, CBINDV_CELL_TIME);
BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, false);
BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, true);
balancingStatus = BCC_CB_SetIndividual(&g_bccData.drvConfig, BCC_CID_DEV1, highestCellIndex,true, CBINDV_CELL_TIME);

I followed this procedure for cell balancing for BCC Driver MC33771C.
written this two functions for BCC_CB_DRV_ENABLED and  BCC_CB_ENABLED.
CBINDV_CELL_TIME=0;
BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, true);
balancingStatus = BCC_CB_SetIndividual(&g_bccData.drvConfig, BCC_CID_DEV1, highestCellIndex,true, CBINDV_CELL_TIME);
Applied cell balancing for individual cell As an action, this only turns on the MOSFET connected to the balancing resistor
but  we are getting voltages on  all balancing resistors  and mosfets on. please support to solve this issu how to individally 
enable the mosfets for particular cell.

 
•	The SYS_CFG1 register contains the CB_DRVEN bit initially disabled. 
•	The CB_DRVEN =1 For cell balance drivers to be active (BCC_CB_DRV_ENABLED)
•	Both the SYS_CFG1 [CB_DRVEN] and the CBx_CFG [CB_EN] bits must be set to logic 1.
•	CBx_CFG[CB_TIMER]=1 (BCC_CB_ENABLED)
•	Explicitly make CB_DRVEN bit is set to logic 0, then cell balancing timers get reset to 0 and all cell balancing MOSFETs are turned off. 
•	Before the CB_DRVEN bit is set again to logic 1, 
•	All CBx_CFG registers need to be configured again. 
•	CB_DRVEN=1
•	CBx_CFG=1
•	CB_MANUAL_PAUSE bit is set again to logic 0 
•	The contents of CBx_CFG [CB_TIMER] and ADC2_OFFSET_COMP [ALLCBOFF ON SHORT] bits must not be changed while balancing. 

 this are the functions included in the cell balancing
 CBINDV_CELL_TIME=0;
 BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, true);
balancingStatus = BCC_CB_SetIndividual(&g_bccData.drvConfig, BCC_CID_DEV1, highestCellIndex,true, CBINDV_CELL_TIME);
BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, false);
BCC_CB_Enable(&g_bccData.drvConfig, BCC_CID_DEV1, true);
balancingStatus = BCC_CB_SetIndividual(&g_bccData.drvConfig, BCC_CID_DEV1, highestCellIndex,true, CBINDV_CELL_TIME);

all mosfets are 
12/9/2021
Thanks for the reply and  I forgot to mention that i am using S32K144  board with MC33771B not MC33771A  is there any difference 
in the  procedure.so please let me know for the same.

I have  the MC33771B datasheet and also Just want to confirm that what are the cases
for getting all MOSFETS on at timewhen when i applied Cell Balancing for individual cell.

16/12/21
coulomb count resetting

MC33771C_ADC_CFG_ADC2_DEF(MC33771C_ADC_CFG_ADC2_DEF_16_BIT_ENUM_VAL)
as per document only power on reset  and ADC_CFG reset POR/ADC_CFG[CC_RST]
MC33771C_ADC_CFG_CC_RST(MC33771C_ADC_CFG_CC_RST_RESET_ENUM_VAL)





Hi,
   please support to to give clarity regarding  coulomb counting.
this Iam calculating the coulomb count and current in 12cell BMS  below are the tables for calculation of coulomb count
and current in  discharge  and charging calculations  but it is not updating sometimes when i charge with 3000maA it is showing 
40869 coulomb count only as -2187 discharge current  coulomb count -40859.

In M33771C data sheet coulomb count caloculations  do i need to update this register to  get the updated coulomb count values
write ADC_CFG[CC_RST] = 1;(MC33771C_ADC_CFG_CC_RST(MC33771C_ADC_CFG_CC_RST_RESET_ENUM_VAL)) //Reset to zero: 
or if i not update it will give previous results.

using 6Ah battery  
charging current 1A/hr it takes 6 hrs   
coulomb count is 22373  
discharging current -2187 mA it takes 3 hrs
coulomb count -40859 
for 3000mA it takes 2 hrs 
coulomb count 40869
 
as 6 Ah = 6*3600 = 21600 Coulombs 
this is the calculation 
rawVal = (int32_t)BCC_GET_COULOMB_CNT(measurements[BCC_MSR_COULOMB_CNT1],
			measurements[BCC_MSR_COULOMB_CNT2]);
PRINTF("| Coulomb Count  \t| %d  \t| \t\r\n",  (int32_t)rawVal);
ccsamples = measurements[BCC_MSR_CC_NB_SAMPLES];
PRINTF("| CC Samples	 \t| %d  \t| \t\r\n", ccsamples);
CCount = (int32_t) ( rawVal / ccsamples );
 

-----------------------------------------------
| Measurement    	|  value	|
-----------------------------------------------
| Cell 1 Voltage  	| 3889 mV 	|	
| Cell 2 Voltage  	| 3861 mV 	|	
| Cell 3 Voltage  	| 3907 mV 	|	
| Cell 4 Voltage  	| 3879 mV 	|	
| Cell 5 Voltage  	| 3989 mV 	|	
| Cell 6 Voltage  	| 3867 mV 	|	
| Cell 7 Voltage  	| 3855 mV 	|	
| Cell 8 Voltage  	| 3823 mV 	|	
| Cell 9 Voltage  	| 3881 mV 	|	
| Cell 10 Voltage  	| 3883 mV 	|	
| Cell 11 Voltage  	| 3823 mV 	|	
| Cell 12 Voltage  	| 3989 mV 	|	
| IC Temperature    	| 41 degC   	|	
| Coulomb Count    	| -120   	|	
| Current           	| -5 mA  	|	
| StackVoltage  	| 46589 mV  	|	
| BAT Temperature      	| 77 degC  	| 	
| SOC                  	| 0%         	| 	
| SOH                  	| 100%        	| 	
|------------------End-------------------------	
|
-----------------------------------------------
| Measurement    	|  value	|
-----------------------------------------------
| Cell 1 Voltage  	| 3234 mV 	|	
| Cell 2 Voltage  	| 3244 mV 	|	
| Cell 3 Voltage  	| 3240 mV 	|	
| Cell 4 Voltage  	| 3233 mV 	|	
| Cell 5 Voltage  	| 3239 mV 	|	
| Cell 6 Voltage  	| 3239 mV 	|	
| Cell 7 Voltage  	| 3242 mV 	|	
| Cell 8 Voltage  	| 3241 mV 	|	
| Cell 9 Voltage  	| 3239 mV 	|	
| Cell 10 Voltage  	| 3231 mV 	|	
| Cell 11 Voltage  	| 3237 mV 	|	
| Cell 12 Voltage  	| 3229 mV 	|	
| IC Temperature    	| 41 degC   	|	
| Coulomb Count    	| -40859   	|	
| Current           	| -2187 mA  	|	
| StackVoltage  	| 38784 mV  	|	
| BAT Temperature      	| 25 degC  	| 	
| SOC                  	| 40%         	| 	
| SOH                  	| 100%        	| 	
|------------------End-------------------------	

 
-----------------------------------------------
| Measurement    	|  value	|
-----------------------------------------------
| Cell 1 Voltage  	| 3521 mV 	|	
| Cell 2 Voltage  	| 3377 mV 	|	
| Cell 3 Voltage  	| 3375 mV 	|	
| Cell 4 Voltage  	| 3377 mV 	|	
| Cell 5 Voltage  	| 3374 mV 	|	
| Cell 6 Voltage  	| 3374 mV 	|	
| Cell 7 Voltage  	| 3376 mV 	|	
| Cell 8 Voltage  	| 3374 mV 	|	
| Cell 9 Voltage  	| 3373 mV 	|	
| Cell 10 Voltage  	| 3376 mV 	|	
| Cell 11 Voltage  	| 3374 mV 	|	
| Cell 12 Voltage  	| 3383 mV 	|	
| IC Temperature    	| 42 degC   	|	
| Coulomb Count    	| 22373   	|	
| Current           	| 1074 mA  	|	
| StackVoltage  	| 40602 mV  	|	
| BAT Temperature      	| 25 degC  	| 	
| SOC                  	| 97%         	| 	
| SOH                  	| 100%        	| 	
|------------------End------------------------	


-----------------------------------------------
| Measurement    	|  value	|
-----------------------------------------------
| Cell 1 Voltage  	| 3495 mV 	|	
| Cell 2 Voltage  	| 3345 mV 	|	
| Cell 3 Voltage  	| 3344 mV 	|	
| Cell 4 Voltage  	| 3345 mV 	|	
| Cell 5 Voltage  	| 3344 mV 	|	
| Cell 6 Voltage  	| 3345 mV 	|	
| Cell 7 Voltage  	| 3344 mV 	|	
| Cell 8 Voltage  	| 3344 mV 	|	
| Cell 9 Voltage  	| 3342 mV 	|	
| Cell 10 Voltage  	| 3343 mV 	|	
| Cell 11 Voltage  	| 3342 mV 	|	
| Cell 12 Voltage  	| 3343 mV 	|	
| IC Temperature    | 39 degC   |	
| Coulomb Count    	| 40869  	|	
| Current           | 3000 mA  	|	
| StackVoltage  	| 40212 mV  	|	
| BAT Temperature      	| 25 degC  	| 	
| SOC                  	| 95%         	| 	
| SOH                  	| 100%        	| 	
|------------------End-------------------------	


the unit of electric charge is a Coulomb (symbol: C). It is defined as the charge that is 
transported by a constant current of 1 ampere during 1 second. Hence, 1 C = 1 A * 1 s expressed
 in SI units.
 
 Is there a register write sequence or a command to reset or initialize the CC_Samples and CC_Registers to 0? 
 The thing is that once the MC3377xB is reset and initialized the CC registers does not seems to start counting
 and integrating for 0.
 
 Yes. By setting ADC2_OFFSET_COMP[CC_RST_CFG] to 1, reading any coulomb counter register (from $2D to $2F) 
 also resets the coulomb counter. Alternatively you can reset the COULOMB_CNTx and CC_NB_SAMPLES 
 registers by writing a 1 to ADC_CFG[CC_RST].
 
 
 Integrating the current into or out of a battery gives the relative value of its charge
 Coulomb Counting" needs a starting point. If the initial charge in the battery is known,
 from then on "Coulomb Counting" can be used to calculate its SOC.
 
 
 Hi,
    Iam working on calculation of SOC using coulomb count method using MC33771C Driver code below are the results 
 
 -----------------------------------------------
| Measurement    	|  value	|
-----------------------------------------------
| Cell 1 Voltage  	| 3521 mV 	|	
| Cell 2 Voltage  	| 3377 mV 	|	
| Cell 3 Voltage  	| 3375 mV 	|	
| Cell 4 Voltage  	| 3377 mV 	|	
| Cell 5 Voltage  	| 3374 mV 	|	
| Cell 6 Voltage  	| 3374 mV 	|	
| Cell 7 Voltage  	| 3376 mV 	|	
| Cell 8 Voltage  	| 3374 mV 	|	
| Cell 9 Voltage  	| 3373 mV 	|	
| Cell 10 Voltage  	| 3376 mV 	|	
| Cell 11 Voltage  	| 3374 mV 	|	
| Cell 12 Voltage  	| 3383 mV 	|	
| IC Temperature    | 42 degC   |	
| Coulomb Count    	| 22373   	|	
| Current           | 1074 mA  	|	
| StackVoltage  	| 40602 mV  |	
| BAT Temperature   | 25 degC  	| 	
|	
|------------------End------------------------

using datasheet information i claculated as
coulomb count=coulomb count/ccsamples;
Coulomb Count =22373uv
Rshunt=12500

I=22373/12500=1.78984
But in datasheet there we dont have any information regarding soc  and i need support to calculate the soc 
or any example code or any related document information.





Coulomb Count  	result value is  2136050216.
I am Using 6AH Battery .
but im getting CC measurement as  some random value
The SOC can be then estimated by subtracting the DOD quantity from the SOH one.
SoH= State-of-Health
The state-of-health (SoH of a battery describes the difference between a battery being studied
and a fresh battery and considers cell aging. It is defined as the ratio of the maximum battery
charge to its rated capacity.
the discharge rate is given by the battery capacity (in Ah)
divided by the number of hours it takes to charge/discharge the battery.
For example, a battery capacity
of 500 Ah that is theoretically discharged to its cut-off voltage
in 20 hours will have a discharge rate of 500 Ah/20 h = 25 A.

I_AVG = (rawVal - COULOMB_CNT_old)/(measurements[BCC_MSR_CC_NB_SAMPLES] -CC_NB_SAMPLES_old); // this is average current
COULOMB_CNT_old = rawVal;
CC_NB_SAMPLES_old =measurements[BCC_MSR_CC_NB_SAMPLES];
or
I_AVG = rawVal/measurements[BCC_MSR_CC_NB_SAMPLES] ;

1. 6 Ah = 6*3600 = 21600 Coulombs = 100% SOC
2. So 1% SOC = 21600/100 = 216 Coulombs
So for every change of 216 in Coulombs count, add 1% to SOC while charging Or substract 1% while discharging.
For a 12 Ah battery 1% = 432 Coulomb count, for 16 Ah it will be 576 Coulomb count etc.


21600 coulombs per hour if we charge 6Ah is  loaded 

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

long map2(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main()
{
int soc ,stack_volt=43000,dod;
soc = map2(stack_volt, 34800, 43800, 0, 100);
dod=100-soc;

printf("%d per\t%d",soc,dod);
return 0;
}




SOC(k) = SOC(k − 1) + ∆k *i(k)/3600


#if		BATLIFP
#define BMS_NOMINAL_VOLTAGE			38400U /*38.4v - 12*3.2*/
#define CELL_NOMINAL_VOLTAGE		3200U  /*3.2v*/
#define CELL_OV_MAX_VOLTAGE			3650U  /*3.65v*/
#define CELL_UV_MAX_VOLTAGE			2900U  /*2.9v*/
#define BMS_OCV_OV_MAX_VOLTAGE		43800U /*43.8v*/
#define BMS_OCV_MIN_VOLTAGE			35500U /*35.5v*/
#define BMS_UV_MIN_VOLTAGE			35000U /*35v - 12*2.9 */

#define BMS_CELLBALANCE_VOLTAGE		3500U  /*3.5v*/
#define CELLBALANCE_VOLTAGE_DIFF	10    /*10mV*/
#endif


The OCV of a battery cell denotes the potential
difference between the positive electrode and the
negative electrode when no current flows and the
electrode potentials are at equilibrium.

In order to obtain the ocv-soc relationship
experimentally, first if you begin with a fully discharged
battery and start charging it with very low c-rate, we
obtain the open circuit voltage UOCV, then ones we reach
a fully charge state at 100% we start discharge the cell
with the same low C-rate, we will see that the discharge
curve is different from the charge curve, which mean
that, for the same SOC level, the value OCVs cannot be
the same during charging and discharging because of the
hysteresis characteristic.




https://www.powertechsystems.eu/home/tech-corner/lithium-ion-state-of-charge-soc-measurement/



The general approach for measuring SOC is to measure very accurately 
both the coulombs and current flowing in and out of the cell stack under 
all operating conditions, and the individual cell voltages of each cell in 
the stack. This data is then employed with previously loaded cell pack 
data for the exact cells being monitored to develop an accurate SOC 
estimate. The additional data required for such a calculation includes 
the cell temperature, whether the cell is charging or discharging when 
the measurements were made, the cell age, and other relevant cell 
data obtained from the cell manufacturer. Sometimes it is possible to 
get characterization data from the manufacturer of how their Li-ion 
cells perform under various operating conditions. Once an SOC has 
been determined, it is up to the system to keep the SOC updated during 
subsequent operation, essentially counting the coulombs that flow in and 
out of the cells. The accuracy of this approach can be derailed by not 
knowing the initial SOC to an accurate enough state and by other factors, 
such as self discharge of the cells and leakage effects.


#include <stdio.h>

long map2(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main()
{
float soc ,stack_volt=43500,dod;
soc = map2(stack_volt, 34800, 43800, 0, 100);
dod=100-soc;
//initially soc is provided by manufacture or we can calculate using OCV method it should only
//read once  from EEprom
printf("soc:%.2f%\tdod:%.2f%\n",soc,dod);
//converting percentage to Ah
soc=soc*6;
soc=soc/100;
printf("soc:%fAh",soc);
float cc=21600,Rshunt=12500,current;
//the average ISENSE Value
current=cc/Rshunt;
printf("\ncur:%fA\n",current);
// we measured 1.72 A over 1 s which leads to 1.72 A.s or 0.00048 A.h.
current=1.728/3600;
printf("CC_Ah:%fAh\n",current);
//Adding intial soc & coulomb count method
soc=soc+current;
printf("soc:%f\n",soc);
//dispalying soc in percentage
soc=(soc/6)*100;
printf("soc:%.2f%\n",soc);
return 0;
}
/*******************************************SOC &DOD*********************************************/
#include <stdio.h>

long map2(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
#define Bat_Ah 6
int main()
{
float soc ,stack_volt=43500,dod;
soc = map2(stack_volt, 34800, 43800, 0, 100);

//initially soc is provided by manufacture or we can calculate using OCV method it should only
//read once from EEprom
//converting percentage to Ah
printf("intial soc:%.2f%\n",soc);
soc=soc*Bat_Ah;
soc=soc/100;
printf("intial soc:%.2fAh",soc);
float ibat=-1;
//initialize the COULOMB_CNTx registers at t0. After 0.5 s, you read again the register content
float cc=21600,Rshunt=12500,current;
//the average ISENSE Value
current=cc/Rshunt;
printf("\ncur:%.2fA\n",current);
// we measured 1.72 A over 1 s which leads to 1.72 A.s or 0.00048 A.h.
current=current/3600;
printf("CC_Ah:%fAh\n",current);
//Adding intial soc & coulomb count method
if(ibat>0)
{
soc=soc+current;
//dispalying soc in percentage
soc=(soc/Bat_Ah)*100;
printf("soc:%.2f%\n",soc);
}
if(ibat<0)
{
dod=soc-current;
dod=100-(dod/Bat_Ah)*100;
printf("dod:%.2f%\n",dod);
}
if(ibat==0)
{
soc=soc-current;
soc=(soc/Bat_Ah)*100;
printf("soc:%.2f%\n",soc);
}
return 0;
}

/*************************************************************************/

#include <stdio.h>

long map2(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
#define Bat_Ah 6
int main()
{
float soc ,stack_volt=41000,dod;
soc = map2(stack_volt, 34800, 43800, 0, 100);

//initially soc is provided by manufacture or we can calculate using OCV method it should only
//read once from EEprom
//converting percentage to Ah
printf("intial soc:%.2f%\n",soc);
soc=soc*Bat_Ah;
soc=soc/100;
printf("intial soc:%.2fAh",soc);
float ibat=1;
//initialize the COULOMB_CNTx registers at t0. After 0.5 s, you read again the register content
float cc=21600,Rshunt=12500,current;
//the average ISENSE Value
current=cc/Rshunt;
printf("\ncur:%.2fA\n",current);
// we measured 1.72 A over 1 s which leads to 1.72 A.s or 0.00048 A.h.
current=current/3600;
float isense=current;
printf("CC_Ah:%fAh\n",current);
//Adding intial soc & coulomb count method
if(ibat>0)
{for(int i=0;i<100;i++)
{
current+=isense;
}
//dispalying soc in percentage
soc=soc+current;
soc=(soc/Bat_Ah)*100;
printf("soc:%.2f%\n",soc);
}
if(ibat<0)
{
for(int i=0;i<100;i++)
{
current+=isense;
}
dod=soc-current;
dod=100-(dod/Bat_Ah)*100;
printf("dod:%.2f%\n",dod);
}
if(ibat==0)
{
soc=soc-current;
soc=(soc/Bat_Ah)*100;
printf("soc:%.2f%\n",soc);
}
return 0;
}
/********************12400*****************************************************/
#include <stdio.h>

long map2(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
#define Bat_Ah 6
int main()
{
float soc ,stack_volt=43800,dod;//stackvol=43800 for dod & 34800 for soc
soc = map2(stack_volt, 34800, 43800, 0, 100);

//initially soc is provided by manufacture or we can calculate using OCV method it should only
//read once from EEprom
//converting percentage to Ah
printf("intial soc:%.2f%\n",soc);
soc=soc*Bat_Ah;
soc=soc/100;
printf("intial soc:%.2fAh",soc);
float ibat=-1;
//initialize the COULOMB_CNTx registers at t0. After 0.5 s, you read again the register content
float cc=21600,Rshunt=12500,current;
//the average ISENSE Value
current=cc/Rshunt;
printf("\ncur:%.2fA\n",current);
// we measured 1.72 A over 1 s which leads to 1.72 A.s or 0.00048 A.h.
current=current/3600;
float isense=current;
printf("CC:%fAh\n",current);
//Adding intial soc & coulomb count method
if(ibat>0)
{
    for(int i=0;i<12400;i++)//12400
    {
    current+=isense;
    }
    //dispalying soc in percentage
    soc=soc+current;
    soc=(soc/Bat_Ah)*100;
    printf("soc:%.2f%\n",soc);
}
if(ibat<0)
{
    for(int i=0;i<12400;i++)//12400
    {
    current-=isense;
    }
    dod=soc+current;
    dod=100-(dod/Bat_Ah)*100;
    printf("dod:%.2f%\n",dod);
}
if(ibat==0)
    {
    soc=soc-current;
    soc=(soc/Bat_Ah)*100;
    printf("soc:%.2f%\n",soc);
    }
return 0;
}


/******************************************/
/***********with flag********************/
#include <stdio.h>

long map2(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
#define Bat_Ah 6
int main()
{
float soc ,stack_volt=43800,dod;//stackvol=43800 for dod & 34800 for soc
char flag=0;
//initially soc is provided by manufacture or we can calculate using OCV method it should only
//read once from EEprom
//converting percentage to Ah
if(flag==0)
{
    soc = map2(stack_volt, 34800, 43800, 0, 100);
    printf("intial soc:%.2f%\n",soc);
    soc=soc*Bat_Ah;
    soc=soc/100;
    printf("intial soc:%.2fAh",soc);
    flag=1;
}
float ibat=-1;
//initialize the COULOMB_CNTx registers at t0. After 0.5 s, you read again the register content
float cc=21600,Rshunt=12500,current;
//the average ISENSE Value
current=cc/Rshunt;
printf("\ncur:%.2fA\n",current);
// we measured 1.72 A over 1 s which leads to 1.72 A.s or 0.00048 A.h.
current=current/3600;
float isense=current;
printf("CC:%fAh\n",current);
//Adding intial soc & coulomb count method
if(ibat>0)
{
    for(int i=0;i<12400;i++)//12400
    {
    current+=isense;
    }
    //dispalying soc in percentage
    soc=soc+current;
    soc=(soc/Bat_Ah)*100;
    printf("soc:%.2f%\n",soc);
}
if(ibat<0)
{
    for(int i=0;i<6000;i++)//12400
    {
    current-=isense;
    }
    dod=soc+current;
    dod=100-(dod/Bat_Ah)*100;
    printf("dod:%.2f%\n",dod);
}
if(ibat==0)
    {
    soc=soc-current;
    soc=(soc/Bat_Ah)*100;
    printf("soc:%.2f%\n",soc);
    }
return 0;
}











#include <stdio.h>

long map2(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
#define Bat_Ah 6
int main()
{
float soc ,stack_volt=34800,dod;//stackvol=43800 for dod & 34800 for soc
char flag=0;
//initially soc is provided by manufacture or we can calculate using OCV method it should only
//read once from EEprom
//converting percentage to Ah
if(flag==0)
{
    soc = map2(stack_volt, 34800, 43800, 0, 100);
    printf("intial soc:%.2f%\n",soc);
    soc=soc*Bat_Ah;
    soc=soc/100;
    printf("intial soc:%.2fAh",soc);
    flag=1;
}
float ibat=1;
//initialize the COULOMB_CNTx registers at t0. After 0.5 s, you read again the register content
float cc=21600,Rshunt=12500,current;
//the average ISENSE Value
current=cc/Rshunt;
printf("\ncur:%.2fA\n",current);
// we measured 1.72 A over 1 s which leads to 1.72 A.s or 0.00048 A.h.
current=current/3600;
float isense=current;
printf("CC:%fAh\n",current);
//Adding intial soc & coulomb count method
if(ibat>0)
{
    for(int i=0;i<400;i++)//12400
    {
    current+=isense;
    }
    //dispalying soc in percentage
    soc=soc+current;
    soc=(soc/Bat_Ah)*100;
    dod=100-soc;
    printf("dod:%.2f\nsoc:%.2f\n",dod,soc);
}
if(ibat<0)
{
    for(int i=0;i<600;i++)//12400
    {
    current-=isense;
    }
    dod=soc+current;
    soc=(soc/Bat_Ah)*100;
    
    dod=100-(dod/Bat_Ah)*100;
    soc=100-dod;
    printf("dod:%.2f%\nsoc:%.2f\n",dod,soc);
}
if(ibat==0)
    {
    soc=soc-current;
    soc=(soc/Bat_Ah)*100;
    printf("soc:%.2f%\n",soc);
    }
return 0;
}

30-12-2021

#include <stdio.h>

long map2(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
#define Bat_Ah 6
int main()
{
float soc ,stack_volt=41800,dod;//stackvol=43800 for dod & 34800 for soc
char flag=0;
//initially soc is provided by manufacture or we can calculate using OCV method it should only
//read once from EEprom
//converting percentage to Ah
if(flag==0){
    soc = map2(stack_volt, 34800, 43800, 0, 100);
    printf("intial soc:%.2f%\n",soc);
    soc=soc*Bat_Ah;
    soc=soc/100;
    printf("intial soc:%.2fAh",soc);
    flag=1;
}
float ibat=1;
//initialize the COULOMB_CNTx registers at t0. After 0.5 s, you read again the register content
float cc=21600,Rshunt=12500,current;
//the average ISENSE Value
current=cc/Rshunt;
printf("\ncur:%.2fA\n",current);
// we measured 1.72 A over 1 s which leads to 1.72 A.s or 0.00048 A.h.
current=current/3600;
float isense=current;
printf("CC:%fAh\n",current);
//Adding intial soc & coulomb count method
if(ibat>0){
    for(int i=0;i<1400;i++){
    current+=isense;
    }
    //dispalying soc in percentage
    soc=soc+current;
    soc=(soc/Bat_Ah)*100;
    dod=100-soc;
    printf("dod:%.2f%\nsoc:%.2f%\n",dod,soc);
    soc=soc*Bat_Ah;
    soc=soc/100;
    printf("final soc:%.2fAh",soc);
}
if(ibat<0){
    for(int i=0;i<600;i++){
    current-=isense;
    }
    dod=soc+current;
    soc=(soc/Bat_Ah)*100;
    dod=100-(dod/Bat_Ah)*100;
    soc=100-dod;
    printf("dod:%.2f%\nsoc:%.2f%\n",dod,soc);
    soc=soc*Bat_Ah;
    soc=soc/100;
    printf("final soc:%.2fAh",soc);
}
if(ibat==0){
    soc=soc-current;
    soc=(soc/Bat_Ah)*100;
    dod=100-soc;
    printf("dod:%.2f%\nsoc:%.2f%\n",dod,soc);
    }
return 0;
}






#include <stdio.h>

long map2(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
#define Bat_Ah 6
int main()
{
float soc ,stack_volt=41800,dod;//stackvol=43800 for dod & 34800 for soc
char flag=0;
//initially soc is provided by manufacture or we can calculate using OCV method it should only
//read once from EEprom
//converting percentage to Ah
if(flag==0){
    soc = map2(stack_volt, 34800, 43800, 0, 100);
    printf("intial soc:%.2f%\n",soc);
    soc=soc*Bat_Ah;
    soc=soc/100;
    printf("intial soc:%.2fAh",soc);
    flag=1;
}
float ibat=1;
//initialize the COULOMB_CNTx registers at t0. After 0.5 s, you read again the register content
float cc=21600,Rshunt=12500,current;
//the average ISENSE Value
current=cc/Rshunt;
printf("\ncur:%.2fA\n",current);
// we measured 1.72 A over 1 s which leads to 1.72 A.s or 0.00048 A.h.
current=current/3600;
float isense=current;
printf("CC:%fAh\n",current);
//Adding intial soc & coulomb count method
if(ibat>0){
    for(int i=0;i<1400;i++){
    current+=isense;
    }
    //dispalying soc in percentage
    soc=soc+current;
    soc=(soc/Bat_Ah)*100;
    dod=100-soc;
    printf("dod:%.2f%\nsoc:%.2f%\n",dod,soc);
    soc=soc*Bat_Ah;
    soc=soc/100;
    printf("final soc:%.2fAh",soc);
}
if(ibat<0){
    for(int i=0;i<600;i++){
    current-=isense;
    }
    dod=soc+current;
    soc=(soc/Bat_Ah)*100;
    dod=100-(dod/Bat_Ah)*100;
    soc=100-dod;
    printf("dod:%.2f%\nsoc:%.2f%\n",dod,soc);
    soc=soc*Bat_Ah;
    soc=soc/100;
    printf("final soc:%.2fAh",soc);
}
if(ibat==0){
    soc=soc-current;
    soc=(soc/Bat_Ah)*100;
    dod=100-soc;
    printf("dod:%.2f%\nsoc:%.2f%\n",dod,soc);
    }
return 0;
}
//code integrate to bms
LPI2C0_read(uint8_t s_r_address, uint8_t s_reg_address, uint8_t *p_buffer, uint8_t n_bytes)//in main function read soc values




#define Bat_Ah 6
    uint8_t soc_set=1; 
	uint32_t dod;
    if(soc_set==1){//store in eeprom OCV calculated initially
	Soc = bmsOCVmap(StackVoltage, 34800, 43800, 0, 100);  ///*34.8v - 12*2.9*//*43.8v*- 12*3.65*/
	eeprom_write(soc);//store in eeprom
	soc_set=0;
	uint32_t temp=soc;
	write(temp);
	write(temp>>8);
	
	EEPROM_write(uint8_t s_w_address, uint16_t *s_reg_address, uint8_t byte)
	}
	
	if(Soc < 0)	Soc = 0;
	else if(Soc > 100)	Soc = 100;
	BatPack.SOC = Soc;
	float iavg;
	
	uint8_t secondsflag;//get rtc value every 1second count
    if(secondsflag==1){
		iavg=CCount/BMS_RSHUNT;
		secondsflag=0;
	}
	if(BatPack.i32Current>0){
		soc=soc+iavg;
        soc=(soc/Bat_Ah)*100;
        dod=100-soc;
		
	}
		if(BatPack.i32Current<0){
		soc=soc+iavg; 
		soc=(soc/Bat_Ah)*100;
		dod=100-(dod/Bat_Ah)*100;
		soc=100-dod;
		
	}
		if(BatPack.i32Current==0){
		soc=soc+iavg; 
        soc=(soc/Bat_Ah)*100;
        dod=100-soc;
		
	}
	PRINTF("| SOC                  \t| %d%c         \t| \t\r\n", BatPack.SOC, '%');
	PRINTF("| DOD                  \t| %d%c         \t| \t\r\n", dod, '%');
	soc=soc*Bat_Ah;
    soc=soc/100;	
	
	PRINTF("| SOC_AH                  \t| %d%c         \t| \t\r\n", BatPack.SOC, ' ');
	
	03/01/2022
	
	BatPack.SOC = Soc;
         temp=Soc;
         BCC_MCU_WaitMs(1000);
	     if(soc_set==0){
				write_value=temp&0xff;//lower byte
				EEPROM_write(EEPROM_WRITE,&write_address0,write_value);
				//BCC_MCU_WaitMs(1500);
				//write_value1=(temp&0xff00)>>8;
				//EEPROM_write(EEPROM_WRITE,&write_address1,write_value1);    //hiher byte
				//BCC_MCU_WaitMs(1500);
				EEPROM_write(EEPROM_WRITE,&write_address2,soc_set);
				EEPROM_read(EEPROM_READ,&write_address0,&read_val0,1);
				//EEPROM_read(EEPROM_READ,&write_address1,&read_val1,1);
				EEPROM_read(EEPROM_READ,&write_address2,&read_val2,1);
				soc_set=1;
	        }
			//BCC_MCU_WaitMs(1500);
		   //EEPROM_read_16(EEPROM_READ, &write_address0, &read_val0,2);
			//EEPROM_read(EEPROM_READ,&write_address0,&read_val0,1);
			//BCC_MCU_WaitMs(1500);
			//EEPROM_read(EEPROM_READ,&write_address1,&read_val1,1);
			//BCC_MCU_WaitMs(1500);
			//EEPROM_read(EEPROM_READ,&write_address2,&read_val2,1);
			//uint16_t initial_Soc=((read_val1)<<8)+read_val0;//higher byte +lower byte
	     EEPROM_read(EEPROM_READ,&write_address0,&read_val0,1);
	        initial_Soc=read_val0;
			float initial_Soc1;
			if(initial_Soc < 0)	initial_Soc = 0;
			else if(initial_Soc > 100)	initial_Soc = 100;
			PRINTF("soc_set :%d %\r\n", soc_set);   //BYTE READ*/
	  		PRINTF("initial soc :%d %\r\n", initial_Soc);   //BYTE READ*/
	  		initial_Soc=initial_Soc*Bat_Ah;//100*6Ah
	  		initial_Soc1=(float)initial_Soc/100;//600Ah/100
	  		PRINTF("initial:%f Ah\r\n", write_address0,initial_Soc1);   //BYTE READ*/
	  		RTC_READ(TIME_FORMAT, AM_PM,&bin);
	  		int prev_seconds=bin.seconds;
	  		//BCC_MCU_WaitSec(1);
	  		//int prev_seconds=0;
	  		RTC_READ(TIME_FORMAT, AM_PM,&bin);
	  		if(bin.seconds-prev_seconds==1||bin.seconds-prev_seconds==59||bin.seconds-prev_seconds==-59){
				 //prev_seconds=bin.seconds;
				iavg=(float)CCount/BMS_RSHUNT;//21600/12500=1.78
				iavg=(float)iavg/3600;//1.78/3600=0.00048
				PRINTF("iavg :%f \r\n", iavg);
				//secondsflag=0;
		      }
	  		/*************charging***************/
		if(BatPack.i32Current>0){
			initial_Soc1=(float)initial_Soc1+iavg;//4ah+iavg
			initial_Soc1=(float)(initial_Soc1/Bat_Ah)*100;//in percentage
	       // dod=100-initial_Soc1;
		}
		/*************discharge******************/
		if(BatPack.i32Current<0){
			initial_Soc1=(float)initial_Soc1-iavg;				
			dod=(float)(initial_Soc1/Bat_Ah)*100;
			//Soc=100-dod;
		}
		/***********self discharge*************/
			if(BatPack.i32Current==0){
			initial_Soc1=(float)initial_Soc1-iavg;//4ah+iavg
			initial_Soc1=(float)(initial_Soc1/Bat_Ah)*100;//in percentage
	      
		}
		//PRINTF("| SOC                  \t| %d%c         \t| \t\r\n", BatPack.SOC, '%');
		PRINTF("final:%f %\r\n", write_address0,initial_Soc1);
		//PRINTF("| DOD                  \t| %d%c         \t| \t\r\n", dod, '%');
		initial_Soc1=initial_Soc1*Bat_Ah;
		initial_Soc1=initial_Soc1/100;
	    PRINTF("final :%f Ah\r\n", write_address0,initial_Soc1);
	//	PRINTF("| SOC_AH               \t| %d%c         \t| \t\r\n", BatPack.SOC, ' ');