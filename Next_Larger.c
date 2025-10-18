#include <stdio.h>

int main() {
    int arr[100];   // Input array
    int res[100];   // Result array
    int n;          // Size of array

    // Input: number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input: array elements
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find next greater element logic
    for (int i = 0; i < n; i++) {
        int found = 0; // Flag to check if next greater is found

        // Compare current element with elements to its right
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {    // Found next greater element
                res[i] = arr[j];      // Store it in result array
                found = 1;            // Mark found
                break;                // Stop after first greater element
            }
        }

        // If no greater element found, keep the same number
        if (!found)
            res[i] = arr[i];
    }

    // The last element should always be -1
    res[n - 1] = -1;

    // Output: print the result array
    printf("\nResult (Next Larger): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}
