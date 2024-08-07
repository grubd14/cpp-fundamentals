//WAP to perform addition,  subtraction , multiplication and division of two numbers


#include <stdio.h>
#include <math.h>

// Function to compute the union of two fuzzy sets
void fuzzyUnion(float setA[], float setB[], float result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = fmax(setA[i], setB[i]);
    }
}

// Function to compute the intersection of two fuzzy sets
void fuzzyIntersection(float setA[], float setB[], float result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = fmin(setA[i], setB[i]);
    }
}

// Function to compute the complement of a fuzzy set
void fuzzyComplement(float set[], float result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = 1.0f - set[i];
    }
}

// Function to display a fuzzy set
void displayFuzzySet(float set[], int size, const char* setName) {
    printf("%s: { ", setName);
    for (int i = 0; i < size; i++) {
        printf("%.1f ", set[i]);
    }
    printf("}\n");
}

int main() {
    // Define two fuzzy sets as arrays
    float setA[] = {0.1, 0.5, 0.7, 0.9};
    float setB[] = {0.2, 0.4, 0.6, 0.8};
    int size = sizeof(setA) / sizeof(setA[0]);

    // Arrays to store the results
    float unionSet[size];
    float intersectionSet[size];
    float complementSetA[size];

    // Perform fuzzy set operations
    fuzzyUnion(setA, setB, unionSet, size);
    fuzzyIntersection(setA, setB, intersectionSet, size);
    fuzzyComplement(setA, complementSetA, size);

    // Display the original sets and the results
    displayFuzzySet(setA, size, "Set A");
    displayFuzzySet(setB, size, "Set B");
    displayFuzzySet(unionSet, size, "Union");
    displayFuzzySet(intersectionSet, size, "Intersection");
    displayFuzzySet(complementSetA, size, "Complement of Set A");

    return 0;
}
