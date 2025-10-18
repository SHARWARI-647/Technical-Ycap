#include <stdio.h>
#include <stdlib.h>

// Structure definition for a BST node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node *root, int x) {
    // If the tree/subtree is empty, create a new node
    if (root == NULL)
        return createNode(x);
    
    // Recursive insertion
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    
    // Return the root node to maintain tree structure
    return root;
}

// Function for Preorder traversal (Root -> Left -> Right)
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d -> ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for Postorder traversal (Left -> Right -> Root)
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d -> ", root->data);
    }
}

// Function for Inorder traversal (Left -> Root -> Right)
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

// Function to find the minimum value node in BST
void min(struct Node *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    // Traverse to the leftmost node
    while (root->left != NULL)
        root = root->left;
    
    printf("Minimum data = %d\n", root->data);
}

// Function to find the maximum value node in BST
void max(struct Node *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    // Traverse to the rightmost node
    while (root->right != NULL)
        root = root->right;

    printf("Maximum data = %d\n", root->data);
}

// Main function
void main() {
    struct Node* root = NULL;
    int ch;

    printf("\n=== Binary Search Tree Operations ===\n");
    printf(" 1. Insert nodes\n 2. Preorder Traversal\n 3. Postorder Traversal\n 4. Inorder Traversal\n 5. Find Minimum Value\n 6. Find Maximum Value\n 7. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                // Predefined array of elements to insert
                int arr[] = {36, 26, 46, 21, 31, 11, 24, 41, 56, 51, 66};
                int size = sizeof(arr) / sizeof(arr[0]);
                for (int i = 0; i < size; i++) {
                    root = insert(root, arr[i]);
                    printf("Inserted: %d\n", arr[i]);
                }
                break;
            }

            case 2:
                printf("\nPreorder Traversal:\n");
                preorder(root);
                printf("NULL\n");
                break;

            case 3:
                printf("\nPostorder Traversal:\n");
                postorder(root);
                printf("NULL\n");
                break;

            case 4:
                printf("\nInorder Traversal:\n");
                inorder(root);
                printf("NULL\n");
                break;

            case 5:
                min(root);
                break;

            case 6:
                max(root);
                break;

            case 7:
                printf("Exiting program...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}
