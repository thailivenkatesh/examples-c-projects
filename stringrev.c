// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>

int main() {
    // Write C code here
  char s[20];
  gets(s);
  char n=strlen(s);
  char start=0,end=n-1;
  while(start<end){
      s[start]^=s[end];
      printf("\nstart1=%c",s[start]);
      s[end]^=s[start];
      printf("\tend1=%c",s[end]);
      s[start]^=s[end];
      printf("\tstart2=%c",s[start]);
      start++;
      end--;
  }
    printf("\n%s",s);
    return 0;
}