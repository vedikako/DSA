#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head1 = NULL, *head2 = NULL, *temp = NULL;

void createNode(struct Node **head) {
    char ch;
    do {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data:\n");
        scanf("%d", &newNode->data);
        newNode->next = *head;

        if (*head == NULL) {
            *head = newNode;
            newNode->next = *head;  // circular reference
        } else {
            temp = *head;
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = *head;  // make it circular
        }

        printf("Do you want to insert a new node? y/n:\n");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}

void concatenate(struct Node **head1, struct Node **head2) {
    if (*head1 == NULL || *head2 == NULL) return;

    struct Node *last1 = *head1;
    while (last1->next != *head1) {  // find last node of head1
        last1 = last1->next;
    }

    struct Node *last2 = *head2;
    while (last2->next != *head2) {  // find last node of head2
        last2 = last2->next;
    }

    last1->next = *head2;   // link last node of head1 to head2
    last2->next = *head1;   // link last node of head2 to head1
}

void display(struct Node *head) {
    if (head == NULL) return;

    temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main() {
    printf("Create first circular linked list:\n");
    createNode(&head1);
    printf("Create second circular linked list:\n");
    createNode(&head2);

    printf("\nFirst Circular Linked List:\n");
    display(head1);
    printf("\nSecond Circular Linked List:\n");
    display(head2);

    concatenate(&head1, &head2);
    printf("\nConcatenated Circular Linked List:\n");
    display(head1);

    return 0;
}
