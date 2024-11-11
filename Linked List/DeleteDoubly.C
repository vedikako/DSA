#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} *head = NULL, *temp = NULL;

void createNode() {
    char ch;
    do {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data:\n");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }

        printf("Do you want to insert a new node? y/n:\n");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}

void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;

    // Case 1: Deleting the head node
    if (current != NULL && current->data == key) {
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(current);
        printf("Node with data %d deleted.\n", key);
        return;
    }

    // Traverse to find the node with the given key
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    // Case 2: Node not found
    if (current == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // Case 3: Deleting a middle or last node
    if (current->next != NULL) { // If not the last node
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) { // If not the first node
        current->prev->next = current->next;
    }

    free(current);
    printf("Node with data %d deleted.\n", key);
}

void display() {
    temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    createNode();
    display();

    int key;
    printf("\nEnter the data value of the node you want to delete:\n");
    scanf("%d", &key);

    deleteNode(key);
    display();

    return 0;
}
