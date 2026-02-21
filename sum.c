// sum
#include <stdio.h>
int main() {
    int n=123,sum=0,rem;
    while(n>0){
    rem=n%10;
    sum+=rem;
    n=n/10;
    }
       printf("sum:%d",sum);
return 0;

}
This code calculates the sum of digits of an integer. It uses a mathematical loop to "peel off" digits one by one from the end of the number.
Code Analysis
Modulo Operator (%): Used to extract the last digit. 123 % 10 gives 3.
Accumulation: The extracted digit is added to the sum variable.
Integer Division (/): Used to remove the last digit. 123 / 10 gives 12.
Termination: The loop runs as long as n is greater than 0.
Step-by-Step Procedure
Using the input n = 123:
Step	Operation	Value of rem	Value of sum	Value of n
Start	Initial values	-	0	123
Iter 1	123 % 10 / sum + 3 / 123 / 10	3	3	12
Iter 2	12 % 10 / sum + 2 / 12 / 10	2	5	1
Iter 3	1 % 10 / sum + 1 / 1 / 10	1	6	0
End	Loop stops (n is 0)	-	6	0
Final Output: sum:6
A Pro Tip for C Beginners
If you ever need to handle negative numbers (like -123), the sum will currently result in a negative value or behave unexpectedly because of how % works with signs. To make it "bulletproof," you can use abs(n) from the math.h library or simply:
c
if (n < 0) n = -n;
Use code with caution.

Would you like to see how to solve this using recursion instead of a while loop?



generate for negative
To handle negative numbers, you need to ensure the digits are treated as positive values. In C, the result of the modulo operator (%) with a negative number is negative (e.g., -123 % 10 is -3).
Here is the "segmentation-free" and negative-ready version:
c
#include <stdio.h>
#include <stdlib.h> // Required for abs()

int main() {
    int n = -123, sum = 0, rem;
    
    // Step 1: Convert to absolute value to handle negative signs
    int temp = abs(n); 
    
    // Step 2: Extract and sum digits
    while(temp > 0){
        rem = temp % 10;
        sum += rem;
        temp = temp / 10;
    }
    
    printf("Number: %d\n", n);
    printf("Sum of digits: %d", sum);
    
    return 0;
}
Use code with caution.

Step-by-Step Procedure for Negative Numbers
Normalization: Use the abs() function from stdlib.h. This turns -123 into 123.
Modulo Operation: 123 % 10 extracts the digit 3.
Accumulation: Add 3 to sum.
Reduction: 123 / 10 performs integer division to get 12.
Iteration: Repeat until temp reaches 0.
Dry Run (n = -123)
Initial: n = -123, temp = 123, sum = 0
Loop 1: rem = 3, sum = 3, temp = 12
Loop 2: rem = 2, sum = 5, temp = 1
Loop 3: rem = 1, sum = 6, temp = 0
Result: 6
Pro-tip: If you don't want to include <stdlib.h>, you can manually flip the sign with if (n < 0) n = -n; before starting the loop.
