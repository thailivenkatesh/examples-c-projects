#include<stdio.h>
typedef int uint8_t;
uint8_t bcd_to_binary(uint8_t value)
{
	  uint8_t m,n;
	  m=(uint8_t)((value>>4)* 10);
	  n=value & (uint8_t)0X0F;
	  return m+n;
}
uint8_t binary_to_bcd( uint8_t value)
{
	  uint8_t m,n;
	  uint8_t bcd=0;

	  if(value >=10)
	  {
		  m=value/10;
		  n=value%10;
		  bcd=( uint8_t) ((m<<4) | n) ;
	  }

	  return bcd;
}

int main()
{
	
uint8_t a,i;
//for(i=0;i<50;i++){
	//a=bcd_to_binary(10);
	a=binary_to_bcd(11);
    printf("%d\n",a);
//}
    return 0;
}