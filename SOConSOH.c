#include<stdio.h>
 float bmsOCVmap(float x, long in_min, float in_max, long out_min, long out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 }

int main(){
    printf("variable soc \t");
   float  Soc, soh;
   float  actualsoc=96;
    soh=97;
    Soc = bmsOCVmap(actualsoc, 0, soh, 0, 100); 
    if(Soc>=100)Soc=100;printf("%.2f",Soc);
}