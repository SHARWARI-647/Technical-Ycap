#include <stdio.h>      // Standard I/O functions
#include <stdlib.h>     // For malloc() and free()

// Structure definition for a single linked list node
struct GetNode {
    int data;                 // To store node value
    struct GetNode *next;     // Pointer to next node
};

// Head pointer for the linked list (global)
struct GetNode *head = NULL;

// ====================== FUNCTION DEFINITIONS ======================

// 1️⃣ Append a node at the end
void append() {
    int x;
    printf("\nEnter the data: ");
    scanf("%d", &x);

    // Create a new node dynamically
    struct GetNode *newnode = (struct GetNode*)malloc(sizeof(struct GetNode));
    newnode->data = x;
    newnode->next = NULL;

    // If the list is empty
    if (head == NULL) {
        head = newnode;
    } else {
        struct GetNode *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    printf("Node appended successfully!");
}

// 2️⃣ Add a node at the beginning
void addAtBeginning() {
    int x;
    printf("\nEnter the data: ");
    scanf("%d", &x);

    struct GetNode *newnode = (struct GetNode*)malloc(sizeof(struct GetNode));
    newnode->data = x;
    newnode->next = head;  // Point new node to current head
    head = newnode;        // Make new node the new head
    printf("Node added at beginning!");
}

// 3️⃣ Add a node at a specific position
void addAtPosition() {
    int x, pos;
    printf("\nEnter the data: ");
    scanf("%d", &x);
    printf("Enter the position (starting from 1): ");
    scanf("%d", &pos);

    struct GetNode *newnode = (struct GetNode*)malloc(sizeof(struct GetNode));
    newnode->data = x;
    newnode->next = NULL;

    // If list is empty or position = 1 → insert at beginning
    if (pos == 1 || head == NULL) {
        newnode->next = head;
        head = newnode;
        printf("Node inserted at position %d!", pos);
        return;
    }

    struct GetNode *ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Invalid position! Node not inserted.");
    } else {
        newnode->next = ptr->next;
        ptr->next = newnode;
        printf("Node inserted at position %d!", pos);
    }
}

// 4️⃣ Delete a node from the beginning
void deleteNodeAtBegin() {
    if (head == NULL) {
        printf("List is empty, nothing to delete!");
        return;
    }
    struct GetNode *ptr = head;
    head = head->next;  // Move head to next node
    free(ptr);          // Delete old head
    printf("Node deleted from beginning!");
}

// 5️⃣ Delete a node from the end
void deleteNodeAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete!");
    } 
    else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted!");
    } 
    else {
        struct GetNode *ptr1 = head;
        struct GetNode *ptr2 = NULL;

        // Traverse to the last node
        while (ptr1->next != NULL) {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }

        ptr2->next = NULL;
        free(ptr1);
        printf("Node deleted from end!");
    }
}

// 6️⃣ Delete a node at a specific position (✅ Corrected)
void deleteAtPosition() {
    int pos;
    printf("\nEnter the position to delete (starting from 1): ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty, nothing to delete!");
        return;
    }

    struct GetNode *ptr = head;
    // If deleting first node
    if (pos == 1) {
        head = head->next;
        free(ptr);
        printf("Node deleted from position 1!");
        return;
    }

    // Traverse to one node before the desired position
    struct GetNode *prev = NULL;
    for (int i = 1; i < pos && ptr != NULL; i++) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Invalid position! Node not found.");
    } else {
        prev->next = ptr->next;
        free(ptr);
        printf("Node deleted from position %d!", pos);
    }
}

// 7️⃣ Traverse the list and print elements
void traverse() {
    if (head == NULL) {
        printf("List is empty!");
        return;
    }

    struct GetNode *ptr = head;
    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// ====================== MAIN FUNCTION ======================
void main() {
    int ch;

    printf("---- Linked List Operations ----\n");
    printf("1. Append\n");
    printf("2. Traverse\n");
    printf("3. Add At Beginning\n");
    printf("4. Delete Node At Beginning\n");
    printf("5. Delete Node At End\n");
    printf("6. Add At Position\n");
    printf("7. Delete Node At Position\n");
    printf("8. Exit\n");

    // Infinite loop for menu
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: append(); break;
            case 2: traverse(); break;
            case 3: addAtBeginning(); break;
            case 4: deleteNodeAtBegin(); break;
            case 5: deleteNodeAtEnd(); break;
            case 6: addAtPosition(); break;
            case 7: deleteAtPosition(); break;
            case 8: exit(0);
            default: printf("\nInvalid choice! Please try again.\n");
        }
    }
}
