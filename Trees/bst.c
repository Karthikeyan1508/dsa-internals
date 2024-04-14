/*Construct a binary tree from the given postorder and inorder traversals :
Postorder:F, D, B, H, G, E, C ,A
Inorder: F, D, B, A, E, H, G, C, */

#include <stdio.h>
#include <stdlib.h>

// Structure definition for a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the index of a character in an array
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Function to construct a binary tree from postorder and inorder traversals
TreeNode* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    // Create a new node with the last element in the postorder traversal
    TreeNode* root = createNode(postorder[*postIndex]);
    (*postIndex)--;

    // If the node has no children, return it
    if (inStart == inEnd) {
        return root;
    }

    // Find the index of the root node in the inorder traversal
    int inIndex = findIndex(inorder, inStart, inEnd, root->data);

    // Construct the right subtree
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);

    // Construct the left subtree
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

int main() {
    // Given postorder and inorder traversals
    int postorder[] = {6, 8, 7, 4, 5, 2, 3, 1};
    int inorder[] = {6, 7, 8, 2, 4, 5, 3, 1};
    int n = sizeof(postorder) / sizeof(postorder[0]);

    int postIndex = n - 1;

    // Construct the binary tree
    TreeNode* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    return 0;
}
