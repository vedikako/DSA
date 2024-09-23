#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct Node {
    int data;
    struct Node *next;
} *top = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(int data) {
    struct Node* newNode = createNode(data);
    if (top == NULL) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
    printf("Pushed %d onto the stack\n", data);
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = top;
    int poppedData = temp->data;
    top = top->next;
    free(temp);
    return poppedData;
}

// Function to display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("Popped %d from the stack\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
