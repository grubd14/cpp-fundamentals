
#include <stdio.h>

int main() {
    float num1, num2;
    float sum, difference, product, quotient;

    // Input two numbers from the user
    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    // Perform addition
    sum = num1 + num2;

    // Perform subtraction
    difference = num1 - num2;

    // Perform multiplication
    product = num1 * num2;

    // Perform division
    if (num2 != 0) {
        quotient = num1 / num2;
    } else {
        printf("Division by zero is not allowed.\n");
        return 1; // Exit the program with an error code
    }

    // Display the results
    printf("\nResults:\n");
    printf("Sum: %.2f\n", sum);
    printf("Difference: %.2f\n", difference);
    printf("Product: %.2f\n", product);
    printf("Quotient: %.2f\n", quotient);

    return 0;
}
