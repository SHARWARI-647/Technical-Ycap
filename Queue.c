#include <stdio.h>    // Standard input/output library
#include <stdlib.h>   // For exit() function
#define MAX 10        // Maximum size of the queue

// Global variables
int f = 0;            // Front pointer (points to the first element)
int r = -1;           // Rear pointer (points to the last element)
int queue[MAX];       // Array to store queue elements

// ------------------ FUNCTION DEFINITIONS ------------------

// Function to check if the queue is full
int isFull() {
    if (r == MAX - 1)
        return 1;     // Queue is full
    else
        return 0;     // Queue has space
}

// Function to check if the queue is empty
int isEmpty() {
    if (r == -1)
        return 1;     // Queue is empty
    else
        return 0;     // Queue has elements
}

// Function to insert (enqueue) an element into the queue
void insert(int x) {
    if (isFull()) {
        printf("Queue is Full\n");  // Cannot insert if queue is full
    } else {
        ++r;               // Move rear pointer forward
        queue[r] = x;      // Insert the new element
        printf("\n%d inserted into the queue.", x);
    }
}

// Function to delete (dequeue) an element from the queue
int delete() {
    int x;
    if (isEmpty()) {
        printf("Queue is empty\n"); // Cannot delete if empty
        return -1;
    } else {
        x = queue[f];  // Store the front element to return later
        
        // Shift elements left to maintain queue order
        for (int i = 0; i <= r; i++) {
            queue[i] = queue[i + 1];
        }

        // Decrement rear pointer as one element is removed
        --r;

        // If queue becomes empty after deletion, reset pointers
        if (r < 0)
            f = 0;

        return x;
    }
}

// Function to get the front element (without removing it)
int peekFront() {
    int x;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    } else {
        x = queue[f];  // Front element
        return x;
    }
}

// Function to get the rear element (without removing it)
int peekRear() {
    int x;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    } else {
        x = queue[r];  // Rear element
        return x;
    }
}

// Function to display all elements of the queue
void traverse() {
    if (isEmpty()) {
        printf("\nQueue is Empty...");
    } else {
        printf("\nQueue elements: ");
        for (int i = f; i <= r; i++) {
            printf("%d ", queue[i]);
        }
    }
}

// ------------------ MAIN FUNCTION ------------------
void main() {
    int ch, n;

    printf("---- Queue Operations using Array ----\n");
    printf("1. Insert (Enqueue)\n");
    printf("2. Delete (Dequeue)\n");
    printf("3. Traverse (Display Queue)\n");
    printf("4. Peek Front Element\n");
    printf("5. Peek Rear Element\n");
    printf("6. Exit\n");

    // Infinite loop for menu-driven program
    while (1) {
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter a number: ");
                scanf("%d", &n);
                insert(n);
                break;

            case 2: {
                int x = delete();
                if (x != -1)
                    printf("Deleted element: %d\n", x);
                break;
            }

            case 3:
                traverse();
                break;

            case 4: {
                int p1 = peekFront();
                if (p1 != -1)
                    printf("Front element: %d\n", p1);
                break;
            }

            case 5: {
                int p2 = peekRear();
                if (p2 != -1)
                    printf("Rear element: %d\n", p2);
                break;
            }

            case 6:
                exit(0);  // Exit program
                break;

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
}
