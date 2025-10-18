#include <stdio.h>     // Header for input/output functions
#include <stdlib.h>    // Header for general utilities (like malloc, exit)
#include <string.h>    // Header for string handling functions (strlen)

#define MAX 100         // Define maximum stack size

// Global variables
int top = -1;           // 'top' keeps track of the top index of the stack
char stack[MAX];        // Stack to hold characters

// Function to check if the stack is full
int isFull() {
    if (top == MAX - 1)   // If top reaches the last index
        return 1;         // Stack is full
    else 
        return 0;         // Stack has space
}

// Function to check if the stack is empty
int isEmpty() {
    if (top == -1)        // If top is -1, stack is empty
        return 1; 
    else 
        return 0;
}

// Function to push a character onto the stack
void push(char x) {
    if (isFull()) {                             // Check for overflow
        printf("Stack overflow\n");
    } else {
        ++top;                                  // Increment top
        stack[top] = x;                         // Place character on stack
    }
}

// Function to pop (remove) a character from the stack
char pop() {
    char x;
    if (isEmpty()) {                            // Check for underflow
        printf("Stack underflow\n");
    } else {
        x = stack[top];                         // Get top character
        top--;                                  // Decrease top pointer
    }
    return x;                                   // Return popped character
}

// Main function
void main() {
    char str[10] = "Sharwari";                  // Original string to be reversed
    int len = strlen(str);                      // Calculate string length

    printf("Original string: ");
    // Push each character of the string onto the stack
    for (int i = 0; i < len; i++) {
        push(str[i]);                           // Push each character
        printf("%c ", str[i]);                  // Print original string
    }

    // Pop characters from stack and store them back in the string (reversing order)
    for (int i = 0; i < len; i++) {
        str[i] = pop();                         // Replace with popped (reversed) character
    }

    printf("\nReversed string: ");
    // Print the reversed string
    for (int i = 0; i < len; i++) {
        printf("%c ", str[i]);
    }
}
