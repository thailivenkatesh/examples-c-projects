#include <stdio.h>

int main()
{
    char a[] = "Hi";
    char b[] = "Every";
    char c[] = "One";
    int i=0;
    char **ptr;
    
    *ptr = a;
	*(ptr+1) = b;
	*(ptr+2) = c;
	
    for(i=0;i<3;i++)
    {
        printf("%s ",*(ptr+i));
    }
    return 0;
}

/*To fix the Segmentation Fault, you need to ensure ptr points to an actual block of memory that can hold the addresses of your strings.
The simplest way to do this is by declaring an array of pointers. In C, an array name can decay into a pointer, so ptr will point to a valid, allocated memory space.
Corrected Code
c
#include <stdio.h>

int main()
{
    char a[] = "Hi";
    char b[] = "Every";
    char c[] = "One";
    int i = 0;

    // Fix: Create an array of pointers to hold the 3 addresses
    char *ptr_array[3]; 
    
    // Fix: Point the double pointer to the start of the array
    char **ptr = ptr_array; 
    
    // Now these assignments are safe because ptr points to valid memory
    *ptr = a;         // ptr_array[0] = a
    *(ptr + 1) = b;   // ptr_array[1] = b
    *(ptr + 2) = c;   // ptr_array[2] = c
	
    for(i = 0; i < 3; i++)
    {
        // Accessing valid memory offsets
        printf("%s ", *(ptr + i));
    }
    
    return 0;
}
Use code with caution.

Why this works (Step-by-Step)
Memory Allocation: char *ptr_array[3] reserves space on the stack specifically to hold three memory addresses (pointers).
Valid Assignment: char **ptr = ptr_array initializes ptr with the address of that reserved space.
Pointer Arithmetic: When you do *(ptr + 1) = b, the computer knows exactly where to put the address of "Every" because ptr + 1 is a specific, allocated spot in ptr_array.
No More "Garbage": Your previous version tried to write to a random location in RAM; this version writes to a "reserved seat."
Alternative (The "Short" Way)
If you don't specifically need the char **ptr variable, you can simplify the whole thing into a single array initialization:
c
char *ptr[] = {"Hi", "Every", "One"};
for(int i=0; i<3; i++) printf("%s ", ptr[i]);
Use code with caution.*/
