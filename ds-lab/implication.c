#include <stdio.h>

int main() {
    printf("Truth table for IMPLICATION operation:\n");
    printf("A | B | A IMPLIES B\n");
    
    for (int A = 0; A <= 1; A++) {
        for (int B = 0; B <= 1; B++) {
            int implication = !A || B; // A implies B is equivalent to !A || B
            printf(" %d | %d |     %d\n", A, B, implication);
        }
    }

    return 0;
}
