#include <stdio.h>
#include <stdlib.h>

// Structure definition for a Doubly Linked List node
struct GetNode {
    struct GetNode *left;   // Pointer to previous node
    int data;               // Data of the node
    struct GetNode *right;  // Pointer to next node
};

// Global head pointer (points to first node)
struct GetNode *head = NULL;

// ================= FUNCTION DEFINITIONS =================

// 1️⃣ Append a node at the end of the list
void append() {
    int x;
    printf("\nEnter the data: ");
    scanf("%d", &x);

    // Create new node
    struct GetNode *newnode = (struct GetNode*)malloc(sizeof(struct GetNode));
    newnode->data = x;
    newnode->right = NULL;
    newnode->left = NULL;

    // If list is empty, assign new node as head
    if (head == NULL) {
        head = newnode;
    } else {
        struct GetNode *ptr = head;

        // Traverse to last node
        while (ptr->right != NULL) {
            ptr = ptr->right;
        }

        // Link new node at the end
        ptr->right = newnode;
        newnode->left = ptr;
    }
}

// 2️⃣ Add a node at the beginning
void addAtBeginning() {
    int x;
    printf("\nEnter the data: ");
    scanf("%d", &x);

    // Create new node
    struct GetNode *newnode = (struct GetNode*)malloc(sizeof(struct GetNode));
    newnode->data = x;
    newnode->right = NULL;
    newnode->left = NULL;

    // If list is empty, assign directly
    if (head == NULL) {
        head = newnode;
    } else {
        // Link newnode before the current head
        newnode->right = head;
        head->left = newnode;
        head = newnode; // Make newnode the new head
    }
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
    newnode->right = NULL;
    newnode->left = NULL;

    // If list empty or position is 1, insert at beginning
    if (head == NULL || pos == 1) {
        addAtBeginning();
        return;
    }

    struct GetNode *ptr = head;
    int i;

    // Traverse to (pos-1) node
    for (i = 1; i < pos - 1 && ptr->right != NULL; i++) {
        ptr = ptr->right;
    }

    // Insert node
    newnode->right = ptr->right;
    newnode->left = ptr;

    if (ptr->right != NULL)
        ptr->right->left = newnode;

    ptr->right = newnode;
}

// 4️⃣ Delete node from beginning
void deleteNodeAtBegin() {
    if (head == NULL) {
        printf("\nList is empty...");
        return;
    }

    struct GetNode *ptr = head;
    head = head->right; // Move head forward

    if (head != NULL)
        head->left = NULL; // Remove backward link

    printf("\nNode deleted from beginning: %d", ptr->data);
    free(ptr);
}

// 5️⃣ Delete node from end
void deleteNodeAtEnd() {
    if (head == NULL) {
        printf("\nList is empty...");
        return;
    }

    struct GetNode *ptr = head;

    // Traverse to the last node
    while (ptr->right != NULL) {
        ptr = ptr->right;
    }

    // If only one node exists
    if (ptr->left == NULL) {
        head = NULL;
    } else {
        ptr->left->right = NULL;
    }

    printf("\nNode deleted from end: %d", ptr->data);
    free(ptr);
}

// 6️⃣ Delete node at a specific position
void deleteNodeAtPosition() {
    int pos;
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("\nList is empty...");
        return;
    }

    struct GetNode *ptr = head;
    int i;

    // Traverse to the desired position
    for (i = 1; i < pos && ptr != NULL; i++) {
        ptr = ptr->right;
    }

    // If position invalid
    if (ptr == NULL) {
        printf("\nInvalid position!");
        return;
    }

    // If deleting the first node
    if (ptr->left == NULL) {
        head = ptr->right;
        if (head != NULL)
            head->left = NULL;
    }
    // If deleting the last node
    else if (ptr->right == NULL) {
        ptr->left->right = NULL;
    }
    // If deleting a middle node
    else {
        ptr->left->right = ptr->right;
        ptr->right->left = ptr->left;
    }

    printf("\nNode deleted at position %d: %d", pos, ptr->data);
    free(ptr);
}

// 7️⃣ Display all nodes
void traverse() {
    if (head == NULL) {
        printf("\nNo node is present in list...");
        return;
    }

    struct GetNode *ptr = head;
    printf("\nDoubly Linked List: ");
    while (ptr != NULL) {
        printf("%d <-> ", ptr->data);
        ptr = ptr->right;
    }
    printf("NULL");
}

// ================= MAIN FUNCTION =================
void main() {
    int ch;

    printf("\n--- Doubly Linked List Operations ---\n");
    printf("1. Append (Add at End)\n");
    printf("2. Add at Beginning\n");
    printf("3. Add at Position\n");
    printf("4. Delete Node at Beginning\n");
    printf("5. Delete Node at End\n");
    printf("6. Delete Node at Position\n");
    printf("7. Traverse (Display List)\n");
    printf("8. Exit\n");

    // Menu-driven loop
    while (1) {
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: append(); break;
            case 2: addAtBeginning(); break;
            case 3: addAtPosition(); break;
            case 4: deleteNodeAtBegin(); break;
            case 5: deleteNodeAtEnd(); break;
            case 6: deleteNodeAtPosition(); break;
            case 7: traverse(); break;
            case 8: exit(0);
            default: printf("\nInvalid choice! Try again.");
        }
    }
}
