#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *head = NULL, *temp = NULL;

void createNode() {
    char ch;
    do {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data:\n");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // If list is empty, the new node becomes the head
            temp = head;
        } else {
            temp->next = newNode;  // Link the last node to the new node
            temp = newNode;        // Update temp to the new node
        }
        temp->next = head;  // Make the last node point to the head (circular link)

        printf("Do you want to insert a new node? y/n:\n");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

void display() {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Loop back to the head (circular behavior)

    printf("(back to head)\n");
}

void reverse() {
    if (head == NULL || head->next == head) {
        return; // If list is empty or has only one node, no need to reverse
    }

    struct Node *prev = NULL, *curr = head, *next = NULL;
    temp = head;

    do {
        next = curr->next;
        curr->next = prev;  // Reverse the current node's pointer
        prev = curr;
        curr = next;
    } while (curr != head);  // Keep iterating until we reach the head again

    head->next = prev;  // Connect the last node (prev) to the head
    head = prev;         // Update the head to the last node (now the first node)
}

int main() {
    createNode();
    printf("Original Circular Linked List:\n");
    display();

    reverse();
    printf("Reversed Circular Linked List:\n");
    display();

    return 0;
}
