#include <stdio.h>    // For standard I/O functions
#include <stdlib.h>   // For exit() function
#define MAX 10        // Maximum size of the stack

// Global variables
int top = -1;         // Stack initially empty
int stack[MAX];       // Array to store stack elements

// Function to check if stack is full
int isFull() {
    if (top == MAX - 1)
        return 1;     // Stack is full
    else
        return 0;     // Stack has space
}

// Function to check if stack is empty
int isEmpty() {
    if (top == -1)
        return 1;     // Stack is empty
    else
        return 0;     // Stack has elements
}

// Function to push (insert) an element into stack
void push(int x) {
    if (isFull()) {
        printf("Stack is overflow\n");  // Cannot push if full
    } else {
        ++top;               // Increase top position
        stack[top] = x;      // Insert element at top
        printf("Pushed %d onto stack\n", x);
    }
}

// Function to pop (remove) the top element
int pop() {
    int x;
    if (isEmpty()) {
        printf("Stack is underflow\n"); // Cannot pop if empty
        return -1;                      // Return invalid value
    } else {
        x = stack[top];   // Store the top element
        top--;            // Decrease top index
        return x;         // Return popped element
    } 
}

// Function to see the top element without removing it
int peek() {
    int x;
    if (isEmpty()) {
        printf("Stack is underflow\n");
        return -1;
    } else {
        x = stack[top];   // Get the top element
        return x;
    } 
}

// Function to display all elements in the stack
void traverse() {
    if (isEmpty()) {
        printf("\nStack is Empty...");
    } else {
        printf("\nStack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
    }
}

// Main menu-driven function
void main() {
    int ch, n;

    printf("---- Stack Operations using Array ----\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Traverse (Display Stack)\n");
    printf("4. Peek (Top Element)\n");
    printf("5. Exit\n");

    // Infinite loop for menu
    while (1) {
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter a number: ");
                scanf("%d", &n);
                push(n);
                break;

            case 2: {
                int x = pop();
                if (x != -1)
                    printf("Popped element: %d\n", x);
                break;
            }

            case 3:
                traverse();
                break;

            case 4: {
                int p = peek();
                if (p != -1)
                    printf("Top element (Peek): %d\n", p);
                break;
            }

            case 5:
                exit(0);   // Exit the program
                break;

            default:
                printf("\nInvalid choice! Please try again.");    
        }
    }
}
