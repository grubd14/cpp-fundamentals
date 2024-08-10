
#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // If the key is greater, ignore the left half
        if (arr[mid] < key) {
            left = mid + 1;
        }
        // If the key is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Key not found
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, size, key);

    if (result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
