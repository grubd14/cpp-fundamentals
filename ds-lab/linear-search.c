
#include <stdio.h>

// Recursive function to implement linear search
int linearSearch(int arr[], int size, int key, int index) {
    if (index >= size) {
        return -1; // Base case: key not found
    }
    if (arr[index] == key) {
        return index; // Key found
    }
    return linearSearch(arr, size, key, index + 1); // Recursive case
}

int main() {
    int arr[] = {3, 5, 2, 4, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, size, key, 0);

    if (result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
