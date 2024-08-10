//A program to implement the extended euclidean Algorithm

#include <stdio.h>

// Function to implement the Extended Euclidean Algorithm
int extendedEuclidean(int a, int b, int *x, int *y) {
    // Base case: if b is 0, gcd is a and coefficients are x=1, y=0
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    // Recursive case
    int x1, y1; // Temporary variables to store results of recursion
    int gcd = extendedEuclidean(b, a % b, &x1, &y1);

    // Update x and y using the results of recursion
    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b;
    int x, y;

    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Call the extended Euclidean function
    int gcd = extendedEuclidean(a, b, &x, &y);

    // Output the results
    printf("GCD: %d\n", gcd);
    printf("Coefficients x and y: %d, %d\n", x, y);
    printf("Verification: %d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);

    return 0;
}

