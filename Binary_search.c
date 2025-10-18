#include <stdio.h>   // Standard input-output header file

void main() {
    // Variable declarations
    int key, flag = 0, loc = 0;
    
    // Predefined sorted array (required for binary search)
    int arr[5] = {15, 52, 82, 120, 718};
    
    // Calculate total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Variables for binary search
    int mid = 0, start = 0, end = n - 1;
    
    // Display message and the elements of the array
    printf("...Binary Search...\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Ask the user to enter the element to search for
    printf("\nEnter the key to search :");
    scanf("%d", &key);
    
    // Binary search algorithm begins
    // Keep dividing the array into halves until the element is found or range is empty
    while (start <= end) {
        mid = (start + end) / 2;   // Find the middle index
        
        // If the key matches the middle element
        if (key == arr[mid]) {
            loc = mid;    // Store the index where it was found
            flag = 1;     // Set flag to indicate element found
            break;        // Exit the loop
        }
        // If key is smaller than middle element, search in left half
        else if (key < arr[mid]) {
            end = mid - 1;
        }
        // If key is greater than middle element, search in right half
        else if (key > arr[mid]) {
            start = mid + 1;
        }
    }
    
    // After loop ends, check if the element was found or not
    if (flag == 1) {
        printf("\nElement found at index %d", loc);
    } else {
        printf("\nElement not found");
    }
}
