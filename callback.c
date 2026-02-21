
//callback
#include <stdio.h>
void add(int a, int b)
{
	printf("Addition is %d\n", a+b);
}
void subtract(int a, int b)
{
	printf("Su is %d\n", a-b);
}
void multiply(int a, int b)
{
	printf("Mul is %d\n", a*b);
}

int main()
{
	// fun_ptr_arr is an array of function pointers
	void (*fun_ptr_arr[3])(int, int) = {add, subtract, multiply};
	unsigned int ch, a = 15, b = 10;
	for(ch=0;ch<3;ch++)
	(*fun_ptr_arr[ch])(a, b);
	return 0;
}
//recursion
// C program to reverse a string using recursion
#include<stdio.h>
void print(int n){
    if(n<10)
    print(n+1);
    printf("%d ",n);
}
int main(){
    print(1);
    return 0;
}

