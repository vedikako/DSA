#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} *head, *temp = NULL;

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
            temp->next = newNode;  // Link the previous node to the new node
            newNode->prev = temp;  // Link the new node back to the previous node
            temp = newNode;
        }

        printf("Do you want to insert a new node? y/n:\n");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}

void display() {
    temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    createNode();
    display();
    return 0;
}