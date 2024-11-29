#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_VALUES 8
#define HEX_LENGTH 16

// Function to convert hex string to a 64-bit integer
unsigned long long hex_to_ull(const char *hex_str) {
    unsigned long long result;
    sscanf(hex_str, "%llx", &result);  // Convert the hex string to an unsigned long long (64-bit)
    return result;
}

// Function to count the number of unmatched bits between two 64-bit values
int count_unmatched_bits(unsigned long long value1, unsigned long long value2) {
    unsigned long long diff = value1 ^ value2;  // XOR to find differing bits
    int count = 0;
    
    // Count the number of 1's in the result (which corresponds to differing bits)
    while (diff) {
        count += diff & 1;
        diff >>= 1;
    }
    
    return count;
}

int main() {
    unsigned long long values[8];

    printf("take 8 different 16-byte hexadecimal values:\n");
    values[0] = hex_to_ull("BE439AD598EF5147");
    values[1] = hex_to_ull("9C8B7A1425369584"); 
    values[2] = hex_to_ull("885522336699CCBB");  
    
    values[3] = hex_to_ull("C975A2132E89CEAF");  
    values[4] = hex_to_ull("DB9A8675342FEC15");
    values[5] = hex_to_ull("A6039AD5F8CFD965"); 
    values[6] = hex_to_ull("1DCA7A54273497CC");  
    values[7] = hex_to_ull("AF8B6C7D5E3F0F9A"); 
    
    // Step 2: Get the two pairs of indices from the user
    int pair1_index, pair2_index;
    printf("\nEnter the indices of the two values to compare\n");
    printf("\n0=Alice, 1=Bob, 2=Charlie, 3=U, 4=V, 5=W, 6=X, 7=Y:\n");
    printf("Pair 1 index: ");
    scanf("%d", &pair1_index);
    printf("Pair 2 index: ");
    scanf("%d", &pair2_index);
    
    // Step 3: Calculate and display the number of unmatched bits
    if (pair1_index >= 0 && pair1_index < NUM_VALUES && pair2_index >= 0 && pair2_index < NUM_VALUES) {
        int unmatched_bits = count_unmatched_bits(values[pair1_index], values[pair2_index]);
        printf("Pair 1 index= &ld ",values[pair1_index] );
        printf("Pair 2 index= &ld ",values[pair2_index] );
        printf("\nThe number of unmatched bits between value %d and value %d is: %d\n", pair1_index + 1, pair2_index + 1, unmatched_bits);
    } else {
        printf("\nInvalid indices! Please enter values between 1 and 8.\n");
    }
    
    return 0;
}
