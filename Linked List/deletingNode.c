#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL, *temp = NULL, *p = NULL;

void createNode() {
    char ch;
    int count = 0;
    do {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data:\n");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;  // Link the previous node to the new node
            temp = newNode;        // Move temp to the new node
        }

        printf("Do you want to insert a new node? y/n:\n");
        scanf(" %c", &ch);
        count++;

    } while (ch == 'y' || ch == 'Y');
}

void deleteNode(int count) {
    int num;
    printf("Enter the position of the element to delete (1 to %d):\n", count);
    scanf("%d", &num);

    if (num < 1 || num > count) {
        printf("Invalid position\n");
        return;
    }

    // If the node to be deleted is the first node
    if (num == 1) {
        temp = head;
        head = head->next;  // Move head to the next node
        free(temp);         // Free the old head
    }
    // If the node to be deleted is in between or at the end
    else {
        p = head;
        for (int i = 1; i < num - 1; i++) {  // Move p to the (num-1)th node
            p = p->next;
        }

        // Now p points to the (num-1)th node, temp will point to the nth node
        temp = p->next;
        p->next = temp->next;  // Link the (num-1)th node to the (num+1)th node
        free(temp);            // Free the nth node
    }

    printf("Node at position %d deleted successfully.\n", num);
}

int countNodes() {
    int count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    createNode();

    int count = countNodes();
    if (count > 0) {
        deleteNode(count);
    } else {
        printf("The list is empty.\n");
    }

    return 0;
}
