#include<stdio.h>
#include<string.h>
char u8PktBuf[31];
#define MAXBYTES 31
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
	dstr = Itoa(dst, intmV, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[0 + i] = (dstr[i+1]);	//45678 digits
	}	
    for(i=0;i<4;i++)
	printf("%d\t",u8PktBuf[i]);
printf("\n");
}
void FormPacket(int intmV, long s32mA, int intTemp, int lpcount,char event) {
	int i,j;
	char *dstr = 0;
	char dst[25];
	char u8NL[3];
	char temp[8];
	
#if	BMSDEBUG
	char tbuf[80]; //remove later
#endif

	memset(u8PktBuf,0,MAXBYTES);

	u8PktBuf[0] = '#';
	u8PktBuf[1] = 'R';
	u8PktBuf[2] = 'A';
	//lcnt
	dstr = Itoa(dst, lpcount, 8);
	for (i = 0; i < 8; i++) {
	u8PktBuf[3 + i] = (dstr[i + 1])-48;
	}
	//Voltage
	dstr = Itoa(dst, intmV, 8);
	for (i = 0; i < 8; i++) {
		u8PktBuf[11 + i] = (dstr[i + 4])-48;	//45678 digits
	}

	//Current
	//s32mA = 987654;
	//s32mA = 0;
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
			temp[i] = dstr[j+1]-48;
			i++;
		}
		for (i = 0; i < 7; i++) {
			u8PktBuf[16 + i] = temp[i];	 //1 234567 digits
		}
	} else {
		for (i = 0; i < 8; i++) {
			u8PktBuf[16 + i] = (dstr[i+1])-48;	 //1 234567 digits
		}
		//u8PktBuf[16] = '+'; //C
	}
	
//	if(s32mA == 0) { //NCND
//		u8PktBuf[16] = '0';
//	}

	//Temperature
	dstr = Itoa(dst, intTemp, 8);
	for (i = 0; i < 8; i++) {
		u8PktBuf[23 + i] = (dstr[i + 5])-48;	 //5678 digits
	}
	u8PktBuf[27] = event;
	u8PktBuf[28] = '.';
    for(i=0;i<29;i++)
	printf("%d\t",u8PktBuf[i]);

}
	
	//Current
	int main(){
		int i;
	FormPacket(34800,-223,16,202,2);
	printf("\n");
	//for (i=0;i<14;i++)
	//FormPacket1(read_arr[i]);
	return 0;
	}