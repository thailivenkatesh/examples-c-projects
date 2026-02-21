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

