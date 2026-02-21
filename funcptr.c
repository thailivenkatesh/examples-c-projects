#include<stdio.h>
int add(int a, int b)
{
	return a+b;
}
int sub(int a, int b)
{
	return a-b;
}

int main()
{
int result;

int i;
//int (*ptr)(int,int)={&add,&sub};
int (*ptr[])(int,int)={add,sub};
for(i=0;i<2;i++){

//result=(*ptr[i])(11,2);
result=(*ptr[i])(11,2);
printf("Value of result is %d\n", result);
}
	return 0;
}
