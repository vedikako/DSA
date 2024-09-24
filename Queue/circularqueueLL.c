#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to enqueue an element into the queue
void enqueue(int data) {
    struct Node* newNode = createNode(data);
    if (rear == NULL) {
        front = rear = newNode;
        rear->next = front; // Make it circular
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circularity
    }
    printf("Enqueued %d\n", data);
}

// Function to dequeue an element from the queue
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int dequeuedData;
    if (front == rear) {
        dequeuedData = front->data;
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        dequeuedData = temp->data;
        front = front->next;
        rear->next = front; // Maintain circularity
        free(temp);
    }
    return dequeuedData;
}

// Function to display the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements are:\n");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("FRONT\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("Dequeued %d\n", data);
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
