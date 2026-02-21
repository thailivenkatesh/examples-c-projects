#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * Brian Kernighan’s Algorithm
 * Returns the number of set bits (1s) in a 32-bit integer.
 */
int count_set_bits(uint32_t n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1); // Clears the lowest set bit
        count++;
    }
    return count;
}

/**
 * Power of Two Check
 * Returns true if n is a power of 2 (e.g., 1, 2, 4, 8, 16...).
 */
bool is_power_of_two(uint32_t n) {
    // A power of two must be > 0 and have exactly one set bit
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    uint32_t num = 8;

    printf("Analysis for Number: %u\n", num);
    printf("--------------------------\n");
    
    // 1. Count Set Bits
    printf("Total Set Bits (1s): %d\n", count_set_bits(num));

    // 2. Check Power of Two
    if (is_power_of_two(num)) {
        printf("Result: %u is a power of 2.\n", num);
    } else {
        printf("Result: %u is NOT a power of 2.\n", num);
    }

    return 0;
}
