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
/*
This code implements an in-place string reversal algorithm using the XOR swap trick. It avoids using a temporary variable by leveraging bitwise operations to swap characters. 
Code Analysis
Initialization: It calculates the string length (n) and sets two pointers: start at the beginning (index 0) and end at the last character (index n-1).
XOR Swap Logic: Inside the loop, it performs three XOR operations to swap s[start] and s[end] without a third variable:
A = A ^ B
B = B ^ A (effectively B = B ^ (A ^ B), which results in the original A)
A = A ^ B (effectively A = (A ^ B) ^ A, which results in the original B)
Debugging: The #if debug directives allow you to see the bitwise transformation of characters in real-time if debug is set to 1.
Step-by-Step Execution
Using the input "helloworld" (length 10):
Step 1: Setup
s = "helloworld"
start = 0 (pointing to 'h')
end = 9 (pointing to 'd')
Step 2: Iteration 1 (Swap 'h' and 'd')
s[0] XOR s[9] stores a combined bitmask in s[0].
s[9] becomes 'h'.
s[0] becomes 'd'.
Increment start to 1, decrement end to 8.
Step 3: Iteration 2 (Swap 'e' and 'l')
s[1] ('e') and s[8] ('l') are swapped using the same XOR logic.
start moves to 2, end moves to 7.
Step 4: Continue Looping
The process repeats for the middle characters: ('l' with 'l'), ('l' with 'o'), and ('o' with 'w').
The loop stops when start (5) is no longer less than end (4).
Step 5: Output
The printf statement displays the modified array: dlrowolleh.
*/
