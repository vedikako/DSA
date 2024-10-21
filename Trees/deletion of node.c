#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
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

// Function to find the minimum value node in the right subtree
struct Node* findMin(struct Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;  // Base case: If the tree is empty

    // If the key to be deleted is smaller, move to the left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key is larger, move to the right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // If the key is the same as the root's key, delete this node
    else {
        // Case 1: Node with no child (leaf)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node with one child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        struct Node* temp = findMin(root->right);

        // Copy the in-order successor's content to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to insert a new node into the BST
struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL) return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);

    return node;
}

// Inorder Traversal to display the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Creating a sample BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Inorder Traversal before deletion
    printf("Inorder Traversal before deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Delete node with value 20
    root = deleteNode(root, 20);
    printf("Inorder Traversal after deleting 20: ");
    inorderTraversal(root);
    printf("\n");

    // Delete node with value 30
    root = deleteNode(root, 30);
    printf("Inorder Traversal after deleting 30: ");
    inorderTraversal(root);
    printf("\n");

    // Delete node with value 50
    root = deleteNode(root, 50);
    printf("Inorder Traversal after deleting 50: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
