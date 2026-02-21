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