#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the sum of all nodes in a subtree
int sumSubtree(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sumSubtree(root->left) + sumSubtree(root->right);
}

// Function to calculate and print the sums of the left and right subtrees
void calculateSubtreeSums(struct Node* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return;
    }
    
    int leftSum = sumSubtree(root->left);
    int rightSum = sumSubtree(root->right);

    printf("Sum of left subtree: %d\n", leftSum);
    printf("Sum of right subtree: %d\n", rightSum);
}

int main() {
    // Creating a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Calculate and display the sums of the left and right subtrees
    calculateSubtreeSums(root);

    return 0;
}
