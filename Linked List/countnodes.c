#include <stdio.h> 
#include <stdlib.h> 
 
struct IntNode { 
    int data; 
    struct IntNode* next; 
}; 
 
struct IntNode* createIntNode(int data) { 
    struct IntNode* newNode = (struct IntNode*)malloc(sizeof(struct 
IntNode)); 
    newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
} 
 
int countNodes(struct IntNode* head) { 
    int count = 0; 
    struct IntNode* temp = head; 
    while (temp != NULL) { 
        count++; 
        temp = temp->next; 
    } 
    return count; 
} 
 
void displayIntList(struct IntNode* head) { 
    struct IntNode* temp = head; 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
int main() { 
     
    struct IntNode* intHead = createIntNode(10); 
    intHead->next = createIntNode(20); 
    intHead->next->next = createIntNode(30); 
 
     
    printf("Integer Linked List: "); 
    displayIntList(intHead); 
 
     
    int nodeCount = countNodes(intHead); 
    printf("Number of nodes in the linked list: %d\n", nodeCount); 
 
    return 0;
}