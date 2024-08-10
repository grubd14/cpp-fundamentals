#include <stdio.h>

int main() {
    printf("Truth table for NAND operation:\n");
    printf("A | B | A NAND B\n");
    for (int A = 0; A <= 1; A++) {
        for (int B = 0; B <= 1; B++) {
            printf(" %d | %d |   %d\n", A, B, !(A && B));
        }
    }
}
