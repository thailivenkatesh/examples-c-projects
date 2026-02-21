/*Factors on Which the Size of a Pointer in C Depend 
As mentioned above, the size of the pointer in C is not fixed. Instead, it depends upon factors like the CPU architecture and the processor’s word size, to be more specific.

Thus, the word size is the main determining factor in finding the size of the pointer. Now, since the word size is the same for a particular computer system, the size of the pointer in C will also be the same, irrespective of the variable’s data type whose address it’s storing. 

For example, the size of a char pointer in a 32-bit processor is 4 bytes, while the size of a char pointer in a 16-bit processor is 2 bytes. 

Q) What is the sizeof( ) operator in a pointer?
1. The sizeof( ) operator in a pointer gives us the size occupied by a pointer in a particular machine.
2. It depends on the word size of the computer system and hence is the same for a specific machine.

Q) What is the sizeof( ) operator in C?
The sizeof( ) operator is a unary operator used to find the memory occupied by its operand in bytes.
*/
#include<stdio.h>
// Size of char Pointer in C
void char_pointer()
{
	char c=3;
	void *ptr = &c;
	printf("\nThe size of the character pointer is %p bytes",sizeof((char *)ptr));
}

// Size of Double Pointer in C
void double_pointer()
{
	double x=3.14;
	double *ptr=&x;
	printf("\nThe size of the double pointer is %d bytes",sizeof(ptr));
}

// Size of a Pointer to Pointer or double pointer
void pointer_pointer()
{
	double x=3.14;
	double *ptr1=&x;
	double **ptr2=&ptr1;
	printf("\nThe size of pointer is %d bytes and pointer to pointer is %d bytes",sizeof(ptr1),sizeof(ptr2));
}

// Pointer to an Array 
void pointer_array()
{
	int arr[]={1,2,3,4,5};
	int *ptr=arr;
	for(int i=0;i<5;i++)
	{
    	     printf("\t%d ",*(ptr+i));
	}
}

// Size of a Pointer to an Array
void pointer_to_array()
{
	int arr[]={1,2,3,4,5};
	int *ptr=arr;
	printf("\nThe size of a pointer to an array is %d bytes\n",sizeof(ptr));
}
// Writing to read-only memory.
void seg() {
             char *s = "Delhi is the capital of India";
             *s = 'A';
             printf("\n%s",s);
 } 
void scan()
{
     int p = 10;
     scanf("%d",p);
     //return 0;
}

void main(){
	
	//char_pointer();
	//double_pointer();
	//pointer_pointer();
	//pointer_to_array();
	//pointer_array();
	seg();
	
}