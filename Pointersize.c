/*Factors on Which the Size of a Pointer in C Depend 
As mentioned above, the size of the pointer in C is not fixed. Instead, it depends upon factors like the CPU architecture and the processor’s word size, to be more specific.

Thus, the word size is the main determining factor in finding the size of the pointer. Now, since the word size is the same for a particular computer system, the size of the pointer in C will also be the same, irrespective of the variable’s data type whose address it’s storing. 

For example, the size of a char pointer in a 32-bit processor is 4 bytes, while the size of a char pointer in a 16-bit processor is 2 bytes. 

Q) What is the sizeof( ) operator in a pointer?
1. The sizeof( ) operator in a pointer gives us the size occupied by a pointer in a particular machine.
2. It depends on the word size of the computer system and hence is the same for a specific machine.

Q) What is the sizeof( ) operator in C?
The sizeof( ) operator is a unary operator used to find the memory occupied by its operand in bytes.

Allocation: The string "Delhi..." is placed in the Read-Only Data Segment.
Pointer Assignment: char *s is created on the stack and points to the start of that read-only memory.
Illegal Access: The line *s = 'A' tries to overwrite a protected memory page.
Signal: The Operating System detects the violation and sends a SIGSEGV signal to the process.
Termination: The program terminates immediately without printing the string.
Better & Safer Implementation
To make this code functional and "segmentation-free," use arrays for modifiable strings and pass addresses to scanf.*/
#include <stdio.h>

// Use %zu for sizeof() as it returns size_t
void pointer_sizes() {
    int a = 10;
    int *p1 = &a;
    int **p2 = &p1;
    
    printf("Pointer size: %zu bytes\n", sizeof(p1));
    printf("Double pointer size: %zu bytes\n", sizeof(p2));
}

// Fix: Use a char array instead of a pointer to a literal
void fix_seg() {
    char s[] = "Delhi is the capital of India"; // Stored on the stack (writable)
    s[0] = 'A'; 
    printf("Modified string: %s\n", s);
}

// Fix: Pass the address of the variable
void fix_scan() {
    int p = 0;
    printf("Enter a number: ");
    if(scanf("%d", &p) == 1) { // Added & and return check
        printf("You entered: %d\n", p);
    }
}

int main() {
    pointer_sizes();
    fix_seg();
    // fix_scan(); // Uncomment to test input
    return 0;
}
Key Takeaways
char *s = "...": Points to read-only memory.
char s[] = "...": Copies the string to the stack, making it writable.
sizeof: Use the size_t format specifier %zu for portability.

