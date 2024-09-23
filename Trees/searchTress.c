#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree (BST)
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

// Function to insert a new node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

//to search key element

struct Node* search(struct Node* root,int key){

    if(root == NULL || root->data ==key)
    return root;

    if(root->data < key){
        return search(root->right, key);
    }else{
        return search(root->left, key);
    }
}

int main() {
    struct Node* root = NULL;
    
    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    printf(search(root, 40)!=NULL?"Found/n":"Notfound/n");
    printf(search(root, 50)!=NULL?"Found/n":"Notfound/n");
    
    return 0;
}