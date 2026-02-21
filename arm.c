// arm
#include <stdio.h>
int main() {
    int n=153,rem,arm=0,temp;
    temp=n;
    while(n>0){
    rem=n%10;
    arm+=(rem*rem*rem);
    n=n/10;
    }
    if(temp==arm)
       printf("arm:%d",arm);
    else
       printf("not arm:%d",arm);
    return 0;

}
//universal Armstrong checker
#include <stdio.h>
#include <math.h>

int main() {
    int n = 1634; // Test with a 4-digit Armstrong number
    int rem, arm = 0, temp, digits = 0;
    
    temp = n;
    
    // Step 1: Count the number of digits
    int countTemp = n;
    while (countTemp > 0) {
        countTemp /= 10;
        digits++;
    }
    
    // Step 2: Calculate sum of digits raised to the power of 'digits'
    while (n > 0) {
        rem = n % 10;
        // Use 'digits' as the exponent, not 'n'
        arm += round(pow(rem, digits)); 
        n = n / 10;
    }
    
    if (temp == arm)
        printf("arm:%d\n", arm);
    else
        printf("not arm: calculated %d for original %d\n", arm, temp);
        
    return 0;
}
