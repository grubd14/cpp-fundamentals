
#include <stdio.h>

int main() {
    printf("Truth table for NAND gate (Universal Gate):\n");
    printf("A | B | A NAND B\n");

    for (int A = 0; A <= 1; A++) {
        for (int B = 0; B <= 1; B++) {
            int nand_result = !(A && B); // NAND operation
            printf(" %d | %d |   %d\n", A, B, nand_result);
        }
    }

    return 0;
}
