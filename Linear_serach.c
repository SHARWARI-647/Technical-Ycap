#include <stdio.h>

// Main function — program execution starts here
void main() {
    int key, flag = 0, loc = 0;  // 'key' for search element, 'flag' to indicate found/not found, 'loc' for location index
    int arr[5] = {15, 78, 52, 62, 718};  // Initialize array with 5 integer elements
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate total number of elements in array

    printf("...Linear Search...\n");
    
    // Display the array elements
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Take input from user for the element to be searched
    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    // Linear Search: iterate through the array to find the key
    for(int i = 0; i < n; i++) {
        if(key == arr[i]) {   // If key matches the current element
            loc = i;          // Store the location (index)
            flag = 1;         // Set flag to indicate element is found
            break;            // Exit loop once found
        }
    }

    // Check if element was found or not
    if(flag == 1) {
        printf("\nElement found at index %d", loc);
    } else {
        printf("\nElement not found");
    }
}
