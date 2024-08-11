#include <stdio.h>

// Function to generate permutations
void generatePermutations(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;

            generatePermutations(arr, start + 1, end);

            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
        }
    }
}

// Function to generate combinations
void generateCombinations(int arr[], int data[], int start, int end, int index, int r) {
    if (index == r) {
        for (int i = 0; i < r; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        generateCombinations(arr, data, i + 1, end, index + 1, r);
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int r = 2; // Size of combination

    printf("Permutations:\n");
    generatePermutations(arr, 0, n - 1);

    printf("\nCombinations:\n");
    int data[r];
    generateCombinations(arr, data, 0, n - 1, 0, r);

    return 0;
}
