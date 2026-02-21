#include<stdio.h>
// function to swap elements
 long bmsOCVmap(long x, long in_min, long in_max, long out_min, long out_max)
 {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 }
int main(){
;
int i=bmsOCVmap(35, 0, 100, 30, 58);
	
	
		printf("%d\t",i);
		return 0;
}