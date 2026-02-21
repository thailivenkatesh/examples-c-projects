#include <stdio.h>

int main()
{
    int a=16909060;//1 0000 0010 0000 0011 0000 0100//1020304
    int rx[4];
    printf("%d\n",a);
    rx[0]=(a)&0xf000000;
    rx[0]=(a>>24);    
    rx[1]=(a)&(0xff0000);
    rx[1]=rx[1]>>16;    
    rx[2]=a&(0xff00);
    rx[2]=rx[2]>>8;    
    rx[3]=(a)&0xff;    
    for(int i=0;i<4;i++)
    printf("%d\n",rx[i]);

int i=rx[0]*1000+rx[1]*100+rx[2]*10+rx[3];
printf("%d",i);
    return 0;
}