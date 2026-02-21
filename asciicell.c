#include<stdio.h>
#include<string.h>
char u8PktBuf[84];
#define MAXBYTES 84
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

void FormPacket1(int cell,int cell1,int cell2,int cell3,int cell4,int cell5,int cell6,int cell7,int cell8,int cell9,int cell10,int cell11,int cell12,int cell13,int lpcount, long s32mA,int Temp) {
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
	u8PktBuf[3 + i] = (dstr[i + 1]);
	}
	
	//cell1
	dstr = Itoa(dst, cell, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[11 + i] = (dstr[i+1]);	//45678 digits
	}	
   //cell2
	dstr = Itoa(dst, cell1, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[15 + i] = (dstr[i+1]);	//45678 digits
	}	
    //cell3	
	dstr = Itoa(dst, cell2, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[19 + i] = (dstr[i+1]);	//45678 digits
	}
	//cell4
	dstr = Itoa(dst, cell3, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[23 + i] = (dstr[i+1]);	//45678 digits
	}	
   //cell5
	dstr = Itoa(dst, cell4, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[27 + i] = (dstr[i+1]);	//45678 digits
	}	
	//cell6
	dstr = Itoa(dst, cell5, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[31 + i] = (dstr[i+1]);	//45678 digits
	}
	//cell7
	dstr = Itoa(dst, cell6, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[35 + i] = (dstr[i+1]);	//45678 digits
	}	
   //cell8
	dstr = Itoa(dst, cell7, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[39 + i] = (dstr[i+1]);	//45678 digits
	}	
	//cell9
	dstr = Itoa(dst, cell8, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[43 + i] = (dstr[i+1]);	//45678 digits
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
	//cell13
	dstr = Itoa(dst, cell12, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[59 + i] = (dstr[i+1]);	//45678 digits
	}	
	//cell14
	dstr = Itoa(dst, cell13, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[63 + i] = (dstr[i+1]);	//45678 digits
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
			u8PktBuf[67 + i] = temp[i];	 //1 234567 digits
		}
	} else {
		for (i = 0; i < 8; i++) {
			u8PktBuf[67 + i] = (dstr[i+1]);	 //1 234567 digits
		}
		//u8PktBuf[16] = '+'; //C
	}
    //Temperature
	dstr = Itoa(dst,Temp, 4);
	for (i = 0; i < 4; i++) {
		u8PktBuf[75 + i] = (dstr[i + 1]);	 //5678 digits
	}
    for(i=0;i<79;i++)
	printf("%d\t",u8PktBuf[i]);
    printf("\n");
}

	//Current
	int main(){
		int i;
	
	FormPacket1(3001,3002,3003,3004,3005,3006,3007,3008,3009,3010,3011,3012,3013,3014,202,-337,20);
	return 0;
	}
	

	
	
	