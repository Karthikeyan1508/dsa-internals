#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
typedef struct tree {
    int info;
    struct tree* left;
    struct tree* right;
} tnode;

// Function to create a new node
tnode* createNode(int data) {
    tnode* newNode = (tnode*)malloc(sizeof(tnode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
tnode* insertNode(tnode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->info) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to print the binary tree in inorder traversal
void printInorder(tnode* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->info);
        printInorder(root->right);
    }
}

int main() {
    // Example binary tree creation
    tnode* root = NULL;
    int n, val;
    printf("Enter the number of nodes (maximum 5): ");
    scanf("%d", &n);
    printf("Enter the values of each node: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertNode(root, val);
    }

    // Print the binary tree in inorder traversal
    printf("Linked representation of the binary tree (inorder traversal):\n");
    printInorder(root);

    return 0;
}
