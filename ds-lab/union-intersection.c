#include <stdio.h>

// Function to find the union of two sets
void findUnion(int set1[], int size1, int set2[], int size2) {
    int result[100];
    int k = 0;

    // Add all elements of set1 to the result
    for (int i = 0; i < size1; i++) {
        result[k++] = set1[i];
    }

    // Add elements of set2 to the result if they are not already in it
    for (int i = 0; i < size2; i++) {
        int found = 0;
        for (int j = 0; j < size1; j++) {
            if (set2[i] == set1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[k++] = set2[i];
        }
    }

    printf("Union of the sets: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

// Function to find the intersection of two sets
void findIntersection(int set1[], int size1, int set2[], int size2) {
    int result[100];
    int k = 0;

    // Add elements to the result if they are present in both sets
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                result[k++] = set1[i];
                break;
            }
        }
    }

    printf("Intersection of the sets: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int set1[] = {1, 2, 3, 4, 5};
    int set2[] = {4, 5, 6, 7, 8};
    int size1 = sizeof(set1) / sizeof(set1[0]);
    int size2 = sizeof(set2) / sizeof(set2[0]);

    findUnion(set1, size1, set2, size2);
    findIntersection(set1, size1, set2, size2);

    return 0;
}
