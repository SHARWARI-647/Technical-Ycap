#include <stdio.h>   // Header file for input/output functions
#include <stdlib.h>  // Header file for general functions like malloc(), exit()

#define MAX 100       // Define the maximum size of the stack

// Global variables for stack implementation
int top = -1;         // 'top' points to the topmost element of the stack; -1 means stack is empty
int stack[MAX];       // Stack array declaration

// Function to check if the stack is full
int isFull() {
    if (top == MAX - 1)   // If top reaches the last index
        return 1;         // Stack is full
    else 
        return 0;         // Stack has space
}

// Function to check if the stack is empty
int isEmpty() {
    if (top == -1)        // If no elements are in stack
        return 1;         // Stack is empty
    else 
        return 0;         // Stack has elements
}

// Function to push an element onto the stack
void push(int x) {
    if (isFull()) {                           // Check if stack is full
        printf("Stack overflow\n");           // Display error if full
    } else {
        ++top;                                // Increment top pointer
        stack[top] = x;                       // Store new element at top position
    }
}

// Function to pop (remove) an element from the stack
int pop() {
    int x;
    if (isEmpty()) {                          // Check if stack is empty
        printf("Stack underflow\n");          // Display error if empty
    } else {
        x = stack[top];                       // Retrieve the top element
        top--;                                // Decrease top pointer (remove element)
    } 
    return x;                                 // Return the popped element
}

// Main function
void main() {
    int a[] = {10, 20, 30, 40, 50};           // Declare and initialize array
    int n = sizeof(a) / sizeof(a[0]);         // Calculate array size (total bytes / element bytes)
    
    printf("Original array: ");
    // Push all array elements onto the stack
    for (int i = 0; i < n; i++) {
        push(a[i]);                           // Push each element into stack
        printf("%d\t", a[i]);                 // Print original array elements
    }

    // Pop elements from stack back into array (this reverses the array)
    for (int i = 0; i < n; i++) {
        a[i] = pop();                         // Assign popped elements back to array
    }
    
    // Print the reversed array
    printf("\nReversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);                 // Display reversed array elements
    }
}
