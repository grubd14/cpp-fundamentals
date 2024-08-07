//WAP to demonstrate example of floor and ceiling function
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double value;

    // Ask the user to enter a floating-point number
    printf("Enter a floating-point number: ");
    scanf("%lf", &value);

    // Calculate floor and ceiling values
    double floorValue = floor(value);
    double ceilValue = ceil(value);

    // Print the results
    printf("Floor of %.2f = %.0f\n", value, floorValue);
    printf("Ceiling of %.2f = %.0f\n", value, ceilValue);

    return 0;
}

