 #include <stdio.h>

#define BMS_MAX_CELLS 12
int SortedCV[BMS_MAX_CELLS];
#define DEBUG  1
 int CellVoltages[]={3200,3201,2356,6798,1234,4321,5674,5437,1906,4000,9000,3000};
  void bmsGetHLVoltageIndexes(int *lowestCellvoltage, int *highestCellvoltage, int *highestCell, int *lowestCell)
 {

 	int i = 0,j, n = BMS_MAX_CELLS;
 	*highestCellvoltage = (int) SortedCV[n-1];
 	*lowestCellvoltage = (int) SortedCV[0];
 	*highestCell = *lowestCell = i;

 	j=0;
 	for (i = 1; i < n; ++i) {
 		if (CellVoltages[i] == *highestCellvoltage) {
 			*highestCell = i;
 			*highestCellvoltage = (int) CellVoltages[i];
 			//PRINTF(" H_Voltage - %d mV, index-%d \t |\r\n", BatPack.CellVoltages[i],i);
 		} else if (CellVoltages[i] == *lowestCellvoltage) {
 			*lowestCell = i;
 			*lowestCellvoltage = (int) CellVoltages[i];
 			//PRINTF(" L_Voltage - %d mV, index-%d \t |\r\n", BatPack.CellVoltages[i],i);
 		}
 	}
 #if	DEBUG
 	printf("| Cell Index b H L - %d,%d\t\r\n", *highestCell,*lowestCell );
 #endif
 	if ( *highestCell > 3 ) //0,1,2,3,4,(6)7,(7)8,(8)9,(9)10,(10)11,(11)12,(12)13,(13)14
 	{
 		*highestCell = (*highestCell + 2); // Adjust the cell index for 12 cells
 	}
	*lowestCell=1;

 #if	DEBUG
 	printf("| HighVlt - %d , LowVlt - %d \r\n", *highestCellvoltage, *lowestCellvoltage);
 	printf("| Cell Index a H L Index- %d,%d\t\r\n", *highestCell,*lowestCell );
 #endif
 }
 int bmsVoltageSorting()
 {

 	int n, c, d, swap;
 	n = BMS_MAX_CELLS;

 	for (int k = 0; k < n; k++) { // Copy to sort the voltages
 		SortedCV[k] = CellVoltages[k];
 	}


 	for (c = 0; c < (n - 1); c++)
 	{
 		for (d = 0; d < (n - c - 1); d++)
 		{
 			if (SortedCV[d] > SortedCV[d + 1]) /* For decreasing order use '<' instead of '>' */
 			{
 				swap = SortedCV[d];
 				SortedCV[d] = SortedCV[d + 1];
 				SortedCV[d + 1] = swap;
 			}
 		}
 }
 #if	DEBUG
 	for (c = 0; c < BMS_MAX_CELLS; c++)
 		printf("\n| SortedVoltage\t| %d mV \t |\n", SortedCV[c]);
 #endif


 return 1;

 }

 int main()
 {	int lowestCellvoltage,highestCellvoltage,highestCellIndex,lowestCell;	
	
	bmsVoltageSorting(); /*Ascending order*/
	bmsGetHLVoltageIndexes(&lowestCellvoltage, &highestCellvoltage,&highestCellIndex,&lowestCell);
 }