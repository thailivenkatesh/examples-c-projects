#include <stdio.h>
#pragma pack(1)
typedef union {
       struct {
           char len;
           short dat;
       }d;
       char rec_dat[3];
}data_;
int main()
{
    data_ val;
	
    val.rec_dat[0]=1;
   val.rec_dat[1]=42;
    //val.d.dat=90;
    val.rec_dat[2]=43;
   printf("%ld",(val.d.dat));
	return 0;
}