#include <stdio.h>
#include <stdlib.h>

// Structure definition for a binary tree node
typedef struct tnode {
    int info;
    struct tnode *left, *right;
} tnode;

// Global variable for the root of the binary tree
tnode *root = NULL;

// Function to create a binary search tree
void create() {
    tnode *newnode, *temp, *prev;
    int k, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values of each node: ");
    
    for (k = 0; k < n; k++) {
        newnode = (tnode*)malloc(sizeof(tnode));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        newnode->left = newnode->right = NULL;
        scanf("%d", &newnode->info);

        if (root == NULL) {
            root = newnode;
        } else {
            temp = root;
            while (temp != NULL) {
                prev = temp;
                if (newnode->info < temp->info) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
            if (newnode->info < prev->info) {
                prev->left = newnode;
            } else {
                prev->right = newnode;
            }
        }
    }
}

// Function to perform inorder traversal of the binary tree
void inorder(tnode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

// Function to perform postorder traversal of the binary tree
void postorder(tnode *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

// Function to perform preorder traversal of the binary tree
void preorder(tnode *root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    // Create the binary search tree
    create();
    
    // Perform inorder traversal and print the result
    printf("\nInorder traversal: ");
    inorder(root);
    
    // Perform postorder traversal and print the result
    printf("\nPostorder traversal: ");
    postorder(root);
    
    // Perform preorder traversal and print the result
    printf("\nPreorder traversal: ");
    preorder(root);
    
    return 0;
}
