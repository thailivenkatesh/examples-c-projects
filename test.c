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
/*To make this code "better," we should focus on portability, type safety, and clarity. Using %ld for a short is technically a mismatch, and relying on short can be risky across different systems.
Here is the improved version using fixed-width types (which are standard in embedded and systems programming) and a more explicit printf.*/
#include <stdio.h>
#include <stdint.h> // For int8_t, int16_t (guarantees size)

#pragma pack(1)
typedef union {
    struct {
        int8_t len;   // Exactly 1 byte
        int16_t dat;  // Exactly 2 bytes
    } d;
    uint8_t rec_dat[3];
} data_t; // "t" suffix is a standard convention for types

int main() {
    data_t val;

    // Explicitly assigning bytes to the raw buffer
    val.rec_dat[0] = 1;
    val.rec_dat[1] = 42;
    val.rec_dat[2] = 43;

    // %d is used for int (short promotes to int in printf)
    // %hd is the specific formatter for 'short'
    printf("Raw Bytes: %d, %d, %d\n", val.rec_dat[0], val.rec_dat[1], val.rec_dat[2]);
    printf("Interpreted Short (dat): %hd\n", val.d.dat);

    return 0;
}
