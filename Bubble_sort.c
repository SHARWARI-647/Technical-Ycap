#include <stdio.h>   // Standard input-output header file

void main() {
    // Variable declarations
    int i, j, temp = 0;

    // Initialize an unsorted array
    int arr[5] = {15, 78, 52, 62, 718};

    // Calculate number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Display original (unsorted) array
    printf("...Bubble sort...\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Bubble Sort algorithm
    // Outer loop for number of passes
    for (int i = 0; i < n - 1; i++) {
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - 1 - i; j++) {
            // If current element is greater than next element, swap them
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display array after sorting
    printf("\n...After sort...\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
