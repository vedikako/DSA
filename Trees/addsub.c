#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int sumLeftSubtree(struct Node* node) {
    if (node == NULL) return 0;
    return node->data + sumLeftSubtree(node->left) + sumLeftSubtree(node->right);
}

void adjustRightSubtree(struct Node* node) {
    if (node == NULL) return;
    adjustRightSubtree(node->left);
    adjustRightSubtree(node->right);
    
    if (node->right) {
        int leftSum = sumLeftSubtree(node->left);
        node->right->data += leftSum;
        node->right->data -= leftSum;  // For subtraction
    }
}

void inOrder(struct Node* node) {
    if (node == NULL) return;
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    printf("Original tree: ");
    inOrder(root);
    printf("\n");

    adjustRightSubtree(root);
    printf("After adjustment: ");
    inOrder(root);
    printf("\n");

    return 0;
}