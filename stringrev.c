// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#define debug 1
int main() {
    // Write C code here
  char s[20]="hello";
  //gets(s);
  char n=strlen(s);
  char start=0,end=n-1;
  while(start<end){
      s[start]^=s[end];
      #if debug
      printf("\nstart1=%c",s[start]);
      #endif
      s[end]^=s[start];
      #if debug
      printf("\tend1=%c",s[end]);
      #endif
      s[start]^=s[end];
      #if debug
      printf("\tstart2=%c",s[start]);
      #endif
      start++;
      end--;
  }
    printf("\n%s",s);
    return 0;
}
