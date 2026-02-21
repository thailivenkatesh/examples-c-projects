// Online C compiler to run C program online
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
int z;
while(z<100)
{
    if(soc<0)soc=0;
    if(soc>100)soc=100;
    z++;
if(ibat>0){
  
    //dispalying soc in percentage
    soc=soc+current;
    soc=(soc/Bat_Ah)*100;
    dod=100-soc;
    printf("\nsoc:%.2f%\n",soc);
    soc=soc*Bat_Ah;
    soc=soc/100;
    printf("final soc:%.2fAh",soc);
}
if(ibat<0){
  
    soc=soc-current;
  
    dod=(soc/Bat_Ah)*100;
   
    printf("\ndod:%.2f%\n",dod);
    dod=dod*Bat_Ah;
    dod=dod/100;
    printf("final dod:%.2fAh",dod);

}
if(ibat==0){
    //soc=soc-current;
    soc=(soc/Bat_Ah)*100;
    dod=100-soc;
    printf("dod:%.2f%\nsoc:%.2f%\n",dod,soc);
    }
}
return 0;
}