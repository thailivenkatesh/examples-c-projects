#include <stdio.h>

int main()
{
    unsigned int CountSetBits = 0; //Total number of bit set.
    unsigned int n = 0; //Variable that set bits you want to count
 
    int	decimal;
	int	binary;
	int base;
	int	rem;
	int	num;

	printf("enter binary: ");
	scanf("%d", &binary);

	decimal = 0;
	base = 1;
	num = binary;
	while (binary != 0)
	{
		rem = binary % 10;
		decimal = decimal + rem * base;
		binary = binary / 10;
		base = base * 2;
	}
	printf("equivalent decimal  %d ", decimal);
    while (decimal)
    {
        CountSetBits += decimal & 1;
      decimal>>= 1;
    }
    printf("\nNumber of 1 = %d", CountSetBits);
}