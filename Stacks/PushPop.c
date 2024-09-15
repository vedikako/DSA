#include <stdio.h>
#include <stdlib.h>

// Define the stack node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} *head, *tail = NULL;

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (tail == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = tail;
    int poppedValue = temp->data;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    return poppedValue;
}

// Function to display the stack
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("Stack elements: ");
    display();
    printf("Popped element: %d\n", pop());
    printf("Stack elements after pop: ");
    display();
    return 0;
}
